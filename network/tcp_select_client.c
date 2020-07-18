#include "common.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

int main(void)
{
	//创建套接字
	int sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
		err_sys("socket error");

	//指定connect地址
	struct sockaddr_in dst_addr;
	bzero(&dst_addr, sizeof(dst_addr));
	dst_addr.sin_family = AF_INET;
	dst_addr.sin_port = htons(9999);
	inet_pton(AF_INET, "127.0.0.1", &dst_addr.sin_addr);

	//发起connect操作
	int ret;
	ret = connect(sockfd, (struct sockaddr*)&dst_addr, sizeof(dst_addr));
	if(ret != 0)
		err_sys("connect error");

	//读写操作
	char send_buf[1024] = {0};
	char recv_buf[1024] = {0};
	
	int maxfd = sockfd + 1;
	fd_set read_set;
	FD_ZERO(&read_set);
	while(1)
	{
		FD_SET(0, &read_set);
		FD_SET(sockfd, &read_set);
		select(maxfd, &read_set, NULL, NULL, NULL);//阻塞，检测描述符是否可读
		
		if(FD_ISSET(0, &read_set))
		{
			//发送
			fgets(send_buf, 1024, stdin);
			if(strncmp(send_buf, "stop", strlen("stop")) == 0)
				break;
			send(sockfd, send_buf, strlen(send_buf), 0);
		}
		
		if(FD_ISSET(sockfd, &read_set))
		{
			//接收
			int ret;
			ret = recv(sockfd, recv_buf, 1024, 0);
			if(ret == 0)
			{
				printf("server closed!\n");
				break;		
			}
			recv_buf[ret] = '\0';
			printf("recv:%s\n", recv_buf);	
		}
	}

	close(sockfd);
	return 0;
}
