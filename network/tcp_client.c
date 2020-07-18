#include "common.h"
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 9999

int main(int argc, char *argv[])
{
	if(argc != 2)
		err_quit("Usage:./tcp_client serverip");
	
	int ret;
	//创建套接字
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
		err_sys("socket error");

	//定义地址结构，用于connect操作
	struct sockaddr_in dstaddr;
	bzero(&dstaddr, sizeof(dstaddr));
	dstaddr.sin_family = AF_INET;
	dstaddr.sin_port = htons(PORT);
	inet_pton(AF_INET, "127.0.0.1", &dstaddr.sin_addr);

	//发起连接
	ret = connect(sockfd, (struct sockaddr*)&dstaddr, sizeof(dstaddr));
	if(ret < 0)
		err_sys("connect error");

	printf("connect success\n");
	
	//发送数据
	while(1)
	{		
		char buffer[1024];
		scanf("%s", buffer);
		if(strncmp(buffer, "stop", strlen("stop")) == 0)
			break;
		send(sockfd, buffer, strlen(buffer), 0);
	}

	close(sockfd);
	return 0;
}


















