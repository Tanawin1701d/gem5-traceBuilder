# time build/X86/gem5.opt \
#  --stats-file=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/traceBuilder/fluidAnimateGemTrace/gemPsuedo.txt \
#  --json-config=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/traceBuilder/fluidAnimateGemTrace/gemPsuedo.json \
#  configs/example/se.py \
#  --elastic-trace-en \
#  --inst-trace-file=traceFluidInstr.proto.gz \
#  --data-trace-file=traceFluidData.proto.gz \
#  --mem-size=8192MB \
#  --mem-type=SimpleMemory \
#  --workloads=fluidanimate \
#  --cpu-type=DerivO3CPU \
#  --l1d_size=16kB \
#  --l1i_size=2kB \
#  -n 1 \
#  --caches


# time build/X86/gem5.opt \
# --stats-file=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/traceBuilder/fluidAnimateGemTrace/gemPsuedoReplay.txt   \
# --json-config=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/traceBuilder/fluidAnimateGemTrace/gemPsuedoReplay.json   \
# /media/tanawin/tanawin1701e/Project/gem5base/gem5/configs/example/etrace_replay.py \
# --inst-trace-file="/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/system.cpu.traceListener.traceFluidInstr.proto.gz" \
# --data-trace-file="/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/system.cpu.traceListener.traceFluidData.proto.gz" \
# --mem-size=8192MB \
# --l1d_size=16kB \
# --l1i_size=2kB \
# --cpu-type=TraceCPU \
# --caches \



####### black holes


time build/X86/gem5.opt \
 --stats-file=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/traceBuilder3/blackscholes/selfTrace/gemPsuedo.txt \
 --json-config=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/traceBuilder3/blackscholes/selfTrace/gemPsuedo.json \
 configs/example/se.py \
 --elastic-trace-en \
 --inst-trace-file=medium_traceBlackHolesInstr.proto.gz \
 --data-trace-file=medium_traceBlackHolesData.proto.gz \
 --mem-size=8192MB \
 --mem-type=SimpleMemory \
 --workloads=blackscholes \
 --cpu-type=DerivO3CPU \
 --l1d_size=32kB \
 --l1i_size=32kB \
 -n 1 \
 --caches



time build/X86/gem5.opt \
--stats-file=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/traceBuilder3/blackscholes/selfTrace/gemPsuedoReplay.txt  \
--json-config=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/traceBuilder3/blackscholes/selfTrace/gemPsuedoReplay.json   \
/media/tanawin/tanawin1701e/Project/gem5base/gem5/configs/example/etrace_replay.py \
--inst-trace-file="/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/system.cpu.traceListener.medium_traceBlackHolesInstr.proto.gz" \
--data-trace-file="/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/system.cpu.traceListener.medium_traceBlackHolesData.proto.gz" \
--mem-size=8192MB \
--l1d_size=32kB \
--l1i_size=32kB \
--cpu-type=TraceCPU \
--caches \