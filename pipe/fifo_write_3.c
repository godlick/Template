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
	
	sleep(5);
	write(fd, data, strlen(data));

	printf("after write\n");
	
	return 0;
}
