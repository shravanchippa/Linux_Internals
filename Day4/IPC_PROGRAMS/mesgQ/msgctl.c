/*This program illustrates how a message queue is deleted */
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

main()
{

	int msgid;
	
	if((msgid=msgget(1,0))==-1) {
		  perror("msgget");
		  exit(1);
	}

	
	if(msgctl(msgid,IPC_RMID,0)==-1) {
		perror("msgctl");
		exit(1);
	}

	printf("Message queue successfully deleted\n");

}	
