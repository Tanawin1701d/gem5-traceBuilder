#ifndef __ARCH_TRACEBUILDER_PROCESS__
#define __ARCH_TRACEBUILDER_PROCESS__

#include "sim/process.hh"
#include "sim/sim_exit.hh"

namespace gem5{

class EmulationPageTable;

namespace TracebuilderISA{

 class TraceBuilderProcess : public Process
    {
      public:

        TraceBuilderProcess(const ProcessParams &params, loader::ObjectFile *objFile);

        void syscall(ThreadContext* tc) override;

    };


}

}


#endif