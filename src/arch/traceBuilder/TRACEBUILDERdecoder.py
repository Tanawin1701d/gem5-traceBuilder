from m5.objects.InstDecoder import InstDecoder



class traceBuilderDecoder(InstDecoder):
    type = 'traceBuilderDecoder'
    cxx_class  = 'gem5::TracebuilderISA::Decoder'
    cxx_header = 'arch/traceBuilder/decoder.hh'