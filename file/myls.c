#include "common.h"

#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h> /*包含目录操作的头文件*/

int main(void)
{
	struct dirent* pfile = NULL;
	struct stat st = {0};

	DIR *pdir = opendir("./"); /*打开当前目录*/
	if(pdir == NULL)
		err_sys("open dir fail");

	pfile = readdir(pdir);/*readdir函数获取目录下的文件信息*/
	while(pfile != NULL)
	{
		printf("%s\t", pfile->d_name);
		stat(pfile->d_name, &st);	/*stat函数获取文件信息*/
		printf("%ld\t", st.st_size);

		/*通过宏来判断文件类型*/
		if(S_ISREG(st.st_mode)) 
			printf("regular file");
		else if(S_ISDIR(st.st_mode))
			printf("directory");
		else if(S_ISCHR(st.st_mode))
			printf("charactor device");
		else if(S_ISBLK(st.st_mode))
			printf("block device");

		printf("\n");
		pfile = readdir(pdir);
	}
	closedir(pdir);
	return 0;
}
