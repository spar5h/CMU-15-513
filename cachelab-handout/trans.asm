
trans.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <transpose_submit>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	89 7d cc             	mov    %edi,-0x34(%rbp)
   7:	89 75 c8             	mov    %esi,-0x38(%rbp)
   a:	48 89 55 c0          	mov    %rdx,-0x40(%rbp)
   e:	48 89 4d b8          	mov    %rcx,-0x48(%rbp)
  12:	8b 45 cc             	mov    -0x34(%rbp),%eax
  15:	48 63 d0             	movslq %eax,%rdx
  18:	48 83 ea 01          	sub    $0x1,%rdx
  1c:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
  20:	48 63 d0             	movslq %eax,%rdx
  23:	49 89 d2             	mov    %rdx,%r10
  26:	41 bb 00 00 00 00    	mov    $0x0,%r11d
  2c:	8b 55 c8             	mov    -0x38(%rbp),%edx
  2f:	48 63 ca             	movslq %edx,%rcx
  32:	48 83 e9 01          	sub    $0x1,%rcx
  36:	48 89 4d e0          	mov    %rcx,-0x20(%rbp)
  3a:	48 63 ca             	movslq %edx,%rcx
  3d:	49 89 c8             	mov    %rcx,%r8
  40:	41 b9 00 00 00 00    	mov    $0x0,%r9d
  46:	c7 45 dc 08 00 00 00 	movl   $0x8,-0x24(%rbp)
  4d:	c7 45 d8 08 00 00 00 	movl   $0x8,-0x28(%rbp)
  54:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  5b:	eb 4f                	jmp    ac <transpose_submit+0xac>
  5d:	8b 4d fc             	mov    -0x4(%rbp),%ecx
  60:	48 63 f1             	movslq %ecx,%rsi
  63:	48 63 ca             	movslq %edx,%rcx
  66:	48 0f af ce          	imul   %rsi,%rcx
  6a:	48 8d 34 8d 00 00 00 	lea    0x0(,%rcx,4),%rsi
  71:	00 
  72:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
  76:	48 8d 3c 0e          	lea    (%rsi,%rcx,1),%rdi
  7a:	8b 4d fc             	mov    -0x4(%rbp),%ecx
  7d:	48 63 f1             	movslq %ecx,%rsi
  80:	48 63 c8             	movslq %eax,%rcx
  83:	48 0f af ce          	imul   %rsi,%rcx
  87:	48 8d 34 8d 00 00 00 	lea    0x0(,%rcx,4),%rsi
  8e:	00 
  8f:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
  93:	48 01 ce             	add    %rcx,%rsi
  96:	8b 4d fc             	mov    -0x4(%rbp),%ecx
  99:	48 63 c9             	movslq %ecx,%rcx
  9c:	8b 34 8e             	mov    (%rsi,%rcx,4),%esi
  9f:	8b 4d fc             	mov    -0x4(%rbp),%ecx
  a2:	48 63 c9             	movslq %ecx,%rcx
  a5:	89 34 8f             	mov    %esi,(%rdi,%rcx,4)
  a8:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
  ac:	8b 4d fc             	mov    -0x4(%rbp),%ecx
  af:	3b 4d c8             	cmp    -0x38(%rbp),%ecx
  b2:	7c a9                	jl     5d <transpose_submit+0x5d>
  b4:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  bb:	e9 bf 00 00 00       	jmpq   17f <transpose_submit+0x17f>
  c0:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
  c7:	e9 a1 00 00 00       	jmpq   16d <transpose_submit+0x16d>
  cc:	8b 4d fc             	mov    -0x4(%rbp),%ecx
  cf:	89 4d f4             	mov    %ecx,-0xc(%rbp)
  d2:	eb 7a                	jmp    14e <transpose_submit+0x14e>
  d4:	8b 4d f8             	mov    -0x8(%rbp),%ecx
  d7:	89 4d f0             	mov    %ecx,-0x10(%rbp)
  da:	eb 59                	jmp    135 <transpose_submit+0x135>
  dc:	8b 4d f4             	mov    -0xc(%rbp),%ecx
  df:	3b 4d f0             	cmp    -0x10(%rbp),%ecx
  e2:	75 02                	jne    e6 <transpose_submit+0xe6>
  e4:	eb 4b                	jmp    131 <transpose_submit+0x131>
  e6:	8b 4d f0             	mov    -0x10(%rbp),%ecx
  e9:	48 63 f1             	movslq %ecx,%rsi
  ec:	48 63 ca             	movslq %edx,%rcx
  ef:	48 0f af ce          	imul   %rsi,%rcx
  f3:	48 8d 34 8d 00 00 00 	lea    0x0(,%rcx,4),%rsi
  fa:	00 
  fb:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
  ff:	48 8d 3c 0e          	lea    (%rsi,%rcx,1),%rdi
 103:	8b 4d f4             	mov    -0xc(%rbp),%ecx
 106:	48 63 f1             	movslq %ecx,%rsi
 109:	48 63 c8             	movslq %eax,%rcx
 10c:	48 0f af ce          	imul   %rsi,%rcx
 110:	48 8d 34 8d 00 00 00 	lea    0x0(,%rcx,4),%rsi
 117:	00 
 118:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
 11c:	48 01 ce             	add    %rcx,%rsi
 11f:	8b 4d f0             	mov    -0x10(%rbp),%ecx
 122:	48 63 c9             	movslq %ecx,%rcx
 125:	8b 34 8e             	mov    (%rsi,%rcx,4),%esi
 128:	8b 4d f4             	mov    -0xc(%rbp),%ecx
 12b:	48 63 c9             	movslq %ecx,%rcx
 12e:	89 34 8f             	mov    %esi,(%rdi,%rcx,4)
 131:	83 45 f0 01          	addl   $0x1,-0x10(%rbp)
 135:	8b 4d d8             	mov    -0x28(%rbp),%ecx
 138:	8b 75 f8             	mov    -0x8(%rbp),%esi
 13b:	01 f1                	add    %esi,%ecx
 13d:	3b 4d f0             	cmp    -0x10(%rbp),%ecx
 140:	7e 08                	jle    14a <transpose_submit+0x14a>
 142:	8b 4d f0             	mov    -0x10(%rbp),%ecx
 145:	3b 4d cc             	cmp    -0x34(%rbp),%ecx
 148:	7c 92                	jl     dc <transpose_submit+0xdc>
 14a:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
 14e:	8b 4d dc             	mov    -0x24(%rbp),%ecx
 151:	8b 75 fc             	mov    -0x4(%rbp),%esi
 154:	01 f1                	add    %esi,%ecx
 156:	3b 4d f4             	cmp    -0xc(%rbp),%ecx
 159:	7e 0c                	jle    167 <transpose_submit+0x167>
 15b:	8b 4d f4             	mov    -0xc(%rbp),%ecx
 15e:	3b 4d c8             	cmp    -0x38(%rbp),%ecx
 161:	0f 8c 6d ff ff ff    	jl     d4 <transpose_submit+0xd4>
 167:	8b 4d d8             	mov    -0x28(%rbp),%ecx
 16a:	01 4d f8             	add    %ecx,-0x8(%rbp)
 16d:	8b 4d f8             	mov    -0x8(%rbp),%ecx
 170:	3b 4d cc             	cmp    -0x34(%rbp),%ecx
 173:	0f 8c 53 ff ff ff    	jl     cc <transpose_submit+0xcc>
 179:	8b 4d dc             	mov    -0x24(%rbp),%ecx
 17c:	01 4d fc             	add    %ecx,-0x4(%rbp)
 17f:	8b 4d fc             	mov    -0x4(%rbp),%ecx
 182:	3b 4d c8             	cmp    -0x38(%rbp),%ecx
 185:	0f 8c 35 ff ff ff    	jl     c0 <transpose_submit+0xc0>
 18b:	5d                   	pop    %rbp
 18c:	c3                   	retq   

