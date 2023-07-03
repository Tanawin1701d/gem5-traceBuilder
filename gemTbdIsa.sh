time build/TRACEBUILDER/gem5.opt \
 --debug-flags=TBDDecode \
 --stats-file=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/tbdIsa/black/gemReal.txt \
 --json-config=/media/tanawin/tanawin1701e/Project/gem5base/gem5/m5out/tbdIsa/black/gemReal.json \
 configs/example/se_tbd.py \
 --tbdfile=/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/TbOutput/blackscholes/DynTbdIsa \
 --mem-size=8192MB \
 --cpu-type=DerivO3CPU \
 --l1d_size=32kB \
 --l1i_size=32kB \
 -n 1 \
 --caches