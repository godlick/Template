#include "common.h"

/*
A  	key		/bin/xxx   	100
B	key		/bin/xxx	100
C	key		/bin/xxx	100
*/


int main()
{
	printf("%d\n", ftok("./", 1));
}
