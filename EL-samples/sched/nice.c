/*
 * Program demonstrating the use of fork()
 * priority system calls: nice(), getpriority()
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
  int childpid;
  if((childpid = fork()) > 0)              //if return value greater than zero
    {                                      //it is parent process 
      printf("I am in Parent Process\n");
      printf("Self process id=%d,Child process id=%d\n",getpid(),childpid);
      nice(4);
      printf("Parent's Priority=%d\n",getpriority(PRIO_PROCESS,0));
      wait(0);                             //wait for the child to terminate 
      printf("Parent Process exits..\n");
    }
  else if(childpid == 0)                   //child process
   {
     printf("I am in Child Process\n");
     printf("Parent process id=%d,Child process id=%d\n",getppid(),getpid());
     printf("Child's Priority=%d\n",getpriority(PRIO_PROCESS,0));
     printf("Child Process exits..\n"); 
   }
  return 0;
}

