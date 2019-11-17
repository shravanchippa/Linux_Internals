#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
struct amsg{
	int typ;
	char buff[20];
}am;
main()
{ 
	int qid,n;
	struct msqid_ds qstatus;
	qid=msgget(333,0666);
	if(qid<0)
	{ 	
		perror("msgget");
		exit(0);
   	}
	if(msgctl(qid,IPC_STAT,&qstatus)<0)
    	{
       		perror("msgctl");
       		exit(0);
     	}
  
	if( (n=msgrcv(qid,&am,20,2,0))<0)
	{
		perror("msgrcv");
  		exit(0);
 	}
	printf("***********status after msgsnd**************\n");
	printf("last msg sent :%d %s\n",qstatus.msg_lspid,ctime(&(qstatus.msg_stime)));
   	msgctl(qid,IPC_RMID,0);

}
