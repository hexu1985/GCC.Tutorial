### 在Linux中通过runpath添加运行时动态库文件搜索路径

1. 在Linux中，我们可以通过runpath设置动态库运行时搜索路径，为了传递-R或者-rpath链接器选项，需要使用额外的--enable-new-dtags链接器选项。此外，根据惯例，凡是间接调用链接器时（也就是直接调用gcc或者g++），我们需要在链接器参数前追加“`-Wl,`”前缀（也就是“减号Wl逗号”）。
	```shell
	$ gcc -Wl,-R /home/milan/projects/ -Wl,--enable-new-dtags -lmilanlibrary  
	      ^   ^        ^                             ^  
	      |   |        |                             |  
	      |   |        actual rpath value            both rpath and runpath set  
	      |   |                                      to the same string value  
	      |   run path linker flag             
	      |                                     
	      -Wl, prefix required when invoking linker  
	      indirectly, through gcc instead of  
	      directly invoking ld  
	```

2. rpath信息会存在二进制文件的DT_RUNPATH字段中，查看二进制文件DT_RUNPATH值的方法是查看二进制文件的ELF头（比如执行`readelf -d`或者`objdump -x`命令）

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

3. 可执行文件中DT_RUNPATH中如果存储了相对路径，装载器并不是将其解释成相对于可执行程序的路径，而是相对于装载器（即应用程序）启动路径（当前工作路径PWD）的相对路径。$ORIGIN是一个特殊的变量，指示实际的可执行文件名。它在运行时解析到可执行文件的位置，在设置RUNPATH时非常有用。

	通过将runpath指定为`$ORIGIN`指示程序目录（需要加单引号，否则会被解释为变量ORIGIN的值）。
	```shell
	$ gcc main.o -Wl,-rpath,'$ORIGIN/../lib' -L../lib -lmydynamiclib -o app
	```
	
	或者makefile里通过`$$ORIGIN`指定（注意要用`$$`，只用一个`$`表示变量展开，`$$`表示转义成一个`$`）
	```
	...
	
	LDFLAGS = -Wl,-rpath,'$$ORIGIN/../lib' -Wl,--enable-new-dtags -lmydynamiclib
	LDPATH = -L../lib
	
	...
	
	app: main.o
	    $(CC) -o $@ $^ $(LDFLAGS) $(LDPATH)
	
	```

4. 在ubuntu18.04上，gcc version: 7.5.0上，加不加`-Wl,--enable-new-dtags`的效果是一样的。

5. 是否指定RUNPATH字段，会影响动态库运行时搜素路径的优先级：
    - 如果指定了RUNPATH字段（即DT_RUNPATH字段非空）：
        + LD_LIBRARY_PATH
        + runpath（RUNPATH字段）
        + ld.so.cache
        + 默认库路径（/lib和/usr/lib）
    - 如果没有指定RUNPATH字段（即DT_RUNPATH字段为空字符串）：
        + 被加载库的RPATH，然后是二进制文件的RPATH，直到可执行文件或者动态库将这些库全部加载完毕为止。
        + LD_LIBRARY_PATH
        + ld.so.cache
        + 默认库路径（/lib和/usr/lib）

	```shell
	$ ldd app 
		linux-vdso.so.1 (0x00007ffde2678000)
		libmydynamiclib.so => /home/mackhe/git/C.And.Cpp.Compiling.Tutorial/dynamic_lib/recipe-03/c/app/./../lib/libmydynamiclib.so (0x00007f662240a000)
		libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f6622019000)
		/lib64/ld-linux-x86-64.so.2 (0x00007f662280e000)
	
	$ cp ../lib/libmydynamiclib.so .
	$ export LD_LIBRARY_PATH=.
	$ ldd app 
		linux-vdso.so.1 (0x00007ffe3859d000)
		libmydynamiclib.so => ./libmydynamiclib.so (0x00007f4913d64000)
		libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f4913973000)
		/lib64/ld-linux-x86-64.so.2 (0x00007f4914168000)
	```

#### 参考资料:
《高级C/C++编译技术》: 7.3章节
