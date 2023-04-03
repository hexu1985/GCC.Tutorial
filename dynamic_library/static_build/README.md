### 静态编译

静态编译是指可执行文件不包含任何动态链接依赖。所有可执行文件需要的外部库都被静态链接到程序中。
因此，最终编译得到的二进制文件是完全可移植的，它不需要任何系统共享库（甚至也不需要libc）作为依赖就可以运行。

静态编译通过用-static链接器标识构建。

我们使用一个"Hello World"示例对比，可以发现。

Hello World示例代码
```c
#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("Hello, world\n");
    return 0;
}
```

分别指定和不指定-static链接器标识构建。
```
gcc main.cpp -o regularBuild
gcc -static main.cpp -o staticBuild
```

比较两个可执行文件的差异:

ls一下, 文件大小相差100倍:

```
$ ls -l
总用量 852
-rwxrwxr-x 1 hexu hexu     65 2月   9 14:33 build.sh
-rwxrwxr-x 1 hexu hexu     28 2月   9 14:34 clean.sh
-rw-rw-r-- 1 hexu hexu    101 2月   9 14:32 main.cpp
-rwxrwxr-x 1 hexu hexu   8304 2月   9 14:33 regularBuild
-rwxrwxr-x 1 hexu hexu 845120 2月   9 14:34 staticBuild
```

readelf -d看一下动态库依赖情况：

```
$ readelf -d regularBuild

Dynamic section at offset 0xdc8 contains 27 entries:
  标记        类型                         名称/值
 0x0000000000000001 (NEEDED)             共享库：[libc.so.6]
 0x000000000000000c (INIT)               0x4e8
 0x000000000000000d (FINI)               0x6d4
 0x0000000000000019 (INIT_ARRAY)         0x200db8
 0x000000000000001b (INIT_ARRAYSZ)       8 (bytes)
 0x000000000000001a (FINI_ARRAY)         0x200dc0
 0x000000000000001c (FINI_ARRAYSZ)       8 (bytes)
 0x000000006ffffef5 (GNU_HASH)           0x298
 0x0000000000000005 (STRTAB)             0x360
 0x0000000000000006 (SYMTAB)             0x2b8
 0x000000000000000a (STRSZ)              130 (bytes)
 0x000000000000000b (SYMENT)             24 (bytes)
 0x0000000000000015 (DEBUG)              0x0
 0x0000000000000003 (PLTGOT)             0x200fb8
 0x0000000000000002 (PLTRELSZ)           24 (bytes)
 0x0000000000000014 (PLTREL)             RELA
 0x0000000000000017 (JMPREL)             0x4d0
 0x0000000000000007 (RELA)               0x410
 0x0000000000000008 (RELASZ)             192 (bytes)
 0x0000000000000009 (RELAENT)            24 (bytes)
 0x000000000000001e (FLAGS)              BIND_NOW
 0x000000006ffffffb (FLAGS_1)            标志： NOW PIE
 0x000000006ffffffe (VERNEED)            0x3f0
 0x000000006fffffff (VERNEEDNUM)         1
 0x000000006ffffff0 (VERSYM)             0x3e2
 0x000000006ffffff9 (RELACOUNT)          3
 0x0000000000000000 (NULL)               0x0

$ readelf -d staticBuild 

There is no dynamic section in this file.
```
-static链接器标识构建的可执行程序的确不依赖任何动态库。

#### 参考资料:
《高级C/C++编译技术》: 3.3.2章节

