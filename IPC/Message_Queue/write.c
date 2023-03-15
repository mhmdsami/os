#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 50

struct message_buffer {
	long type;
	char text[100];
} message;

int main() {
	key_t key = ftok("progfile", 65);
	int msg_id = msgget(key, 0666|IPC_CREAT);

	message.type = 1;
	
	printf("Write Data: ");
	fgets(message.text, MAX, stdin);
	msgsnd(msg_id, &message, sizeof(message), 0);
	
	printf("Data sent is: %s\n", message.text);
	
	return 0;
}
