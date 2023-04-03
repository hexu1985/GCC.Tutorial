
- 编译示例程序

```
$ make
```

- 通过perf直接启动方式, 采样程序

```
$ perf record -F 99 -g ./sched 5000 100 
$ perf report -n --stdio
$ perf script -i perf.data &> perf.unfold
$ ./stackcollapse-perf.pl perf.unfold > out.perf-folded 
$ ./flamegraph.pl out.perf-folded > perf.svg
```

- 通过指定pid方式, 采样程序

```
$ nohup ./sched 50000 200 &
$ sched_pid=$!
$ perf record -F 99 -p ${sched_pid} -g sleep 15 
$ perf report -n --stdio
$ perf script | ./stackcollapse-perf.pl | ./flamegraph.pl out.perf-folded > perf.svg
```

open perf.svg by chrome etc
