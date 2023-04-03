
rm -f ./perf.data
perf record -F 99 -g ./sched 5000 100 
#perf report -n --stdio
perf script | ./stackcollapse-perf.pl | ./flamegraph.pl > perf.svg
