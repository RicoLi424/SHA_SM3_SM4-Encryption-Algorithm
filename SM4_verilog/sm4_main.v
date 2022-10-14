module	sm4_main (
				clk				,  //时钟信号
				rst			   ,  //复位信号
				
				dec_en			,	//加密解密模式判断符号：为0时进行加密操作，为1时进行解密操作
				
				MK0		      ,	//密钥MK的第[127:96]位
				MK1		      ,	//密钥MK的第[95:64位
				MK2		      ,	//密钥MK的第[63:32]位
				MK3		      ,	//密钥MK的第[31:0]位
				
				rki_ready		,	//rki生成完毕标志，为1时生成完毕
				
				X0		         ,	//明（密）文数据的第[127:96]位
				X1		         ,	//明（密）文数据的第[95:64位
				X2		         ,	//明（密）文数据的第[63:32]位
				X3		         ,  //明（密）文数据的第[31:0]位
								
				Y0		         ,	//密（明）文输出的第[127:96]位
				Y1		         ,	//密（明）文输出的第[95:64]位
				Y2		         ,	//密（明）文输出的第[63:32]位
				Y3  		      ,  //密（明）文输出的第[31:0]位
						
				finish				//加（解）密进程完成标志，为1时进程完成
				
			 );


input			clk				;
input			rst			   ;

input			dec_en			;	

input	[31:0]  MK0		;	
input	[31:0]  MK1		;
input	[31:0]  MK2		;
input	[31:0]  MK3		;

input	[31:0]	X0		;	
input	[31:0]	X1		;
input	[31:0]	X2		;
input	[31:0]	X3		;

output	[31:0]	Y0		;	
output	[31:0]	Y1		;
output	[31:0]	Y2		;
output	[31:0]	Y3		;

output	rki_ready		;	
output	finish			;

reg	[5:0]	   cnt	   =6'h0 ;  //计数器，用以计每次迭代运算的32次次数
reg				running	=1'b0	;  //进程判断标识符，为1时表示正在进行中
reg				done		=1'b0	;  //进程结束标识符，为1时表示进程已结束


/*定义常量FKi*/
wire	[31:0]	FK0	;
wire	[31:0]	FK1	;
wire	[31:0]	FK2	;
wire	[31:0]	FK3	;
assign	FK0 = 32'hA3B1BAC6 ;
assign	FK1 = 32'h56AA3350 ;
assign	FK2 = 32'h677D9197 ;
assign	FK3 = 32'hB27022DC ;

/*定义常量CKi*/
wire	   [31:0]	CK    [31:0]	;
assign	CK[ 0] = 32'h00070e15	;
assign	CK[ 1] = 32'h1c232a31	;
assign	CK[ 2] = 32'h383f464d	;
assign	CK[ 3] = 32'h545b6269	;

assign	CK[ 4] = 32'h70777e85	;
assign	CK[ 5] = 32'h8c939aa1	;
assign	CK[ 6] = 32'ha8afb6bd	;
assign	CK[ 7] = 32'hc4cbd2d9	;

assign	CK[ 8] = 32'he0e7eef5	;
assign	CK[ 9] = 32'hfc030a11	;
assign	CK[10] = 32'h181f262d	;
assign	CK[11] = 32'h343b4249	;

assign	CK[12] = 32'h50575e65	;
assign	CK[13] = 32'h6c737a81	;
assign	CK[14] = 32'h888f969d	;
assign	CK[15] = 32'ha4abb2b9	;

assign	CK[16] = 32'hc0c7ced5	;
assign	CK[17] = 32'hdce3eaf1	;
assign	CK[18] = 32'hf8ff060d	;
assign	CK[19] = 32'h141b2229	;

assign	CK[20] = 32'h30373e45	;
assign	CK[21] = 32'h4c535a61	;
assign	CK[22] = 32'h686f767d	;
assign	CK[23] = 32'h848b9299	;

assign	CK[24] = 32'ha0a7aeb5	;
assign	CK[25] = 32'hbcc3cad1	;
assign	CK[26] = 32'hd8dfe6ed	;
assign	CK[27] = 32'hf4fb0209	;

assign	CK[28] = 32'h10171e25	;
assign	CK[29] = 32'h2c333a41	;
assign	CK[30] = 32'h484f565d	;
assign	CK[31] = 32'h646b7279	;


