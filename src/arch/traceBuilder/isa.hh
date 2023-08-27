#ifndef __ARCH_TRACEBUILDER_ISA__
#define __ARCH_TRACEBUILDER_ISA__


#include "arch/generic/isa.hh"
#include "params/traceBuilderISAX.hh"
#include "arch/traceBuilder/pcstate.hh"


namespace gem5{

    namespace TracebuilderISA{

        class ISA : public BaseISA{
        public:

            ISA(const traceBuilderISAXParams& params);

            PCStateBase* newPCState(Addr new_inst_addr=0) const override;

            bool inUserMode() const override{
                return true;
            }

            void copyRegsFrom(ThreadContext *src){

            }

            void clear(){};

            int flattenIntIndex(RegIndex idx){return idx;};
            
            int flattenFloatIndex(RegIndex idx){return idx;};

            int flattenVecIndex(RegIndex idx){return idx;};

            int flattenVecElemIndex(RegIndex idx){return idx;};

            int flattenVecPredIndex(RegIndex idx){return idx;};

            int flattenCCIndex(RegIndex idx){return idx;};

            RegVal readMiscRegNoEffect(RegIndex idx){return idx;};

            RegVal readMiscReg(RegIndex idx){return idx;};
            
            void setMiscRegNoEffect(RegIndex idx, RegVal val){};

            void setMiscReg(RegIndex idx, RegVal val){};



            RegId flattenRegId(RegId idx){return idx;};

        };


    }


}



#endif
