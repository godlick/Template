#include "common.h"
/*
   全缓冲：普通文件
   行缓冲：标准输出
   不缓冲：stderr
 */
int main(void)
{
	FILE *fp = fopen("test.data", "w");
	if(fp == NULL)
		err_sys("open file error");

	char buffer[] = "hello\n";//字符串以'\0'多一个字节
	printf("%s%d%d\n",buffer,(int)sizeof(buffer),(int)strlen(buffer));
	for(int i = 0; i < strlen(buffer); i++)
	{
		printf("%c\n",buffer[i]);
	}
	fwrite(buffer, 1, strlen(buffer), fp);

	sleep(20);
	fclose(fp);

	return 0;
}
