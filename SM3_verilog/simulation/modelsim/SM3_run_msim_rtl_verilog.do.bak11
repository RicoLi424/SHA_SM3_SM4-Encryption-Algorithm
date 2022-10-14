transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+D:/FPGA/SM3_2 {D:/FPGA/SM3_2/SM3Calc.v}
vlog -vlog01compat -work work +incdir+D:/FPGA/SM3_2 {D:/FPGA/SM3_2/SM3ProcessMessageBlock.v}

vlog -vlog01compat -work work +incdir+D:/FPGA/SM3_2 {D:/FPGA/SM3_2/SM3Calc_tb.vt}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cyclonev_ver -L cyclonev_hssi_ver -L cyclonev_pcie_hip_ver -L rtl_work -L work -voptargs="+acc"  SM3Calc_tb

add wave *
view structure
view signals
run -all
