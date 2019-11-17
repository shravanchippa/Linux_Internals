/***************************************************************************
                          alarm.c  -  description
                             -------------------
    begin                : Wed Jul 23 2003

	used system calls are :
 	        pid_t fork(void);
		unsigned int alarm(unsigned int seconds);
		unsigned int sleep(unsigned int seconds);
		pid_t wait(int *status);
	        pid_t waitpid(pid_t pid, int *status, int options);

	structure used : NOne
	Discription:
		Child process sleeps for 2 seconds. By that, parent waits for
		childs termination. After childs termination parent process
		sets alarm for 3 secs, then goes to infinate loop. After 3 secs 
		when the alarm expaires kernel sends signal SIGALRM;
		due to that process terminates.    
	version : 1.4
	Author : vikaskaranth@gmail.com
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

main()
{
	int pid;
	pid = fork();
	if(pid == 0)
	{
		printf(" In Child Process\n");
		printf(" Child will go to sleep\n");
		sleep(2);	// Sleep for 2 secs
		printf(" Child woke up\n");
	}
	else
	{
		wait(0);
		printf(" In parent\n");
		printf( "Process will terminate in 3 secs\n");
		alarm(3);
		for(;;);
	}
}
		
