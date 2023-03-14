#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {
	char buff[25];
	int rfd, wfd;

	mkfifo("pipe", O_CREAT|0644);

	if (fork() == 0) {
		printf("Child writing into FIFO\n");
		wfd = open("pipe", O_WRONLY);
		write(wfd, "Hello World!", 13);
	} else {
		rfd = open("pipe", O_RDONLY);
		read(rfd, buff, 13);
		printf("Parent reads from FIFO: %s\n", buff);
	}

	return 0;
}

