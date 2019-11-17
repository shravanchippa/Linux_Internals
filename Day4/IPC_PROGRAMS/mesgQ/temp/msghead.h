# include <stdio.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/msg.h>

extern int errno;

# define	MSGKEY1	1111L
# define	MSGKEY2	2222L

# define	PERMS	0644
# define	MAXDATA	1024

struct Message
{
	int  mesg_type;
	int  mesg_length;
	char mesg_data[MAXDATA];
};
void server(int , int );
void client(int, int);
int mesg_send(int , struct Message *);
int mesg_recv(int , struct Message *);
