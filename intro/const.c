#include <stdio.h>

int main(void)
{
	const int a = 1;
	int *p  = &a;
	
	//a = 2;  	//不允许通过变量名修改const变量
	*p = 4;		//可以通过地址修改const变量
	
	printf("a is %d\n", a);
	return 0;
}
