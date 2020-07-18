#include "common.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#inlcude <sys/time.h>

#define PORT 9999

int main(int argc, char *argv[])
{
	if(argc != 2)
		err_quit("Usage:./tcp_server ipaddr");
	
	int ret;

	//创建套接字
	int servfd = socket(AF_INET, SOCK_STREAM, 0); 
	if(servfd < 0)
		err_sys("socket error");

	//定义地址结构，用于bind操作
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	//servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	//绑定套接字
	ret = bind(servfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	if(ret < 0)
		err_sys("bind error");

	//将套接字改为监听套接字
	ret = listen(servfd, 5);
	if(ret < 0)
		err_sys("listen error");
	printf("server listening...\n");

	//等待客户端连接
	while(1)
	{
		struct sockaddr_in cliaddr;
		socklen_t addrlen;
		int clifd;//客户端套接字
		addrlen = sizeof(cliaddr);

		//等待接受客户端的连接
		clifd = accept(servfd, (struct sockaddr*)&cliaddr, &addrlen);
		
		char ip[16] = {0};
		printf("client addr:%s ", inet_ntop(AF_INET, &cliaddr.sin_addr, ip, 16));
		printf("port:%d\n", ntohs(cliaddr.sin_port));

		//收发数据
		while(1)
		{
			fd_set read_set;//定义文件描述符集合
			FD_ZERO(&read_set);//清空
			FD_SET(0, &read_set);//标准输入
			FD_SET(clifd, &read_set);//套接字
			struct timeval tv = {5, 0};
			
			//永远等直到指定的描述符可读
			//ret = select(clifd + 1, &read_set, NULL, NULL, NULL);
			ret = select(clifd + 1, &read_set, NULL, NULL, &tv);
			if(ret == 0) //超时
				continue;
			
			//逐个检测描述符，并读取数据
			if(FD_ISSET(0, &read_set)) //标准输入可读
			{
				char input[1024] = {0};
				scanf("%s", input);//阻塞
				send(clifd, input, strlen(input), 0);
				//printf("%s\n", input);
			}
			
			if(FD_ISSET(clifd, &read_set)) //套接字可读
			{
				char buffer[1024] = {0};
				int n;
				//等待接受数据
				n = recv(clifd, buffer, 1024, 0);
				if(n < 0)
					err_sys("recv error");
				else if(n == 0)//客户端主动关闭连接
				{
					printf("client closed\n");
					close(clifd);
					break;
				}
				else
				{
					buffer[n] = '\0';
					printf("serv recv:%s\n", buffer);
				}	
			}
		}
	}
	
	return 0;
}
