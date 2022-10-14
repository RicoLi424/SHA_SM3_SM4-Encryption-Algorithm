set designtopgroup "Design Top Signals"
add wave -group $designtopgroup
set clockgroup "Clock"
add wave -group $designtopgroup -group $clockgroup
add wave -group $designtopgroup -group $clockgroup /apatb_SM3Calc_top/AESL_inst_SM3Calc/ap_clk
set resetgroup "Reset"
add wave -group $designtopgroup -group $resetgroup
add wave -group $designtopgroup -group $resetgroup /apatb_SM3Calc_top/AESL_inst_SM3Calc/ap_rst
set blocksiggroup "Block-level IO Handshake"
add wave -group $designtopgroup -group $blocksiggroup
add wave -group $designtopgroup -group $blocksiggroup /apatb_SM3Calc_top/AESL_inst_SM3Calc/ap_start
add wave -group $designtopgroup -group $blocksiggroup /apatb_SM3Calc_top/AESL_inst_SM3Calc/ap_done
add wave -group $designtopgroup -group $blocksiggroup /apatb_SM3Calc_top/AESL_inst_SM3Calc/ap_idle
add wave -group $designtopgroup -group $blocksiggroup /apatb_SM3Calc_top/AESL_inst_SM3Calc/ap_ready
set cinputgroup "C Inputs"
add wave -group $designtopgroup -group $cinputgroup
set message_group message(memory)
add wave -group $designtopgroup -group $cinputgroup -group $message_group
add wave -group $designtopgroup -group $cinputgroup -group $message_group -radix hex /apatb_SM3Calc_top/AESL_inst_SM3Calc/message_address0
add wave -group $designtopgroup -group $cinputgroup -group $message_group -color #ffff00 -radix hex /apatb_SM3Calc_top/AESL_inst_SM3Calc/message_ce0
add wave -group $designtopgroup -group $cinputgroup -group $message_group -radix hex /apatb_SM3Calc_top/AESL_inst_SM3Calc/message_q0
set messageLen_group messageLen(wire)
add wave -group $designtopgroup -group $cinputgroup -group $messageLen_group
add wave -group $designtopgroup -group $cinputgroup -group $messageLen_group -radix hex /apatb_SM3Calc_top/AESL_inst_SM3Calc/messageLen
set coutputgroup "C Outputs"
add wave -group $designtopgroup -group $coutputgroup
set digest_group digest(memory)
add wave -group $designtopgroup -group $coutputgroup -group $digest_group
add wave -group $designtopgroup -group $coutputgroup -group $digest_group -radix hex /apatb_SM3Calc_top/AESL_inst_SM3Calc/digest_address0
add wave -group $designtopgroup -group $coutputgroup -group $digest_group -color #ffff00 -radix hex /apatb_SM3Calc_top/AESL_inst_SM3Calc/digest_ce0
add wave -group $designtopgroup -group $coutputgroup -group $digest_group -color #ffff00 -radix hex /apatb_SM3Calc_top/AESL_inst_SM3Calc/digest_we0
add wave -group $designtopgroup -group $coutputgroup -group $digest_group -radix hex /apatb_SM3Calc_top/AESL_inst_SM3Calc/digest_d0
set testbenchgroup "Test Bench Signals"
add wave -group $testbenchgroup
set tbcinputgroup "C Inputs"
add wave -group $testbenchgroup -group $tbcinputgroup
set tb_message_group message(memory)
add wave -group $testbenchgroup -group $tbcinputgroup -group $tb_message_group
add wave -group $testbenchgroup -group $tbcinputgroup -group $tb_message_group -radix hex /apatb_SM3Calc_top/message_address0
add wave -group $testbenchgroup -group $tbcinputgroup -group $tb_message_group -color #ffff00 -radix hex /apatb_SM3Calc_top/message_ce0
add wave -group $testbenchgroup -group $tbcinputgroup -group $tb_message_group -radix hex /apatb_SM3Calc_top/message_q0
set tb_messageLen_group messageLen(wire)
add wave -group $testbenchgroup -group $tbcinputgroup -group $tb_messageLen_group
add wave -group $testbenchgroup -group $tbcinputgroup -group $tb_messageLen_group -radix hex /apatb_SM3Calc_top/messageLen
set tbcoutputgroup "C Outputs"
add wave -group $testbenchgroup -group $tbcoutputgroup
set tb_digest_group digest(memory)
add wave -group $testbenchgroup -group $tbcoutputgroup -group $tb_digest_group
add wave -group $testbenchgroup -group $tbcoutputgroup -group $tb_digest_group -radix hex /apatb_SM3Calc_top/digest_address0
add wave -group $testbenchgroup -group $tbcoutputgroup -group $tb_digest_group -color #ffff00 -radix hex /apatb_SM3Calc_top/digest_ce0
add wave -group $testbenchgroup -group $tbcoutputgroup -group $tb_digest_group -color #ffff00 -radix hex /apatb_SM3Calc_top/digest_we0
add wave -group $testbenchgroup -group $tbcoutputgroup -group $tb_digest_group -radix hex /apatb_SM3Calc_top/digest_d0
set tbinternalsiggroup "Internal Signals"
add wave -group $testbenchgroup -group $tbinternalsiggroup
set tb_simstatus_group "Simulation Status"
add wave -group $testbenchgroup -group $tbinternalsiggroup -group $tb_simstatus_group
add wave -group $testbenchgroup -group $tbinternalsiggroup -group $tb_simstatus_group -radix hex /apatb_SM3Calc_top/AUTOTB_TRANSACTION_NUM
add wave -group $testbenchgroup -group $tbinternalsiggroup -group $tb_simstatus_group -radix hex /apatb_SM3Calc_top/ready_cnt
add wave -group $testbenchgroup -group $tbinternalsiggroup -group $tb_simstatus_group -radix hex /apatb_SM3Calc_top/done_cnt
set tb_portdepth_group "Port Depth"
add wave -group $testbenchgroup -group $tbinternalsiggroup -group $tb_portdepth_group
add wave -group $testbenchgroup -group $tbinternalsiggroup -group $tb_portdepth_group -radix hex /apatb_SM3Calc_top/LENGTH_message
add wave -group $testbenchgroup -group $tbinternalsiggroup -group $tb_portdepth_group -radix hex /apatb_SM3Calc_top/LENGTH_messageLen
add wave -group $testbenchgroup -group $tbinternalsiggroup -group $tb_portdepth_group -radix hex /apatb_SM3Calc_top/LENGTH_digest
