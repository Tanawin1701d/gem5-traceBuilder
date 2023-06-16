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

        preRetQueueIside.push({
            req,
            tc,
            mode,
            translation
        });

        schedule(finishTranslateEvent, curTick() + 500);

    };

    void
    Mmu::completeTiming(){
        preRetQueueIside.front().translationIside->finish(NoFault, 
                                                          preRetQueueIside.front().reqIside, 
                                                          preRetQueueIside.front().tcIside, 
                                                          preRetQueueIside.front().modeIside
        );
        preRetQueueIside.pop();
    }
    
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