#include <stdio.h>
#include "csapp.h"

/* Recommended max cache and object sizes */
#define MAX_CACHE_SIZE 1049000
#define MAX_OBJECT_SIZE 102400

/* You won't lose style points for including this long line in your code */
static const char *user_agent_hdr = "User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:10.0.3) Gecko/20120305 Firefox/10.0.3\r\n";
static const char *connect_hdr = "Connection: close\r\n";
static const char *proxy_connect_hdr = "Proxy-Connection: close\r\n";
static const char *http_version = "HTTP/1.0";

void* thread_function(void* arg);
void request(int fd);
void clienterror(int fd, char *cause, char *errnum, 
		 char *shortmsg, char *longmsg);
void parse_uri(const char* uri, char* host, char* port, char* path);
void forward_first_line(int clientfd, char* method, char* path) ;
void forward_requesthdrs(rio_t *rio_s, int clientfd, char* host);
void parse_header(const char* buf, char* key, char* value);

int main(int argc, char** argv) {
    int listenfd, connfd;
    char host[MAXLINE], port[MAXLINE];
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;

    /* Check command line args */
    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listenfd = Open_listenfd(argv[1]);
    while (1) {
        clientlen = sizeof(clientaddr);
        connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen); //line:netp:tiny:accept
        Getnameinfo((SA *) &clientaddr, clientlen, host, MAXLINE, 
                    port, MAXLINE, 0);
        printf("Accepted connection from (%s, %s)\n", host, port);

        int *connfd_copy = malloc(sizeof(int));
        *connfd_copy = connfd;

        pthread_t thread;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
        pthread_create(&thread, &attr, thread_function, connfd_copy);
        pthread_attr_destroy(&attr);
    }

    return 0;
}

void* thread_function(void* arg) {
    int connfd = *((int *) arg);
    request(connfd);
    Close(connfd);                                            //line:netp:tiny:close
}

void request(int fd) {
    int clientfd;
    char buf[MAXLINE], method[MAXLINE], uri[MAXLINE], version[MAXLINE];
    rio_t rio_s, rio_c;

    /* Read request line and headers */
    Rio_readinitb(&rio_s, fd);
    if (!Rio_readlineb(&rio_s, buf, MAXLINE))  //line:netp:doit:readrequest
        return;

    printf("%s", buf);
    sscanf(buf, "%s %s %s", method, uri, version);       //line:netp:doit:parserequest
    if (strcasecmp(method, "GET")) {                     //line:netp:doit:beginrequesterr
        clienterror(fd, method, "501", "Not Implemented",
                    "Proxy does not implement this method");
        return;
    }
    
    char host[MAXLINE], port[MAXLINE], path[MAXLINE];
    parse_uri(uri, host, port, path);
    
    printf("method: %s, uri: %s, version: %s\n", method, uri, version);

    // establish connection to server
    clientfd = Open_clientfd(host, port);
    
    forward_first_line(clientfd, method, path);

    forward_requesthdrs(&rio_s, clientfd, host);                              //line:netp:doit:readrequesthdrs
    Rio_writen(clientfd, "\r\n", 2); // end of request

    Rio_readinitb(&rio_c, clientfd);
    size_t n;
    printf("trying to get response....\n");
    while((n = Rio_readlineb(&rio_c, buf, MAXLINE)) != 0) {
        printf("proxy received %d bytes\n", (int)n);
        Rio_writen(fd, buf, n);
    }

    Close(clientfd);

    printf("Response sent\n");

    // clienterror(fd, host, "404", "Not found", "Work In Progress");
}

void parse_uri(const char* uri, char* host, char* port, char* path) {
    const int uri_len = strlen(uri);
    int i = 0, j = 0;
    int host_start = 0, port_start = -1, path_start = uri_len;
    
    for (i = 0; i + 2 < uri_len; i++) {
        if (uri[i] == ':' && uri[i + 1] == '/' && uri[i + 2] == '/') {
            host_start = i + 3;
            break;
        }
    }
    
    for (i = host_start; i < uri_len; i++) {
        if (uri[i] == '/') {
            path_start = i;
            break;
        }
        if (uri[i] == ':') {
            port_start = i;
        }
    }

    const int host_end = port_start != -1 ? port_start : path_start;
    for (i = host_start, j = 0; i < host_end; i++, j++) {
        host[j] = uri[i];
    }
    host[j] = '\0';

    if (port_start != -1) {
        for (i = port_start + 1, j = 0; i < path_start; i++, j++) {
            port[j] = uri[i];
        }
        port[j] = '\0';
    }
    else {
        strcpy(port, "80");
    }

    if (path_start != uri_len) {
        for (i = path_start, j = 0; i < uri_len; i++, j++) {
            path[j] = uri[i];
        }
        path[j] = '\0';
    }
    else {
        path[0] = '/';
        path[1] = '\0';
    }

    printf("host: %s, port: %s, path: %s\n", host, port, path);
}

