#include "common.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int main(void)
{
	DIR *pdir = NULL;
	struct dirent *p = NULL;

	pdir = opendir(".");
	if(pdir == NULL)
		err_sys("opendir error");

	p = readdir(pdir);
	while(p != NULL)
	{
		printf("%s ", p->d_name);

		struct stat st;
		if(stat(p->d_name, &st) < 0)
			err_sys("stat error");
		printf("%ld ", st.st_size);

		if(S_ISREG(st.st_mode))
			printf("-\n");

		if(S_ISDIR(st.st_mode))
			printf("d\n");
		p = readdir(pdir);
	}

	closedir(pdir);
	return 0;
}
