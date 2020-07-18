#include "common.h"
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;

	printf("before open by writeonly\n");
	
	fd = open("myfifo", O_WRONLY);
	if(fd < 0)
		err_sys("open fail\n");

	printf("after open by writeonly\n");
	
	return 0;
}
