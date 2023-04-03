
rm -f ./perf.data
nohup ./sched 20000 200 &
sched_pid=$!
perf record -F 99 -p ${sched_pid} -g sleep 15 
#perf report -n --stdio
perf script | ./stackcollapse-perf.pl > out.perf-folded && ./flamegraph.pl out.perf-folded > perf.svg
