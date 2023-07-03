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

        if (mode == BaseMMU::Execute){

            /** for i side*/
            preRetIsideQueue.push({
                req,
                tc,
                mode,
                translation
            });
            if (!finishIsideTranslateEvent.scheduled()){
                schedule(finishIsideTranslateEvent, curTick() + 500);
            }

        }else{
            /** for d side*/
            preRetDsideQueue.push({
                req,
                tc,
                mode,
                translation
            });
            if (!finishDsideTranslateEvent.scheduled()){
                schedule(finishDsideTranslateEvent, curTick() + 500);
            }

        }

    };

    void
    Mmu::completeIsideTiming(){
        preRetIsideQueue.front().translation->finish(NoFault, 
                                                          preRetIsideQueue.front().reqside, 
                                                          preRetIsideQueue.front().tcside, 
                                                          preRetIsideQueue.front().modeside
        );
        preRetIsideQueue.pop();
        if (!preRetIsideQueue.empty() && !finishIsideTranslateEvent.scheduled()){
            schedule(finishIsideTranslateEvent, curTick() + 500);
        }
    }

    void
    Mmu::completeDsideTiming(){
        preRetDsideQueue.front().translation->finish(NoFault, preRetDsideQueue.front().reqside,
                                                              preRetDsideQueue.front().tcside,
                                                              preRetDsideQueue.front().modeside
        );
        preRetDsideQueue.pop();
        if (!preRetDsideQueue.empty() && !finishDsideTranslateEvent.scheduled()){
            schedule(finishDsideTranslateEvent, curTick() + 500);
        }
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