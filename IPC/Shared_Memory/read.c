#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main() {
	int shmid;
	char *str;
	shmid = shmget((key_t) 100, 1024, IPC_CREAT|0666);
	str = (char *) shmat(shmid, (char *) 0, 0);
	printf("Data read: %s", str);
	shmdt(str);
	shmctl(shmid, IPC_RMID, NULL);
	printf("smhid: %d\n", shmid);
	return 0;
}

