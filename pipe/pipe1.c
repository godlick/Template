#include "common.h"

int main(void)
{
	int ret;
	int fd[2] = {-1, -1};

	ret = pipe(fd);
	if(ret == -1)
		err_sys("pipe error");

	char buffer[1024] = "hello";
	write(fd[1], buffer, strlen(buffer));

	bzero(buffer, 1024);
	read(fd[0], buffer, 1024);
	printf("read from pipe:%s\n", buffer);

	close(fd[0]);
	close(fd[1]);
	return 0;
}
