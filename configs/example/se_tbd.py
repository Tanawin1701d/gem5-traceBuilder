# Copyright (c) 2012-2013 ARM Limited
# All rights reserved.
#
# The license below extends only to copyright in the software and shall
# not be construed as granting a license to any other intellectual
# property including but not limited to intellectual property relating
# to a hardware implementation of the functionality of the software
# licensed hereunder.  You may use the software subject to the license
# terms below provided that you ensure that this notice is replicated
# unmodified and in its entirety in all distributions of the software,
# modified or unmodified, in source code or in binary form.
#
# Copyright (c) 2006-2008 The Regents of The University of Michigan
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met: redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer;
# redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution;
# neither the name of the copyright holders nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

# Simple test script
#
# "m5 test.py"

import argparse
import sys
import os

import m5
from m5.defines import buildEnv
from m5.objects import *
from m5.params import NULL
from m5.util import addToPath, fatal, warn

addToPath('../')

from ruby import Ruby

from common import Options
from common import Simulation
from common import CacheConfig
from common import CpuConfig
from common import ObjectList
from common import MemConfig
from common.FileSystemConfig import config_filesystem
from common.Caches import *
from common.cpu2000 import *

def get_processes(args):
    """Interprets provided args and returns a list of processes"""

    multiprocesses = []
    inputs = []
    outputs = []
    errouts = []
    pargs = []

    workloads = args.cmd.split(';')
    if args.input != "":
        inputs = args.input.split(';')
    if args.output != "":
        outputs = args.output.split(';')
    if args.errout != "":
        errouts = args.errout.split(';')
    if args.options != "":
        pargs = args.options.split(';')

    idx = 0
    for wrkld in workloads:
        process = Process(pid = 100 + idx)
        process.executable = wrkld
        process.cwd = os.getcwd()
        process.gid = os.getgid()

        if args.env:
            with open(args.env, 'r') as f:
                process.env = [line.rstrip() for line in f]

        if len(pargs) > idx:
            process.cmd = [wrkld] + pargs[idx].split()
        else:
            process.cmd = [wrkld]

        if len(inputs) > idx:
            process.input = inputs[idx]
        if len(outputs) > idx:
            process.output = outputs[idx]
        if len(errouts) > idx:
            process.errout = errouts[idx]

        multiprocesses.append(process)
        idx += 1

    if args.smt:
        assert(args.cpu_type == "DerivO3CPU")
        return multiprocesses, idx
    else:
        return multiprocesses, 1


parser = argparse.ArgumentParser()

parser.add_argument("-tf","--tbdfile", help = "workload for test")


Options.addCommonOptions(parser)
Options.addSEOptions(parser)

if '--ruby' in sys.argv:
    Ruby.define_options(parser)

args = parser.parse_args()
opt_workload = getattr(args, "workloads", "lu")


class fluidanimateWK(Process):
    cwd = '/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/TestProgram/parsec-3.0/pkgs/apps/fluidanimate'
    executable = '/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/TestProgram/parsec-3.0/pkgs/apps/fluidanimate/inst/amd64-linux.gcc-serial/bin/fluidanimate'
    cmd = ['inst/amd64-linux.gcc-serial/bin/fluidanimate', 
            '1', 
            '5', 
            'inputs/input_simmedium/in_100K.fluid',
            'output/myoutput'
          ]

class blackscholesWK(Process):
    cwd = '/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/TestProgram/parsec-3.0/pkgs/apps/blackscholes'
    executable = '/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/TestProgram/parsec-3.0/pkgs/apps/blackscholes/inst/amd64-linux.gcc-serial/bin/blackscholes'
    cmd = ['inst/amd64-linux.gcc-serial/bin/blackscholes', 
            '1', 
            'inputs/input_simmedium/in_16K.txt', 
            'output/myoutput'
          ]

class loopchecker(Process):
    cwd = "/media/tanawin/tanawin1701d/Project/sms/compiledEle/meta_workloads/test-progs/foolloop"
    executable = "/media/tanawin/tanawin1701d/Project/sms/compiledEle/meta_workloads/test-progs/foolloop/1000l"
    cmd = ["1000l"]

