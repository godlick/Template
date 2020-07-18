#include "common.h"
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int fd = -1;

	fd = open("test.data", O_RDWR | O_CREAT | O_TRUNC);
	if(fd < 0)
		err_sys("open file error");
	printf("open file ok, fd is %d\n", fd);

	//dupfd = dup(fd);

	dup2(fd, 1); //关闭1，复制 fd 到1

	printf("after dup2\n");
	fflush(stdout);

	close(fd);
	return 0;
}
