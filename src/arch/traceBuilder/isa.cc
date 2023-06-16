#include"arch/traceBuilder/isa.hh"


namespace gem5{
    namespace TracebuilderISA{
        
        ISA::ISA(const traceBuilderISAXParams &p) : BaseISA(p){
            _regClasses.emplace_back(2);
            _regClasses.emplace_back(2);
            _regClasses.emplace_back(2);
            _regClasses.emplace_back(2);
            _regClasses.emplace_back(2);
            _regClasses.emplace_back(0);
            _regClasses.emplace_back(0);
            _regClasses.emplace_back(0);

        }

        PCStateBase*
        ISA::newPCState(Addr new_inst_addr) const {
            return new PCState(new_inst_addr);
        }
    }
}