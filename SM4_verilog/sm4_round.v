module	sm4_round ( kgen_en,x0_in,x1_in,x2_in,x3_in,rkey_in,x4_out );

/*判断条件标识符，若为1则进行rki生成（此时进行L'），若为0则进行明（密）文数据迭代运算（此时进行L）*/
input			kgen_en			;	

/*四组4字节的输入X0,X1,X2,X3*/
input	[ 31:0]	x0_in			;  
input	[ 31:0]	x1_in			;
input	[ 31:0]	x2_in			;
input	[ 31:0]	x3_in			;

/*32位的轮钥匙（rki或CKi）*/
input	[ 31:0]	rkey_in	   ;

/*一轮迭代运算得到的新4字节X4*/
output	[ 31:0]	x4_out			;	

/*中间变量，T（T'）函数的输入值即τ函数的输入值*/
wire	[ 31:0]	x0_s0 			;

/*中间变量，L函数的输入值*/
wire	[ 31:0]	x0_s1 			;

/*T（T'）函数的输出值*/
wire	[ 31:0]	x0_s2 			;

/*四组8位的Sbox的输入值a0、a1、a2、a3*/
wire	[  7:0]	x00_sr  		;
wire	[  7:0]	x01_sr  		;
wire	[  7:0]	x02_sr  		;
wire	[  7:0]	x03_sr  		;

/*四组8位的Sbox的输出值b0、b1、b2、b3*/
wire	[  7:0]	x00_Sbox		;
wire	[  7:0]	x01_Sbox		;
wire	[  7:0]	x02_Sbox		;
wire	[  7:0]	x03_Sbox		;


/*L变化L(B)=B^(B<<<2)^(B<<<10)^(B<<<18)^(B<<<24)*/
function [31:0] trans_l_data;
	input  [31:0] data_in;
	trans_l_data  = data_in[31:0] ^ ({data_in[29:0],data_in[31:30]}) 
								 ^ ({data_in[21:0],data_in[31:22]}) 
								 ^ ({data_in[13:0],data_in[31:14]})
								 ^ ({data_in[ 7:0],data_in[31: 8]});	
endfunction


/*L'变化L'(B)=B^(B<<<13)^(B<<<23)*/
function [31:0] trans_l_key;
	input  [31:0] data_in;
	trans_l_key  = data_in[31:0] ^ ({data_in[18:0],data_in[31:19]}) 
								 ^ ({data_in[ 8:0],data_in[31: 9]});	
endfunction


/*T(T')函数的输入量X1 ^ X2 ^ X3 ^ RK*/ 
assign	x0_s0  = x1_in ^ x2_in ^ x3_in ^ rkey_in;

/*将32位的T(T')函数输入量拆分成4组8位的Sbox输入量*/
assign	x00_sr = x0_s0[31:24];
assign	x01_sr = x0_s0[23:16];
assign	x02_sr = x0_s0[15: 8];
assign	x03_sr = x0_s0[ 7: 0];

/*进行四组Sbox变化*/
sm4_Sbox u0 (.data_in (x00_sr	),	.data_out (x00_Sbox	));
sm4_Sbox u1 (.data_in (x01_sr	),	.data_out (x01_Sbox	));
sm4_Sbox u2 (.data_in (x02_sr	),	.data_out (x02_Sbox	));
sm4_Sbox u3 (.data_in (x03_sr	),	.data_out (x03_Sbox	));

/*将四组8位的Sbox输出值合并为一个32位的中间变量，作为L(L')变化的输入量*/
assign	x0_s1 = {x00_Sbox,x01_Sbox,x02_Sbox,x03_Sbox};

/*若kgen_en=1,将x0_s1作为输入进行L'变化；若kgen_en=0,将x0_s1作为输入进行L变化*/
assign x0_s2 = kgen_en ? trans_l_key(x0_s1) : trans_l_data(x0_s1) ;

/*一轮迭代运算后得到一个新的4字节数据*/
assign	x4_out = x0_s2 ^ x0_in ;

endmodule
