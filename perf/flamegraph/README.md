perf record -F 99 -p 13204 -g sleep 30
perf report -n --stdio
perf script | ./stackcollapse-perf.pl > out.perf-folded && ./flamegraph.pl out.perf-folded > perf.svg

第一行是抓数据。sleep 30，采样时间为30s。

第二行是简单解析数据（可以不用）。

第三行是把第一行抓的数据生成一个能在浏览器中看的火焰图。
[https://github.com/brendangregg/FlameGraph](https://github.com/brendangregg/FlameGraph) 第三行用的脚本可以在这里下载
