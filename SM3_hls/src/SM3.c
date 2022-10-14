#include <stdio.h>      //包含标准库
#include "SM3.h"
#include <ap_cint.h>

/*
* 定义向左循环移位函数LeftRotate(word, bits)
* 将word左移bits比特
*/
uint32_t LeftRotate(uint32_t X, uint6_t i)
{
	if (i >= 0 && i <= 32)
		return ( ( X << i ) | ( X >> (32 - i) ) );
	else if (i >= 33 && i <= 63)
		return ( (X << (i - 32) ) | ( X >> (64 - i) ) );
	else
		return 0;
}

/*
* 定义无符号整型常量T(i)
* 根据i的值所属区间为T赋值
* 若i >= 0 且 i <= 15，则T为0x79CC4519(十六进制三十二比特)
* 若i >= 16 且 i <= 63，则T为0x7A879D8A(十六进制三十二比特)
* 此外，T为0
*/
uint32_t T(uint7_t i)
{
	if (i >= 0 && i <= 15)
		return 0x79CC4519;
	else if (i >= 16 && i <= 63)
		return 0x7A879D8A;
	else
		return 0;
}

/*
* 定义布尔函数FF(i)，无符号整型
* 根据i的值所属区间返回不同的函数值
* 若i >= 0 且 i <= 15，则FF = X ^ Y ^ Z（^表示异或）
* 若i >= 16 且 i <= 63,则FF = (X & Y) | (X & Z) | (Y & Z)
*/
uint32_t FF(uint32_t X, uint32_t Y, uint32_t Z, uint7_t i)
{
	if (i >= 0 && i <= 15)
		return X ^ Y ^ Z;
	else if (i >= 16 && i <= 63)
		return (X & Y) | (X & Z) | (Y & Z);
	else
		return 0;
}

/*
* 定义布尔函数GG(i)，无符号整型
* 根据i的值所属区间返回不同的函数值
* 若i >= 0 且 i <= 15，则GG = X ^ Y ^ Z
* 若i >= 16 且 i <= 63,则GG = (X & Y) | (~X & Z)
*/
uint32_t GG(uint32_t X, uint32_t Y, uint32_t Z, uint7_t i)
{
	if (i >= 0 && i <= 15)
		return X ^ Y ^ Z;
	else if (i >= 16 && i <= 63)
		return (X & Y) | (~X & Z);
	else
		return 0;
}

/*
* 定义置换函数P0(X)
* P0 = X ^ LeftRotate(X, 9) ^ LeftRotate(X, 17)
* 其中LeftRotate(X, 9)表示X向左循环位移9比特的结果
*/
uint32_t P0(uint32_t X)
{
	return X ^ LeftRotate(X, 9) ^ LeftRotate(X, 17);
}

/*
* 定义置换函数P1(X)
* P0 = X ^ LeftRotate(X, 15) ^ LeftRotate(X, 23)
* 其中LeftRotate(X, 15)表示X向左循环位移15比特的结果
*/
uint32_t P1(uint32_t X)   //置换函数P1
{
	return X ^ LeftRotate(X, 15) ^ LeftRotate(X, 23);
}

void initial(uint32_t X[8])
{
    X[0] = 0x7380166F;
    X[1] = 0x4914B2B9;
    X[2] = 0x172442D7;
    X[3] = 0xDA8A0600;
    X[4] = 0xA96F30BC;
    X[5] = 0x163138AA;
    X[6] = 0xE38DEE4D;
    X[7] = 0xB0FB0E4E;
}
/*
* 定义处理消息块test函数
*/

