#include "common.h"
#include <arpa/inet.h>

int main(void)
{
	unsigned int x = 0x12345678;

	printf("%x\n", htonl(x)); //0x78563412

	return 0;
}
