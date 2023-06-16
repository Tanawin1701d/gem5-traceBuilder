x   =                    [{
                            "type": "FUDesc",
                            "cxx_class": "gem5::FUDesc",
                            "name": "FUList0",
                            "path": "system.cpu.fuPool.FUList0",
                            "count": 6,
                            "eventq_index": 0,
                            "opList": [
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList",
                                    "path": "system.cpu.fuPool.FUList0.opList",
                                    "eventq_index": 0,
                                    "opClass": "IntAlu",
                                    "opLat": 1,
                                    "pipelined": True
                                }
                            ]
                        },
                        {
                            "type": "FUDesc",
                            "cxx_class": "gem5::FUDesc",
                            "name": "FUList1",
                            "path": "system.cpu.fuPool.FUList1",
                            "count": 2,
                            "eventq_index": 0,
                            "opList": [
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList0",
                                    "path": "system.cpu.fuPool.FUList1.opList0",
                                    "eventq_index": 0,
                                    "opClass": "IntMult",
                                    "opLat": 3,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList1",
                                    "path": "system.cpu.fuPool.FUList1.opList1",
                                    "eventq_index": 0,
                                    "opClass": "IntDiv",
                                    "opLat": 1,
                                    "pipelined": False
                                }
                            ]
                        },
                        {
                            "type": "FUDesc",
                            "cxx_class": "gem5::FUDesc",
                            "name": "FUList2",
                            "path": "system.cpu.fuPool.FUList2",
                            "count": 4,
                            "eventq_index": 0,
                            "opList": [
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList0",
                                    "path": "system.cpu.fuPool.FUList2.opList0",
                                    "eventq_index": 0,
                                    "opClass": "FloatAdd",
                                    "opLat": 2,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList1",
                                    "path": "system.cpu.fuPool.FUList2.opList1",
                                    "eventq_index": 0,
                                    "opClass": "FloatCmp",
                                    "opLat": 2,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList2",
                                    "path": "system.cpu.fuPool.FUList2.opList2",
                                    "eventq_index": 0,
                                    "opClass": "FloatCvt",
                                    "opLat": 2,
                                    "pipelined": True
                                }
                            ]
                        },
                        {
                            "type": "FUDesc",
                            "cxx_class": "gem5::FUDesc",
                            "name": "FUList3",
                            "path": "system.cpu.fuPool.FUList3",
                            "count": 2,
                            "eventq_index": 0,
                            "opList": [
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList0",
                                    "path": "system.cpu.fuPool.FUList3.opList0",
                                    "eventq_index": 0,
                                    "opClass": "FloatMult",
                                    "opLat": 4,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList1",
                                    "path": "system.cpu.fuPool.FUList3.opList1",
                                    "eventq_index": 0,
                                    "opClass": "FloatMultAcc",
                                    "opLat": 5,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList2",
                                    "path": "system.cpu.fuPool.FUList3.opList2",
                                    "eventq_index": 0,
                                    "opClass": "FloatMisc",
                                    "opLat": 3,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList3",
                                    "path": "system.cpu.fuPool.FUList3.opList3",
                                    "eventq_index": 0,
                                    "opClass": "FloatDiv",
                                    "opLat": 12,
                                    "pipelined": False
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList4",
                                    "path": "system.cpu.fuPool.FUList3.opList4",
                                    "eventq_index": 0,
                                    "opClass": "FloatSqrt",
                                    "opLat": 24,
                                    "pipelined": False
                                }
                            ]
                        },
                        {
                            "type": "FUDesc",
                            "cxx_class": "gem5::FUDesc",
                            "name": "FUList4",
                            "path": "system.cpu.fuPool.FUList4",
                            "count": 0,
                            "eventq_index": 0,
                            "opList": [
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList0",
                                    "path": "system.cpu.fuPool.FUList4.opList0",
                                    "eventq_index": 0,
                                    "opClass": "MemRead",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList1",
                                    "path": "system.cpu.fuPool.FUList4.opList1",
                                    "eventq_index": 0,
                                    "opClass": "FloatMemRead",
                                    "opLat": 1,
                                    "pipelined": True
                                }
                            ]
                        },
                        {
                            "type": "FUDesc",
                            "cxx_class": "gem5::FUDesc",
                            "name": "FUList5",
                            "path": "system.cpu.fuPool.FUList5",
                            "count": 4,
                            "eventq_index": 0,
                            "opList": [
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList00",
                                    "path": "system.cpu.fuPool.FUList5.opList00",
                                    "eventq_index": 0,
                                    "opClass": "SimdAdd",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList01",
                                    "path": "system.cpu.fuPool.FUList5.opList01",
                                    "eventq_index": 0,
                                    "opClass": "SimdAddAcc",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList02",
                                    "path": "system.cpu.fuPool.FUList5.opList02",
                                    "eventq_index": 0,
                                    "opClass": "SimdAlu",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList03",
                                    "path": "system.cpu.fuPool.FUList5.opList03",
                                    "eventq_index": 0,
                                    "opClass": "SimdCmp",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList04",
                                    "path": "system.cpu.fuPool.FUList5.opList04",
                                    "eventq_index": 0,
                                    "opClass": "SimdCvt",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList05",
                                    "path": "system.cpu.fuPool.FUList5.opList05",
                                    "eventq_index": 0,
                                    "opClass": "SimdMisc",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList06",
                                    "path": "system.cpu.fuPool.FUList5.opList06",
                                    "eventq_index": 0,
                                    "opClass": "SimdMult",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList07",
                                    "path": "system.cpu.fuPool.FUList5.opList07",
                                    "eventq_index": 0,
                                    "opClass": "SimdMultAcc",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList08",
                                    "path": "system.cpu.fuPool.FUList5.opList08",
                                    "eventq_index": 0,
                                    "opClass": "SimdShift",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList09",
                                    "path": "system.cpu.fuPool.FUList5.opList09",
                                    "eventq_index": 0,
                                    "opClass": "SimdShiftAcc",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList10",
                                    "path": "system.cpu.fuPool.FUList5.opList10",
                                    "eventq_index": 0,
                                    "opClass": "SimdDiv",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList11",
                                    "path": "system.cpu.fuPool.FUList5.opList11",
                                    "eventq_index": 0,
                                    "opClass": "SimdSqrt",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList12",
                                    "path": "system.cpu.fuPool.FUList5.opList12",
                                    "eventq_index": 0,
                                    "opClass": "SimdFloatAdd",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList13",
                                    "path": "system.cpu.fuPool.FUList5.opList13",
                                    "eventq_index": 0,
                                    "opClass": "SimdFloatAlu",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList14",
                                    "path": "system.cpu.fuPool.FUList5.opList14",
                                    "eventq_index": 0,
                                    "opClass": "SimdFloatCmp",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList15",
                                    "path": "system.cpu.fuPool.FUList5.opList15",
                                    "eventq_index": 0,
                                    "opClass": "SimdFloatCvt",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList16",
                                    "path": "system.cpu.fuPool.FUList5.opList16",
                                    "eventq_index": 0,
                                    "opClass": "SimdFloatDiv",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList17",
                                    "path": "system.cpu.fuPool.FUList5.opList17",
                                    "eventq_index": 0,
                                    "opClass": "SimdFloatMisc",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList18",
                                    "path": "system.cpu.fuPool.FUList5.opList18",
                                    "eventq_index": 0,
                                    "opClass": "SimdFloatMult",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList19",
                                    "path": "system.cpu.fuPool.FUList5.opList19",
                                    "eventq_index": 0,
                                    "opClass": "SimdFloatMultAcc",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList20",
                                    "path": "system.cpu.fuPool.FUList5.opList20",
                                    "eventq_index": 0,
                                    "opClass": "SimdFloatSqrt",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList21",
                                    "path": "system.cpu.fuPool.FUList5.opList21",
                                    "eventq_index": 0,
                                    "opClass": "SimdReduceAdd",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList22",
                                    "path": "system.cpu.fuPool.FUList5.opList22",
                                    "eventq_index": 0,
                                    "opClass": "SimdReduceAlu",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList23",
                                    "path": "system.cpu.fuPool.FUList5.opList23",
                                    "eventq_index": 0,
                                    "opClass": "SimdReduceCmp",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList24",
                                    "path": "system.cpu.fuPool.FUList5.opList24",
                                    "eventq_index": 0,
                                    "opClass": "SimdFloatReduceAdd",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList25",
                                    "path": "system.cpu.fuPool.FUList5.opList25",
                                    "eventq_index": 0,
                                    "opClass": "SimdFloatReduceCmp",
                                    "opLat": 1,
                                    "pipelined": True
                                }
                            ]
                        },
                        {
                            "type": "FUDesc",
                            "cxx_class": "gem5::FUDesc",
                            "name": "FUList6",
                            "path": "system.cpu.fuPool.FUList6",
                            "count": 1,
                            "eventq_index": 0,
                            "opList": [
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList",
                                    "path": "system.cpu.fuPool.FUList6.opList",
                                    "eventq_index": 0,
                                    "opClass": "SimdPredAlu",
                                    "opLat": 1,
                                    "pipelined": True
                                }
                            ]
                        },
                        {
                            "type": "FUDesc",
                            "cxx_class": "gem5::FUDesc",
                            "name": "FUList7",
                            "path": "system.cpu.fuPool.FUList7",
                            "count": 0,
                            "eventq_index": 0,
                            "opList": [
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList0",
                                    "path": "system.cpu.fuPool.FUList7.opList0",
                                    "eventq_index": 0,
                                    "opClass": "MemWrite",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList1",
                                    "path": "system.cpu.fuPool.FUList7.opList1",
                                    "eventq_index": 0,
                                    "opClass": "FloatMemWrite",
                                    "opLat": 1,
                                    "pipelined": True
                                }
                            ]
                        },
                        {
                            "type": "FUDesc",
                            "cxx_class": "gem5::FUDesc",
                            "name": "FUList8",
                            "path": "system.cpu.fuPool.FUList8",
                            "count": 4,
                            "eventq_index": 0,
                            "opList": [
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList0",
                                    "path": "system.cpu.fuPool.FUList8.opList0",
                                    "eventq_index": 0,
                                    "opClass": "MemRead",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList1",
                                    "path": "system.cpu.fuPool.FUList8.opList1",
                                    "eventq_index": 0,
                                    "opClass": "MemWrite",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList2",
                                    "path": "system.cpu.fuPool.FUList8.opList2",
                                    "eventq_index": 0,
                                    "opClass": "FloatMemRead",
                                    "opLat": 1,
                                    "pipelined": True
                                },
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList3",
                                    "path": "system.cpu.fuPool.FUList8.opList3",
                                    "eventq_index": 0,
                                    "opClass": "FloatMemWrite",
                                    "opLat": 1,
                                    "pipelined": True
                                }
                            ]
                        },
                        {
                            "type": "FUDesc",
                            "cxx_class": "gem5::FUDesc",
                            "name": "FUList9",
                            "path": "system.cpu.fuPool.FUList9",
                            "count": 1,
                            "eventq_index": 0,
                            "opList": [
                                {
                                    "type": "OpDesc",
                                    "cxx_class": "gem5::OpDesc",
                                    "name": "opList",
                                    "path": "system.cpu.fuPool.FUList9.opList",
                                    "eventq_index": 0,
                                    "opClass": "IprAccess",
                                    "opLat": 3,
                                    "pipelined": False
                                }
                            ]
                        }
]



for mydic in x:
    co = mydic["count"]
    print(f"COUNT : {co}")
    for opdic in mydic["opList"]:
        opclass = opdic["opClass"]
        oplat   = opdic["opLat"]
        opPipe  = opdic["pipelined"]
        print(f"{opclass}  lat: {oplat} pip: {opPipe}")
    print("-------------------------------------------")