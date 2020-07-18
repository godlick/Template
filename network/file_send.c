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
	if(argc != 3)
		err_quit("Usage:./file_send serverip filename");
	
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
	inet_pton(AF_INET, argv[1], &dstaddr.sin_addr);

	//发起连接
	ret = connect(sockfd, (struct sockaddr*)&dstaddr, sizeof(dstaddr));
	if(ret < 0)
		err_sys("connect error");
	printf("connect success\n");
	
	//打开文件
	int fd = -1;
	fd = open(argv[2], O_RDONLY);
	if(fd < 0)
		err_sys("open error");
	
	//发送文件信息
	struFileInfo_t info;
	bzero(&info, sizeof(info));
	strncpy(info.filename, argv[2], strlen(argv[2]));
	info.filelen = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	printf("filename:%s, length:%ld\n", info.filename, info.filelen);
	if(write(sockfd, &info, sizeof(info)) != sizeof(info))
		err_sys("write error");
	
	//循环读取并发送
	while(1)
	{
		int n;
		char buffer[4096] = {0};
		
		n = read(fd, buffer, 4096);
		if(n < 0)
			err_sys("read error");
		else if(n > 0)
		{
			write(sockfd, buffer, n);
		}
		else //n == 0，读到文件结尾
		{
			close(fd);
			break;
		}
	}
	close(sockfd);
	
	return 0;
}


















