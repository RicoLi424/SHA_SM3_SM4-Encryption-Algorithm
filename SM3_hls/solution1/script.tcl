############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project SM3
set_top SM3Calc
add_files SM3/src/SM3.h
add_files SM3/src/SM3.c
add_files -tb SM3/test/test_SM3.c -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7vx980t-ffg1930-2} -tool vivado
create_clock -period 10 -name default
#source "./SM3/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all -tool modelsim
export_design -format ip_catalog
