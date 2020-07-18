#include "common.h"
#include <fcntl.h>
#include <errno.h>

int main(void)
{
	int ret;
	pid_t pid;
	int fd[2] = {-1, -1};

	ret = pipe(fd);
	if(ret == -1)
		err_sys("pipe error");
	
	pid = fork();
	if(pid < 0)
		err_sys("fork error");
	if(pid == 0)
	{
		//close(fd[1]);//子进程关闭写入端
		fcntl(fd[0], F_SETFL, O_NONBLOCK); //设置非阻塞读取
		while(1){
			int ret;
			char buffer[1024];
			bzero(buffer, 1024);
			ret = read(fd[0], buffer, 1024);
			if(ret > 0)
			{
				printf("read from pipe:%s\n", buffer);
			}
			else if( ret == 0)
			{
				printf("pipe closed\n");
				close(fd[0]);
				exit(0);
			}
			else if(ret < 0)
			{
				if(errno == EWOULDBLOCK)
				{
					printf("no data\n");
					sleep(1);
					continue;
				}
				else
				{
					err_sys("read error");
				}
			}
		}
	}
	else
	{
		close(fd[0]);//父进程关闭读取端
		while(1)
		{
			char buffer[1024];
			fgets(buffer, 1024, stdin);
			if(strcmp(buffer, "stop\n") == 0)
			{
				close(fd[1]);
				exit(0);
			}
			write(fd[1], buffer, strlen(buffer));
		}
	}
	return 0;
}
