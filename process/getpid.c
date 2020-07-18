#include "common.h"

int main(void)
{
	pid_t pid, ppid, pgid;

	pid = getpid();
	printf("pid = %d\n", pid);

	ppid = getppid();
	printf("ppid = %d\n", ppid);

	pgid = getpgid(pid);
	printf("pgid = %d\n", pgid);

	return 0;
}
