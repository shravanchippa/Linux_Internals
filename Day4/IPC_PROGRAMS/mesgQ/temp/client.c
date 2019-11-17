/*  ***********************************************************************/
	

# include "msghead.h"

struct Message mesg;

main()
{
	int	readid,   writeid;

	if((readid = msgget(MSGKEY1 , PERMS | IPC_CREAT)) < 0)
		perror("server: faild to get massage queue\n");
	if((writeid = msgget(MSGKEY2 , PERMS | IPC_CREAT)) < 0)
		perror("server: faild to get massage queue\n");

	client(readid, writeid);

	if(msgctl(readid,IPC_RMID,(struct msqid_ds *)0) < 0)
		perror("client: error in msgctl\n");
	if(msgctl(writeid,IPC_RMID,(struct msqid_ds *)0) < 0)
		perror("client: error in msgctl\n");
	exit(0);
}

void client(int readfd,int  writefd)
{
	int   n;
	printf("Enter file name\n");
	if(fgets(mesg.mesg_data, MAXDATA, stdin) == NULL)
		perror("client: fgets failed\n");
	n= strlen(mesg.mesg_data);
	printf("Read file name is:%s\n",mesg.mesg_data);
	printf("string length is %d\n",n);
	//if(mesg.mesg_data[n-1] == '\n')
	//	n--;
	mesg.mesg_length = n;
	mesg.mesg_type = 1L; //getpid()
	if(msgsnd(readfd,&mesg, mesg.mesg_length, 0)!=0){
		perror("message send error\n");
		exit(0);
	}

	while((n = msgrcv(writefd,&mesg,MAXDATA,mesg.mesg_type, 0)) > 0){
		if(write(1, mesg.mesg_data, n)!= n)
			perror("client: data write error\n");
	}
}
