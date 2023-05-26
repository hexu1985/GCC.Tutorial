### 输出目标文件阶段（以及反汇编）

gcc编译器可以用于完整的编译（其中包括预处理、汇编和编译阶段），该过程中会生成  
二进制目标文件（标准扩展名是.o），其结构遵循ELF格式规范。

如果只需要执行编译过程（不执行链接），可以使用下面的命令行：

```
$ gcc -c <input file> -o <output file>.o
```

我们可以通过hexdump命令或xxd命令查看目标文件的十六进制值：

```
$ hexdump -C function.o
或者
$ xxd function.o
```

输出结果如下（xxd的结果）：

```
00000000: 7f45 4c46 0201 0100 0000 0000 0000 0000  .ELF............
00000010: 0100 3e00 0100 0000 0000 0000 0000 0000  ..>.............
00000020: 0000 0000 0000 0000 6003 0000 0000 0000  ........`.......
00000030: 0000 0000 4000 0000 0000 4000 0d00 0c00  ....@.....@.....
00000040: 5548 89e5 f30f 1145 ecf3 0f11 4de8 f30f  UH.....E....M...
00000050: 1045 ecf3 0f58 45e8 f30f 1145 fcf3 0f10  .E...XE....E....
00000060: 45fc 5dc3 5548 89e5 4883 ec20 f30f 1145  E.].UH..H.. ...E
00000070: ecf3 0f11 4de8 f30f 1045 e88b 45ec 0f28  ....M....E..E..(
00000080: c889 45e4 f30f 1045 e4e8 0000 0000 660f  ..E....E......f.
00000090: 7ec0 8945 fcf3 0f10 4dfc f30f 1005 0000  ~..E....M.......
000000a0: 0000 f30f 59c1 f30f 1145 fcf3 0f10 45fc  ....Y....E....E.
000000b0: c9c3 0000 0000 4040 0047 4343 3a20 2855  ......@@.GCC: (U
000000c0: 6275 6e74 7520 372e 352e 302d 3375 6275  buntu 7.5.0-3ubu
000000d0: 6e74 7531 7e31 382e 3034 2920 372e 352e  ntu1~18.04) 7.5.
000000e0: 3000 0000 0000 0000 1400 0000 0000 0000  0...............
000000f0: 017a 5200 0178 1001 1b0c 0708 9001 0000  .zR..x..........
00000100: 1c00 0000 1c00 0000 0000 0000 2400 0000  ............$...
00000110: 0041 0e10 8602 430d 065f 0c07 0800 0000  .A....C.._......
00000120: 1c00 0000 3c00 0000 0000 0000 4e00 0000  ....<.......N...
00000130: 0041 0e10 8602 430d 0602 490c 0708 0000  .A....C...I.....
00000140: 0000 0000 0000 0000 0000 0000 0000 0000  ................
00000150: 0000 0000 0000 0000 0100 0000 0400 f1ff  ................
00000160: 0000 0000 0000 0000 0000 0000 0000 0000  ................
00000170: 0000 0000 0300 0100 0000 0000 0000 0000  ................
00000180: 0000 0000 0000 0000 0000 0000 0300 0300  ................
00000190: 0000 0000 0000 0000 0000 0000 0000 0000  ................
000001a0: 0000 0000 0300 0400 0000 0000 0000 0000  ................
000001b0: 0000 0000 0000 0000 0000 0000 0300 0500  ................
000001c0: 0000 0000 0000 0000 0000 0000 0000 0000  ................
000001d0: 0000 0000 0300 0700 0000 0000 0000 0000  ................
000001e0: 0000 0000 0000 0000 0000 0000 0300 0800  ................
000001f0: 0000 0000 0000 0000 0000 0000 0000 0000  ................
00000200: 0000 0000 0300 0600 0000 0000 0000 0000  ................
00000210: 0000 0000 0000 0000 0c00 0000 1100 0400  ................
00000220: 0000 0000 0000 0000 0400 0000 0000 0000  ................
00000230: 1e00 0000 1200 0100 0000 0000 0000 0000  ................
00000240: 2400 0000 0000 0000 2200 0000 1200 0100  $.......".......
00000250: 2400 0000 0000 0000 4e00 0000 0000 0000  $.......N.......
00000260: 0066 756e 6374 696f 6e2e 6300 6e43 6f6d  .function.c.nCom
00000270: 706c 6574 696f 6e53 7461 7475 7300 6164  pletionStatus.ad
00000280: 6400 6164 645f 616e 645f 6d75 6c74 6970  d.add_and_multip
00000290: 6c79 0000 0000 0000 4a00 0000 0000 0000  ly......J.......
000002a0: 0200 0000 0a00 0000 fcff ffff ffff ffff  ................
000002b0: 5e00 0000 0000 0000 0200 0000 0500 0000  ^...............
000002c0: fcff ffff ffff ffff 2000 0000 0000 0000  ........ .......
000002d0: 0200 0000 0200 0000 0000 0000 0000 0000  ................
000002e0: 4000 0000 0000 0000 0200 0000 0200 0000  @...............
000002f0: 2400 0000 0000 0000 002e 7379 6d74 6162  $.........symtab
00000300: 002e 7374 7274 6162 002e 7368 7374 7274  ..strtab..shstrt
00000310: 6162 002e 7265 6c61 2e74 6578 7400 2e64  ab..rela.text..d
00000320: 6174 6100 2e62 7373 002e 726f 6461 7461  ata..bss..rodata
00000330: 002e 636f 6d6d 656e 7400 2e6e 6f74 652e  ..comment..note.
00000340: 474e 552d 7374 6163 6b00 2e72 656c 612e  GNU-stack..rela.
00000350: 6568 5f66 7261 6d65 0000 0000 0000 0000  eh_frame........
00000360: 0000 0000 0000 0000 0000 0000 0000 0000  ................
...
```


我们除了可以看目标文件的十六进制值，还能通过反汇编，了解到更多的细节。

objdump是一款专门用于反汇编二进制文件的Linux工具。该工具同时支持AT&T（默认）  
和Intel两种风格汇编代码的输出。

通过简单执行objdump命令：
```
$  objdump -D <input file>.o
```

你将会在终端屏幕上得到以下输出内容（AT&T汇编格式）：

```
function.o：     文件格式 elf64-x86-64


Disassembly of section .text:

0000000000000000 <add>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	f3 0f 11 45 ec       	movss  %xmm0,-0x14(%rbp)
   9:	f3 0f 11 4d e8       	movss  %xmm1,-0x18(%rbp)
   e:	f3 0f 10 45 ec       	movss  -0x14(%rbp),%xmm0
  13:	f3 0f 58 45 e8       	addss  -0x18(%rbp),%xmm0
  18:	f3 0f 11 45 fc       	movss  %xmm0,-0x4(%rbp)
  1d:	f3 0f 10 45 fc       	movss  -0x4(%rbp),%xmm0
  22:	5d                   	pop    %rbp
  23:	c3                   	retq

0000000000000024 <add_and_multiply>:
  24:	55                   	push   %rbp
  25:	48 89 e5             	mov    %rsp,%rbp
  28:	48 83 ec 20          	sub    $0x20,%rsp
  2c:	f3 0f 11 45 ec       	movss  %xmm0,-0x14(%rbp)
  31:	f3 0f 11 4d e8       	movss  %xmm1,-0x18(%rbp)
  36:	f3 0f 10 45 e8       	movss  -0x18(%rbp),%xmm0
  3b:	8b 45 ec             	mov    -0x14(%rbp),%eax
  3e:	0f 28 c8             	movaps %xmm0,%xmm1
  41:	89 45 e4             	mov    %eax,-0x1c(%rbp)
  44:	f3 0f 10 45 e4       	movss  -0x1c(%rbp),%xmm0
  49:	e8 00 00 00 00       	callq  4e <add_and_multiply+0x2a>
  4e:	66 0f 7e c0          	movd   %xmm0,%eax
  52:	89 45 fc             	mov    %eax,-0x4(%rbp)
  55:	f3 0f 10 4d fc       	movss  -0x4(%rbp),%xmm1
  5a:	f3 0f 10 05 00 00 00 	movss  0x0(%rip),%xmm0        # 62 <add_and_multiply+0x3e>
  61:	00
  62:	f3 0f 59 c1          	mulss  %xmm1,%xmm0
  66:	f3 0f 11 45 fc       	movss  %xmm0,-0x4(%rbp)
  6b:	f3 0f 10 45 fc       	movss  -0x4(%rbp),%xmm0
  70:	c9                   	leaveq
  71:	c3                   	retq

Disassembly of section .bss:

0000000000000000 <nCompletionStatus>:
   0:	00 00                	add    %al,(%rax)
	...

Disassembly of section .rodata:

0000000000000000 <.rodata>:
   0:	00 00                	add    %al,(%rax)
   2:	40                   	rex
   3:	40                   	rex

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	00 47 43             	add    %al,0x43(%rdi)
   3:	43 3a 20             	rex.XB cmp (%r8),%spl
   6:	28 55 62             	sub    %dl,0x62(%rbp)
   9:	75 6e                	jne    79 <add_and_multiply+0x55>
   b:	74 75                	je     82 <add_and_multiply+0x5e>
   d:	20 37                	and    %dh,(%rdi)
   f:	2e 35 2e 30 2d 33    	cs xor $0x332d302e,%eax
  15:	75 62                	jne    79 <add_and_multiply+0x55>
  17:	75 6e                	jne    87 <add_and_multiply+0x63>
  19:	74 75                	je     90 <add_and_multiply+0x6c>
  1b:	31 7e 31             	xor    %edi,0x31(%rsi)
  1e:	38 2e                	cmp    %ch,(%rsi)
  20:	30 34 29             	xor    %dh,(%rcx,%rbp,1)
  23:	20 37                	and    %dh,(%rdi)
  25:	2e                   	cs
  26:	35                   	.byte 0x35
  27:	2e 30 00             	xor    %al,%cs:(%rax)

Disassembly of section .eh_frame:

0000000000000000 <.eh_frame>:
   0:	14 00                	adc    $0x0,%al
   2:	00 00                	add    %al,(%rax)
   4:	00 00                	add    %al,(%rax)
   6:	00 00                	add    %al,(%rax)
   8:	01 7a 52             	add    %edi,0x52(%rdx)
   b:	00 01                	add    %al,(%rcx)
   d:	78 10                	js     1f <.eh_frame+0x1f>
   f:	01 1b                	add    %ebx,(%rbx)
  11:	0c 07                	or     $0x7,%al
  13:	08 90 01 00 00 1c    	or     %dl,0x1c000001(%rax)
  19:	00 00                	add    %al,(%rax)
  1b:	00 1c 00             	add    %bl,(%rax,%rax,1)
  1e:	00 00                	add    %al,(%rax)
  20:	00 00                	add    %al,(%rax)
  22:	00 00                	add    %al,(%rax)
  24:	24 00                	and    $0x0,%al
  26:	00 00                	add    %al,(%rax)
  28:	00 41 0e             	add    %al,0xe(%rcx)
  2b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  31:	5f                   	pop    %rdi
  32:	0c 07                	or     $0x7,%al
  34:	08 00                	or     %al,(%rax)
  36:	00 00                	add    %al,(%rax)
  38:	1c 00                	sbb    $0x0,%al
  3a:	00 00                	add    %al,(%rax)
  3c:	3c 00                	cmp    $0x0,%al
  3e:	00 00                	add    %al,(%rax)
  40:	00 00                	add    %al,(%rax)
  42:	00 00                	add    %al,(%rax)
  44:	4e 00 00             	rex.WRX add %r8b,(%rax)
  47:	00 00                	add    %al,(%rax)
  49:	41 0e                	rex.B (bad)
  4b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  51:	02 49 0c             	add    0xc(%rcx),%cl
  54:	07                   	(bad)
  55:	08 00                	or     %al,(%rax)
	...
```

于上面命令类似，我们可以指定Intel汇编风格：

```
$ objdump -D -M intel <input file>.o
```

你将会在终端屏幕上得到以下输出内容（Intel汇编格式）：

```
function.o：     文件格式 elf64-x86-64


Disassembly of section .text:

0000000000000000 <add>:
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	f3 0f 11 45 ec       	movss  DWORD PTR [rbp-0x14],xmm0
   9:	f3 0f 11 4d e8       	movss  DWORD PTR [rbp-0x18],xmm1
   e:	f3 0f 10 45 ec       	movss  xmm0,DWORD PTR [rbp-0x14]
  13:	f3 0f 58 45 e8       	addss  xmm0,DWORD PTR [rbp-0x18]
  18:	f3 0f 11 45 fc       	movss  DWORD PTR [rbp-0x4],xmm0
  1d:	f3 0f 10 45 fc       	movss  xmm0,DWORD PTR [rbp-0x4]
  22:	5d                   	pop    rbp
  23:	c3                   	ret

0000000000000024 <add_and_multiply>:
  24:	55                   	push   rbp
  25:	48 89 e5             	mov    rbp,rsp
  28:	48 83 ec 20          	sub    rsp,0x20
  2c:	f3 0f 11 45 ec       	movss  DWORD PTR [rbp-0x14],xmm0
  31:	f3 0f 11 4d e8       	movss  DWORD PTR [rbp-0x18],xmm1
  36:	f3 0f 10 45 e8       	movss  xmm0,DWORD PTR [rbp-0x18]
  3b:	8b 45 ec             	mov    eax,DWORD PTR [rbp-0x14]
  3e:	0f 28 c8             	movaps xmm1,xmm0
  41:	89 45 e4             	mov    DWORD PTR [rbp-0x1c],eax
  44:	f3 0f 10 45 e4       	movss  xmm0,DWORD PTR [rbp-0x1c]
  49:	e8 00 00 00 00       	call   4e <add_and_multiply+0x2a>
  4e:	66 0f 7e c0          	movd   eax,xmm0
  52:	89 45 fc             	mov    DWORD PTR [rbp-0x4],eax
  55:	f3 0f 10 4d fc       	movss  xmm1,DWORD PTR [rbp-0x4]
  5a:	f3 0f 10 05 00 00 00 	movss  xmm0,DWORD PTR [rip+0x0]        # 62 <add_and_multiply+0x3e>
  61:	00
  62:	f3 0f 59 c1          	mulss  xmm0,xmm1
  66:	f3 0f 11 45 fc       	movss  DWORD PTR [rbp-0x4],xmm0
  6b:	f3 0f 10 45 fc       	movss  xmm0,DWORD PTR [rbp-0x4]
  70:	c9                   	leave
  71:	c3                   	ret

Disassembly of section .bss:

0000000000000000 <nCompletionStatus>:
   0:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .rodata:

0000000000000000 <.rodata>:
   0:	00 00                	add    BYTE PTR [rax],al
   2:	40                   	rex
   3:	40                   	rex

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	00 47 43             	add    BYTE PTR [rdi+0x43],al
   3:	43 3a 20             	rex.XB cmp spl,BYTE PTR [r8]
   6:	28 55 62             	sub    BYTE PTR [rbp+0x62],dl
   9:	75 6e                	jne    79 <add_and_multiply+0x55>
   b:	74 75                	je     82 <add_and_multiply+0x5e>
   d:	20 37                	and    BYTE PTR [rdi],dh
   f:	2e 35 2e 30 2d 33    	cs xor eax,0x332d302e
  15:	75 62                	jne    79 <add_and_multiply+0x55>
  17:	75 6e                	jne    87 <add_and_multiply+0x63>
  19:	74 75                	je     90 <add_and_multiply+0x6c>
  1b:	31 7e 31             	xor    DWORD PTR [rsi+0x31],edi
  1e:	38 2e                	cmp    BYTE PTR [rsi],ch
  20:	30 34 29             	xor    BYTE PTR [rcx+rbp*1],dh
  23:	20 37                	and    BYTE PTR [rdi],dh
  25:	2e                   	cs
  26:	35                   	.byte 0x35
  27:	2e 30 00             	xor    BYTE PTR cs:[rax],al

Disassembly of section .eh_frame:

0000000000000000 <.eh_frame>:
   0:	14 00                	adc    al,0x0
   2:	00 00                	add    BYTE PTR [rax],al
   4:	00 00                	add    BYTE PTR [rax],al
   6:	00 00                	add    BYTE PTR [rax],al
   8:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
   b:	00 01                	add    BYTE PTR [rcx],al
   d:	78 10                	js     1f <.eh_frame+0x1f>
   f:	01 1b                	add    DWORD PTR [rbx],ebx
  11:	0c 07                	or     al,0x7
  13:	08 90 01 00 00 1c    	or     BYTE PTR [rax+0x1c000001],dl
  19:	00 00                	add    BYTE PTR [rax],al
  1b:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  1e:	00 00                	add    BYTE PTR [rax],al
  20:	00 00                	add    BYTE PTR [rax],al
  22:	00 00                	add    BYTE PTR [rax],al
  24:	24 00                	and    al,0x0
  26:	00 00                	add    BYTE PTR [rax],al
  28:	00 41 0e             	add    BYTE PTR [rcx+0xe],al
  2b:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  31:	5f                   	pop    rdi
  32:	0c 07                	or     al,0x7
  34:	08 00                	or     BYTE PTR [rax],al
  36:	00 00                	add    BYTE PTR [rax],al
  38:	1c 00                	sbb    al,0x0
  3a:	00 00                	add    BYTE PTR [rax],al
  3c:	3c 00                	cmp    al,0x0
  3e:	00 00                	add    BYTE PTR [rax],al
  40:	00 00                	add    BYTE PTR [rax],al
  42:	00 00                	add    BYTE PTR [rax],al
  44:	4e 00 00             	rex.WRX add BYTE PTR [rax],r8b
  47:	00 00                	add    BYTE PTR [rax],al
  49:	41 0e                	rex.B (bad)
  4b:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  51:	02 49 0c             	add    cl,BYTE PTR [rcx+0xc]
  54:	07                   	(bad)
  55:	08 00                	or     BYTE PTR [rax],al
	...
```

#### 参考资料:
《高级C/C++编译技术》: 2.3.3 编译的各个阶段

