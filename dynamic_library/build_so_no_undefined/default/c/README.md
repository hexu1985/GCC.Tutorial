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

由于没加--no-undefined链接器选项，最终app链接mydynamiclib库时会报undefined reference的错误，
但是构建动态库mydynamiclib库却是成功的。

```
make --directory=lib 
make[1]: Entering directory '/home/hexu/git/C.And.Cpp.Compiling.Tutorial/dynamic_library/build_so_no_undefined/default/c/lib'
DYNAMICLIB = libmydynamiclib.so
make[1]: Leaving directory '/home/hexu/git/C.And.Cpp.Compiling.Tutorial/dynamic_library/build_so_no_undefined/default/c/lib'
make --directory=app 
make[1]: Entering directory '/home/hexu/git/C.And.Cpp.Compiling.Tutorial/dynamic_library/build_so_no_undefined/default/c/app'
gcc -o app main.o -lmydynamiclib -L../lib
../lib/libmydynamiclib.so: undefined reference to `no_such_function'
collect2: error: ld returned 1 exit status
Makefile:24: recipe for target 'app' failed
make[1]: *** [app] Error 1
make[1]: Leaving directory '/home/hexu/git/C.And.Cpp.Compiling.Tutorial/dynamic_library/build_so_no_undefined/default/c/app'
Makefile:9: recipe for target 'app' failed
make: *** [app] Error 2
```
