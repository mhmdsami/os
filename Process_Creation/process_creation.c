#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void create_process() 
{
	if (fork() == 0) 
	{
		printf("Hello from the Child!\n");
	}
	else 
	{
		printf("Hello from the Parent!\n");
	}
}

int main() 
{
	create_process();
	return 0;
}
