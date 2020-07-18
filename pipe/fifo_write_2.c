#include "common.h"
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	char data[] = "hello world\n";

	printf("before open by writeonly\n");
	
	fd = open("myfifo", O_WRONLY);
	if(fd < 0)
		err_sys("open fail\n");

	printf("after open by writeonly\n");

	printf("before write, sleep 5\n");
	sleep(5);
	write(fd, data, strlen(data));
	printf("after write\n");
	
	return 0;
}
