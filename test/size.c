#include <stdio.h>

//、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、
//							64位		32位
//Size of char			:	 1		 1
//Size of int			:	 4		 4
//Size of short			:	 2		 2
//Size of long			:	 8		 4
//Size of long int		:	 8		 4
//Size of float			:	 4		 4
//Size of double		:	 8		 8
//Size of long double	:	 16		 8
//Size of (void *)		:	 8		 4
//、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、


int main(void)
{
	char a[2];
	char *b;
	printf("%d\n", (int)sizeof(b));
	printf("%d\n", (int)sizeof(*b));
	printf("%d\n", (int)sizeof(char));
	printf("%d\n", (int)sizeof(char *));
	printf("%d %d\n",(int)sizeof(&a[0]),(int)sizeof(a));
	printf("%d\n", (int)sizeof(int));
	printf("%d\n", (int)sizeof(int*));
	return 0;
}