/*
 * Program demonstrating shared memory
*/

#include "shm.h"

int main()
{
  CFG_SHM *cfgshmPtr,cfgdata;                                
  int shmid;
  
  shmid = shmget(SHMKEY,sizeof(CFG_SHM),IPC_CREAT|PERMS);   //create the shared
  if(shmid < 0)                                             //memory segment
   {
    printf("Error in getting shared memory, %s",strerror(errno));
    exit(0);
   }
  
  cfgshmPtr = (CFG_SHM *) shmat(shmid,0,0);     //attach it to the 
  if(cfgshmPtr == (CFG_SHM *) 0)                //process
   {
    printf("Error in attaching shared memory, %s",strerror(errno));
    exit(0);
   }
                                             //get the configuration
                                             //data from user  
  printf("Enter the IP address :");
  scanf("%s",cfgdata.ipaddr);
  printf("Port number:");
  scanf("%d",&(cfgdata.portno));
  printf("Protocol name:");
  scanf("%s",cfgdata.protocol);
  printf("Message queue name:");
  scanf("%s",cfgdata.msgqname);
  printf("Semaphore name:");
  scanf("%s",cfgdata.semname);
                                            //copy the data to shared memory 
  memcpy((void *)cfgshmPtr,(const void *)&cfgdata,sizeof(CFG_SHM));

  if(shmdt(cfgshmPtr) < 0)                 //detach the shared memory segment 
    printf("Error in detaching shared memory segment, %s\n",strerror(errno));
}

