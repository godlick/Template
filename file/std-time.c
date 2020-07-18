#include "common.h"
#include <time.h>
#include <sys/time.h>

int main(void)
{
	char c = 'a';
	int i = 0;
	struct timeval tv1, tv2;

	gettimeofday(&tv1, NULL);
	for( ; i < 10000; i++)
		printf("%c",c);
	gettimeofday(&tv2, NULL);
	printf("\n");

	printf("%d ms passed\n", (tv2.tv_sec - tv1.tv_sec) * 1000 + (tv2.tv_usec - tv1.tv_usec) / 1000);
	return 0;
}