void processmessageblock(uint32_t intermediateHash[8], uint32_t messageBlock[16])
{
	uint7_t i;
	uint32_t W[68];                                       //数组W
	uint32_t W_[64];                                      //数组W_
	uint32_t A, B, C, D, E, F, G, H;                      //A, B, C, D, E, F, G, H为字寄存器
	uint32_t SS1, SS2, TT1, TT2;                          //SS1, SS2, TT1, TT2为中间变量


	/* 消息扩展	*/

	/*
	* 为W[0]-W[15]赋值
	* i从0到15依次自增
	* 每循环一次便将context(上下文)所指向的结构体中包含的
	* 数据项messageBlock(消息块)中的数据(共64个字节)四个字节赋给W[i]
	* 若检测到字的存储格式为小端存储，则反转字符顺序
	*/
	for (i = 0; i < 16; i++)
	{
		W[15 - i] = messageBlock[i];
		//printf("%d: %08x\n", (unsigned int)i, (unsigned int)W[i]);
	}
	/*
	* 生成W[16]-W[67]
	* i从16到67依次自增
    * 每循环一次便为W[i]赋值P1(W[i - 16] ^ W[i - 9] ^ LeftRotate(W[i - 3], 15))
			                ^ LeftRotate(W[i - 13], 7)
			                ^ W[i - 6];
	*/

	for (i = 16; i < 68; i++)
	{
		W[i] = P1(W[i - 16] ^ W[i - 9] ^ LeftRotate(W[i - 3], 15))
			^ LeftRotate(W[i - 13], 7)
			^ W[i - 6];
		//printf("%d: %08x\n", (unsigned int)i, (unsigned int)W[i]);
	}

    /*
	* 生成W_[16]-W_[63]
	* i从16到63依次自增
    * 每循环一次便为W_[i]赋值W[i] ^ W[i + 4];
	*/

	for (i = 0; i < 64; i++)
	{
		W_[i] = W[i] ^ W[i + 4];
		//printf("%d: %08x\n", (unsigned int)i, (unsigned int)W_[i]);
	}

	/* 消息压缩 */

	//为八个字寄存器赋初始值
	A = intermediateHash[0];
	B = intermediateHash[1];
	C = intermediateHash[2];
	D = intermediateHash[3];
	E = intermediateHash[4];
	F = intermediateHash[5];
	G = intermediateHash[6];
	H = intermediateHash[7];

	//压缩过程
	for (i = 0; i < 64; i++)
	{
		//对ABCDEFGH中存储的八组数据进行逻辑运算

        //中间变量用于暂存数据
		SS1 = LeftRotate((LeftRotate(A, 12) + E + LeftRotate(T(i), i)), 7);
		SS2 = SS1 ^ LeftRotate(A, 12);
		TT1 = FF(A, B, C, i) + D + SS2 + W_[i];
		TT2 = GG(E, F, G, i) + H + SS1 + W[i];
		//一轮运算后寄存器中存储新的数据
		D = C;
		C = LeftRotate(B, 9);
		B = A;
		A = TT1;
		H = G;
		G = LeftRotate(F, 19);
		F = E;
		E = P0(TT2);

	}

	//按位异或后再赋值

	intermediateHash[0] ^= A;
	intermediateHash[1] ^= B;
	intermediateHash[2] ^= C;
	intermediateHash[3] ^= D;
	intermediateHash[4] ^= E;
	intermediateHash[5] ^= F;
	intermediateHash[6] ^= G;
	intermediateHash[7] ^= H;
}

void SM3Calc(uint8_t message[32], uint8_t messageLen, uint32_t digest[8])
{
	uint512_t pack;
	uint32_t  messageBlock[16];
	uint32_t  intermediateHash[8];
	uint6_t   i;

	//消息块初始值为零
	pack = 0;

	for (i = 0; i < 32; i++)
	{
		pack = apint_set_range(pack, i * 8 + 7, i * 8, message[i]);
		//printf("2:%0128x\n",(unsigned int)pack);
	}

	pack = pack << ( 512 - messageLen );

	pack = apint_set_bit(pack, 511 - messageLen, 1);

	pack = apint_set_range(pack, 7, 0, messageLen);

	for (i = 0; i < 16; i++)
	{
		messageBlock[i] = apint_get_range(pack, i * 32 + 31, i * 32);
	}

	for (i = 0; i < 16; i++)
	{
		printf("%08x\n",(unsigned int)messageBlock[15 - i]);
	}

	initial(intermediateHash);

	processmessageblock(intermediateHash, messageBlock);

	for (i = 0; i < 8; i++)
	{
		digest[i] = intermediateHash[7 - i];
	}
}
