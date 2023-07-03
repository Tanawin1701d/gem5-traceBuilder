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

RegId 
tbdMicroop::buildTbdRegId(RegIndex rid){
    if (rid >= startRawIdx_UNK){
                                                          /** int reg  + spare for tem reg*/
        return RegId(IntRegClass, rid - startRawIdx_UNK + amtRawIdx_INT + 10);
    }else if (rid >= startRawIdx_TEM){
        return RegId(IntRegClass, rid - startRawIdx_UNK + amtRawIdx_INT);
    }else if (rid >= startRawIdx_VEC){
        return RegId(VecRegClass, rid - startRawIdx_VEC);
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