
build/main.elf:     file format elf32-m68k


Disassembly of section .text:

00000000 <ascii>:
   0:	598f           	subql #4,%sp
   2:	4297           	clrl %sp@
   4:	601e           	bras 24 <ascii+0x24>
   6:	2017           	movel %sp@,%d0
   8:	206f 0008      	moveal %sp@(8),%a0
   c:	d1c0           	addal %d0,%a0
   e:	1010           	moveb %a0@,%d0
  10:	1200           	moveb %d0,%d1
  12:	2017           	movel %sp@,%d0
  14:	d080           	addl %d0,%d0
  16:	206f 000c      	moveal %sp@(12),%a0
  1a:	d1c0           	addal %d0,%a0
  1c:	4240           	clrw %d0
  1e:	1001           	moveb %d1,%d0
  20:	3080           	movew %d0,%a0@
  22:	5297           	addql #1,%sp@
  24:	2017           	movel %sp@,%d0
  26:	206f 0008      	moveal %sp@(8),%a0
  2a:	d1c0           	addal %d0,%a0
  2c:	1010           	moveb %a0@,%d0
  2e:	66d6           	bnes 6 <ascii+0x6>
  30:	2017           	movel %sp@,%d0
  32:	d080           	addl %d0,%d0
  34:	206f 000c      	moveal %sp@(12),%a0
  38:	d1c0           	addal %d0,%a0
  3a:	4250           	clrw %a0@
  3c:	4e71           	nop
  3e:	588f           	addql #4,%sp
  40:	4e75           	rts

00000042 <my_printf>:
  42:	4fef fe00      	lea %sp@(-512),%sp
  46:	200f           	movel %sp,%d0
  48:	2f00           	movel %d0,%sp@-
  4a:	2f2f 0208      	movel %sp@(520),%sp@-
  4e:	4eba ffb0      	jsr %pc@(0 <ascii>)
  52:	508f           	addql #8,%sp
  54:	200f           	movel %sp,%d0
  56:	2f00           	movel %d0,%sp@-
  58:	4eb9 0000 0096 	jsr 96 <print_ascii>
  5e:	588f           	addql #4,%sp
  60:	4e71           	nop
  62:	4fef 0200      	lea %sp@(512),%sp
  66:	4e75           	rts

00000068 <main>:
  68:	598f           	subql #4,%sp
  6a:	7002           	moveq #2,%d0
  6c:	2e80           	movel %d0,%sp@
  6e:	7001           	moveq #1,%d0
  70:	b097           	cmpl %sp@,%d0
  72:	6c02           	bges 76 <main+0xe>
  74:	5297           	addql #1,%sp@
  76:	4878 0005      	pea 5 <ascii+0x5>
  7a:	4878 0001      	pea 1 <ascii+0x1>
  7e:	4eb9 0000 008c 	jsr 8c <my_add>
  84:	508f           	addql #8,%sp
  86:	7000           	moveq #0,%d0
  88:	588f           	addql #4,%sp
  8a:	4e75           	rts

0000008c <my_add>:
  8c:	202f 0004      	movel %sp@(4),%d0
  90:	d0af 0008      	addl %sp@(8),%d0
  94:	4e75           	rts

00000096 <print_ascii>:
  96:	206f 0004      	moveal %sp@(4),%a0

0000009a <print_loop>:
  9a:	3018           	movew %a0@+,%d0
  9c:	6700 0006      	beqw a4 <end_print>
  a0:	6000 fff8      	braw 9a <print_loop>

000000a4 <end_print>:
  a4:	4e75           	rts
