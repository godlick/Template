/*通过lseek获取文件的大小*/

#include "common.h"  

#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
	if(argc < 2)
		err_quit("Argument error!");

	int fd = open(argv[1], O_RDONLY);
	if(fd < 0)
		err_sys("Open fail!");

	int filesize = lseek(fd, 0, SEEK_END);/*定位到文件尾部，返回偏移量*/
	if(filesize == -1)	/*lseek有可能返回负的偏移量，判断lseek出错只能用-1*/
		err_sys("lseek error!");
	else
		printf("file size:%d\n", filesize);

	
	close(fd);
	return 0;
}
