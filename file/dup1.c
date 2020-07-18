#include "common.h"
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int fd;

	fd = dup(1); //fd = 3

	write(fd, "hello\n", strlen("hello\n"));

	return 0;
}
