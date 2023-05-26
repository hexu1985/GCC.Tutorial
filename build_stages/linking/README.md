### 链接阶段

我们可以通过两种方法来编译链接项目，用于创建可执行文件。

如果采用按部就班的方式，首先需要编译每个源代码文件，生成目标文件；  
然后将两个目标文件链接输出可执行文件。

```
$ gcc -c function.c main.c
$ gcc function.o main.o -o demoApp
```

如果想一步到位，你可以使用一条命令调用编译器和链接器来完成相同的工作。

```
$ gcc function.c main.c -o demoApp
```

我们采用按部就班的方式，生成的main.o文件，我们用objdump反汇编看看：

```
$ objdump -D -M intel main.o
```

该命令的输出中包含了未解析的引用：

```
...
Disassembly of section .text:

0000000000000000 <main>:
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 20          	sub    rsp,0x20
   8:	89 7d ec             	mov    DWORD PTR [rbp-0x14],edi
   b:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
   f:	f3 0f 10 05 00 00 00 	movss  xmm0,DWORD PTR [rip+0x0]        # 17 <main+0x17>
  16:	00 
  17:	f3 0f 11 45 f4       	movss  DWORD PTR [rbp-0xc],xmm0
  1c:	f3 0f 10 05 00 00 00 	movss  xmm0,DWORD PTR [rip+0x0]        # 24 <main+0x24>
  23:	00 
  24:	f3 0f 11 45 f8       	movss  DWORD PTR [rbp-0x8],xmm0
  29:	f3 0f 10 45 f8       	movss  xmm0,DWORD PTR [rbp-0x8]
  2e:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
  31:	0f 28 c8             	movaps xmm1,xmm0
  34:	89 45 e8             	mov    DWORD PTR [rbp-0x18],eax
  37:	f3 0f 10 45 e8       	movss  xmm0,DWORD PTR [rbp-0x18]
  3c:	e8 00 00 00 00       	call   41 <main+0x41>
  41:	66 0f 7e c0          	movd   eax,xmm0
  45:	89 45 fc             	mov    DWORD PTR [rbp-0x4],eax
  48:	c7 05 00 00 00 00 01 	mov    DWORD PTR [rip+0x0],0x1        # 52 <main+0x52>
  4f:	00 00 00 
  52:	b8 00 00 00 00       	mov    eax,0x0
  57:	c9                   	leave  
  58:	c3                   	ret    

Disassembly of section .rodata:

0000000000000000 <.rodata>:
...
```

第3c行有一个跳转到自身的调用指令，而第48行测访问了位于地址0处的变量。很明显，  
链接器是故意插入这两个奇怪的值的。

我们来看一下可执行文件的反汇编输出。可以发现，链接器不仅将目标文件main.o的起始地址  
重定位成5fa，而且解析了那两个未解析的引用。

```
$ objdump -D -M intel demoApp
```

你将会在终端屏幕上得到以下输出内容（Intel汇编格式）：

