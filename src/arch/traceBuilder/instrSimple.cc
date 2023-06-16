#include"arch/traceBuilder/instrSimple.hh"


namespace gem5{

Fault 
InstrSimple::execute(ExecContext* xc, Trace::InstRecord* traceData) const{
    return NoFault;
}

void 
InstrSimple::advancePC(PCStateBase&  pc_state) const {
    pc_state.advance();
}



}