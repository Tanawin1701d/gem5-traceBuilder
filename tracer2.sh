#!/bin/bash
# echo "Waiting for 7 hours..."
# sleep 7h
time build/X86/gem5.opt \
--stats-file=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/traceBuilder3/fluidAnimate/tbd/mytbdOpt256.txt   \
--json-config=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/traceBuilder3/fluidAnimate/tbd/mytbdOpt256.json   \
/media/tanawin/tanawin1701e/Project/gem5base/gem5/configs/example/etrace_replay.py \
--inst-trace-file=/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/TbOutput/fluidanimate/testRunInstr256 \
--data-trace-file=/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/TbOutput/fluidanimate/testRunDyn256 \
--mem-size=8192MB \
--l1d_size=32kB \
--l1i_size=32kB \
--cpu-type=TraceCPU \
--caches 