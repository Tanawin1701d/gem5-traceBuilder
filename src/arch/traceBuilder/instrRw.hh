#ifndef __ARCH_TRACEBUILDER_INSTRRW_HH__
#define __ARCH_TRACEBUILDER_INSTRRW_HH__

#include "arch/traceBuilder/instrSimple.hh"
#include "base/types.hh"
#include "enums/OpClass.hh"
#include "proto/mach.pb.h"
#include "arch/traceBuilder/pcstate.hh"

namespace gem5{
    namespace TracebuilderISA{

        class tbdReadMicroop : public tbdMicroop{
        public:
            tbdReadMicroop(ProtoMessage::machRecord& _machRec, bool isFirstMicroop,bool isLastMicroop);
            Fault initiateAcc(ExecContext *xc, Trace::InstRecord *traceData) const override;
            Fault completeAcc(Packet *pkt, ExecContext *xc, Trace::InstRecord *trace_data) const override;
        };

        class tbdWriteMicroop : public tbdMicroop{
        public:
            tbdWriteMicroop(ProtoMessage::machRecord& _machRec, bool isFirstMicroop,bool isLastMicroop);
            Fault initiateAcc(ExecContext *xc, Trace::InstRecord *traceData) const override;
            Fault completeAcc(Packet *pkt, ExecContext *xc, Trace::InstRecord *trace_data) const override;
            
        };



    }
}


#endif