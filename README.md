# SHA_SM3_SM4-Encryption-Algorithm
* _**SM4**_  
      * _**SM4_C：**_ `SM4` Encryption module with `C` , designed in the same idea with verilog  
      * _**SM4_verilog：**_ `SM4` Encryption module with `verilog` , packaged as a `minimun IP` with input of `128 bits`. You need to reuse the IP if input has bits more than 128  
* _**SM3**_  
      * _**SM3_verilog：**_ `SM3` Encryption module with `verilog`, with no input bitwidth restriction,but the default input bits set is `256 bits`. You need to reset the `'massagelen'` value for other bitwise settings  
      * **_SM3_C：**_ `SM4` Encryption module with `C` , input bitwidth settings same with verilog  
      * **_SM3_hls：**_ developed from `SM3_C` to `HLS` format to implant the encrytion function into `Xilinx FPGA`   
* **_RV32_SM3：**_ a packaged module enabling `switches` between `SM3` and `SHA` encrytion in higher effiency and less space usage  

