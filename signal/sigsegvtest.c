#include "common.h"
#include "sigsegv.h"
#include <signal.h>

int main(void)
{
	setup_sigsegv();

	int *p = NULL;
	*p = 1;

	return 0;
}
