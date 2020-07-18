#include "common.h"
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;

	printf("before open by readonly\n");
	
	fd = open("myfifo", O_RDONLY);
	if(fd < 0)
		err_sys("open fail\n");

	printf("after open by readonly\n");
	
	return 0;
}
