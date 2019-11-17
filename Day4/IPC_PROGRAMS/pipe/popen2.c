/*****************************************************************************
	Program name: 	popen2.c
	Description:	out put of ls command is put into read end of pipe1.
			content of pipe1 is read by readbuff. Readbuf is 
			passed to sort command through pipe2.(One parent 
			and two children communication. More detail refer 
			program popen1.c) 
# Version 2.0 
# 17 sept 2004, vikas karanth <vikaskaranth@gmail.com>
# written to use as  program to ipc using pipe
 *****************************************************************************/

#include <stdio.h>

int main(void)
{
        FILE *pipein_fp, *pipeout_fp;
        char readbuf[80];

        /* Create one way pipe line with call to popen() */
        if (( pipein_fp = popen("ls", "r")) == NULL)
        {
                perror("popen");
                exit(1);
        }

        /* Create one way pipe line with call to popen() */
        if (( pipeout_fp = popen("wc -l", "w")) == NULL)
        {
                perror("popen");
                exit(1);
        }

        /* Processing loop */
        while(fgets(readbuf, 80, pipein_fp)) /*content of pipein_fp is put into
						readbuf */
                fputs(readbuf, pipeout_fp);/* content of readbuf is put into pip						eout_fp*/

        /* Close the pipes */
        pclose(pipein_fp);
        pclose(pipeout_fp);

        return(0);
}
