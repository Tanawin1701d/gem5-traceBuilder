# build/X86/gem5.opt \
# --debug-flags=TraceCPUData \
# /media/tanawin/tanawin1701d/Project/gem5base/gem5/configs/example/etrace_replay.py \
# --inst-trace-file=/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/protoFile/instrBeta \
# --data-trace-file=/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/protoFile/dynamicData \
# --cpu-type=TraceCPU \
# --caches \
# --mem-size=24GB

time build/X86/gem5.opt \
--stats-file=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/traceBuilder3/blackscholes/tbd/mytbd256.txt   \
--json-config=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/traceBuilder3/blackscholes/tbd/mytbd256.json   \
/media/tanawin/tanawin1701e/Project/gem5base/gem5/configs/example/etrace_replay.py \
--inst-trace-file=/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/TbOutput/blackscholes/testRunInstr256 \
--data-trace-file=/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/TbOutput/blackscholes/testRunDyn256 \
--mem-size=8192MB \
--l1d_size=32kB \
--l1i_size=32kB \
--cpu-type=TraceCPU \
--caches \



#shutdown