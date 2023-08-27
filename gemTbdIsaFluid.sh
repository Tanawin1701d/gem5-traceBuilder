time build/TRACEBUILDER/gem5.opt \
 --debug-flags=TBDDecode \
 --stats-file=/tanawin1701e/Project/gem5base/gem5/m5out/tbdIsa/fluid/pyNative3.txt \
 --json-config=/tanawin1701e/Project/gem5base/gem5/m5out/tbdIsa/fluid/pyNative3.json \
 configs/example/se_tbd.py \
 --commitstat=/tanawin1701e/Project/gem5base/gem5/m5out/tbdIsa/fluid/DynTbdIsaStat3.txt \
 --tbdfile=/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/TbOutput/fluidanimate/DynTbdIsa3 \
 --mem-size=8192MB \
 --cpu-type=DerivO3CPU \
 --l1d_size=32kB \
 --l1i_size=32kB \
 -n 1 \
 --caches