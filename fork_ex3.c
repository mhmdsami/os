#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid, mypid, myppid;
	pid = fork();

	if (pid < 0)
	{
		printf("fork() failed\n");
		return 1;
	}

	if (pid == 0)
	{
		printf("This is child process\n");
		mypid = getpid();
		myppid = getppid();
		printf("Process id is %d and PPID is %d\n", mypid, myppid);
	}

	else
	{
		sleep(2);
		printf("This is parent process\n");
		mypid = getpid();
		myppid = getppid();
		printf("Process id is %d and PPID is %d\n", mypid, myppid);
	}
	return 0;
}

