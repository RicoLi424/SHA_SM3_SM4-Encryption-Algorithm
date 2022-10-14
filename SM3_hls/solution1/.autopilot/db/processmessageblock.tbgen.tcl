set moduleName processmessageblock
set isTopModule 0
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isFreeRunPipelineModule 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {processmessageblock}
set C_modelType { void 0 }
set C_modelArgList {
	{ intermediateHash int 32 regular {array 8 { 2 2 } 1 1 }  }
	{ messageBlock int 32 regular {array 16 { 1 3 } 1 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "intermediateHash", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE"} , 
 	{ "Name" : "messageBlock", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} ]}
# RTL Port declarations: 
set portNum 19
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ intermediateHash_address0 sc_out sc_lv 3 signal 0 } 
	{ intermediateHash_ce0 sc_out sc_logic 1 signal 0 } 
	{ intermediateHash_we0 sc_out sc_logic 1 signal 0 } 
	{ intermediateHash_d0 sc_out sc_lv 32 signal 0 } 
	{ intermediateHash_q0 sc_in sc_lv 32 signal 0 } 
	{ intermediateHash_address1 sc_out sc_lv 3 signal 0 } 
	{ intermediateHash_ce1 sc_out sc_logic 1 signal 0 } 
	{ intermediateHash_we1 sc_out sc_logic 1 signal 0 } 
	{ intermediateHash_d1 sc_out sc_lv 32 signal 0 } 
	{ intermediateHash_q1 sc_in sc_lv 32 signal 0 } 
	{ messageBlock_address0 sc_out sc_lv 4 signal 1 } 
	{ messageBlock_ce0 sc_out sc_logic 1 signal 1 } 
	{ messageBlock_q0 sc_in sc_lv 32 signal 1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "intermediateHash_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "intermediateHash", "role": "address0" }} , 
 	{ "name": "intermediateHash_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "intermediateHash", "role": "ce0" }} , 
 	{ "name": "intermediateHash_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "intermediateHash", "role": "we0" }} , 
 	{ "name": "intermediateHash_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "intermediateHash", "role": "d0" }} , 
 	{ "name": "intermediateHash_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "intermediateHash", "role": "q0" }} , 
 	{ "name": "intermediateHash_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "intermediateHash", "role": "address1" }} , 
 	{ "name": "intermediateHash_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "intermediateHash", "role": "ce1" }} , 
 	{ "name": "intermediateHash_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "intermediateHash", "role": "we1" }} , 
 	{ "name": "intermediateHash_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "intermediateHash", "role": "d1" }} , 
 	{ "name": "intermediateHash_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "intermediateHash", "role": "q1" }} , 
 	{ "name": "messageBlock_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "messageBlock", "role": "address0" }} , 
 	{ "name": "messageBlock_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "messageBlock", "role": "ce0" }} , 
 	{ "name": "messageBlock_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "messageBlock", "role": "q0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2"],
		"CDFG" : "processmessageblock",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "507", "EstimateLatencyMax" : "507",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "intermediateHash", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "messageBlock", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.W_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.W_s_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	processmessageblock {
		intermediateHash {Type IO LastRead 7 FirstWrite 8}
		messageBlock {Type I LastRead 1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "507", "Max" : "507"}
	, {"Name" : "Interval", "Min" : "507", "Max" : "507"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	intermediateHash { ap_memory {  { intermediateHash_address0 mem_address 1 3 }  { intermediateHash_ce0 mem_ce 1 1 }  { intermediateHash_we0 mem_we 1 1 }  { intermediateHash_d0 mem_din 1 32 }  { intermediateHash_q0 mem_dout 0 32 }  { intermediateHash_address1 MemPortADDR2 1 3 }  { intermediateHash_ce1 MemPortCE2 1 1 }  { intermediateHash_we1 MemPortWE2 1 1 }  { intermediateHash_d1 MemPortDIN2 1 32 }  { intermediateHash_q1 MemPortDOUT2 0 32 } } }
	messageBlock { ap_memory {  { messageBlock_address0 mem_address 1 4 }  { messageBlock_ce0 mem_ce 1 1 }  { messageBlock_q0 mem_dout 0 32 } } }
}
