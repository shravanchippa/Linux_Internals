/***********************************************************************
 	program name: 	rcv_message.c.c
 	Description : A command line tool for tinkering with SysV 
			style Message Queues
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_SEND_SIZE 80

struct mymsgbuf {
                long    mtype;          /* Message type */
                int     request;        /* Work request number */
                double  salary;         /* Employee's salary */
        } msg;


void read_message(int qid, struct mymsgbuf *qbuf, long type);
void remove_queue(int qid);
void change_queue_mode(int qid, char *mode);
void usage(void);


int main()
{
        key_t key;
        char	c;
	int   msgqueue_id;
        struct mymsgbuf qbuf;

        usage();
	printf("enter u'r choice\n");
        scanf("%c",&c);
	/* Create unique key via call to ftok() */
        key = ftok(".", 'm');

        /* Open the queue - create if necessary */
        if((msgqueue_id = msgget(key, IPC_CREAT|0660)) == -1) {
                perror("msgget");
                exit(1);
        }
        
        switch(tolower(c))
        {
                case 'r': read_message(msgqueue_id, &qbuf, qbuf.mtype); 
                          break;
                case 'd': remove_queue(msgqueue_id); 
                          break;        
                case 'm': change_queue_mode(msgqueue_id, "0600"); 
                          break;

                default: usage();

        }
        
        return(0);
}


void read_message(int qid, struct mymsgbuf *qbuf, long type)
{
        /* Read a message from the queue */
        printf("Reading a message ...\n");
        qbuf->mtype = type;
        msgrcv(qid, (struct msgbuf *)qbuf, MAX_SEND_SIZE, type, 0);
        
        printf("Type: %ld Text: %g\n", qbuf->mtype, qbuf->salary);
}

void remove_queue(int qid)
{
        /* Remove the queue */
        msgctl(qid, IPC_RMID, 0);
}

void change_queue_mode(int qid, char *mode)
{
        struct msqid_ds myqueue_ds;

        /* Get current info */
        msgctl(qid, IPC_STAT, &myqueue_ds);

        /* Convert and load the mode */
        sscanf(mode, "%ho", &myqueue_ds.msg_perm.mode);

        /* Update the mode */
        msgctl(qid, IPC_SET, &myqueue_ds);
}

void usage(void)
{
        printf("A utility for tinkering with msg queues\n");
        printf("               (r)ecv <type>\n");
        printf("               (d)elete\n");
        printf("               (m)ode <octal mode>\n");
        
}
