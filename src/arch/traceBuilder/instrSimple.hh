


#ifndef ARCH_TRACEBUILDER_INSTRSIMPLE__HH
#define ARCH_TRACEBUILDER_INSTRSIMPLE__HH

#include "cpu/static_inst.hh"
#include "base/types.hh"
#include "enums/OpClass.hh"

namespace gem5{

class InstrSimple : public StaticInst{

public:
    InstrSimple(): StaticInst("simpleTraceBuilder", enums::IntAlu){};

    Fault execute(ExecContext* xc, Trace::InstRecord* traceData) const;

    void advancePC(PCStateBase& pc_state) const ;

    std::string generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab)  const override
            {
                return "this is dummy traceBuilder";
            }

};


}

#endif