```
...
00000000000005fa <main>:
 5fa:	55                   	push   rbp
 5fb:	48 89 e5             	mov    rbp,rsp
 5fe:	48 83 ec 20          	sub    rsp,0x20
 602:	89 7d ec             	mov    DWORD PTR [rbp-0x14],edi
 605:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
 609:	f3 0f 10 05 43 01 00 	movss  xmm0,DWORD PTR [rip+0x143]        # 754 <_IO_stdin_used+0x4>
 610:	00 
 611:	f3 0f 11 45 f4       	movss  DWORD PTR [rbp-0xc],xmm0
 616:	f3 0f 10 05 3a 01 00 	movss  xmm0,DWORD PTR [rip+0x13a]        # 758 <_IO_stdin_used+0x8>
 61d:	00 
 61e:	f3 0f 11 45 f8       	movss  DWORD PTR [rbp-0x8],xmm0
 623:	f3 0f 10 45 f8       	movss  xmm0,DWORD PTR [rbp-0x8]
 628:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
 62b:	0f 28 c8             	movaps xmm1,xmm0
 62e:	89 45 e8             	mov    DWORD PTR [rbp-0x18],eax
 631:	f3 0f 10 45 e8       	movss  xmm0,DWORD PTR [rbp-0x18]
 636:	e8 3c 00 00 00       	call   677 <add_and_multiply>
 63b:	66 0f 7e c0          	movd   eax,xmm0
 63f:	89 45 fc             	mov    DWORD PTR [rbp-0x4],eax
 642:	c7 05 c8 09 20 00 01 	mov    DWORD PTR [rip+0x2009c8],0x1        # 201014 <nCompletionStatus>
 649:	00 00 00 
 64c:	b8 00 00 00 00       	mov    eax,0x0
 651:	c9                   	leave  
 652:	c3                   	ret    
 ...

0000000000000677 <add_and_multiply>:
 677:	55                   	push   rbp
 678:	48 89 e5             	mov    rbp,rsp
 67b:	48 83 ec 20          	sub    rsp,0x20
 67f:	f3 0f 11 45 ec       	movss  DWORD PTR [rbp-0x14],xmm0
 684:	f3 0f 11 4d e8       	movss  DWORD PTR [rbp-0x18],xmm1
 689:	f3 0f 10 45 e8       	movss  xmm0,DWORD PTR [rbp-0x18]
 68e:	8b 45 ec             	mov    eax,DWORD PTR [rbp-0x14]
 691:	0f 28 c8             	movaps xmm1,xmm0
 694:	89 45 e4             	mov    DWORD PTR [rbp-0x1c],eax
 697:	f3 0f 10 45 e4       	movss  xmm0,DWORD PTR [rbp-0x1c]
 69c:	e8 b2 ff ff ff       	call   653 <add>
 6a1:	66 0f 7e c0          	movd   eax,xmm0
 6a5:	89 45 fc             	mov    DWORD PTR [rbp-0x4],eax
 6a8:	f3 0f 10 4d fc       	movss  xmm1,DWORD PTR [rbp-0x4]
 6ad:	f3 0f 10 05 a7 00 00 	movss  xmm0,DWORD PTR [rip+0xa7]        # 75c <_IO_stdin_used+0xc>
 6b4:	00 
 6b5:	f3 0f 59 c1          	mulss  xmm0,xmm1
 6b9:	f3 0f 11 45 fc       	movss  DWORD PTR [rbp-0x4],xmm0
 6be:	f3 0f 10 45 fc       	movss  xmm0,DWORD PTR [rbp-0x4]
 6c3:	c9                   	leave  
 6c4:	c3                   	ret    
 6c5:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
 6cc:	00 00 00 
 6cf:	90                   	nop
...

Disassembly of section .bss:

0000000000201010 <__bss_start>:
  201010:	00 00                	add    BYTE PTR [rax],al
	...

0000000000201014 <nCompletionStatus>:
  201014:	00 00                	add    BYTE PTR [rax],al
	...

```

内存映射地址642那行引用了地址201014（rip+0x2009c8）处的变量。  
现在还需解决的问题就是那个地方存放了什么数据？

万能的objdump工具可以帮助我们回答这个问题。

执行下面这条命令：

```
$ objdump -x -j .bss demoApp
```

你可以对含有未初始化数据的.bss节进行反汇编，发现变量nCompletionStatus存放  
在地址201014处，如下：

```
节：
Idx Name          Size      VMA               LMA               File off  Algn
 22 .bss          00000008  0000000000201010  0000000000201010  00001010  2**2
                  ALLOC
SYMBOL TABLE:
0000000000201010 l    d  .bss	0000000000000000              .bss
0000000000201010 l     O .bss	0000000000000001              completed.7698
0000000000201014 g     O .bss	0000000000000004              nCompletionStatus
0000000000201018 g       .bss	0000000000000000              _end
0000000000201010 g       .bss	0000000000000000              __bss_start
```

#### 参考资料:
《高级C/C++编译技术》: 2.4.1 链接阶段

