#include "sm4.h"

//4字节无符号数组转无符号long型
void four_uCh2uLong(u8 *in, u32 *out)
{
	//对i赋初值，将*out所有位置零使方便用异或操作对其进行数据载入
	int i = 0;
	*out = 0;

	//利用移位将四个字节的数据分别移至不同位段，并将数据载入*out的对应部分
	for (i = 0; i < 4; i++)
		*out = ((u32)in[i] << (24 - i * 8)) ^ *out;
}

//无符号long型转4字节无符号数组
void uLong2four_uCh(u32 in, u8 *out)
{
	//给i赋初值
	int i = 0;
	//从32位unsigned long的高位开始取，每8位一组移至低位后分别赋给四组*out
	for (i = 0; i < 4; i++)
		*(out + i) = (u32)(in >> (24 - i * 8));
}

//循环左移函数，保留丢弃位放置尾部
u32 leftrotate(u32 data, int length)
{
    u32 result= 0;
	/*
	将data中我们需要的长度为length的低位有效位移至高位，
	将丢弃的长度为（32-length）的高位部分移至低位，
	两者通过异或操作实现倒置拼接并将数据载入result
	*/
	result = (data << length) ^ (data >> (32 - length));
    return result;
}


//非线性变化τ，输入数据通过4个并行的S盒进行数据替换
u32 func_tao(u32 input)
{
	int i = 0;

	//T函数的最终输出量赋初值
	u32 taout = 0;

	//SBOX的索引列表，即τ函数的输入数组（a0,a1,a2,a3）∈（Z28）4
	u8 ucIndexList[4] = { 0 };

	//SBOX索引得到的参数值，即τ函数的输出数组（SBOX（a0），SBOX（a1），SBOX（a2），SBOX（a3））
	u8 ucSBOXValueList[4] = { 0 };

	/*
	由于T函数的输入值，即τ函数的输入值，
	为 Xi+1 XOR Xi+2 XOR Xi+3 XOR rki，
	这是一个32位的数据，而SBOX的索引列表应为四个8位数据构成的数组，
	所以先将输入转为四个字节
	*/
	uLong2four_uCh(input, ucIndexList);

	//通过索引得到对应的四组SBOX输出值（若输入为EF，则输出SBOX第E行第F列的数值）从而得到τ函数的输出数组
	for (i = 0; i < 4; i++)
	{
		ucSBOXValueList[i] = SBOX[ucIndexList[i]];
	}

	//将τ函数输出数组的四个8位数据合并成32位数据
	four_uCh2uLong(ucSBOXValueList, &taout);
	
	return taout;
}



//线性变换L，L(B)=B XOR (B<<<2) XOR (B<<<10) XOR (B<<<18) XOR (B<<<24)
u32 func_L(u32 input)
{
	u32 Lout = 0;
	Lout = input ^ leftrotate(input, 2) ^ leftrotate(input, 10) ^ leftrotate(input, 18) ^ leftrotate(input, 24);

	return Lout;
}


//线性变化L',L’(B)=B XOR (B<<<13) XOR (B<<<23)  */
u32 func_Lp(u32 input)
{
	u32 Lpout = 0;
	Lpout = input ^ leftrotate(input, 13) ^ leftrotate(input, 23);

	return Lpout;
}

//迭代函数round，用于进行明（密）文迭代或生成轮密钥
u32 round(int kgen_en,u32 RoundIn)
{
    u32 RoundOut = 0;
    u32 taout = 0;
	
	//首先统一进行τ变化
	taout = func_tao(RoundIn);
	
	//判断标识kgen_en=0时进行明（密）文迭代，此时进行的是L变化
	if (kgen_en==0)
	{
		RoundOut =func_L(taout);
	}
	//判断标识kgen_en=1时进行轮密钥生成，此时进行的是L'变化
	else if(kgen_en==1)
	{
		RoundOut =func_Lp(taout);
	}
	return RoundOut;
}


