# GCC Tutorial

## Table of contents

### [生成可执行程序](build_stages)

- [预处理阶段](build_stages/preprocessing)
- [汇编阶段](build_stages/assembling)
- [输出目标文件阶段（以及反汇编）](build_stages/object_files_and_disassembling)
- [链接阶段](build_stages/linking)

### [静态库](static_library)

- [创建静态库](static_library/build_a)
- [静态库工具ar](static_library/manipulate_a)
- [将静态库转换成动态库](static_library/manipulate_a)

### [动态库](dynamic_library)

- [创建动态库](dynamic_library/build_so)
- [控制动态库符号的可见性](dynamic_library/export_symbol_visibility_control)
- [动态库完成链接需要满足的条件](dynamic_library/build_so_no_undefined)
- [通过rpath添加加载动态库文件搜索路径](dynamic_library/load_so_by_rpath)
- [通过runpath添加加载动态库文件搜索路径](dynamic_library/load_so_by_runpath)
- [运行时动态链接](dynamic_library/load_so_by_dlopen)
- [静态编译](dynamic_library/static_build)
- [导入完整归档的情况](dynamic_library/build_so_whole_archive)

### [Asan内存检测](address_sanitizer)

- [ASan简介](address_sanitizer/intro)
- [(heap) use after free 释放后使用](address_sanitizer/use_after_free)
- [heap buffer overflow 堆缓存访问溢出](address_sanitizer/heap_buffer_overflow)
- [stack buffer overflow 栈缓存访问溢出](address_sanitizer/stack_buffer_overflow)
- [global buffer overflow 全局缓冲访问溢出](address_sanitizer/global_buffer_overflow)
- [use after return 使用函数返回的局部变量引用](address_sanitizer/use_after_return)
- [use after scope](address_sanitizer/use_after_scope)
- [initializations order bugs 全局对象初始化顺序问题](address_sanitizer/initialization_order_bugs)
- [memory leaks 内存泄露](address_sanitizer/memory_leaks)




