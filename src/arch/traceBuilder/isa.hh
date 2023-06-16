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

            int flattenIntIndex(RegIndex idx){return 0;};
            
            int flattenFloatIndex(RegIndex idx){return 0;};

            int flattenVecIndex(RegIndex idx){return 0;};

            int flattenVecElemIndex(RegIndex idx){return 0;};

            int flattenVecPredIndex(RegIndex idx){return 0;};

            int flattenCCIndex(RegIndex idx){return 0;};

            RegVal readMiscRegNoEffect(RegIndex idx){return 0;};

            RegVal readMiscReg(RegIndex idx){return 0;};
            
            void setMiscRegNoEffect(RegIndex idx, RegVal val){};

            void setMiscReg(RegIndex idx, RegVal val){};

            RegId flattenRegId(RegId idx){return RegId();};

            





            

        };


    }


}



#endif
