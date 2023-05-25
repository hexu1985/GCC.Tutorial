### 运行时动态链接

Linux下运行时动态链接是通过dlopen等接口完成的。

| 目的     | Linux接口 |
| -------- | --------- |
| 加载库   | dlopen()  |
| 查找符号 | dlsym()   |
| 卸载库   | dlclose() |
| 错误报告 | dlerror() |

Linux下运行时动态加载的步骤伪码：

```
1) 
handle = do_load_library("<library path>", optional_flags);
if(NULL == handle)
    report_error();

2) 
pFunction = (function_type)do_find_library_symbol(handle);
if(NULL == pFunction)
{
    report_error();
    unload_library();
    handle = NULL;
    return;
}

3)
pFunction(function arguments); // execute the function

4)
do_unload_library(handle);
    handle = NULL;
```

#### 参考资料:
《高级C/C++编译技术》: 6.3.2 运行时动态链接
