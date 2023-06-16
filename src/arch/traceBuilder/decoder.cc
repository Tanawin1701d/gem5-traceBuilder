#include "arch/traceBuilder/decoder.hh"
#include "arch/traceBuilder/instrSimple.hh"
#include "pcstate.hh"


namespace gem5{
    namespace TracebuilderISA{


    void Decoder::moreBytes(const PCStateBase& pc, Addr fetchPc){
        outOfBytes = true;
        instDone   = true;
    }


    StaticInstPtr Decoder::decode(PCStateBase& pc){
        consumed++;
        if (consumed == 2){
            consumed = 0;
            outOfBytes = true;
            instDone = true;
        }else{
            outOfBytes = false;
            instDone   = true;
        }
        
        //////// to do update pc state
        auto& pcState = pc.as<PCState>();
        return StaticInstPtr( (StaticInst*)(new InstrSimple()));
    }

    }
}
