#include "common.h"

int global = 7;
int global_uninit;		//BSS��

int main(void)
{
	int a = 1;
	int b = 2;
	static int s = 3;
	char *p = (char *)malloc(100);

	printf("address of a is:%p\n", &a); //ջ��
	printf("address of b is:%p\n", &b);
	printf("code is %p\n", main);		//�����
	printf("data is %p\n", &global);	//���ݶ�
	printf("data is %p\n", &s);
	printf("heap is %p\n", p);			//����

	free(p);

    return 0;
}