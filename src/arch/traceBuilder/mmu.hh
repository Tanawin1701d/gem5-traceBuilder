#ifndef __ARCH_TRACEBUILDER_MMU_HH__
#define __ARCH_TRACEBUILDER_MMU_HH__


#include "arch/generic/mmu.hh"
#include "params/traceBuilderMmu.hh"
#include "arch/traceBuilder/mmu.hh"

#include "mem/translation_gen.hh"
#include <queue>


namespace gem5{

    namespace TracebuilderISA{




        class Mmu : public BaseMMU{

            struct preRetMmu{
                RequestPtr     reqside;
                ThreadContext* tcside;
                Mode           modeside;
                Translation*   translation = nullptr;
            };

            public:
                std::queue<preRetMmu> preRetIsideQueue;
                EventFunctionWrapper finishIsideTranslateEvent;

                std::queue<preRetMmu> preRetDsideQueue;
                EventFunctionWrapper finishDsideTranslateEvent;
                

                class traceBuilderTranslationGen : public TranslationGen{
                
                    using TranslationGen::TranslationGen;
                
                    void translate(Range& range) const{
                        range.paddr = range.vaddr;
                        range.fault = NoFault;
                    }
                };


                


                Mmu(const traceBuilderMmuParams& p): 
                    BaseMMU(p), 
                    finishIsideTranslateEvent([this]{completeIsideTiming();}, name()),
                    finishDsideTranslateEvent([this]{completeDsideTiming();}, name())
                    {};
                void flushAll() override {};

                Fault translateAtomic(const RequestPtr &req, ThreadContext *tc,
                    Mode mode) override;

                void
                translateTiming(const RequestPtr &req, ThreadContext *tc,
                Translation *translation, Mode mode) override;

                void
                completeIsideTiming();

                void 
                completeDsideTiming();

                Fault
                translateFunctional(const RequestPtr &req, ThreadContext *tc, Mode mode) override;

                TranslationGenPtr 
                translateFunctional(Addr start, Addr size,
                ThreadContext *tc, BaseMMU::Mode mode, Request::Flags flags) override;

                Fault
                finalizePhysical(const RequestPtr &req, ThreadContext *tc,
                Mode mode) const;




        };


    }



}


#endif