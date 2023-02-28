#include <stdio.h>
#include <malloc.h>

int main() {
	int n, *bt, *wt, *tt;
	printf("Number of processes = ");
	scanf("%d", &n);

	bt = (int *) malloc(n * sizeof(int));
	wt = (int *) malloc(n * sizeof(int));
	tt = (int *) malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("bt[%d] = ", i + 1);
		scanf("%d", &bt[i]);
	}

	int total_wait_time = 0, total_turnaround_time = 0;
	wt[0] = 0;
	for (int i = 1; i < n; i++) {
		wt[i] = bt[i - 1] + wt[i - 1];
		total_wait_time += wt[i];
	}

	for (int i = 0; i < n; i++) {
		tt[i] = wt[i] + bt[i];
		total_turnaround_time += tt[i];
	}

	printf("Process\tBurst Time\tWait Time\tTurnaround Time\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tt[i]);
	}

	float average_wait_time = total_wait_time / (float) n;
	float average_turnaround_time = total_turnaround_time / (float) n;

	printf("Average wait time = %.2f\n", average_wait_time);
	printf("Average turnaround time = %.2f\n", average_turnaround_time);

	return 0;
}

