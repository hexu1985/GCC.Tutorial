### 在Linux中动态库完成链接需要满足的条件

动态库的创建过程是一个完整的构建过程，因为其涉及了编译和链接两个阶段。通常来说，
当链接器解析了所有引用后，链接阶段就完成了，而且无论其目标是可执行文件还是动态库，
都应该遵守这个判断标准。

而在Linux中，在构建动态库时的默认行为同这条规则略有出入，因为即使链接器没有完成
所有符号的解析工作，动态库的链接过程也会完成（并创建二进制文件）。

之所以允许这种情况发生，是因为链接器会隐式假设在链接阶段中缺失的符号，最终都能在
进程内存映射中找到，很有可能在运行时加载某些动态库后就能找到缺失符号的实现。
那些需要却未在动态库中提供的符号会被标记成undefined（“U”）。

**--no-undefined链接器选项**

如果将--no-undefined选项传递给gcc链接器，在构建时一旦有符号无法解析，就会导致构建失败。

需要注意的是，当通过gcc调用链接器时，必须使用-Wl,前缀来处理链接器选项，比如：

```
$ gcc -fPIC <source files> -l <libraries> -Wl,--no-undefined -o <shlib output filename>
```


#### 参考资料:
《高级C/C++编译技术》: 6.2.4 完成链接需要满足的条件
