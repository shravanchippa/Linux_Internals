/*This program illustrtes how a message is received from message queue*/
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<unistd.h>
#include<stdio.h>

struct message
{
	long mtype;
	char mtext[50];
};

main()
{
	struct message m1;
	int msgid;
	
	if((msgid=msgget(1,0666|IPC_CREAT))==-1) {
		perror("msgget");
		exit(1);
	}
	
	if(msgrcv(msgid,&m1,10,0,MSG_NOERROR)==-1) {
		perror("msgsnd");
		exit(1);
	}

	if(msgrcv(msgid,&m1,10,0,MSG_NOERROR)==-1) {
		perror("msgsnd");
		exit(1);
	}
	printf("Message received from the process whose pid is:%ld\n",m1.mtype);
	printf("And the message is:%s\n",m1.mtext);

}
