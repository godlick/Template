#include "common.h"

int main(void)
{
	printf("in child pross:%d\n", dup(0));
	return 0;
}
