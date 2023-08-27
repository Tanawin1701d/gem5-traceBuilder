#include "arch/traceBuilder/mmu.hh"


namespace gem5{

    namespace TracebuilderISA{


    Fault 
    Mmu::translateAtomic(const RequestPtr &req, ThreadContext *tc,
        Mode mode){
            const Addr vaddr = req->getVaddr();
            req->setPaddr(vaddr);
            return NoFault;
    };


    void
    Mmu::translateTiming(const RequestPtr &req, ThreadContext *tc,Translation *translation, Mode mode){
        
        translateAtomic(req, tc, mode);
        translation->finish(NoFault, req, tc, mode);

    };
    
    Fault
    Mmu::translateFunctional(const RequestPtr &req, ThreadContext *tc, Mode mode) {
        translateAtomic(req, tc, mode);
        return NoFault;
    };

    TranslationGenPtr
    Mmu::translateFunctional(Addr start, Addr size,
                             ThreadContext *tc, BaseMMU::Mode mode, 
                             Request::Flags flags){



    
        return std::make_unique<traceBuilderTranslationGen>(start, size);
    
    
    }

    Fault
    Mmu::finalizePhysical(const RequestPtr &req, ThreadContext *tc,Mode mode) const {
        //translateAtomic(req, tc, mode);
        return NoFault;
    };


    }



}