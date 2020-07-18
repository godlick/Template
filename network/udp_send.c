#include "common.h"
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 9999

int main(void)
{
	//创建套接字
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd < 0)
		err_sys("socket error");

	//定义服务器地址结构
	struct sockaddr_in dstaddr;
	bzero(&dstaddr, sizeof(dstaddr));
	dstaddr.sin_family = AF_INET;
	dstaddr.sin_port = htons(PORT); //服务器的端口号
	inet_pton(AF_INET, "192.168.27.119", &dstaddr.sin_addr);

	char buffer[1024] = "hello";

	//发送数据
	sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&dstaddr, sizeof(dstaddr));

	close(sockfd);
	return 0;
}
