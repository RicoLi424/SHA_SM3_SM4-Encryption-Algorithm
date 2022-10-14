# SHA_SM3_SM4-Encryption-Algorithm
_SM4_C：_SM4 Encryption module with C , designed in the same idea with verilog  
SM4_verilog：SM4 Encryption module with verilog , packaged as a minimun IP with input of 128 bits. You need to reuse the IP if input has bits more than 128.
SM3_verilog：SM3 Encryption module with verilog, with no input bitwidth restriction,but the default input bits set is 256 bits. You need to reset the 'massagelen' value for other bitwise settings
SM3_C：SM4 Encryption module with C , input bitwidth settings same with verilog
RV32_SM3：a packaged module enabling switches between SM3 and SHA encrytion in higher effiency and less space usage
SM3_hls：developed from SM3_C to HLS format to implant the encrytion function into Xilinx FPGA
