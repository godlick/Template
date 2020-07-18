#include "common.h"
#include <fcntl.h>

int main(void)
{
	int fd;
	fd = open("test.data", O_RDWR | O_CREAT); //fd == 3

	int flags;
	flags = fcntl(fd, F_GETFD);
	flags |= FD_CLOEXEC;
	fcntl(fd, F_SETFD, flags);

	pid_t pid;
	pid = fork();
	if(pid < 0)
		err_sys("fork error");
	else if(pid == 0)
	{
		execl("/myWork/template/pipe/exec_test", "exec_test", (char*)0);
	}

	return 0;
}
