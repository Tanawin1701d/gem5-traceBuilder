


#ifndef ARCH_TRACEBUILDER_INSTRSIMPLE__HH
#define ARCH_TRACEBUILDER_INSTRSIMPLE__HH

#include "cpu/static_inst.hh"
#include "base/types.hh"
#include "enums/OpClass.hh"
#include "proto/mach.pb.h"
#include "arch/traceBuilder/pcstate.hh"
#include "sim/faults.hh"

namespace gem5{

namespace TracebuilderISA{

class tbdMacroop : public StaticInst{
protected:
    ProtoMessage::InstrRecord instrMeta;
    

public:
    tbdMacroop(ProtoMessage::InstrRecord& instrRec);

    Fault execute(ExecContext* xc, Trace::InstRecord* traceData) const override;

    void advancePC(PCStateBase& pc_state) const override;

    std::string generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab)  const override
            {
                return "this is dummy traceBuilder";
            }
    StaticInstPtr
    fetchMicroop(MicroPC upc) const override;

};


class tbdMicroop : public StaticInst{
    protected:
    ProtoMessage::machRecord curmach;
    bool isFirst;
    bool isLast;
    RegId srcRegs[10];
    RegId desRegs[10];
    static const int startRawIdx_INT = 0; /** we need to convert to 0*/
    static const int amtRawIdx_INT  = 16;

    static const int startRawIdx_FLT = 100; /** we need to - 16*/
    static const int amtRawIdx_FLT   = 8;

    static const int startRawIdx_VEC = 200; /** vector register start index*/
    static const int tamtRawIdx_VEC  = 32;

    static const int startRawIdx_TEM = 300; /** we need t o -500*/

    static const int startRawIdx_UNK = 400; /** start of unknow register*/

    static const int dummyOpclass = 99; /** for gem5, we will fix to 0*/
    

    RegId buildTbdRegId(RegIndex rid);

    public:
    tbdMicroop(ProtoMessage::machRecord& _machRec, bool isFirstMicroop,
                                                   bool isLastMicroop);

    Fault execute(ExecContext* xc, Trace::InstRecord* traceData) const override;

    void advancePC(PCStateBase& pc_state) const override;

    std::string generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab)  const override
            {
                return "this is microop traceBuilder@ " + std::to_string(pc);
            }

};


class tbdSyscallMacroop : public StaticInst{

    public:
    tbdSyscallMacroop();

    Fault execute(ExecContext* xc, Trace::InstRecord* traceData) const override;

    void advancePC(PCStateBase& pc_state) const override;

    std::string generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab)  const override
            {
                return "this is microop for syscall traceBuilder@ " + std::to_string(pc);
            }
};

}
}

#endif