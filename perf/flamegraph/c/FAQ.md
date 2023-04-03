
- 执行`perf record -F 99 -g ./sched 5000 100`  报如下错误:
```
WARNING: perf.back not found for kernel 5.4.0-121

  You may need to install the following packages for this specific kernel:
    linux-tools-5.4.0-121-generic
    linux-cloud-tools-5.4.0-121-generic

  You may also want to install one of the following packages to keep up to date:
    linux-tools-generic
    linux-cloud-tools-generic
```

需要安装`linux-tools-generic`
```
$ sudo apt linux-tools-5.4.0-121-generic    # 根据ubuntu不同版本, 可能tools的版本也需要调整
$ export PATH=/usr/lib/linux-tools/5.4.0-120-generic:$PATH
$ perf --version
```

- 执行`perf record -F 99 -g ./sched 5000 100`  报如下错误:
```
perf_event_open(..., PERF_FLAG_FD_CLOEXEC) failed with unexpected error 13 (权限不够)
perf_event_open(..., 0) failed unexpectedly with error 13 (权限不够)
Error:
You may not have permission to collect stats.

Consider tweaking /proc/sys/kernel/perf_event_paranoid,
which controls use of the performance events system by
unprivileged users (without CAP_SYS_ADMIN).

The current value is 3:

  -1: Allow use of (almost) all events by all users
      Ignore mlock limit after perf_event_mlock_kb without CAP_IPC_LOCK
>= 0: Disallow ftrace function tracepoint by users without CAP_SYS_ADMIN
      Disallow raw tracepoint access by users without CAP_SYS_ADMIN
>= 1: Disallow CPU event access by users without CAP_SYS_ADMIN
>= 2: Disallow kernel profiling by users without CAP_SYS_ADMIN

To make this setting permanent, edit /etc/sysctl.conf too, e.g.:

        kernel.perf_event_paranoid = -1
```
执行如下命令:
```
$ sudo sh -c " echo -1 > /proc/sys/kernel/perf_event_paranoid"
```

- 执行`perf record -F 99 -g ./sched 5000 100`  报如下错误:
```
WARNING: Kernel address maps (/proc/{kallsyms,modules}) are restricted,
check /proc/sys/kernel/kptr_restrict and /proc/sys/kernel/perf_event_paranoid.

Samples in kernel functions may not be resolved if a suitable vmlinux
file is not found in the buildid cache or in the vmlinux path.

Samples in kernel modules won't be resolved at all.

If some relocation was applied (e.g. kexec) symbols may be misresolved
even with a suitable vmlinux or kallsyms file.

Couldn't record kernel reference relocation symbol
Symbol resolution may be skewed if relocation was used (e.g. kexec).
Check /proc/kallsyms permission or run as root.
```
执行如下命令:
```
$ sudo sh -c " echo 0 > /proc/sys/kernel/kptr_restrict"
```
