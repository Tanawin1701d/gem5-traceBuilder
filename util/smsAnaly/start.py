from threading import Thread
import sys
import subprocess

gem5Dir= "/media/tanawin/tanawin1701d/Project/Intern/InternGem5"
curDir = "/media/tanawin/tanawin1701d/Project/Intern/InternGem5/util/smsAnaly"


def runMemCtrlSim(workload, schedType, mctlBS = 64, ncore = 1): # memory controller buffer size each size
    #TODO we might able to heterogenous workload on same chip

    #workload command
    wlCmd = ""
    if (workload == "fluidanimate"):
        wlCmd = "--workloads=fluidanimate"
    elif(workload == "luDenseBlock"):
        wlCmd = "--workloads=lu"
    else:
        sys.exit('no workload exit')

    #scheduling type and it buffer size
    stCmd = ""   #scheduling type command
    mctlSCmd = ""#memory controller size command
    if (schedType == "frfcfs"):
        stCmd    = "--memSched=frfcfs"
        mctlSCmd = "--memSchedSize=" + str(mctlBS)
    elif (schedType == "fcfs"):
        stCmd = "--memSched=frfcfs"
        mctlSCmd = "--memSchedSize=" + str(mctlBS)
    elif (schedType == "sms"):
        stCmd    = "--interQmemSched=STAGE_SCHED_Queue"
        mctlSCmd = "--interQmemSchedSize="+ str(mctlBS) # for now it stand for stage 1 size per buffer
    else:
        sys.exit('no sched type exit')
    print("start invoke simulation")

    process = subprocess.Popen(
                    [

                        '''gnome-terminal\\
                        --\\
                        time\\
                        {_gem5Dir}/build/X86/gem5.opt\\
                        --stats-file={_curDir}/{_workload}_{_schedType}_{_bn}.txt\\
                        --json-config={_curDir}/{_workload}_{_schedType}_{_bn}.json\\
                        {_gem5Dir}/configs/learning_gem5/newBench.py\\
                        --memAccessDebugStat={_curDir}/{_workload}_{_ncore}core_{_schedType}_{_bn}_mad.txt\\
                        --mem-size=8192MB\\
                        {_wlCmd}\\
                        --cpu-type=DerivO3CPU\\
                        --l1d_size=1kB\\
                        --l1i_size=16kB\\
                        -n 16\\
                        {_stCmd}\\
                        {_mctlSCmd}\\
                        --caches \\
                        --l2cache
                        '''.format(_gem5Dir=gem5Dir,
                                              _curDir=curDir,
                                              _workload=workload,
                                              _schedType=schedType,
                                              _bn=str(mctlBS),
                                              _wlCmd=wlCmd,
                                              _stCmd=stCmd,
                                              _mctlSCmd=mctlSCmd,  
                                              _ncore=ncore
                                              )
                        
                    ],
                    shell=True,
                     stdout=subprocess.PIPE, 
                     stderr=subprocess.PIPE,
                     universal_newlines=True)
    # for outLine in iter(process.stdout.readline, ""):
    #     yield outLine
    # process.stdout.close()
    # return_code = process.wait()
    # if return_code:
    #     raise subprocess.CalledProcessError(return_code)
    stdout, stderr = process.communicate()
    print(stdout, stderr)    

# for out in runMemCtrlSim("fluidanimate", "sms", 64):
#     print(out, end ="")

#runMemCtrlSim("fluidanimate", "frfcfs", 64) # memory controller buffer size each size
# runMemCtrlSim("fluidanimate", "sms", 32) # memory controller buffer size each size
runMemCtrlSim("fluidanimate", "sms", 32) # memory controller buffer size each size
