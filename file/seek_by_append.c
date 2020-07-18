#include "common.h"

#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("seektest", O_RDWR|O_CREAT|O_TRUNC|O_APPEND, 0755);/*以追加的方式打开文件并清空*/
	if(fd < 0)
		err_sys("open fail");
	
	int ret = lseek(fd, 1024, SEEK_SET);/*文件已清空，使用lseek定位到一个比文件总长度要大的位置*/
	if(ret == -1)
	{
		err_sys("lseek fail");
	}
	else
	{
		printf("lseek OK\n");
		write(fd, "hello\n", strlen("hello\n"));
	}

	close(fd);
	return 0;
}
	

