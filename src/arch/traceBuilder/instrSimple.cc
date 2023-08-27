#include"arch/traceBuilder/instrSimple.hh"
#include"arch/traceBuilder/instrRw.hh"


namespace gem5{
namespace TracebuilderISA{



/** 
 * 
 * 
 * 
 * macro op
 * 
 * 
 * 
 * 
 * */


tbdMacroop::tbdMacroop(ProtoMessage::InstrRecord& instrRec)
    : StaticInst("simpleTraceBuilder", enums::No_OpClass),
    instrMeta(instrRec)
     {

    setFlag(IsMacroop);
    }

Fault 
tbdMacroop::execute(ExecContext* xc, Trace::InstRecord* traceData) const{
    return NoFault;
}

void 
tbdMacroop::advancePC(PCStateBase&  pc_state) const {
    auto& pc = pc_state.as<PCState>();
    /** decoder must set next pc to support vary length not us*/
    pc.advance();
}

StaticInstPtr
tbdMacroop::fetchMicroop(MicroPC upc) const{
    assert(upc < (instrMeta.uops()).size());

    ProtoMessage::machRecord curmach = instrMeta.uops((int)upc);
    
    /** static instr*/
    auto uopType = curmach.rectype();

    tbdMicroop* cur_microop;

    if (uopType == ProtoMessage::machRecord::UOP_COMP ||
        uopType == ProtoMessage::machRecord::UOP_IMM
    ){
        cur_microop = new tbdMicroop(curmach, 
                                      upc == 0, 
                                      upc == (instrMeta.uops()).size()-1
                                      );

    }else if (uopType == ProtoMessage::machRecord::UOP_LOAD){

        cur_microop = new tbdReadMicroop(curmach, 
                                         upc == 0, 
                                         upc == (instrMeta.uops()).size()-1
                                        );


    }else if (uopType == ProtoMessage::machRecord::UOP_STORE){
        cur_microop = new tbdWriteMicroop(curmach, 
                                         upc == 0, 
                                         upc == (instrMeta.uops()).size()-1
                                        );
    }else{
        panic("unknow uop type");
    }

    return StaticInstPtr(cur_microop);

    

}



/** 
 * 
 * 
 * 
 * 
 * micro op
 * 
 * 
 * 
 * 
 * */

void
tbdMicroop::setINTFLT(int fu){
    static int mapFlag[] = {
/* "No_OpClass"             */ IsInteger, 
/* "IntAlu"                 */ IsInteger,
/* "IntMult"                */ IsInteger,
/* "IntDiv"                 */ IsInteger, 
/* "FloatAdd"               */ IsFloating,
/* "FloatCmp"               */ IsFloating, 
/* "FloatCvt"               */ IsFloating, 
/* "FloatMult"              */ IsFloating, 
/* "FloatMultAcc"           */ IsFloating, 
/* "FloatDiv"               */ IsFloating, 
/* "FloatMisc"              */ IsFloating, 
/* "FloatSqrt"              */ IsFloating, 
/* "SimdAdd"                */ IsInteger,
/* "dAddAcc"                */ IsInteger,
/* "SimdAlu"                */ IsInteger,
/* "SimdCmp"                */ IsInteger,
/* "SimdCvt"                */ IsInteger,
/* "SimdMisc"               */ IsInteger,
/* "SimdMult"               */ IsInteger,
/* "SimdMultAcc"            */ IsInteger,
/* "SimdShift"              */ IsInteger,
/* "SimdShiftAcc"           */ IsInteger,
/* "SimdDiv"                */ IsInteger,
/* "SimdSqrt"               */ IsInteger,
/* "SimdFloatAdd"           */ IsFloating,
/* "SimdFloatAlu"           */ IsFloating,
/* "SimdFloatCmp"           */ IsFloating,
/* "SimdFloatCvt"           */ IsFloating,
/* "SimdFloatDiv"           */ IsFloating,
/* "SimdFloatMisc"          */ IsFloating,
/* "SimdFloatMult"          */ IsFloating,
/* "SimdFloatMultAcc"       */ IsFloating,
/* "SimdFloatSqrt"          */ IsFloating,
/* "SimdReduceAdd"          */ IsInteger,
/* "SimdReduceAlu"          */ IsInteger,
/* "SimdReduceCmp"          */ IsInteger,
/* "SimdFloatReduceAdd"     */ IsFloating,
/* "SimdFloatReduceCmp"     */ IsFloating,
/* "SimdAes"                */ IsInteger,
/* "SimdAesMix"             */ IsInteger,
/* "SimdSha1Hash"           */ IsInteger,
/* "SimdSha1Hash2"          */ IsInteger,
/* "SimdSha256Hash"         */ IsInteger,
/* "SimdSha256Hash2"        */ IsInteger,
/* "SimdShaSigma2"          */ IsInteger,
/* "SimdShaSigma3"          */ IsInteger,
/* "SimdPredAlu"            */ IsInteger,
/* cxxTypeUOP_LOAD_INT      */ IsInteger,
/* cxxTypeUOP_STORE_INT     */ IsInteger,
/* cxxTypeUOP_LOAD_FLT      */ IsFloating,
/* cxxTypeUOP_STORE_FLT     */ IsFloating,
/* "IprAccess"              */ IsInteger,
/* "InstPrefetch"           */ IsInteger
    };
    assert( mapFlag[fu] == IsInteger || mapFlag[fu] == IsFloating);
    //std::cout << mapFlag[fu] << std::endl;
    flags[mapFlag[fu]] = true;
}

RegId 
tbdMicroop::buildTbdRegId(RegIndex rid){
    /////// int | temp | newBuilt
    /////// flt | vec  | 
    if (rid >= startRawIdx_UNK){
                                                          /** int reg  + spare for tem reg*/
        return RegId(IntRegClass, rid - startRawIdx_UNK + amtRawIdx_INT  + amtRawIdx_TEM);
    }else if (rid >= startRawIdx_TEM){
        return RegId(IntRegClass, rid - startRawIdx_TEM + amtRawIdx_INT);
    }else if (rid >= startRawIdx_VEC){
        return RegId(FloatRegClass, rid - startRawIdx_VEC + amtRawIdx_FLT);
    }else if (rid >= startRawIdx_FLT){
        return RegId(FloatRegClass, rid - startRawIdx_FLT);
    } // if (rid >= startRawIdx_INT){
    
    return RegId(IntRegClass, rid -startRawIdx_INT);
}

tbdMicroop::tbdMicroop(ProtoMessage::machRecord& _machRec, 
                       bool isFirstMicroop,
                       bool isLastMicroop)
    : 
      StaticInst("simpleTraceBuildermicroop", enums::OpClass::No_OpClass),
      curmach(_machRec),
      isFirst(isFirstMicroop),
      isLast(isLastMicroop)
      
{
        /** manually set opclass*/
        uint32_t functionalUnit = _machRec.funcunit();

        setINTFLT(functionalUnit);
        
        if (functionalUnit == dummyOpclass){
            _opClass = enums::OpClass::No_OpClass;
        }else{
            _opClass = static_cast<enums::OpClass>(functionalUnit);
        }

        /* set position of microop*/
        if (isFirst)
            setFirstMicroop();
        if (isLast)
            setLastMicroop();
        /** set uop type*/
        //// for now we use integer operation for convinient
        //setFlag(IsInteger);
        /** set register and */
        _numSrcRegs  = (curmach.srcarchregid()).size();
        _numDestRegs = (curmach.desarchregid()).size();

        setRegIdxArrays(
                reinterpret_cast<RegIdArrayPtr>(&std::remove_pointer_t<decltype(this)>::srcRegs),
                reinterpret_cast<RegIdArrayPtr>(&std::remove_pointer_t<decltype(this)>::desRegs)
        );



        /** set src reg*/
        for (int i = 0; i < _numSrcRegs; i++){
            uint32_t regNum = (uint16_t)curmach.srcarchregid(i);
            setSrcRegIdx(i, buildTbdRegId(regNum));
        }
        /** set des reg*/
        for (int i = 0; i < _numDestRegs; i++){
            uint32_t regNum = (uint16_t) curmach.desarchregid(i);
            setDestRegIdx(i, buildTbdRegId(regNum));
        }
    
}


Fault 
tbdMicroop::execute(ExecContext* xc, Trace::InstRecord* traceData) const{
    return NoFault;
}


void
tbdMicroop::advancePC(PCStateBase& pc_state) const{
    auto& cur_pc = pc_state.as<PCState>();
    /** next microop*/
    if (isLastMicroop()){
        cur_pc.uEnd();
    }else{
        cur_pc.uAdvance();
    }
}


/** 
 * 
 * 
 * microop for system call
 * 
 * 
 * */

tbdSyscallMacroop::tbdSyscallMacroop():
StaticInst("Buildersyscall", enums::No_OpClass){

    setFlag(IsSyscall);

}

Fault 
tbdSyscallMacroop::execute(ExecContext* xc, Trace::InstRecord* traceData) const{
    return std::make_shared<SESyscallFault>();
}


void
tbdSyscallMacroop::advancePC(PCStateBase& pc_state) const{
    
    
    auto& pc = pc_state.as<PCState>();
    /** decoder must set next pc to support vary length not us*/
    pc.advance();
}


}
}