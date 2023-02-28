#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int n, pid1, pid2;
	printf("Enter a number: ");
	scanf("%d", &n);
	pid1 = fork();
	pid2 = fork();

	if (pid1 > 0 && pid2 > 0) {
		wait(NULL);
		wait(NULL);
		int fib[100] = { 0 };
		fib[1] = 1;
		for (int i = 2; i <= n; i++) {
			fib[i] = fib[i - 1] + fib[i - 2];
		}

		printf("fib(%d) = %d\n", n, fib[n]);
	}

	else if (pid1 == 0 && pid2 > 0) {
		wait(NULL);
		int sum = 0;
		for (int i = 1; i <= n; i += 2) {
			sum += i * i;
		}

		printf("Sum of squares of odd numbers = %d\n", sum);
	}

	else if (pid1 > 0 && pid2 == 0) {
		wait(NULL);
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += i * i;
		}

		printf("Sum of squares of %d numbers = %d\n", n, sum);
	}

	else {
		int fact = 1;
		for (int i = 1; i <= n; i++) {
			fact *= i;
		}

		printf("fact(%d) = %d\n", n, fact);
	}

	return 0;
}

