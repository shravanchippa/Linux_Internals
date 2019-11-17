/* This is a simple program wwhich demonstrates how a message is sent by process with it's pid*/

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
	
	m1.mtype=getpid();
	
	printf("Process id of the current process is:%ld\n",getpid());
	printf("Enter the message you want to send to the process\n");	
	fgets(m1.mtext,50,stdin);
	
	if(msgsnd(msgid,&m1,50,0)==-1) {
		perror("msgsnd");
		exit(1);
	}

	printf("Message successfully sent\n");
}
