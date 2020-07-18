#include "common.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#define PORT 9999
int main(void)
{
	int ret;

	//创建套接字
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd < 0)
		err_sys("socket error");

	//定义地址结构，用于bind操作
	struct sockaddr_in localaddr;
	bzero(&localaddr, sizeof(localaddr));
	localaddr.sin_family = AF_INET;
	localaddr.sin_port = htons(PORT);
	//localaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	//TODO:只绑定到192.168.27.119 
	inet_pton(AF_INET, "192.168.27.119", &localaddr.sin_addr);

	//绑定地址结构
	ret = bind(sockfd, (struct sockaddr*)&localaddr, sizeof(localaddr));
	if(ret < 0)
		err_sys("bind error");

	//循环接收数据
	while(1)
	{
		int n;
		char buffer[1024];
		struct sockaddr_in addr;
		socklen_t addrlen;
		bzero(&addr, sizeof(addr));
		addrlen = sizeof(addr);

		n = recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr*)&addr, &addrlen);
		if(n >= 0)
		{
			buffer[n] = '\0';
			printf("recv:%s ", buffer);

			char ipaddr[16] = {0};
			inet_ntop(AF_INET, &addr.sin_addr, ipaddr, 16);
			printf(" from:%s ", ipaddr);

			//打印端口
			printf("port:%d\n", ntohs(addr.sin_port));
		}
		else
		{
			err_msg("recvfrom error\n");
			break;
		}
	}
	close(sockfd);
	return 0;
}
