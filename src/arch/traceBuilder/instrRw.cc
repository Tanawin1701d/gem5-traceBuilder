#include "arch/traceBuilder/instrRw.hh"
#include "cpu/exec_context.hh"
#include "mem/request.hh"




namespace gem5::TracebuilderISA{



    /** read microop*/

    tbdReadMicroop::tbdReadMicroop(ProtoMessage::machRecord& _machRec, bool isFirstMicroop,bool isLastMicroop)
    :tbdMicroop( _machRec, isFirstMicroop,isLastMicroop)
    {
        setFlag(IsLoad);
    }

    Fault
    tbdReadMicroop::initiateAcc(ExecContext *xc, Trace::InstRecord *traceData) const{
       Addr EA      = curmach.p_effaddr();
       int dataSize = curmach.p_effsize();
       Request::Flags flags;
       const std::vector<bool> byte_enable( dataSize, true);
       xc->initiateMemRead(EA, dataSize, flags, byte_enable);

       return NoFault;

    }

    Fault
    tbdReadMicroop::completeAcc(Packet *pkt, ExecContext *xc, Trace::InstRecord *trace_data) const{
        return  NoFault;
    }

    /** write microop*/

    tbdWriteMicroop::tbdWriteMicroop(ProtoMessage::machRecord& _machRec, bool isFirstMicroop,bool isLastMicroop)
    :tbdMicroop( _machRec, isFirstMicroop,isLastMicroop)
    {
        setFlag(IsStore);
    }

    Fault
    tbdWriteMicroop::initiateAcc(ExecContext *xc, Trace::InstRecord *traceData) const{
       Addr EA      = curmach.p_effaddr();
       int dataSize = curmach.p_effsize();
       Request::Flags flags;
       const std::vector<bool> byte_enable( dataSize, true);
       uint8_t* psuedodata = new uint8_t[dataSize];
       xc->writeMem(psuedodata, dataSize, EA, flags, NULL, byte_enable);

       return NoFault;

    }

    Fault
    tbdWriteMicroop::completeAcc(Packet *pkt, ExecContext *xc, Trace::InstRecord *trace_data) const{
        return  NoFault;
    }

}