#include "common.h"
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	char buffer[1024] = {0};

	fd = open("myfifo", O_RDONLY);
	if(fd < 0)
		err_sys("open fail\n");

	while(1)
	{
		bzero(buffer, 1024);
		read(fd, buffer, 1024);
		printf("read from fifo:%s\n", buffer);
		sleep(1);
	}
	return 0;
}
