#include "sm3_wrap.h"

// 数据比特级别操作头文件
#include "bitmanip.h"

// SM3 RV32 函数文件
uint32_t sm3_p0(uint32_t rs1)
{
	/*
	* P0(x) = x ^ (x <<< 9) ^ (x <<< 17)
	*/
	return rs1 ^ rv32b_ror(rs1, 15) ^ rv32b_ror(rs1, 23);
}

uint32_t sm3_p1(uint32_t rs1)
{
	/*
	* P1(x) = x ^ (x <<< 15) ^ (x <<< 23)
	*/
	return rs1 ^ rv32b_ror(rs1, 9) ^ rv32b_ror(rs1, 17);
}


// 消息扩展（字的扩展）
// 使用W(j-16),W(j-9),W(j-3),W(j-13),W(j-6)
// 对应W(0),W(7),W(13)|W(d),W(3),W(10)|W(a)
/*
* 过程：
* t = W(j-16) ^ W(j-9) ^ (W(j-3) <<< 15)
* t = P1(t)
* Wj = t ^ W(j-13) ^ W10
*/
#define SM3KEY(w0, w3, w7, wa, wd) {				\
	t = w0 ^ w7 ^ rv32b_ror(wd, 17);				\
	t = sm3_p1(t);									\
	w0 = wa ^ rv32b_ror(w3, 25) ^ t;				}

// 前16轮消息哈希
/* 
* 过程：
* h = h + wj
* SS2 = a <<< 12;
* SS1 = (a <<< 12 + e + Tj)
* SS1 = (a <<< 12 + e + Tj) <<< 7
* TT1 = FFj(a, b, c) + d + SS2
* d = c (未列出)
* c = b <<< 9
* b = a (未列出)
* TT2 = GGj(e, f, g) + h + SS1 + wj
* e = P0(TT2)
* h = g (未列出)
* g = f <<< 19
* d = d + wj' --> a = TT1
* tj 更新为 tj1
*/
#define SM3RF0(a, b, c, d, e, f, g, h, w0, w4) {	\
	h = h + w0;										\
	t = rv32b_ror(a, 20);							\
	u = t + e + tj;									\
	u = rv32b_ror(u, 25);							\
	d = d + (t ^ u) + (a ^ b ^ c);					\
	b = rv32b_ror(b, 23);							\
	h = h + u + (e ^ f ^ g);						\
	h = sm3_p0(h);									\
	f = rv32b_ror(f, 13);							\
	d = d + (w0 ^ w4);								\
	tj = rv32b_ror(tj, 31);							}

// 16 - 64轮消息哈希
/* 
* 过程：
* h = h + wj
* SS2 = a <<< 12;
* SS1 = (a <<< 12 + e + Tj)
* SS1 = (a <<< 12 + e + Tj) <<< 7
* TT1 = FFj(a, b, c) + d + SS2
* d = c (未列出)
* c = b <<< 9
* b = a (未列出)
* TT2 = GGj(e, f, g) + h + SS1 + wj
* e = P0(TT2)
* h = g (未列出)
* g = f <<< 19
* d = d + wj' --> a = TT1
* tj 更新为 tj1
*/
#define SM3RF1(a, b, c, d, e, f, g, h, w0, w4) {	\
	h = h + w0;										\
	t = rv32b_ror(a, 20);							\
	u = t + e + tj;									\
	u = rv32b_ror(u, 25);							\
	d = d + (t ^ u) + (((a | c) & b) | (a & c));	\
	b = rv32b_ror(b, 23);							\
	h = h + u + ((e & f) ^ rv32b_andn(g, e));		\
	h = sm3_p0(h);									\
	f = rv32b_ror(f, 13);							\
	d = d + (w0 ^ w4);								\
	tj = rv32b_ror(tj, 31);							}


