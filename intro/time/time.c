#include "common.h"
#include <time.h>
#include <sys/time.h>

int main(void)
{
	time_t now;
	struct tm *pUTC;
	struct tm *pLOCAL;
	struct timeval tv1;
	struct timeval tv2;
	int timepass;

	gettimeofday(&tv1, NULL);
	usleep(5000);

	now = time(NULL);
	printf("%ld\n", now);

	pLOCAL = localtime(&now);
	pUTC = gmtime(&now);

	printf("UTC hour:%d, UTC min:%d, UTC sec:%d\n", 
			pUTC->tm_hour,
			pUTC->tm_min,
			pUTC->tm_sec);

	printf("pLOCAL hour:%d, pLOCAL min:%d, pLOCAL sec:%d\n", 
			pLOCAL->tm_hour,
			pLOCAL->tm_min,
			pLOCAL->tm_sec);

	printf("%s\n", asctime(pUTC));
	printf("%s\n", ctime(&now));
	
	gettimeofday(&tv2, NULL);

	timepass = (tv2.tv_sec - tv1.tv_sec)*1000 + (tv2.tv_usec - tv1.tv_usec)/1000;
	printf("ms passed:%d\n", timepass);

	return 0;
}
