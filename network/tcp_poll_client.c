#include "common.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <poll.h>

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

	//数据收发，检测套接字是否可读，检测终端是否有输入
	while(1)
	{
		struct pollfd fd[2];
		bzero(fd, sizeof(fd));
		fd[0].fd = 0;
		fd[0].events |= POLLIN; //终端关心的事件是是否可读 
		fd[1].fd = sockfd;
		fd[1].events |= POLLRDNORM; //套接字关心的事件是是否可读
		
		poll(fd, 2, -1); //阻塞，等待事件发生
		
		//检测各描述符发生的事件
		if(fd[0].revents & POLLIN)
		{
			fgets(send_buf, 1024, stdin);
			if(strncmp(send_buf, "stop", strlen("stop")) == 0)
				break;
			send(sockfd, send_buf, strlen(send_buf), 0);
		}
		
		if(fd[1].revents & POLLRDNORM) //套接字可读
		{
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
