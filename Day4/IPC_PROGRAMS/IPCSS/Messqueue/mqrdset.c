
#include <stdio.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include "common.h"

int main()
{
  int msgid, ret;
  struct msqid_ds buf;

  /* Get the message queue for the id MY_MQ_ID */
  msgid = msgget( MY_MQ_ID, 0 );

  /* Check successful completion of msgget */
  if (msgid >= 0) {

    ret = msgctl( msgid, IPC_STAT, &buf );

    buf.msg_perm.uid = geteuid();
    buf.msg_perm.gid = getegid();
    buf.msg_perm.mode = 0644;
    buf.msg_qbytes = 8096;

    ret = msgctl( msgid, IPC_SET, &buf );

    if (ret == 0) {

      printf( "Parameters successfully changed.\n");

    } else {

      printf( "Error %d\n", errno );

    }

  }

  return 0;
}

