#include "common.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	int fd;
	int n;
	char buffer[1024] = {0};

	fd = open("myfifo", O_RDONLY|O_NONBLOCK);
	if(fd < 0)
		err_sys("open fail\n");
	printf("after open\n");

	while(1)
	{
		bzero(buffer, 1024);
		n = read(fd, buffer, 1024);
		printf("read %d bytes from fifo:%s\n", n, buffer);
		sleep(1);
	}
	return 0;
}
