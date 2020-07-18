#include "common.h"

struct a
{
	char c;
	double d;
};

struct b
{
	short a;
	short b;
	short c;
};

int main(void)
{
	printf("sizeof a:%d\n", sizeof(struct a));
	printf("sizeof b:%d\n", sizeof(struct b));
    return 0;
}
