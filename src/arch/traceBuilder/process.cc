#include "arch/traceBuilder/process.hh"
#include "params/Process.hh"
#include "mem/page_table.hh"
#include <iostream>


namespace gem5{

namespace TracebuilderISA{


TraceBuilderProcess::TraceBuilderProcess(
    const ProcessParams &params, 
    loader::ObjectFile *objFile
    ): Process(params, new EmulationPageTable(params.name, params.pid, 1 << 12), objFile){
            std::cout << "traceBuilderProcess is built" << std::endl;


            memState = std::make_shared<MemState>(
            this, 1 << 12, 0, 1 << 12,
            0, 1 << 12);
    }


}

}