void rv32_sm3_compress(void *s)
{
	/*
	* 输入256比特数据s，输出
	* 
	*/
	int i;
	uint32_t a, b, c, d, e, f, g, h;
	uint32_t m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, ma, mb, mc, md, me, mf;
	uint32_t tj, t, u;

	uint32_t *sp = s;					// 初始化sp指针指向原始输入256位输入
	const uint32_t *mp = sp + 8;		// mp地址为sp向后8位

	a = sp[0];							// 初始化8个中间字
	b = sp[1];							
	c = sp[2];							 
	d = sp[3];							 
	e = sp[4];							 
	f = sp[5];							 
	g = sp[6];							 
	h = sp[7];							 


	// 读取16个字的初始值并整形， 80636261 --> 61626380
	m0 = rv32b_grev(mp[0], 0x18);
	m1 = rv32b_grev(mp[1], 0x18);
	m2 = rv32b_grev(mp[2], 0x18);
	m3 = rv32b_grev(mp[3], 0x18);
	m4 = rv32b_grev(mp[4], 0x18);
	m5 = rv32b_grev(mp[5], 0x18);
	m6 = rv32b_grev(mp[6], 0x18);
	m7 = rv32b_grev(mp[7], 0x18);
	m8 = rv32b_grev(mp[8], 0x18);
	m9 = rv32b_grev(mp[9], 0x18);
	ma = rv32b_grev(mp[10], 0x18);
	mb = rv32b_grev(mp[11], 0x18);
	mc = rv32b_grev(mp[12], 0x18);
	md = rv32b_grev(mp[13], 0x18);
	me = rv32b_grev(mp[14], 0x18);
	mf = rv32b_grev(mp[15], 0x18);

	// 前16轮初始变量
	tj = 0x79CC4519;

	// 前12轮算法迭代
	SM3RF0(a, b, c, d, e, f, g, h, m0, m4);
	SM3RF0(d, a, b, c, h, e, f, g, m1, m5);
	SM3RF0(c, d, a, b, g, h, e, f, m2, m6);
	SM3RF0(b, c, d, a, f, g, h, e, m3, m7);

	SM3RF0(a, b, c, d, e, f, g, h, m4, m8);
	SM3RF0(d, a, b, c, h, e, f, g, m5, m9);
	SM3RF0(c, d, a, b, g, h, e, f, m6, ma);
	SM3RF0(b, c, d, a, f, g, h, e, m7, mb);

	SM3RF0(a, b, c, d, e, f, g, h, m8, mc);
	SM3RF0(d, a, b, c, h, e, f, g, m9, md);
	SM3RF0(c, d, a, b, g, h, e, f, ma, me);
	SM3RF0(b, c, d, a, f, g, h, e, mb, mf);

	// 因为第13轮迭代要用到第 13+4=17 位的中间关键字，所以这里进行4轮字更新
	SM3KEY(m0, m3, m7, ma, md);
	SM3KEY(m1, m4, m8, mb, me);
	SM3KEY(m2, m5, m9, mc, mf);
	SM3KEY(m3, m6, ma, md, m0);

	// 13~16轮算法迭代
	SM3RF0(a, b, c, d, e, f, g, h, mc, m0);
	SM3RF0(d, a, b, c, h, e, f, g, md, m1);
	SM3RF0(c, d, a, b, g, h, e, f, me, m2);
	SM3RF0(b, c, d, a, f, g, h, e, mf, m3);

	// 后48轮初始变量
	tj = 0x9D8A7A87;

	for (i = 0; i < 3; i++) {
		// 如之前所说，更新12个中间关键字
		SM3KEY(m4, m7, mb, me, m1);
		SM3KEY(m5, m8, mc, mf, m2);
		SM3KEY(m6, m9, md, m0, m3);
		SM3KEY(m7, ma, me, m1, m4);
		SM3KEY(m8, mb, mf, m2, m5);
		SM3KEY(m9, mc, m0, m3, m6);
		SM3KEY(ma, md, m1, m4, m7);
		SM3KEY(mb, me, m2, m5, m8);
		SM3KEY(mc, mf, m3, m6, m9);
		SM3KEY(md, m0, m4, m7, ma);
		SM3KEY(me, m1, m5, m8, mb);
		SM3KEY(mf, m2, m6, m9, mc);
		
		// 进行12次算法迭代
		SM3RF1(a, b, c, d, e, f, g, h, m0, m4);
		SM3RF1(d, a, b, c, h, e, f, g, m1, m5);
		SM3RF1(c, d, a, b, g, h, e, f, m2, m6);
		SM3RF1(b, c, d, a, f, g, h, e, m3, m7);

		SM3RF1(a, b, c, d, e, f, g, h, m4, m8);
		SM3RF1(d, a, b, c, h, e, f, g, m5, m9);
		SM3RF1(c, d, a, b, g, h, e, f, m6, ma);
		SM3RF1(b, c, d, a, f, g, h, e, m7, mb);

		SM3RF1(a, b, c, d, e, f, g, h, m8, mc);
		SM3RF1(d, a, b, c, h, e, f, g, m9, md);
		SM3RF1(c, d, a, b, g, h, e, f, ma, me);
		SM3RF1(b, c, d, a, f, g, h, e, mb, mf);

		// 进行4次中间关键字更新
		SM3KEY(m0, m3, m7, ma, md);
		SM3KEY(m1, m4, m8, mb, me);
		SM3KEY(m2, m5, m9, mc, mf);
		SM3KEY(m3, m6, ma, md, m0);
		
		// 进行4次算法迭代
		SM3RF1(a, b, c, d, e, f, g, h, mc, m0);
		SM3RF1(d, a, b, c, h, e, f, g, md, m1);
		SM3RF1(c, d, a, b, g, h, e, f, me, m2);
		SM3RF1(b, c, d, a, f, g, h, e, mf, m3);
	}

	// 算完前64轮以后将结果赋予sp即s，完成一次哈希迭代
	sp[0] = sp[0] ^ a;
	sp[1] = sp[1] ^ b;
	sp[2] = sp[2] ^ c;
	sp[3] = sp[3] ^ d;
	sp[4] = sp[4] ^ e;
	sp[5] = sp[5] ^ f;
	sp[6] = sp[6] ^ g;
	sp[7] = sp[7] ^ h;
}