#include "common.h"
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	close(1);
	
	int fd = -1;

	fd = open("test.data", O_RDWR);
	if(fd == -1)
	{
		err_msg("open by read only fail");
		fd = open("test.data", O_RDWR | O_CREAT, 0755);
		if(fd == -1)
			err_sys("creat file error");
		printf("creat file ok, fd is %d\n", fd);
	}
	else
	{
		printf("open file ok, fd is %d\n", fd);
	}
	fflush(stdout);
	close(fd);

	return 0;
}
