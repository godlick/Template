#include "common.h"
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	char data[] = "hello world\n";
	
	fd = open("myfifo", O_WRONLY);
	if(fd < 0)
		err_sys("open fail\n");

	while(1)
	{
		write(fd, data, strlen(data));
		printf("write to myfifo:%s\n", data);
		sleep(2);
	}

	return 0;
}
