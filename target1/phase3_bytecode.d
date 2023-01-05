
phase3_asm.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <.text>:
   0:	48 c7 c7 d0 dc 61 55 	mov    $0x5561dcd0,%rdi
   7:	c7 07 35 39 62 39    	movl   $0x39623935,(%rdi)
   d:	c7 47 04 39 37 66 61 	movl   $0x61663739,0x4(%rdi)
  14:	c6 47 08 00          	movb   $0x0,0x8(%rdi)
  18:	48 81 ec 58 06 00 00 	sub    $0x658,%rsp
  1f:	c7 04 24 fa 18 40 00 	movl   $0x4018fa,(%rsp)
  26:	c3                   	ret    
