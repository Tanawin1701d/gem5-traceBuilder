from m5.objects.InstDecoder import InstDecoder
from m5.params              import *



class traceBuilderDecoder(InstDecoder):
    type = 'traceBuilderDecoder'
    cxx_class  = 'gem5::TracebuilderISA::Decoder'
    cxx_header = 'arch/traceBuilder/decoder.hh'
    uopStreamName = Param.String("path to traceBuilder uop generated file")

    #prc = Param.Process("for getting proocess to generate uops")