#include <stdio.h>
#include <malloc.h>

int main() {
	int n, quantum, *bt, *rem_bt, *wt, *tt;

	printf("Number of processes = ");
	scanf("%d", &n);

	printf("quantum = ");
	scanf("%d", &quantum);

	bt = (int *) malloc(n * sizeof(int));
	rem_bt = (int *) malloc(n * sizeof(int));
	wt = (int *) malloc(n * sizeof(int));
	tt = (int *) malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("bt[%d] = ", i + 1);
		scanf("%d", &bt[i]);
		rem_bt[i] = bt[i];
	}

	int t = 0, done = 0, total_wait_time = 0, total_turnaround_time = 0;
	while (!done) {
		done = 1;

		for (int i = 0; i < n; i++) {
			if (rem_bt[i] > 0) {
				done = 0;

				if (rem_bt[i] > quantum) {
					t += quantum;
					rem_bt[i] -= quantum;
				}

				else {
					t += rem_bt[i];
					wt[i] = t - bt[i];
					total_wait_time += wt[i];
					rem_bt[i] = 0;
				}
			}
		}

		if (done) break;
	}

	for (int i = 0; i < n; i++) {
		tt[i] = wt[i] + bt[i];
		total_turnaround_time += tt[i];
	}

	float average_wait_time = total_wait_time / (float) n;
	float average_turnaround_time = total_turnaround_time / (float) n;

	printf("Process\tBurst Time\tWait Time\tTurnaround Time\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tt[i]);
	}

	printf("Average wait time = %.2f\n", average_wait_time);
	printf("Average turnaround time = %.2f\n", average_turnaround_time);

	return 0;
}