class dummyProc(Process):
    cwd = "/media/tanawin/tanawin1701e/Project/gem5base/gem5/tests/dummy"
    executable = "/media/tanawin/tanawin1701e/Project/gem5base/gem5/tests/dummy/d"
    cmd = ["d"]


multiprocesses = []
numThreads = 1

# if args.workloads:
#     templateWorkloads = {
#      "fluidanimate" : fluidanimateWK,
#      "blackscholes" : blackscholesWK,
#      "loopchecker"  : loopchecker
#     }

#     if (opt_workload not in templateWorkloads):
#         sys.exit("no match workload")

#     for mock in range(args.num_cpus):
#         mnp = templateWorkloads[opt_workload]()
#         mnp.pid = 100 + mock
#         multiprocesses.append(mnp)

# elif args.bench:
#     apps = args.bench.split("-")
#     if len(apps) != args.num_cpus:
#         print("number of benchmarks not equal to set num_cpus!")
#         sys.exit(1)

#     for app in apps:
#         try:
#             if buildEnv['TARGET_ISA'] == 'arm':
#                 exec("workload = %s('arm_%s', 'linux', '%s')" % (
#                         app, args.arm_iset, args.spec_input))
#             else:
#                 exec("workload = %s(buildEnv['TARGET_ISA', 'linux', '%s')" % (
#                         app, args.spec_input))
#             multiprocesses.append(workload.makeProcess())
#         except:
#             print("Unable to find workload for %s: %s" %
#                   (buildEnv['TARGET_ISA'], app),
#                   file=sys.stderr)
#             sys.exit(1)
# elif args.cmd:
#     multiprocesses, numThreads = get_processes(args)
# else:
#     print("No workload specified. Exiting!\n", file=sys.stderr)
#     sys.exit(1)




(CPUClass, test_mem_mode, FutureClass) = Simulation.setCPUClass(args)
CPUClass.numThreads = numThreads

# Check -- do not allow SMT with multiple CPUs
if args.smt and args.num_cpus > 1:
    fatal("You cannot use SMT with multiple CPUs!")

np = args.num_cpus

for i in range(np):
    proc = dummyProc()
    proc.pid = 100 + i
    multiprocesses.append(proc)



mp0_path = multiprocesses[0].executable
system = System(cpu = [CPUClass(cpu_id=i) for i in range(np)],
                mem_mode = test_mem_mode,
                mem_ranges = [AddrRange(args.mem_size)],
                cache_line_size = args.cacheline_size)

if numThreads > 1:
    system.multi_thread = True

# Create a top-level voltage domain
system.voltage_domain = VoltageDomain(voltage = args.sys_voltage)

# Create a source clock for the system and set the clock period
system.clk_domain = SrcClockDomain(clock =  args.sys_clock,
                                   voltage_domain = system.voltage_domain)

# Create a CPU voltage domain
system.cpu_voltage_domain = VoltageDomain()

# Create a separate clock domain for the CPUs
system.cpu_clk_domain = SrcClockDomain(clock = args.cpu_clock,
                                       voltage_domain =
                                       system.cpu_voltage_domain)

# All cpus belong to a common cpu_clk_domain, therefore running at a common
# frequency.
for cpu in system.cpu:
    cpu.clk_domain = system.cpu_clk_domain


# Sanity check
########## add workload
myTbdFile = getattr(args, "tbdfile", None)
for i in range(np):
    system.cpu[i].workload = multiprocesses[i]
    print("try createThread")
    system.cpu[i].createTbdThreads(myTbdFile)


#### memmory subsystem
MemClass = Simulation.setMemClass(args)
system.membus = SystemXBar()
system.system_port = system.membus.cpu_side_ports
CacheConfig.config_cache(args, system)
MemConfig.config_mem(args, system)
config_filesystem(system, args)

system.workload = SEWorkload.init_compatible(mp0_path)

if args.wait_gdb:
    system.workload.wait_for_remote_gdb = True

root = Root(full_system = False, system = system)
Simulation.run(args, root, system, FutureClass)
