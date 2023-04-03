### 在Linux中创建动态库

通常来说，创建动态库的过程至少需要下面两个选项：
- -fPIC编译器选项。
- -shared连接器选项。

下面的简单示例演示了从两个源代码文件创建动态库的过程：
```shell
$ gcc -fPIC -c first.c second.c
$ gcc -shared first.o second.o -o libdynamiclib.so
```

### Linux构建过程中库文件定位规则

在Linux中使用-L和-l选项来指定构建过程中库文件的路径。这两个选项的正确使用方法是：
- 将完整的库文件路径分成两个部分：目录路径和库文件名。
- 将目录路径添加到-L链接器选项后面，并传递给链接器。
- 将库文件名（链接器名称）添加到-l参数后面，并传递给链接器。

比如，使用命令行来对main.o文件进行编译，并链接../sharedLib目录中的动态库libworkingdemo.so，
然后生成示例程序，命令如下所示：
```shell
$ gcc main.o -L../sharedLib -lworkingdemo -o demo
                         ^              ^
                         |              |
                library folder path    library name only
                                       (not the full library filename !)
```

在使用gcc命令行一次性完成编译链接两个过程时，应该在链接器选项之前添加-Wl选项，如下所示：
```shell
$ gcc -Wall -fPIC main.cpp -Wl,-L../sharedLib -Wl,-lworkingdemo -o demo
```

#### 参考资料:
《高级C/C++编译技术》: 6.1章节，7.2章节
