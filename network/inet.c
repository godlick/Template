#include "common.h"
#include <arpa/inet.h>

int main(void)
{
	char *ipaddr = "192.168.0.1";  //p->表达式
	int addr; //n->网络地址

	//把字符串形式转换整数形式
	inet_pton(AF_INET, ipaddr, &addr);
	printf("%u\n", addr);

	//整数->字符串
	char strip[16] = {0};
	inet_ntop(AF_INET, &addr, strip, 16);
	printf("%s\n", strip);

	return 0;
}
