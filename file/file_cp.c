#include "common.h"
#include <sys/stat.h>
#include <fcntl.h>

#define LENGTH 4096 //一次读取的字节数

int main(int argc, char *argv[])
{
	int fromfd, tofd;
	char buffer[LENGTH];
	int n;

	if(argc != 3)
		err_quit("Usage:./file_cp filename1 filename2");

	fromfd = open(argv[1], O_RDONLY);
	if(fromfd < 0)
		err_sys("open file %s error", argv[1]);

	tofd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC);
	if(tofd < 0)
		err_sys("open file %s error", argv[2]);

	n = read(fromfd, buffer, LENGTH);
	while(n > 0)
	{
		write(tofd, buffer, n);
		n = read(fromfd, buffer, LENGTH);
	}
	close(fromfd);
	close(tofd);

	return 0;
}
