#ifndef _SM3_WRAP_H_
#define _SM3_WRAP_H_

#include <stddef.h>
#include <stdint.h>

//  Compute 32-byte hash to "md" from "in" which has "inlen" bytes (sm3.c)
// === 仅调用hash算法及其对应包装器 ===
// SHA2-224: Compute 28-byte hash to "md" from "in" which has "inlen" bytes.
// 输入为“in”（任意长度），长度为inlen（可调用readhex计算），输出为md（28个字节，224bits）
void sm3_256(uint8_t * md, const void *in, size_t inlen);

//  function pointer to the compression function (sm3.c)
// 输入为“in”（任意长度），长度为inlen（可调用readhex计算），输出为md（28个字节，224bits
extern void (*sm3_compress)(void *);

// SM3 compression function for RV32 (rv32_sm3.c)
// RV32用SM3单轮（256 bits）主函数
void rv32_sm3_compress(void *s);

#endif