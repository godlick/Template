/*打印指定目录文件的树状图*/

#include "common.h"

#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

/*递归形式进入当前目录下的各子目录并打印文件名称，由depth控制每层缩进的大小*/
void print_dir(char *dir, int depth)
{
	DIR *pdir = NULL;
	struct dirent *entry = NULL;
	struct stat st = {0};

	pdir = opendir(dir);
	if(pdir == NULL)
		err_sys("cannot open directory:%s\n", dir);

	chdir(dir); /*转到该目录下*/
	
	while((entry = readdir(pdir)) != NULL)
	{
		lstat(entry->d_name, &st);
		if(S_ISDIR(st.st_mode)) /*如果当前路径下还有目录文件，则进入子目录继续打印*/
		{
			if(strcmp(".", entry->d_name) == 0 ||	/*不显示.和..目录*/
					strcmp("..", entry->d_name) == 0)
				continue;
			printf("%*s%s/\n",depth, " ", entry->d_name);
			print_dir(entry->d_name, depth + 4); /*递归进入子目录下打印*/
		}
		else
			printf("%*s%s\n", depth, " ", entry->d_name);
	}
	chdir("..");
	closedir(pdir);
}

int main(int argc, char *argv[])
{
	char *dir = NULL;

	if(argc == 1)
		dir = "./";
	else
		dir = argv[1];

	print_dir(dir, 4);

	return 0;
}
