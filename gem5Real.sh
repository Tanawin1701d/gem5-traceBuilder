# build/X86/gem5.opt \
#                       configs/example/ruby_random_test.py  \
#                       --num-cpus=16 \
#                       --num-dirs=16  \
#                       --network=garnet \
#                       --topology=Mesh_XY \
#                       --mesh-rows=4

#scons build/X86/gem5.opt -j 9

# time build/X86/gem5.opt \
#  --stats-file=/media/tanawin/tanawin1701d/Project/Intern/InternGem5/m5out/fluidanimateRubyTester/sms1.txt \
#  --json-config=/media/tanawin/tanawin1701d/Project/Intern/InternGem5/m5out/fluidanimateRubyTester/sms1.json \
#  configs/learning_gem5/newBench.py \
#  --memAccessDebugStat=/media/tanawin/tanawin1701d/Project/Intern/InternGem5/m5out/fluidanimateRubyTester/sms1.txt \
#  --ruby \
#  --vcs-per-vnet=256 \
#  --topology=Mesh_XY \
#  --mesh-rows=4 \
#  --num-dirs=16  \
#  --network=simple \
#  --mem-size=8192MB \
#  --pasec \
#  --cpu-type=DerivO3CPU \
#  --l1d_size=1kB \
#  --l1i_size=16kB \
#  -n 16 \
#  --interQmemSched=STAGE_SCHED_Queue \


# time build/X86/gem5.opt \
#  --stats-file=/media/tanawin/tanawin1701d/Project/Intern/InternGem5/m5out/fluidanimateRubyTester/sms1.txt \
#  --json-config=/media/tanawin/tanawin1701d/Project/Intern/InternGem5/m5out/fluidanimateRubyTester/sms1.json \
#  configs/learning_gem5/newBench.py \
#  --memAccessDebugStat=/media/tanawin/tanawin1701d/Project/Intern/InternGem5/m5out/fluidanimateRubyTester/sms1.txt \
#  --ruby \
#  --vcs-per-vnet=256 \
#  --topology=Mesh_XY \
#  --mesh-rows=4 \
#  --num-dirs=16  \
#  --network=simple \
#  --mem-size=8192MB \
#  --pasec \
#  --cpu-type=DerivO3CPU \
#  --l1d_size=1kB \
#  --l1i_size=16kB \
#  -n 16 \
#  --interQmemSched=STAGE_SCHED_Queue

# time build/X86/gem5.opt \
#  --stats-file=/media/tanawin/tanawin1701d/Project/gem5base/gem5/m5out/fluid/fluidSerial.txt \
#  --json-config=/media/tanawin/tanawin1701d/Project/gem5base/gem5/m5out/fluid/fluidSerial.json \
#  configs/example/se.py \
#  --elastic-trace-en \
#  --inst-trace-file=fluidSerialInstr.proto.gz \
#  --data-trace-file=fluidSerialData.proto.gz \
#  --workloads=fluidanimate \
#  --mem-size=16GB \
#  --cpu-type=DerivO3CPU \
#  --caches \
#  --mem-type=SimpleMemory



# time build/X86/gem5.opt \
#  --stats-file=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/traceBuilder/fluidAnimateGemTrace/gemPsuedo.txt \
#  --json-config=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/traceBuilder/fluidAnimateGemTrace/gemPsuedo.json \
#  configs/example/se.py \
#  --elastic-trace-en \
#  --inst-trace-file=traceFluidInstr.proto.gz \
#  --data-trace-file=traceFluidData.proto.gz \
#  --workloads=fluidAnimate \
#  --mem-size=16GB \
#  --cpu-type=DerivO3CPU \
#  --caches \
#  --mem-type=SimpleMemory


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


time build/X86/gem5.opt \
 --stats-file=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/traceBuilder3/blackscholes/real/gemReal.txt \
 --json-config=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/traceBuilder3/blackscholes/real/gemReal.json \
 configs/example/se.py \
 --mem-size=8192MB \
 --workloads=blackscholes \
 --cpu-type=DerivO3CPU \
 --l1d_size=32kB \
 --l1i_size=32kB \
 -n 1 \
 --caches

# time build/X86/gem5.opt \
#  --stats-file=/media/tanawin/tanawin1701d/Project/Intern/InternGem5/m5out/fluidanimate_8core/frfcfs.txt \
#  --json-config=/media/tanawin/tanawin1701d/Project/Intern/InternGem5/m5out/fluidanimate_8core/frfcfs.json \
#  configs/learning_gem5/newBench.py \
#  --mem-size=3072MB \
#  --pasec \
#  --cpu-type=DerivO3CPU \
#  --l1d_size=1kB \
#  --l1i_size=16kB \
#  --caches \
#  -n 8 \
#  --memSched=frfcfs \
#  --l2cache

#  time build/X86/gem5.opt \
#  --stats-file=/media/tanawin/tanawin1701d/Project/Intern/InternGem5/m5out/fluidanimate_8core/fcfs.txt \
#  --json-config=/media/tanawin/tanawin1701d/Project/Intern/InternGem5/m5out/fluidanimate_8core/fcfs.json \
#  configs/learning_gem5/newBench.py \
#  --mem-size=3072MB \
#  --pasec \
#  --cpu-type=DerivO3CPU \
#  --l1d_size=1kB \
#  --l1i_size=16kB \
#  --caches \
#  -n 8 \
#  --memSched=fcfs \
#  --l2cache