000000000000018d <trans>:
 18d:	55                   	push   %rbp
 18e:	48 89 e5             	mov    %rsp,%rbp
 191:	89 7d dc             	mov    %edi,-0x24(%rbp)
 194:	89 75 d8             	mov    %esi,-0x28(%rbp)
 197:	48 89 55 d0          	mov    %rdx,-0x30(%rbp)
 19b:	48 89 4d c8          	mov    %rcx,-0x38(%rbp)
 19f:	8b 45 dc             	mov    -0x24(%rbp),%eax
 1a2:	48 63 d0             	movslq %eax,%rdx
 1a5:	48 83 ea 01          	sub    $0x1,%rdx
 1a9:	48 89 55 f0          	mov    %rdx,-0x10(%rbp)
 1ad:	48 63 d0             	movslq %eax,%rdx
 1b0:	49 89 d2             	mov    %rdx,%r10
 1b3:	41 bb 00 00 00 00    	mov    $0x0,%r11d
 1b9:	8b 55 d8             	mov    -0x28(%rbp),%edx
 1bc:	48 63 ca             	movslq %edx,%rcx
 1bf:	48 83 e9 01          	sub    $0x1,%rcx
 1c3:	48 89 4d e8          	mov    %rcx,-0x18(%rbp)
 1c7:	48 63 ca             	movslq %edx,%rcx
 1ca:	49 89 c8             	mov    %rcx,%r8
 1cd:	41 b9 00 00 00 00    	mov    $0x0,%r9d
 1d3:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
 1da:	eb 6a                	jmp    246 <trans+0xb9>
 1dc:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
 1e3:	eb 55                	jmp    23a <trans+0xad>
 1e5:	8b 4d fc             	mov    -0x4(%rbp),%ecx
 1e8:	48 63 f1             	movslq %ecx,%rsi
 1eb:	48 63 c8             	movslq %eax,%rcx
 1ee:	48 0f af ce          	imul   %rsi,%rcx
 1f2:	48 8d 34 8d 00 00 00 	lea    0x0(,%rcx,4),%rsi
 1f9:	00 
 1fa:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
 1fe:	48 01 ce             	add    %rcx,%rsi
 201:	8b 4d f8             	mov    -0x8(%rbp),%ecx
 204:	48 63 c9             	movslq %ecx,%rcx
 207:	8b 0c 8e             	mov    (%rsi,%rcx,4),%ecx
 20a:	89 4d e4             	mov    %ecx,-0x1c(%rbp)
 20d:	8b 4d f8             	mov    -0x8(%rbp),%ecx
 210:	48 63 f1             	movslq %ecx,%rsi
 213:	48 63 ca             	movslq %edx,%rcx
 216:	48 0f af ce          	imul   %rsi,%rcx
 21a:	48 8d 34 8d 00 00 00 	lea    0x0(,%rcx,4),%rsi
 221:	00 
 222:	48 8b 4d c8          	mov    -0x38(%rbp),%rcx
 226:	48 8d 3c 0e          	lea    (%rsi,%rcx,1),%rdi
 22a:	8b 4d fc             	mov    -0x4(%rbp),%ecx
 22d:	48 63 c9             	movslq %ecx,%rcx
 230:	8b 75 e4             	mov    -0x1c(%rbp),%esi
 233:	89 34 8f             	mov    %esi,(%rdi,%rcx,4)
 236:	83 45 f8 01          	addl   $0x1,-0x8(%rbp)
 23a:	8b 4d f8             	mov    -0x8(%rbp),%ecx
 23d:	3b 4d dc             	cmp    -0x24(%rbp),%ecx
 240:	7c a3                	jl     1e5 <trans+0x58>
 242:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
 246:	8b 4d fc             	mov    -0x4(%rbp),%ecx
 249:	3b 4d d8             	cmp    -0x28(%rbp),%ecx
 24c:	7c 8e                	jl     1dc <trans+0x4f>
 24e:	5d                   	pop    %rbp
 24f:	c3                   	retq   

