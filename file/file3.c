#include "common.h"
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int fd = -1;
	int dupfd = -1;
	int n = 0;
	char buffer[1024] ={0};

	fd = open("test.data", O_RDWR);
	if(fd < 0)
		err_sys("open file error");
	printf("open file ok, fd is %d\n", fd);

	dupfd = dup(fd);

	write(fd, "hello", strlen("hello"));

	write(dupfd, "world", strlen("world"));

	close(fd);
	return 0;
}
