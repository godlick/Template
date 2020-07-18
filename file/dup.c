#include "common.h"

#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int fd = creat("log.txt", 0755);
	if(fd < 0)
		err_sys("creat file error");

	dup2(fd, 1); /*将fd复制到文件描述符1上，会先把1关闭，再复制*/

	printf("hello\n");
	fflush(stdout);

	return 0;
}
	

