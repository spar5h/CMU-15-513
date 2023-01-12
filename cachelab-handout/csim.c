#include "cachelab.h"
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct cache_line {
    int valid;   
    unsigned tag;
    int time;
};

int main(int argc, char* argv[])
{
    int opt;
    // int h = 0;
    int v = 0;
    int s = 1; // default for now
    int E = 1; // default for now
    int b = 1; // default for now
    char t[30];

    while ((opt = getopt(argc, argv, "s:E:b:t:hv")) != -1) {
        switch (opt) {
            case 'h':
                // h = 1;
                break;
            case 'v':
                v = 1;
                break;
            case 's':
                s = atoi(optarg);
                break;
            case 'E':
                E = atoi(optarg); 
                break;
            case 'b':
                b = atoi(optarg);
                break;
            case 't':
                strcpy(t, optarg); // unsafe 
                break;
            default: /* '?' */
                fprintf(stderr, "Usage: %s [-s set_bits] [-t file_name] [-v] name\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
 
    int S = 1 << s;
    struct cache_line cache[S][E];
    
    int i, j;
    for (i = 0; i < S; i++) {
        for (j = 0; j < E; j++) {
            cache[i][j].valid = 0;
            cache[i][j].tag = 0;
            cache[i][j].time = -1;
        }
    }   

    FILE* pFile;
    pFile = fopen(t, "r");

    char identifier;
    unsigned address;
    int size;

    int hit_count = 0, miss_count = 0, evict_count = 0;
    int time = 0;

    while (fscanf(pFile, " %c %x,%d", &identifier, &address, &size) > 0) {
        if (identifier == 'I')
            continue;

        time++;
        unsigned tag = address >> (s + b);
        unsigned set = (S - 1) & (address >> b);          
        
        // printf("time=%d; set=%d; tag=%d; address=%x; \n", time, set, tag, address);

        int idx = -1;
        for (i = 0; i < E; i++) {
            if (cache[set][i].valid && !(tag ^ cache[set][i].tag)) {
                idx = i; cache[set][i].time = time; break;
            }
        }
        
        int hit = idx != -1;
        int evict = 0;
        if (!hit) {
            for (i = 0; i < E; i++) {
                if (!cache[set][i].valid) { // found unused entry
                    idx = i; break;
                }
                if (idx == -1 || cache[set][i].time < cache[set][idx].time) {
                    idx = i;
                }
            }
            evict = (cache[set][idx].valid == 1);
            cache[set][idx].tag = tag;
            cache[set][idx].valid = 1;
            cache[set][idx].time = time;   
        }
        
        hit_count += hit ? 1 : 0;
        miss_count += hit ? 0 : 1;
        evict_count += evict ? 1 : 0;

        if (identifier == 'M') {
            hit_count++;
        }

        if (v) {
            printf("%c %x,%d ", identifier, address, size);
            
            if (hit) {
                printf("hit ");
            } else {
                printf("miss ");
                if (evict) {
                    printf("eviction ");   
                }
            }

            if (identifier == 'M')
                printf("hit ");

            printf("\n");
        }
    }
    
    printf("hits:%d misses:%d evictions:%d\n", hit_count, miss_count, evict_count);

    fclose(pFile);

    printSummary(hit_count, miss_count, evict_count);
    return 0;
}


