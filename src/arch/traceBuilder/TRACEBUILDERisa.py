
from m5.params import *
from m5.objects.BaseISA import BaseISA

class traceBuilderISAX(BaseISA):
    type = "traceBuilderISAX"
    cxx_header = "arch/traceBuilder/isa.hh"
    cxx_class  = "gem5::TracebuilderISA::ISA"