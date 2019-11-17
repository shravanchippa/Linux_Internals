/*
 *  Program demonstrating shared memory
*/

#include "shm.h"

int main()
{
  CFG_SHM *cfgshmPtr;
  int shmid;
  
  shmid = shmget(SHMKEY,sizeof(CFG_SHM),0);        //open the shared memory
  if(shmid < 0)                                    //segment
   {
    printf("Error in getting shared memory, %s\n",strerror(errno));
    exit(0);
   }
  
  cfgshmPtr = (CFG_SHM *) shmat(shmid,0,0);      //attach it to the process
  if(cfgshmPtr == (CFG_SHM *) 0)
   {
    printf("Error in attaching shared memory, %s\n",strerror(errno));
    exit(0);
   }
                                                //get the configuration 
                                                //data from shared memory
  printf("IP address : %s\n",cfgshmPtr->ipaddr);             
  printf("Port number: %d\n",cfgshmPtr->portno);
  printf("Protocol name: %s\n",cfgshmPtr->protocol);
  printf("Message queue name: %s\n",cfgshmPtr->msgqname);
  printf("Semaphore name: %s\n",cfgshmPtr->semname);

  if(shmdt(cfgshmPtr) < 0)                   //detach the shared memory  
     printf("Error in detaching shared memory segment, %s\n",strerror(errno)); 
 
  if(shmctl(shmid,IPC_RMID,0) < 0)           //remove the shared memory segment
     printf("Error in removing shared memory segment, %s\n",strerror(errno));
  else
    printf("Shared memory removed successfully\n");
}

