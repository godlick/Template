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
		int ret;
		bzero(buffer, 1024);
		ret = read(fd, buffer, 1024);//读取
		printf("read %d bytes from fifo:%s\n", ret, buffer);
		sleep(1);
	}
	return 0;
}
