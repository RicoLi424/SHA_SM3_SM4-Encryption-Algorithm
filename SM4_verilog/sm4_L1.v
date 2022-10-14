module sm4_L1 (data_in,data_out);
input    [31:0]    data_in;
output   [31:0]    data_out;
reg      [31:0]    data_out;
assign data_out = data_in[31:0] ^ ({data_in[18:0],data_in[31:19]}) 
								 ^ ({data_in[ 8:0],data_in[31: 9]});	
endmodule
