
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
#include "sim/process.hh"
#include "base/loader/object_file.hh"
#include "proto/protoio.hh"
#include "proto/mach.pb.h"

#include "debug/TBDDecode.hh"


namespace gem5{
    namespace TracebuilderISA{

        class Decoder : public InstDecoder{

        private:
        ProtoInputStream* inputStream = nullptr;

        /** variable that need to update*/
        ProtoMessage::InstrRecord nextInstr;
        Addr consumedByte = 0;
        Addr neededByte   = 0;
        bool nextStop     = false; /** next is last microop*/

        uint64_t generated = 0; /// used for track how much generated
        
        protected:
        
        using MachInstr = uint64_t;
        using Params    = traceBuilderDecoderParams;
        MachInstr fetchChunk;

        public:
            /** please denote that this type of decoder must be declared when object file is finished built*/
            Decoder(const Params& p);

            void moreBytes(const PCStateBase& pc, Addr fetchPc);
            /** we need to generate */
            StaticInstPtr decode(PCStateBase &pc);

        };

    }
}


#endif