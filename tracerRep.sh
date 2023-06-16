# build/X86/gem5.opt \
# --debug-flags=TraceCPUData \
# /media/tanawin/tanawin1701d/Project/gem5base/gem5/configs/example/etrace_replay.py \
# --inst-trace-file=/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/protoFile/instrBeta \
# --data-trace-file=/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/protoFile/dynamicData \
# --cpu-type=TraceCPU \
# --caches \
# --mem-size=24GB

# build/X86/gem5.opt \
# --stats-file=/media/tanawin/tanawin1701d/Project/gem5base/gem5/m5out/loop/loopTraceRob192.txt   \
# --json-config=/media/tanawin/tanawin1701d/Project/gem5base/gem5/m5out/loop/loopTraceRob192.json   \
# /media/tanawin/tanawin1701d/Project/gem5base/gem5/configs/example/etrace_replay.py \
# --inst-trace-file=/media/tanawin/tanawin1701d/Project/gem5base/gem5/m5out/system.cpu.traceListener.loopInstTrace.proto.gz \
# --data-trace-file=/media/tanawin/tanawin1701d/Project/gem5base/gem5/m5out/system.cpu.traceListener.loopDataTrace.proto.gz \
# --cpu-type=TraceCPU \
# --caches \
# --mem-size=16GB \
# --mem-type=SimpleMemory \
# --test-tracer

build/X86/gem5.opt \
--stats-file=/media/tanawin/tanawin1701d/Project/gem5base/gem5/m5out/traceFluid/pintraceFluidRob192.txt   \
--json-config=/media/tanawin/tanawin1701d/Project/gem5base/gem5/m5out/traceFluid/pintraceFluidRob192.json   \
/media/tanawin/tanawin1701d/Project/gem5base/gem5/configs/example/etrace_replay.py \
--inst-trace-file=/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/generatedFile/dummyencoded \
--data-trace-file=/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/generatedFile/FluidDataSerial \
--cpu-type=TraceCPU \
--caches \
--mem-size=16GB \
--mem-type=SimpleMemory \
--test-tracer