/*计数器设置*/
always @(negedge rst or posedge clk) 
begin  
  if(!rst) begin
  cnt	<= 6'h0	;                   //复位清零
  end
  else if(running) begin
  cnt	<= cnt + 1'b1	;             //当进程进行时，计数器随时钟信号上升沿自加1
  end
  else  begin 
  cnt	<= 6'h0	;                   //当进程出在非运行状态时，cnt始终置0
  end

end


/*running参数设置，判断进程是否在进行中*/
always @(negedge rst or posedge clk) 
begin 
  if(!rst) begin
    running	<= 1'b0	;             //复位置0
  end
  else 
  if (cnt == 6'h1f) begin
    running	<= 1'b0	;             //当恰好完成32次迭代运算后，一次进程结束，running置0
  end  	 
  else begin
    running	<= 1'b1	;             //当迭代运算还未进行满32次时保持程序在运行状态，当cnt=32时将运行状态由0改为1
  end
end


/*done参数设置，判断进程是否已完成*/
always @(negedge rst or posedge clk)
begin  
  if(!rst) begin
    done	<= 1'b0	;                //复位置0
  end
  else if(!running) begin
    done	<= 1'b0	;                //当程序未开始运行 或 一次进程结束，状态由运行转为非运行 时，done始终置0
  end
  else if(cnt >= 6'h1f) begin
    done	<= 1'b1           ;       //当一轮32次迭代结束时，将done置1，表示进程已完成
  end 
end



reg				kgen_en	=1'b1	;	   //进程模式选择标识符，若为0则进行明（密）文数据迭代运算，若为1则进行轮密钥rki生成
                                    //这里置初值为1，表示我们每一轮加密或解密，都是先生成rki再进行明（密）文迭代


/*kgen_en参数设置，判断进程是进行轮密钥rki生成 还是 明（密）文数据迭代运算*/
always @(negedge rst or posedge clk) 
begin  
  if(!rst) begin
    kgen_en		<= 1'b1	;        //复位置1
  end
  else if(done & kgen_en) begin
    kgen_en		<= 1'b0	;        //当轮密钥rki生成进程结束时，将其置0，改为明（密）文迭代进程模式
  end
end



reg				rki_ready =1'b0	;

/*rki_ready参数设置，判断rki生成是否完成*/
always @(negedge rst or posedge clk) 
begin  
  if(!rst) begin
    rki_ready	<= 1'b0	;        //复位置零
  end
  else if(done & kgen_en) begin
    rki_ready	<= 1'b1	;        //当轮密钥rki生成进程结束，置其为1表示rki已准备完毕
  end
  else begin
    rki_ready	<= 1'b0	;        //其他情况下都置其为0
  end
end


reg		[31:0]	rki_buf [0:31]	;   //存放32轮轮密钥rki
reg		[31:0]	rkey	=32'h0	;	 //每一轮轮钥匙（CKi或rki）
wire	   [31:0]	data_round_out	; 	 //每一轮迭代运算生成的新4字节结果


reg		[ 5:0]	j				;

/*设置32组rki的赋值*/
always @(negedge rst or posedge clk) 
begin
  if(!rst) begin
    for(j=0; j<=6'h1f; j=j+1) 
	 rki_buf[j]  <= 32'h0;             //复位时将32组rki全部归零
  end
  else if(kgen_en & running) begin
	rki_buf[cnt] <= data_round_out ;   //当轮密钥rki生成进程正在运行中时，将每一轮迭代运算生成的4字节结果赋给该轮的rki
  end
end


/*设置轮钥匙rkey*/
always @(negedge rst or posedge clk)
begin  
  if(!rst) begin
  rkey  <= 32'h0;                                             //复位归零
  end
  else if(cnt==6'h0 & kgen_en & !running) begin
	rkey  <=  CK[0];                                           //当生成rki时，置其初始的轮钥匙为CK0，即准备开始进行第一轮密钥扩展
  end
  else if(cnt==6'h20 & kgen_en & !running) begin
  rkey  <=  dec_en ? rki_buf[31] : rki_buf[0] ;               //当生成rki结束、准备开始进行明（密）文迭代运算使能时，若为加密则置初始轮钥匙为rk0，若为解密则置为rk31
  end
  else if((cnt<6'h1f) & !kgen_en & running) begin
	rkey  <=  dec_en ? rki_buf[6'h1e - cnt] : rki_buf[cnt+1];  //当正在运行明（密）文迭代运算进程时，若为加密置该轮轮钥匙为rk[cnt+1]，若为解密置其为rk[31-(cnt+1)]
  end
  else if((cnt<6'h1f) &  kgen_en & running) begin             
	rkey  <=  CK[cnt+1] ;                                      //当正在运行生成rki进程时，置该轮轮钥匙为CK[cnt+1]
  end
  else begin
	rkey  <=  32'h0;                                           //否则置其为0
  end
end


/*每轮迭代运算的四组4字节输入*/
reg		[31:0]	data_in_0	;
reg		[31:0]	data_in_1	;
reg		[31:0]	data_in_2	;
reg		[31:0]	data_in_3	;

/*每轮4字节变化时所用的中间转化量，类似于状态机*/
wire	[31:0]	data_in_0_next;
wire	[31:0]	data_in_1_next;
wire	[31:0]	data_in_2_next;
wire	[31:0]	data_in_3_next;


/*对生成rki或明（密）文加密过程赋值*/
always @(negedge rst or posedge clk) 
begin  
  if(!rst) begin
	data_in_0   <=  32'h0;
	data_in_1   <=  32'h0;
	data_in_2   <=  32'h0;
	data_in_3   <=  32'h0;                  //复位置零
  end
  else if(kgen_en & cnt==6'h0 & !running) begin
	data_in_0   <=  MK0 ^ FK0 ;
	data_in_1   <=  MK1 ^ FK1 ;
	data_in_2   <=  MK2 ^ FK2 ;    
	data_in_3   <=  MK3 ^ FK3 ;             //如果是生成rki过程且进程正准备开始进行中，则令初始的四组数据K0~K3为MKi^FKi
  end
  else if(kgen_en & cnt==6'h20 & !running) begin
	data_in_0   <=  X0 ;
	data_in_1   <=  X1 ;
	data_in_2   <=  X2 ;
	data_in_3   <=  X3 ;                    //如果是生成rki进程结束、正准备开始进行明（密）文迭代进程，则令输入迭代运算的四组初始数据为四组4字节明（密）文X0~X3
  end
  else if((cnt<6'h1f) & running) begin
	data_in_0   <=  data_in_0_next ;
	data_in_1   <=  data_in_1_next ;
	data_in_2   <=  data_in_2_next ;
	data_in_3   <=  data_in_3_next ;         //当进程开始后，利用状态机转变每一轮迭代运算的4组数据输入
  end
  else begin
  	data_in_0   <=  32'h0;
	data_in_1   <=  32'h0;
	data_in_2   <=  32'h0;
	data_in_3   <=  32'h0; 
  end
end  

/*Xi~X[i+3]状态机设置*/
assign	data_in_0_next = data_in_1	;
assign	data_in_1_next = data_in_2	;
assign	data_in_2_next = data_in_3	;
assign	data_in_3_next = data_round_out	; //实现Xi，X[i+1],X[i+2],X[i+3]转为X[i+1],X[i+2],X[i+3]，X[i+4]（为该轮迭代运算产生的新4字节结果）

/*调用设计好的round模块，实现迭代运算*/
sm4_round u_sm4_round (
				.kgen_en		   (kgen_en		),	
				.x0_in			(data_in_0		),
				.x1_in			(data_in_1		),
				.x2_in			(data_in_2		),
				.x3_in			(data_in_3		),
				.rkey_in		   (rkey			),
				.x4_out			(data_round_out	)
		);


reg		[31:0]	Y0	= 32'h0;
reg		[31:0]	Y1	= 32'h0;
reg		[31:0]	Y2	= 32'h0;
reg		[31:0]	Y3	= 32'h0;

reg			finish =1'b0	;

wire			done_pre 	   ;                   //明（密）文迭代进程的32轮迭代结束标志

assign	done_pre = (cnt==6'h1f)  & !kgen_en;  //当明（密）文迭代进程的32轮迭代结束时，结束标志为1
 
always @(posedge clk) finish <=  done_pre;     //整套加（解）密结束、密（明）文输出完成标志在数据输出完成的同时置1

always @(negedge rst or posedge clk)
begin 
  if(!rst) begin
    Y0 <=  32'h0;
    Y1 <=  32'h0;
    Y2 <=  32'h0;
    Y3 <=  32'h0;             //复位置零
  end
  else if(done_pre) begin
	Y0 <=  data_in_3_next;
	Y1 <=  data_in_2_next;
	Y2 <=  data_in_1_next;
	Y3 <=  data_in_0_next;     //当明（密）文32轮迭代运算完成后，输出密（明）文Y0,Y1,Y2,Y3为最后一轮迭代运算结果的倒置X32,X33,X34,X35
  end	
end
endmodule

