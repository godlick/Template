#include "common.h"
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	char buffer[1024] = {0};

	printf("before open by readonly\n");
	
	fd = open("myfifo", O_RDONLY);
	if(fd < 0)
		err_sys("open fail\n");

	printf("after open by readonly\n");

	printf("before read by readonly\n");
	read(fd, buffer, 1024);
	printf("after read by readonly\n");
	printf("read from fifo:%s\n", buffer);
	
	return 0;
}