//加密函数，可以加密任意长度数据，16字节为一次循环，不足部分补0凑齐16字节的整数倍
//dec_en:加解密判断标识，0为加密，1为解密 kgen_en：迭代模式选择标识符，0为明（密）文迭代，1为生成轮密钥 key:密钥（16字节） input:输入的原始数据 output:加密后输出数据
void SM4_IP(int dec_en,int kgen_en,u8 *key, u8 *input, u8 *output)
{
	int i = 0;
	/*定义一个50字节缓存区
	  C 库函数 void *malloc(size_t size) 分配所需的内存空间，并返回一个指向它的指针*/
	u8 *p = (u8 *)malloc(50);

    //用于存放密钥
	u32 MK[4] = { 0 };

	//用于存放Ki的值
	u32 K[36] = { 0 };

	//用于存放迭代过程的初始数据及每轮迭代新生成的4字节数据
	u32 X[36] = { 0 };




	/***************************开始生成轮秘钥rki********************************/

	//将16字节的密钥MK=（MK0,MK1,MK2,MK3）中的四组4字节数据分别转为四组u32数据进行存放
	four_uCh2uLong(key, &(MK[0]));
	four_uCh2uLong(key + 4, &(MK[1]));
	four_uCh2uLong(key + 8, &(MK[2]));
	four_uCh2uLong(key + 12, &(MK[3]));

	/*
	K0=MK0 XOR FK0；

    K1=MK1 XOR FK1；

    K2=MK2 XOR FK2；

    K3=MK3 XOR FK3。
	*/
	K[0] = MK[0] ^ FK[0];
	K[1] = MK[1] ^ FK[1];
	K[2] = MK[2] ^ FK[2];
	K[3] = MK[3] ^ FK[3];

	/*
	32次循环迭代运算生成rk0~rk31
	轮密钥生成方法为rki=K[i+4]=Ki XOR T’(K[i+1] XOR K[i+2] XOR K[i+3] XOR CKi)(i=0,1,2,···,31)
	*/
	for (i = 0; i < 32; i++)
	{
		K[i + 4] = K[i] ^ round(kgen_en,(K[i + 1] ^ K[i + 2] ^ K[i + 3] ^ CK[i]));
		if (i==31)
		{
			kgen_en=0;
		}
	}

	/***************************生成轮秘钥rki结束**********************************/



    //将输入的明（密）文数据存放在p缓存区
	for (i = 0; i < 16; i++)
		*(p + i) = *(input + i);

	//开始处理加（解）密数据,得到X0~X3的u32数据
	four_uCh2uLong(p , &(X[0]));
	four_uCh2uLong(p + 4, &(X[1]));
	four_uCh2uLong(p + 8, &(X[2]));
	four_uCh2uLong(p + 12, &(X[3]));

	/*
	加（解）密过程，执行32次迭代运算得到X4~X35的u32数据
	Xi+4=F(Xi,Xi+1,Xi+2,Xi+3,rki)=Xi XOR T(Xi+1 XOR Xi+2 XOR Xi+3 XOR rki（若为解密，则为rk[31-i]）),i=0,1,···31
	*/
	for (i = 0; i < 32; i++)
	{
		  if(dec_en==0)
		  {
			X[i + 4] = X[i] ^ round(kgen_en,X[i + 1] ^ X[i + 2] ^ X[i + 3] ^ K[i + 4]);
		  }
          else if(dec_en==1)
          {
            X[i + 4] = X[i] ^ round(kgen_en,X[i + 1] ^ X[i + 2] ^ X[i + 3] ^ K[35 - i]);
          }
	}

	/*
	将加（解）密后数据输出为四字节
	对最后一轮数据进行反序变换并得到密（明）文输出：
    (Y0,Y1,Y2,Y3)=R(X32,X33,X34,X35)=(X35,X34,X33,X32)
	*/
	uLong2four_uCh(X[35], output );
	uLong2four_uCh(X[34], output + 4);
	uLong2four_uCh(X[33], output + 8);
	uLong2four_uCh(X[32], output + 12);


	//free函数通常与malloc在一起使用，用于释放malloc函数分配的内存空间。
	free(p);
}



//主函数，在其中实现16字节数据加密或解密
int main(void)
{
	u8 i;
	int kgen_en = 1;
    int dec_en = 0;
	//定义加（解）密输出缓存区
	u8 SM4_Result[50] = { 0 };

	//定义16字节的密钥
	u8 key[16] = { 0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10 };

	//定义16字节的原始输入数据（测试用）
	u8 Data_plain[16] = { 0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10};

    //数据加（解）密
	SM4_IP(dec_en,kgen_en,key, Data_plain, SM4_Result);

    //打印加（解）密后数据
    if (dec_en==0)
    {
        printf("加密后数据是：\n");
    }
	else if(dec_en==1)
    {
        printf("解密后数据是：\n");
    }
	for (i = 0; i < 16 ; i++)
		printf("%x ", *(SM4_Result + i));

	//执行系统环境中的pause命令，冻结屏幕，用户按任意键结束
	system("pause");

	return 0;
}
