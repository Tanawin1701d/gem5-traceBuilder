
#ifndef __ARCH_TRACEBUILDER_DECODER_HH__
#define __ARCH_TRACEBUILDER_DECODER_HH__


#include<cassert>
#include<unordered_map>
#include<vector>

#include "arch/generic/decoder.hh"
#include "base/logging.hh"
#include "base/trace.hh"
#include "base/types.hh"
#include "cpu/decode_cache.hh"
#include "params/traceBuilderDecoder.hh"


namespace gem5{
    namespace TracebuilderISA{

        class Decoder : public InstDecoder{
        
        protected:
        int   consumed;
        const int maxConsumed = 2;
        using MachInstr = uint64_t;
        using Params    = traceBuilderDecoderParams;
        MachInstr fetchChunk;

        public:
            Decoder(const Params& p) : InstDecoder(p, &fetchChunk), consumed(0){

            }

            void moreBytes(const PCStateBase& pc, Addr fetchPc);

            StaticInstPtr decode(PCStateBase &pc);

        };

    }
}


#endif