void forward_first_line(int clientfd, char* method, char* path) {
    char buf[MAXLINE];
    int end = 0;
    strcpy(buf, method);
    end += strlen(method);
    strcpy(&buf[end], " ");
    end += 1;
    strcpy(&buf[end], path);
    end += strlen(path);
    strcpy(&buf[end], " ");
    end += 1;
    strcpy(&buf[end], http_version);
    end += strlen(http_version);
    strcpy(&buf[end], "\r\n");
    end += 2;

    printf("buf: %s\n", buf);
    Rio_writen(clientfd, buf, strlen(buf));
}

void forward_requesthdrs(rio_t *rio_s, int clientfd, char* host) {
    char buf[MAXLINE];
    char key[MAXLINE], value[MAXLINE];
    int host_sent = 0;
    int i = 0, j = 0;
    const int host_len = strlen(host);

    while (1) {
        Rio_readlineb(rio_s, buf, MAXLINE);
        if (!strcmp(buf, "\r\n"))
            break;
        printf("%s", buf);
        parse_header(buf, key, value);

        if (!strcmp(key, "Host")) {
            host_sent = 1;
            Rio_writen(clientfd, buf, strlen(buf));
        }
        else if (strcmp(key, "User-Agent") && 
                strcmp(key, "Connection") && strcmp(key, "Proxy-Connection")) {
            Rio_writen(clientfd, buf, strlen(buf));
        }
    }

    if (!host_sent) {
        strncpy(buf, "Host: ", 6);
        for (i = 6, j = 0; j < host_len; i++, j++)
            buf[i] = host[j];
        buf[i] = '\0';
        Rio_writen(clientfd, buf, strlen(buf));
    }

    Rio_writen(clientfd, user_agent_hdr, strlen(user_agent_hdr));
    Rio_writen(clientfd, connect_hdr, strlen(connect_hdr));
    Rio_writen(clientfd, proxy_connect_hdr, strlen(proxy_connect_hdr));

    return;
}

void parse_header(const char* buf, char* key, char* value) {
    const int buf_len = strlen(buf);
    int key_end = -1;
    int i = 0, j = 0;
    for (i = 0; i < buf_len; i++) {
        if (buf[i] == ':') {
            key_end = i;
            break;
        }
    }
    for (i = 0; i < key_end; i++) {
        key[i] = buf[i];
    }
    key[i] = '\0';

    for (i = key_end + 2, j = 0; i < buf_len; i++, j++) {
        value[j] = buf[i];
    }
    value[j] = '\0';

    printf("key: %s, value: %s\n", key, value);
}

/*
 * clienterror - returns an error message to the client
 */
/* $begin clienterror */
void clienterror(int fd, char *cause, char *errnum, 
		 char *shortmsg, char *longmsg) 
{
    char buf[MAXLINE];

    /* Print the HTTP response headers */
    sprintf(buf, "HTTP/1.0 %s %s\r\n", errnum, shortmsg);
    Rio_writen(fd, buf, strlen(buf));
    sprintf(buf, "Content-type: text/html\r\n\r\n");
    Rio_writen(fd, buf, strlen(buf));

    /* Print the HTTP response body */
    sprintf(buf, "<html><title>Tiny Error</title>");
    Rio_writen(fd, buf, strlen(buf));
    sprintf(buf, "<body bgcolor=""ffffff"">\r\n");
    Rio_writen(fd, buf, strlen(buf));
    sprintf(buf, "%s: %s\r\n", errnum, shortmsg);
    Rio_writen(fd, buf, strlen(buf));
    sprintf(buf, "<p>%s: %s\r\n", longmsg, cause);
    Rio_writen(fd, buf, strlen(buf));
    sprintf(buf, "<hr><em>The Tiny Web server</em>\r\n");
    Rio_writen(fd, buf, strlen(buf));
}
/* $end clienterror */
