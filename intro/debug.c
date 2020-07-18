#include "common.h"

#define SUM(a, b)
#define DEBUG(a, ...) do{if(a > 0) printf(__VA_ARGS__);}while(0) 

int main(void)
{
	DEBUG(1, "hello\n");
	DEBUG(1, "hello %d\n", 123);
	DEBUG(0, "hello %d\n", 123);

	return 0;
}
