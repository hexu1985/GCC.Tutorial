### 构建动态库和可执行程序

1. 基于gcc命令行方式构建程序
```
$ cd ${CURRENT_DIR}/lib
$ ./build_static_lib.sh
$ cd ${CURRENT_DIR}/app
$ ./build_app.sh
```
或者
```
$ ./build.sh
```

2. 基于make脚本方式构建程序
```
$ cd ${CURRENT_DIR}/lib
$ make
$ cd ${CURRENT_DIR}/app
$ make
```
或者
```
$ make
```

3. 基于cmake脚本方式构建程序
```
$ cmake -H. -Bbuild     # build为创建的工程目录
$ cmake --build build   # --build是cmake选项，--build后面跟的命令行参数是工程目录
```
或者
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

由于没加--whole-archive链接器选项的工程，最终app链接mydynamiclib库时会报undefined reference的错误
```
main.c:(.text+0x1c): undefined reference to `first_function'
main.c:(.text+0x29): undefined reference to `second_function'
main.c:(.text+0x36): undefined reference to `third_function'
main.c:(.text+0x43): undefined reference to `fourth_function'
collect2: error: ld returned 1 exit status
```

