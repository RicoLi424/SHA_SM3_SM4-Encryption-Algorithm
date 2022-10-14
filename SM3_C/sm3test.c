#include <string.h>
#include <stdio.h>
#include "sm3.h"
#include <iostream>
 
//#pragma comment(lib,"sm3dll2")
//extern "C" void SM3Call(const unsigned char *message,unsigned int messageLen, unsigned char digest[SM3_HASH_SIZE]);
 
int main( int argc, char *argv[] )
{
	unsigned char input[256] = "abc";
	int ilen = 3;
	unsigned char output[32];
	int i;
	// ctx;
 
	printf("Message:\n");
	printf("%s\n",input);
 
	SM3Calc(input, ilen, output);
	printf("Hash:\n   ");
	for(i=0; i<32; i++)
	{
		printf("%02x",output[i]);
		if (((i+1) % 4 ) == 0) printf(" ");
	} 
 
	printf("\n");
 
 
	unsigned char input2[256] = "abcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcd";
	int ilen2 = 64;
	unsigned char output2[32];
	int i2;
	// ctx;
 
	printf("Message:\n");
	printf("%s\n", input2);
 
	SM3Calc(input2, ilen2, output2);
	printf("Hash:\n   ");
	for (i2 = 0; i2<32; i2++)
	{
		printf("%02x", output2[i2]);
		if (((i2 + 1) % 4) == 0) printf(" ");
	}
	printf("\n");
	system("pause");
}
