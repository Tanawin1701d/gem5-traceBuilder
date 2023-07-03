#include "arch/traceBuilder/decoder.hh"
#include "arch/traceBuilder/instrSimple.hh"
#include "pcstate.hh"



namespace gem5{
    namespace TracebuilderISA{


    Decoder::Decoder(const Params& p):  
        InstDecoder(p, &fetchChunk){

            inputStream = new ProtoInputStream(p.uopStreamName);
            /** read header*/
            ProtoMessage::headerRecord header;
            inputStream->read(header);
            assert(header.obj_id() == "gem5");
            /** read first instr*/
            inputStream->read(nextInstr);
            consumedByte = 0;
            neededByte   = nextInstr.v_instrsize();
     }


    void Decoder::moreBytes(const PCStateBase& pc, Addr fetchPc){
        
        /** add the consumed byte*/
        consumedByte += sizeof(MachInstr);

        if (consumedByte >= neededByte){
            instDone = true;
            outOfBytes = false;
        }else{
            instDone = false;
            outOfBytes = true;
        }


    }


    StaticInstPtr Decoder::decode(PCStateBase& pc){
        /** select new instruction to be next*/
        ProtoMessage::InstrRecord futureInstr;
        
        bool shouldNextRoundStop = false;
        auto& cur_pc = pc.as<PCState>();

        if ( !inputStream->read(futureInstr) ){
            shouldNextRoundStop = true;
            if (nextStop){
                /* nothing to do*/
                cur_pc.set(cur_pc.pc());
                cur_pc.setNPC(cur_pc.npc());
                cur_pc.size(cur_pc.size());
            }else{
                /** fo iy */
                cur_pc.set(nextInstr.v_instraddr());
                cur_pc.size(nextInstr.v_instrsize());
                cur_pc.setNPC(cur_pc.pc() + cur_pc.size());
            }
        }else{
            /** there is future instruction*/
            Addr futureAddr = futureInstr.v_instraddr();
            /** set pc current and future use*/
            cur_pc.set(nextInstr.v_instraddr());
            cur_pc.setNPC(futureAddr);
            cur_pc.size(nextInstr.v_instrsize());
        }
        
        
        
        /** when decode we need to update variable*/
        if (cur_pc.branching()){
            consumedByte = 0;
            instDone = false;
            outOfBytes = true;

        }else{
            consumedByte = neededByte - consumedByte;
            instDone     = consumedByte >= futureInstr.v_instrsize();
            outOfBytes   = !instDone;
        }

        StaticInstPtr retMop;

        if (nextStop){
            retMop = StaticInstPtr(new tbdSyscallMacroop());
        }else{
            retMop = StaticInstPtr(new tbdMacroop(nextInstr));
        }

        nextInstr = futureInstr;
        neededByte = futureInstr.v_instrsize();

        nextStop = shouldNextRoundStop;

        generated++;
        if (generated % 1000000 == 0){
            DPRINTF(TBDDecode, "---->generated %llu instrNum\n", nextInstr.instr_num());
            DPRINTF(TBDDecode, "generated %llu objected\n", generated);
        }

        return retMop;


    }

    }
}
