#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message_buffer {
	long type;
	char text[100];
} message;

int main() {
	key_t key = ftok("progfile", 65);
	int msg_id = msgget(key, 0666|IPC_CREAT);

	msgrcv(msg_id, &message, sizeof(message), 1, 0);
	printf("Data received is: %s\n", message.text);
	msgctl(msg_id, IPC_RMID, NULL);

	return 0;
}
