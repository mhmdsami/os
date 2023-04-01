#include <stdio.h>
#include <string.h>
#include <unistd.h>

void main(int argc, char *argv[]) {
	int pid;
	int err;
	int num_times;
	char num_times_str[5];

	if (argc == 1) {
		printf("Taken loop maximum as 10\n");
		num_times = 10;
		sprintf(num_times_str, "%d", num_times);
	} else {
		strcpy(num_times_str, argv[1]);
		printf("num_times_str is %s\n", num_times_str);
	}

	pid = fork();
	if (pid == 0) {
		printf("Child process: Running Hello World program\n");
		err = execl("./hello-world", "Hello World", (char *) 0);
		printf("Error %d\n", err);
		perror("execl error: ");
		printf("This wouldn't print");
	} else {
		sleep(3);
		printf("Parent process: Running Loop program\n");
		execl("./loop", "Loop", (char *) num_times_str, (char *) 0);
		printf("Won't reach here");
	}

	return;
}
