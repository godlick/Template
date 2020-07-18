#include "common.h"

typedef int (*func)(int ,int);

int sum(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int divi(int a, int b)
{
	return a / b;
}

struct proc
{
	int operator;	//运算符
	func p;			//处理函数的指针
};

/*定义数据表*/
struct proc table[] = {
	{'+', sum},
	{'-', sub},
	{'*', mul},
	{'/', divi}
};

int main(void)
{
	int a = 0;
	int b = 0;
	char c = 0;
	int i;
	scanf("%d %d %c", &a, &b, &c);

	for(i = 0; i < sizeof(table) / sizeof(table[0]); i++)
	{
		if(table[i].operator == c)
			printf("the result is %d\n", table[i].p(a, b));
	}
}
