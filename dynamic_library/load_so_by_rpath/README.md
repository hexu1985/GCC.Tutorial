### 在Linux中通过rpath添加运行时动态库文件搜索路径

1. 在Linux中，我们可以通过rpath设置动态库运行时搜索路径，我们通常使用-R或者-rpath选项向链接器传递rpath。
此外，根据惯例，凡是间接调用链接器时（也就是直接调用gcc或者g++），我们需要在链接器参数前追加“`-Wl,`”前缀（也就是“减号Wl逗号”）。
	```shell
	gcc -Wl,-R/home/milan/projects/ -lmilanlibrary
	      ^   ^       ^
	      |   |       |
	      |   |       actual rpath value
	      |   |
	      |   run path linker flag
	      |
	      -Wl, prefix required when invoking linker
	      indirectly, through gcc instead of 
	      directly invoking ld
	```

2. rpath信息会存在二进制文件的DT_RPATH字段中，查看二进制文件DT_RPATH值的方法是查看二进制文件的ELF头（比如执行`readelf -d`或者`objdump -x`命令）

	在centos7.5上，gcc version 4.8.5可以看到如下结果：
	
	```shell
	$ readelf -d app 
	
	Dynamic section at offset 0xe08 contains 26 entries:
	  标记        类型                         名称/值
	 0x0000000000000001 (NEEDED)             共享库：[libmydynamiclib.so]
	 0x0000000000000001 (NEEDED)             共享库：[libc.so.6]
	 0x000000000000000f (RPATH)              Library rpath: [$ORIGIN/../lib]
	 0x000000000000000c (INIT)               0x4005b0
	 0x000000000000000d (FINI)               0x400814
	
	```

	```shell
	$ objdump -x app
	
	app/app：     文件格式 elf64-x86-64
	app/app
	体系结构：i386:x86-64，标志 0x00000112：
	EXEC_P, HAS_SYMS, D_PAGED
	起始地址 0x0000000000400650
	
	...
	
	动态节：
	  NEEDED               libmydynamiclib.so
	  NEEDED               libc.so.6
	  RPATH                $ORIGIN/../lib
	
	...
	```

	有趣的是在在ubuntu18.04上，gcc version: 7.5.0，却是RUNPATH字段，猜测是因为高版本的gcc做出了调整。

	```shell
	$ readelf -d app 
	
	Dynamic section at offset 0xd88 contains 29 entries:
	  标记        类型                         名称/值
	 0x0000000000000001 (NEEDED)             共享库：[libmydynamiclib.so]
	 0x0000000000000001 (NEEDED)             共享库：[libc.so.6]
	 0x000000000000001d (RUNPATH)            Library runpath: [../lib]
	 0x000000000000000c (INIT)               0x6d0
	 0x000000000000000d (FINI)               0x944
	```

	```shell
	$ objdump -x app
	
	app：     文件格式 elf64-x86-64
	app
	体系结构：i386:x86-64， 标志 0x00000150：
	HAS_SYMS, DYNAMIC, D_PAGED
	起始地址 0x0000000000000750
	
	...
	
	动态节：
	  NEEDED               libmydynamiclib.so
	  NEEDED               libc.so.6
	  RUNPATH              ../lib
	
	...
	
	```

3. 可执行文件中DT_RPATH中如果存储了相对路径，装载器并不是将其解释成相对于可执行程序的路径，而是相对于装载器（即应用程序）启动路径（当前工作路径PWD）的相对路径。$ORIGIN是一个特殊的变量，指示实际的可执行文件名。它在运行时解析到可执行文件的位置，在设置RPATH时非常有用。

	通过将rpath指定为`$ORIGIN`指示程序目录（需要加单引号，否则会被解释为变量ORIGIN的值）。

	```shell
	$ gcc main.o -Wl,-rpath,'$ORIGIN/../lib' -L../lib -lmydynamiclib -o app
	```

	或者makefile里通过`$$ORIGIN`指定（注意要用`$$`，只用一个`$`表示变量展开，`$$`表示转义成一个`$`）

	```
	...
	
	LDFLAGS = -Wl,-rpath,'$$ORIGIN/../lib' -lmydynamiclib
	LDPATH = -L../lib
	
	...
	
	app: main.o
		$(CC) -o $@ $^ $(LDFLAGS) $(LDPATH)
	
	```

#### 参考资料:
《高级C/C++编译技术》: 7.3章节
