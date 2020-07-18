#include "common.h"
#include <sys/stat.h>
#include <fcntl.h>

#define MAXLINE 4096 //定义一行的最大字符数

/*读取一行，读到换行符或是读到文件结束时停止，返回读到的字节数，失败返回-1，读到的行以'\0'结尾*/
static int readline(int fd, char buffer[])
{
	int i;
	int ret;
	for(i = 0; i < MAXLINE; i++)
	{
		char c;
		ret = read(fd, &c, 1);
		if(ret < 0)
		{
			err_msg("read error");
			return -1;
		}
		else if(ret == 0 || c == '\n')
		{
			buffer[i] = '\0';
			return i;
		}
		else
		{
			buffer[i] = c;
		}
	}
	return i;
}

int main(void)
{
	int fd;

	fd = open("test.data", O_RDWR | O_CREAT | O_EXCL);
	if(fd != -1)
	{
		printf("create file ok\n");
		write(fd, "hello\n", strlen("hello\n"));
		write(fd, "world\n", strlen("world\n"));
		close(fd);
	}
	else
	{
		printf("file exists\n");
		char buffer[MAXLINE] = {0};
		fd = open("test.data", O_RDONLY);
		if(fd < 0)
			err_sys("open fail error");
		else
		{
			readline(fd, buffer);
			printf("readline:%s\n", buffer);
		}
		close(fd);
	}

	return 0;
}
