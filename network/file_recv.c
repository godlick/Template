#include "common.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define PORT 9999
#define NAMELEN 1024
typedef struct
{
	char filename[NAMELEN];
	long filelen;
}struFileInfo_t;

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
		
		//读取文件信息
		struFileInfo_t info;
		bzero(&info, sizeof(info));
		if(read(clifd, &info, sizeof(info)) != sizeof(info))
			err_sys("read error");
		printf("filename:%s, length:%ld\n", info.filename, info.filelen);
		
		//创建文件，循环读取套接字，将读取内容保存到文件
		int fd = -1;
		fd = open(info.filename, O_WRONLY | O_CREAT | O_TRUNC, 0755);
		if(fd < 0)
			err_sys("open error");
		
		//读取套接字，写文件
		int n;
		char buffer[4096] = {0};
		n = read(clifd, buffer, 4096);
		if(n < 0)
			err_sys("read error");
		while(n > 0)
		{
			write(fd, buffer, n);
			n = read(clifd, buffer, 4096);
			if(n < 0)
				err_sys("read error");
		}
		close(fd);
		close(clifd);
	}
	
	return 0;
}















