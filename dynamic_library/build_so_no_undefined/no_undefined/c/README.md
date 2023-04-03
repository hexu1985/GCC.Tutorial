### 构建动态库和可执行程序

1. 基于gcc命令行方式构建程序
```
$ export CURRENT_DIR=$(PWD)
$ cd ${CURRENT_DIR}/lib
$ ./build_dynamic_lib.sh
$ cd ${CURRENT_DIR}/app
$ ./build_app.sh
```
或者
```
$ ./build.sh
```

2. 基于make脚本方式构建程序
```
$ export CURRENT_DIR=$(PWD)
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

由于加了--no-undefined链接器选项，构建动态库mydynamiclib库时就会报undefined reference的错误。

```
make --directory=lib 
make[1]: Entering directory '/home/hexu/git/C.And.Cpp.Compiling.Tutorial/dynamic_library/build_so_no_undefined/no_undefined/c/lib'
gcc -shared -o libmydynamiclib.so first.o fourth.o second.o third.o  -Wl,--no-undefined
first.o: In function `first_function':
/home/hexu/git/C.And.Cpp.Compiling.Tutorial/dynamic_library/build_so_no_undefined/no_undefined/c/lib/first.c:7: undefined reference to `no_such_function'
collect2: error: ld returned 1 exit status
Makefile:26: recipe for target 'libmydynamiclib.so' failed
make[1]: *** [libmydynamiclib.so] Error 1
make[1]: Leaving directory '/home/hexu/git/C.And.Cpp.Compiling.Tutorial/dynamic_library/build_so_no_undefined/no_undefined/c/lib'
Makefile:9: recipe for target 'lib' failed
make: *** [lib] Error 2
```
