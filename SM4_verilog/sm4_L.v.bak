module sm4_L (data_in,data_out);
input    [31:0]    data_in;
output   [31:0]    data_out;
reg      [31:0]    data_out;
assign data_out = data_in[31:0] ^ ({data_in[29:0],data_in[31:30]}) 
								 ^ ({data_in[21:0],data_in[31:22]}) 
								 ^ ({data_in[13:0],data_in[31:14]})
								 ^ ({data_in[ 7:0],data_in[31: 8]});	
endmodule
