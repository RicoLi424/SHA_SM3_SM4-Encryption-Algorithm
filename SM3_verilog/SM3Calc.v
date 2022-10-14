module SM3Calc(CLK,RST,ENABLE,message,messageLen,digest);

    input                  CLK;       //输入变量：时钟信号
	 input                  RST;       //输入变量：低电平有效，异步复位信号
	 input                  ENABLE;    //输入变量：高电平有效使能信号
	 
	 input  [255:0]         message;   //输入变量：消息（该程序只考虑消息最大长度为2**8-8=248比特,且长度可以被8整除的情况）
	 input  [7:0]           messageLen;//输入变量：消息长度
//  input  [511:0]         message;   //输入变量：消息（该程序只考虑消息最大长度为2**9-8=504比特,且长度可以被8整除的情况）
//  input  [8:0]           messageLen;//输入变量：消息长度
    output [255:0]         digest;    //输出变量：摘要

    wire                   CLK;
	 wire                   RST;
	 wire                   ENABLE;
	 wire   [255:0]         message;
    wire   [7:0]           messageLen;
//  wire   [511:0]         message;
//  wire   [8:0]           messageLen;
    reg    [255:0]         digest;

	 reg                    rst;       //处理模块的复位信号
	 reg                    enable;    //处理模块的使能信号
    reg    [511:0]         messageBlock;//处理模块的输入，即待处理消息块
	 reg    [255:0]         V_i;       //处理模块的输入
	 wire   [255:0]         V_o;       //处理模块的输出，一次压缩所得的结果
	 
	 wire   [7:0]           remainder; //余数，即消息长度对512取余数所得的结果，用于判断需要压缩的次数

    reg    [7:0]           j;
	 
