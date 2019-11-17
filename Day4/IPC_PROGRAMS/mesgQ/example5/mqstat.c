#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>

# define KEY 	333L

  struct msg{
   int type;
   char buff[20];
   }message;

main()
{ 
	int qid,n;
	struct msqid_ds qstatus;
	qid=msgget(KEY,0666|IPC_CREAT);
	if(qid<0){
		 perror("msgget");
		 exit(0);
   	}
     
	message.type=2;
	strcpy(message.buff,"msgsnt");
  
	if( (n=msgsnd(qid,&message,20,0))<0){
		perror("msgsnd");
		exit(0);
 	}
	printf("msg snt by pid->%d\n",getpid());

}
