### 构建动态库

1. 基于make脚本方式构建程序

```
$ make
```

2. 查看动态库导出符号

```
$ nm -D libdefaultvisibility.so
# or
$ readelf --dyn-syms libdefaultvisibility.so
# or
$ objdump -T libdefaultvisibility.so
```
