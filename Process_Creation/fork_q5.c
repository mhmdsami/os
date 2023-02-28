#include <stdio.h>
#include <unistd.h>

int main() {
	int n = 2;
	for (int i = 0; i < n; i++) {
		fork();
		printf("Hi from a process\n");
	}
	return 0;
}

