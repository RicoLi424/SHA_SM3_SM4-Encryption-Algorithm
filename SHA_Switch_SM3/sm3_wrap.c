#include <string.h>
#include "sm3_wrap.h"

//  pointer to the compression functions
// 函数指针，指向sm3_rv32_cf文件中的单轮hash主函数
void (*sm3_compress)(void *s) = &rv32_sm3_compress;

//  Compute 32-byte message digest to "md" from "in" which has "inlen" bytes
void sm3_256(uint8_t * md, const void *in, size_t inlen)
{
	/*
	* :param in		:		输入的消息
	* :param inlen	:		输入消息的字节长度（一个ascii码代表一个字节）
	* :param md		:		输出的消息摘要
	*/
	size_t i;
	uint64_t x;
	uint32_t t, s[8 + 16];

	uint8_t *mp = (uint8_t *) & s[8];
	const uint8_t *p = in;

	// SM3所用的8个初始字，对应a,b,c,d,e,f,g,h的初始值
	// 对"每次"消息摘要（非"每组"）重新赋值
	s[0] = 0x7380166F;
	s[1] = 0x4914B2B9;
	s[2] = 0x172442D7;
	s[3] = 0xDA8A0600;
	s[4] = 0xA96F30BC;
	s[5] = 0x163138AA;
	s[6] = 0xE38DEE4D;
	s[7] = 0xB0FB0E4E;

	//  "md padding"
	x = inlen << 3;							//  length in bits

	// 长度超过512bits时，对前512位进行消息摘要运算，返回到s指针处
	// 完成一轮摘要运算，则指针向前推进512bits
	while (inlen >= 64) {					//  full blocks
		memcpy(mp, p, 64);
		sm3_compress(s);
		inlen -= 64;
		p += 64;
	}
	
	// 原长度最后一个block
	memcpy(mp, p, inlen);					// 将地址拷贝出来
	mp[inlen++] = 0x80;						// 先补充一组1000_0000
	// 如果长度大于448，则本block完全补0x00至512位，完成本轮hash 运算
	if (inlen > 56) {
		memset(mp + inlen, 0x00, 64 - inlen);
		sm3_compress(s);
		inlen = 0;
	}
	// 最后一个block将长度信息赋予最后64个bits
	i = 64;									//  process length
	while (x > 0) {
		mp[--i] = x & 0xFF;
		x >>= 8;
	}
	memset(&mp[inlen], 0x00, i - inlen);	// 未补齐的部分用0x00补齐
	sm3_compress(s);						// 进行最后一次sm3压缩

	// 按照大端格式存储
	for (i = 0; i < 32; i += 4) {
		t = s[i >> 2];
		md[i] = t >> 24;
		md[i + 1] = (t >> 16) & 0xFF;
		md[i + 2] = (t >> 8) & 0xFF;
		md[i + 3] = t & 0xFF;
	}
}