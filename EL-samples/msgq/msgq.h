/*
 * message queue - header file
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/errno.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

extern int errno;
int msgqid;

#define KEY            1234L
#define PERMS          0666
#define MAXMESGDATA    1024
#define MESGHDRSIZE    (sizeof(Mesg) - MAXMESGDATA)   //length of mesg_len  
                                                      //and mesg_type
typedef struct {                                 
  int mesg_len;                    //message length
  long mesg_type;                  //message type, must be greater than 0
  char mesg_data[MAXMESGDATA];     //message
}Mesg;

