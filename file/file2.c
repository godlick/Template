#include "common.h"
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int fd = -1;
	int n = 0;
	char buffer[1024] ={0};

	fd = open("test.data", O_RDWR);
	if(fd < 0)
		err_sys("open file error");
	printf("open file ok, fd is %d\n", fd);

	n = read(fd, buffer, 1024);
	if(n > 0)
	{
		printf("read %d bytes\n", n);
		printf("%s\n", buffer);
	}

	strncpy(buffer, "hello world", strlen("hello world"));
	n = write(fd, buffer, strlen(buffer));
	printf("write %d bytes\n", n);

	close(fd);
	return 0;
}
