### 在Linux中创建静态库

在Linux中打包工具被简单地称作ar，我们可以从GCC工具链中找到这个工具。

下面所展示的一个简单例子演示了根据两个源代码文件来创建静态库的过程：
```shell
$ gcc -c first.c second.c
$ ar rcs libstaticlib.a first.o second.o 
```


#### 参考资料:
《高级C/C++编译技术》: 5.1章节
