### 控制动态库符号的可见性

在Linux中所有动态链接器符号默认都是外部可见的。

gcc编译器提供了多种机制来设置链接器符号的可见性：

#### 方法1：（影响所有代码）

`-fvisibility compiler flag`

根据GCC手册页（<http://linux.die.net/man/1/gcc>），通过向编译器传递编译器选项`-fvisibility=hidden`就可以将所有的动态库符号置为对外不可见。

#### 方法2：（只影响单个符号）

`__attribute__ ((visibility("<default | hidden>")))`

通过在函数前面使用编译属性修饰，你可以指示链接器允许（默认行为）或者禁止（隐藏符号）对外提供该符号。

#### 方法3：（影响单个符号或者一组符号）

`#pragma GCC visibility [push | pop]`

该选项通常用在头文件中。比如：

```
#pragma visibility push(hidden)
void someprivatefunction_1(void);
void someprivatefunction_2(void);
...
void someprivatefunction_N(void);
#pragma visibility pop
```

你就可以将#pragma语句之间所有声明的函数设定成对外不可见的。


#### 参考资料:
《高级C/C++编译技术》: 6.2.3章节

