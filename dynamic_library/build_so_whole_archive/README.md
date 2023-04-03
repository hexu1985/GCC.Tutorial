### 导入完整归档的情况

中介动态库（The intermediary dynamic library）自身并不使用任何动态库的功能。
链接器通过--whole-archive链接器选项来提供这个功能。

default目录下是没加--whole-archive链接器选项的工程，最终app链接mydynamiclib库时会报undefined reference的错误
```
main.c:(.text+0x1c): undefined reference to `first_function'
main.c:(.text+0x29): undefined reference to `second_function'
main.c:(.text+0x36): undefined reference to `third_function'
main.c:(.text+0x43): undefined reference to `fourth_function'
collect2: error: ld returned 1 exit status
```

whole_archive目录下是通过--whole-archive和-no-whole-archive把静态库包含在内，达到把整个静态库包含在中介动态库中的目的。
```
$ gcc -fPIC <source files> -o <executable-output-file> \
        -Wl,--whole-archive -l<libraries-to-be-entirely-linked-in> \
        -Wl,--no-whole-archive -l<all-other-libraries>
```
```
gcc -shared mydynamiclibshell.o -o libmydynamiclib.so -Wl,--whole-archive libmystaticlib.a -Wl,-no-whole-archive
```

#### 参考资料:
《高级C/C++编译技术》: 4.3章节