//	 integer j;//整数j，用于表示循环次数
	 
	 //处理模块的例化
	 SM3ProcessMessageBlock SM3ProcessMessageBlock_0(
	                                                 .clk(CLK),
													             .rst(rst),
													             .enable(enable),
													             .messageBlock(messageBlock),
													             .V_i(V_i),
													             .V_o(V_o)
													             );
	 //常数，用于确定压缩器的初态
	 parameter IV = 256'h7380166F_4914B2B9_172442D7_DA8A0600_A96F30BC_163138AA_E38DEE4D_B0FB0E4E;
	 //一个字节的字符串，用于添加在输入的消息末尾
	 parameter char = 8'b1000_0000;
	
	 //对消息长度除512取余数，在此程序中余数即为消息长度
	 assign remainder = messageLen % 10'd512;
	
    always@(posedge CLK or negedge RST)
	 begin
	     if(!RST)
		  begin//复位有效时回归默认状态，输出为零，处理模块停止工作
		      digest = 256'd0;
				
				j = 8'd0;
				rst = 1'b0;
				enable = 1'd0;
				messageBlock = 512'd0;
				V_i = IV;
		  end
		  else if(!ENABLE)//使能无效时，暂停工作
		  begin
		      digest = digest;
				
				j = j;
				rst = rst;
				enable = 1'b0;
				messageBlock = messageBlock;
				V_i = V_i;
		  end
		  else
		  begin//电路正常工作
				messageBlock = (message << (512-remainder)); //将消息放在消息块左端。原始消息高位为补齐长度的零，左移后无意义的零被抹去，而右端添上了一串零
				messageBlock[(511-remainder)-:8] = char;		//为消息末尾的一个字节赋值1000_0000 
				
				V_i = IV;//确定压缩器初态
				
		      if(remainder <= 9'd440)
				begin
				    //若消息长度能被放入待处理消息块中
				    messageBlock[7:0] = messageLen;//将消息长度放在待处理消息块末端
					 
					 case(j)
					     8'd0:
						  begin
						      rst = 1'b0;
								j = j + 8'd1;
						  end
						  8'd1,8'd2,8'd3,8'd4,8'd5,8'd6,8'd7,8'd8,8'd9,8'd10,8'd11,8'd12,8'd13,8'd14,8'd15,
						  8'd16,8'd17,8'd18,8'd19,8'd20,8'd21,8'd22,8'd23,8'd24,8'd25,8'd26,8'd27,8'd28,8'd29,8'd30,
						  8'd31,8'd32,8'd33,8'd34,8'd35,8'd36,8'd37,8'd38,8'd39,8'd40,8'd41,8'd42,8'd43,8'd44,8'd45,
						  8'd46,8'd47,8'd48,8'd49,8'd50,8'd51,8'd52,8'd53,8'd54,8'd55,8'd56,8'd57,8'd58,8'd59,8'd60,
						  8'd61,8'd62,8'd63,8'd64,8'd65,8'd66,8'd67:
						  begin
						      rst = 1'b1;
						      enable = 1'b1;
								digest = V_o;
						      j = j + 8'd1;
						  end
						  8'd68:
						  begin
						      rst = 1'b1;     //压缩器输出即为摘要
								enable = 1'b1;
						      digest = V_o;
								j = j + 8'd1;
						  end
						  default:
						  begin
						      j = j;
						  end
					 endcase 
					 /*
					 for(j = 8'd0;j <= 8'd66;j = j + 8'd1)//处理消息
				    begin
					     if(j == 8'd0)
					     begin
						      rst = 1'b0;     //压缩器复位
					     end
					     else if(j <= 8'd65) //65个clk
					     begin
					         rst = 1'b1;     //开始压缩
						      enable = 1'b1;
					     end
					     else
					     begin
					         rst = 1'b1;     //压缩器输出即为摘要
								enable = 1'b1;
						      digest = V_o;
					     end
				    end
					 
					 */
				end
				else
				begin
				    //消息长度不能被直接放入待处理消息块中
					 
					 case(j)
					     8'd0:
						  begin
						      rst = 1'b0;
								j = j + 8'd1;
						  end
						  8'd1,8'd2,8'd3,8'd4,8'd5,8'd6,8'd7,8'd8,8'd9,8'd10,8'd11,8'd12,8'd13,8'd14,8'd15,
						  8'd16,8'd17,8'd18,8'd19,8'd20,8'd21,8'd22,8'd23,8'd24,8'd25,8'd26,8'd27,8'd28,8'd29,8'd30,
						  8'd31,8'd32,8'd33,8'd34,8'd35,8'd36,8'd37,8'd38,8'd39,8'd40,8'd41,8'd42,8'd43,8'd44,8'd45,
						  8'd46,8'd47,8'd48,8'd49,8'd50,8'd51,8'd52,8'd53,8'd54,8'd55,8'd56,8'd57,8'd58,8'd59,8'd60,
						  8'd61,8'd62,8'd63,8'd64,8'd65,8'd66,8'd67:
						  begin
						      rst = 1'b1;
						      enable = 1'b1;
						      j = j + 8'd1;
						  end
						  8'd68:
						  begin
						      rst = 1'b1;     
								enable = 1'b0;
								//更新V_i
						      V_i = V_o;                      //压缩器输出即为下一次压缩的输入
								//更新消息块中的内容
								messageBlock = 512'd0;          //先将消息块用零填满
					         messageBlock[7:0] = messageLen; //再将消息长度放在待处理消息块末端
								
								j = j + 8'd1;
						  end
						  8'd69:
						  begin
						      rst = 1'b0;     
								enable = 1'b0;
						     	j = j + 8'd1;
						  end
						  8'd70,8'd71,8'd72,8'd73,8'd74,8'd75,8'd76,8'd77,8'd78,8'd79,8'd80,8'd81,8'd82,
						  8'd83,8'd84,8'd85,8'd86,8'd87,8'd88,8'd89,8'd90,8'd91,8'd92,8'd93,8'd94,8'd95,8'd96,8'd97,
						  8'd98,8'd99,8'd100,8'd101,8'd102,8'd103,8'd104,8'd105,8'd106,8'd107,8'd108,8'd109,8'd110,
						  8'd111,8'd112,8'd113,8'd114,8'd115,8'd116,8'd117,8'd118,8'd119,8'd120,8'd121,8'd122,8'd123,
						  8'd124,8'd125,8'd126,8'd127,8'd128,8'd129,8'd130,8'd131,8'd132,8'd133,8'd134:
                    begin
                        rst = 1'b1;     
								enable = 1'b1;
						     	j = j + 8'd1;
                    end
                    8'd135:
                    begin
						      rst = 1'b1;     //压缩器输出即为摘要
								enable = 1'b1;
						      digest = V_o;
								j = j + 8'd1;
						  end						  
						  default:
						  begin
						      j = j;
						  end
					 endcase
					 /*
				    for(j = 8'd0;j <= 8'd66;j = j + 8'd1)//先处理消息和字符串10……00组成的第一个消息块
				    begin
					     if(j == 8'd0)       
					     begin
					         rst = 1'b0;     //压缩器复位
					     end
					     else if(j <= 8'd65)
					     begin
					         rst = 1'b1;     //开始压缩
						      enable = 1'b1;
					     end
					     else
					     begin
					         rst = 1'b1;     //压缩器输出即为下一次压缩时的输入V_i
								enable = 1'b1;
						      V_i = V_o;
					     end
				    end
					 
					 
				    //更新消息块中的内容
					 messageBlock = 512'd0;          //先将消息块用零填满
					 messageBlock[7:0] = messageLen; //再将消息长度放在待处理消息块末端
					 //处理第二个消息块
					 
					 
				    for(j = 8'd0;j <= 8'd66;j = j + 8'd1)
				    begin
					     if(j == 8'd0)
					     begin
						      rst = 1'b0;     //压缩器复位
					     end
					     else if(j <= 8'd65)
					     begin
					         rst = 1'b1;     //压缩器工作
						      enable = 1'b1;
					     end
					     else
					     begin
					         rst = 1'b1;     //压缩器输出即为摘要
								enable = 1'b1;
						      digest = V_o;
						  end
					 end
					*/ 
				end
		  end
	 end

endmodule
