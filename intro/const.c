#include <stdio.h>

int main(void)
{
	const int a = 1;
	int *p  = &a;
	
	//a = 2;  	//������ͨ���������޸�const����
	*p = 4;		//����ͨ����ַ�޸�const����
	
	printf("a is %d\n", a);
	return 0;
}