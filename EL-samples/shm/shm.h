/*
 * shared memory - header file
 *
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

#define SHMKEY          0x123
#define PERMS           0666
#define ADDRESS_LENGTH  30
#define PROTOCOL_LENGTH 10
#define MSGQNAME_LENGTH 20
#define SEMNAME_LENGTH  20

extern int errno;

typedef struct 
{
  int  portno;
  char ipaddr[ADDRESS_LENGTH];
  char protocol[PROTOCOL_LENGTH];
  char msgqname[MSGQNAME_LENGTH];
  char semname[SEMNAME_LENGTH];
}CFG_SHM;

