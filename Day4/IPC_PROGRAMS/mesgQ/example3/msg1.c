# include <sys/msg.h>
# include "my_ipc.h"

struct msgbuf{
	long	mtype;
	char	mtext[1];
};
main(int    argc,   char   *argv[])
{
	int	msqid;
	struct msqid_ds	info;
	struct  msgbuf   buf;

	msqid = msgget(1122, IPC_CREAT|0644);
	buf.mtext[0] = 1;
	buf.mtype = 1;

	msgsnd(msqid, &buf, 1,0);

	msgctl(msqid,IPC_STAT, &info);
	printf("read-write = %03o, cbytes = %lu , qnum = %lu , qbytes = %lu\n",info.msg_perm.mode ,(ulong) info.msg_cbytes,(ulong) info.msg_qnum,(ulong) info.msg_qbytes);
	//system("ipcs ");
	msgctl(msqid, IPC_RMID, NULL);
	exit(0);
}
