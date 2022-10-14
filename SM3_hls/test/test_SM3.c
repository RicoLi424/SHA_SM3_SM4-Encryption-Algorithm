#include <string.h>
#include <stdio.h>
#include "./../src/SM3.h"
#include <ap_cint.h>

int main()
{
	uint6_t i;
	uint8_t message_test[32];
	uint8_t messageLen_test;
	uint32_t digest_test[8];

	message_test[2] = 0x61;
	message_test[1] = 0x62;
	message_test[0] = 0x63;
	for(i=3; i<32; i++)
	{
		message_test[i] = 0x00;
	}

	messageLen_test = 0x18;

	printf("message:\n");
	for(i=0; i<32; i++)
	{
		printf( "%02x",(unsigned int)message_test[31 - i]);
	}
    printf("\n");

	printf("messageLen:\n");
	printf( "%02x",(unsigned int)messageLen_test);
	printf("\n");

	SM3Calc(message_test, messageLen_test, digest_test);

	printf("digest:\n");
	for(i=0; i<8; i++)
	{
		printf("%08x\n",(unsigned int)digest_test[7 - i]);
	}
	printf("\n");

	return 0;
}
