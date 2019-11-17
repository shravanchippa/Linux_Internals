/* *** *******************************************************************
	Program name:	server.c
	Description :
***************************************************************************/

# include "msghead.h"
struct Message mesg;

main()
{
	int	readid,   writeid;
	void server(int  ,int);

	if((readid = msgget(MSGKEY1 , PERMS | IPC_CREAT)) < 0)
		perror("server: faild to get massage queue\n");
	if((writeid = msgget(MSGKEY2 , PERMS | IPC_CREAT)) < 0)
		perror("server: faild to get massage queue\n");

	server(readid, writeid);
	exit(0);
}

void server(int  readid,  int writeid)
{
	int	n,filefd;
	mesg.mesg_type=1L;
	if((n = msgrcv(readid,&mesg,1024,mesg.mesg_type, 0))< 0){
			perror("error in mesg recv\n");
		perror("server: filename read error\n");
	}
	printf("Recived bytes :%d\n",n);
	printf("mesg type is : %d\n",mesg.mesg_type);
	printf("mesg length is :%d\n",mesg.mesg_length);
	mesg.mesg_data[n]='\0';
	printf("File name is %s\n",mesg.mesg_data);
	if((filefd = open(mesg.mesg_data,0)) < 0){
		perror("server:file open failed\n");
		exit(1);
	}
	while(( n = read(filefd,mesg.mesg_data,MAXDATA)) > 0){
		mesg.mesg_length = n;
		if(msgsnd(writeid,&mesg,mesg.mesg_length, 0)!=0){
			perror("message send error\n");
			exit(0);
		}
	}
	close(filefd);
	
	mesg.mesg_length = 0;
	msgsnd(writeid,&mesg,mesg.mesg_length, 0);
	
}