0000000000000250 <registerFunctions>:
 250:	55                   	push   %rbp
 251:	48 89 e5             	mov    %rsp,%rbp
 254:	be 00 00 00 00       	mov    $0x0,%esi
 259:	bf 00 00 00 00       	mov    $0x0,%edi
 25e:	e8 00 00 00 00       	callq  263 <registerFunctions+0x13>
 263:	be 00 00 00 00       	mov    $0x0,%esi
 268:	bf 00 00 00 00       	mov    $0x0,%edi
 26d:	e8 00 00 00 00       	callq  272 <registerFunctions+0x22>
 272:	5d                   	pop    %rbp
 273:	c3                   	retq   

0000000000000274 <is_transpose>:
 274:	55                   	push   %rbp
 275:	48 89 e5             	mov    %rsp,%rbp
 278:	89 7d dc             	mov    %edi,-0x24(%rbp)
 27b:	89 75 d8             	mov    %esi,-0x28(%rbp)
 27e:	48 89 55 d0          	mov    %rdx,-0x30(%rbp)
 282:	48 89 4d c8          	mov    %rcx,-0x38(%rbp)
 286:	8b 45 dc             	mov    -0x24(%rbp),%eax
 289:	48 63 d0             	movslq %eax,%rdx
 28c:	48 83 ea 01          	sub    $0x1,%rdx
 290:	48 89 55 f0          	mov    %rdx,-0x10(%rbp)
 294:	48 63 d0             	movslq %eax,%rdx
 297:	49 89 d2             	mov    %rdx,%r10
 29a:	41 bb 00 00 00 00    	mov    $0x0,%r11d
 2a0:	8b 55 d8             	mov    -0x28(%rbp),%edx
 2a3:	48 63 ca             	movslq %edx,%rcx
 2a6:	48 83 e9 01          	sub    $0x1,%rcx
 2aa:	48 89 4d e8          	mov    %rcx,-0x18(%rbp)
 2ae:	48 63 ca             	movslq %edx,%rcx
 2b1:	49 89 c8             	mov    %rcx,%r8
 2b4:	41 b9 00 00 00 00    	mov    $0x0,%r9d
 2ba:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
 2c1:	eb 6e                	jmp    331 <is_transpose+0xbd>
 2c3:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
 2ca:	eb 59                	jmp    325 <is_transpose+0xb1>
 2cc:	8b 4d fc             	mov    -0x4(%rbp),%ecx
 2cf:	48 63 f1             	movslq %ecx,%rsi
 2d2:	48 63 c8             	movslq %eax,%rcx
 2d5:	48 0f af ce          	imul   %rsi,%rcx
 2d9:	48 8d 34 8d 00 00 00 	lea    0x0(,%rcx,4),%rsi
 2e0:	00 
 2e1:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
 2e5:	48 01 ce             	add    %rcx,%rsi
 2e8:	8b 4d f8             	mov    -0x8(%rbp),%ecx
 2eb:	48 63 c9             	movslq %ecx,%rcx
 2ee:	8b 34 8e             	mov    (%rsi,%rcx,4),%esi
 2f1:	8b 4d f8             	mov    -0x8(%rbp),%ecx
 2f4:	48 63 f9             	movslq %ecx,%rdi
 2f7:	48 63 ca             	movslq %edx,%rcx
 2fa:	48 0f af cf          	imul   %rdi,%rcx
 2fe:	48 8d 3c 8d 00 00 00 	lea    0x0(,%rcx,4),%rdi
 305:	00 
 306:	48 8b 4d c8          	mov    -0x38(%rbp),%rcx
 30a:	48 01 cf             	add    %rcx,%rdi
 30d:	8b 4d fc             	mov    -0x4(%rbp),%ecx
 310:	48 63 c9             	movslq %ecx,%rcx
 313:	8b 0c 8f             	mov    (%rdi,%rcx,4),%ecx
 316:	39 ce                	cmp    %ecx,%esi
 318:	74 07                	je     321 <is_transpose+0xad>
 31a:	b8 00 00 00 00       	mov    $0x0,%eax
 31f:	eb 1d                	jmp    33e <is_transpose+0xca>
 321:	83 45 f8 01          	addl   $0x1,-0x8(%rbp)
 325:	8b 4d f8             	mov    -0x8(%rbp),%ecx
 328:	3b 4d dc             	cmp    -0x24(%rbp),%ecx
 32b:	7c 9f                	jl     2cc <is_transpose+0x58>
 32d:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
 331:	8b 4d fc             	mov    -0x4(%rbp),%ecx
 334:	3b 4d d8             	cmp    -0x28(%rbp),%ecx
 337:	7c 8a                	jl     2c3 <is_transpose+0x4f>
 339:	b8 01 00 00 00       	mov    $0x1,%eax
 33e:	5d                   	pop    %rbp
 33f:	c3                   	retq   
