#include "common.h"

int global = 7;
int global_uninit;		//BSS段

int main(void)
{
	int a = 1;
	int b = 2;
	static int s = 3;
	char *p = (char *)malloc(100);

	printf("address of a is:%p\n", &a); //栈区
	printf("address of b is:%p\n", &b);
	printf("code is %p\n", main);		//代码段
	printf("data is %p\n", &global);	//数据段
	printf("data is %p\n", &s);
	printf("heap is %p\n", p);			//堆区

	free(p);

    return 0;
}
