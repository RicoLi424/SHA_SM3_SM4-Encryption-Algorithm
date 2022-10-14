#ifndef _SM3_H_
#define _SM3_H_
#include <ap_cint.h>

typedef uint512 uint512_t; // 512-bit user defined type
typedef uint32  uint32_t;  // 32-bit user defined type
typedef uint8   uint8_t;   // 8-bit user defined type
typedef uint7   uint7_t;   // 7-bit user defined type
typedef uint6   uint6_t;   // 6-bit user defined type
typedef uint5   uint5_t;   // 5-bit user defined type
typedef uint4   uint4_t;   // 4-bit user defined type

uint32_t intermediateHash[8];
uint32_t messageBlock[16];

void initial(uint32_t intermediateHash[8]);

void processmessageblock(uint32_t intermediateHash[8], uint32_t messageBlock[16]);

void SM3Calc(uint8_t message[32], uint8_t messageLen, uint32_t digest[8]);

#endif
