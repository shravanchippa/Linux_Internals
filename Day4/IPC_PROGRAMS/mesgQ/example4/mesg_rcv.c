/*************************************************************************
	Program name : mq2.c
	Description : This is reciver program. Run mq1.c before runnig 
		      this program Run this program twice to see what happens
		      when there is no message.
***************************************************************************/
#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>

#define KEY	555	

struct mesg{
    int type;
    char msg[20];
   };

main()
{  
	struct  mesg message;
	int qid,n;
	qid=msgget(555,0666|IPC_CREAT);
	if(qid<0)
	{ 
		perror("msgget");
		exit(0);
        }			// Any first message in the msg queue
	if((n=msgrcv(qid,&message,20,12,0))<0)
  	{ 	
		perror("msgrcv");
		exit(0);
    	}
	printf("msg is:%s\n",message.msg);
	printf("msg typ is %d\n",message.type);
}
