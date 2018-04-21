#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t pid = fork();
	if(pid > 0) printf("Parent\n");
	else if (pid < 0) printf("Failed\n");
	else printf("Child made.\n");
	printf("%d %d\n", getpid(), getppid());
	return 0;
}
