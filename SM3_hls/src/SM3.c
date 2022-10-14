#include <stdio.h>      //������׼��
#include "SM3.h"
#include <ap_cint.h>

/*
* ��������ѭ����λ����LeftRotate(word, bits)
* ��word����bits����
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
* �����޷������ͳ���T(i)
* ����i��ֵ��������ΪT��ֵ
* ��i >= 0 �� i <= 15����TΪ0x79CC4519(ʮ��������ʮ������)
* ��i >= 16 �� i <= 63����TΪ0x7A879D8A(ʮ��������ʮ������)
* ���⣬TΪ0
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
* ���岼������FF(i)���޷�������
* ����i��ֵ�������䷵�ز�ͬ�ĺ���ֵ
* ��i >= 0 �� i <= 15����FF = X ^ Y ^ Z��^��ʾ���
* ��i >= 16 �� i <= 63,��FF = (X & Y) | (X & Z) | (Y & Z)
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
* ���岼������GG(i)���޷�������
* ����i��ֵ�������䷵�ز�ͬ�ĺ���ֵ
* ��i >= 0 �� i <= 15����GG = X ^ Y ^ Z
* ��i >= 16 �� i <= 63,��GG = (X & Y) | (~X & Z)
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
* �����û�����P0(X)
* P0 = X ^ LeftRotate(X, 9) ^ LeftRotate(X, 17)
* ����LeftRotate(X, 9)��ʾX����ѭ��λ��9���صĽ��
*/
uint32_t P0(uint32_t X)
{
	return X ^ LeftRotate(X, 9) ^ LeftRotate(X, 17);
}

/*
* �����û�����P1(X)
* P0 = X ^ LeftRotate(X, 15) ^ LeftRotate(X, 23)
* ����LeftRotate(X, 15)��ʾX����ѭ��λ��15���صĽ��
*/
uint32_t P1(uint32_t X)   //�û�����P1
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
* ���崦����Ϣ��test����
*/

void processmessageblock(uint32_t intermediateHash[8], uint32_t messageBlock[16])
{
	uint7_t i;
	uint32_t W[68];                                       //����W
	uint32_t W_[64];                                      //����W_
	uint32_t A, B, C, D, E, F, G, H;                      //A, B, C, D, E, F, G, HΪ�ּĴ���
	uint32_t SS1, SS2, TT1, TT2;                          //SS1, SS2, TT1, TT2Ϊ�м����


	/* ��Ϣ��չ	*/

	/*
	* ΪW[0]-W[15]��ֵ
	* i��0��15��������
	* ÿѭ��һ�α㽫context(������)��ָ��Ľṹ���а�����
	* ������messageBlock(��Ϣ��)�е�����(��64���ֽ�)�ĸ��ֽڸ���W[i]
	* ����⵽�ֵĴ洢��ʽΪС�˴洢����ת�ַ�˳��
	*/
	for (i = 0; i < 16; i++)
	{
		W[15 - i] = messageBlock[i];
		//printf("%d: %08x\n", (unsigned int)i, (unsigned int)W[i]);
	}
	/*
	* ����W[16]-W[67]
	* i��16��67��������
    * ÿѭ��һ�α�ΪW[i]��ֵP1(W[i - 16] ^ W[i - 9] ^ LeftRotate(W[i - 3], 15))
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
	* ����W_[16]-W_[63]
	* i��16��63��������
    * ÿѭ��һ�α�ΪW_[i]��ֵW[i] ^ W[i + 4];
	*/

	for (i = 0; i < 64; i++)
	{
		W_[i] = W[i] ^ W[i + 4];
		//printf("%d: %08x\n", (unsigned int)i, (unsigned int)W_[i]);
	}

	/* ��Ϣѹ�� */

	//Ϊ�˸��ּĴ�������ʼֵ
	A = intermediateHash[0];
	B = intermediateHash[1];
	C = intermediateHash[2];
	D = intermediateHash[3];
	E = intermediateHash[4];
	F = intermediateHash[5];
	G = intermediateHash[6];
	H = intermediateHash[7];

	//ѹ������
	for (i = 0; i < 64; i++)
	{
		//��ABCDEFGH�д洢�İ������ݽ����߼�����

        //�м���������ݴ�����
		SS1 = LeftRotate((LeftRotate(A, 12) + E + LeftRotate(T(i), i)), 7);
		SS2 = SS1 ^ LeftRotate(A, 12);
		TT1 = FF(A, B, C, i) + D + SS2 + W_[i];
		TT2 = GG(E, F, G, i) + H + SS1 + W[i];
		//һ�������Ĵ����д洢�µ�����
		D = C;
		C = LeftRotate(B, 9);
		B = A;
		A = TT1;
		H = G;
		G = LeftRotate(F, 19);
		F = E;
		E = P0(TT2);

	}

	//��λ�����ٸ�ֵ

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

	//��Ϣ���ʼֵΪ��
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
