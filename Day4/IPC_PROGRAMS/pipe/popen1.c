/*****************************************************************************
	Preogram name: 	popen1.c
	
	Description:	program to open a pipe using popen.Shell creats a proces
			s to execute sort command newly created process is child
			process of a.out(process) pipe is established between
			parent and child. Parent sends strings to child which
			executes sort command. Parent reads from pipe (output)
			and prints in the moniter.
# Version 2.0 
# 17 sept 2004, vikas karanth <vikaskaranth@gmail.com>
# written to use as  program to ipc using pipe
 *****************************************************************************/
  
#include <stdio.h>

#define MAXSTRS 5 

int main(void)
{
        int  cntr;
        FILE *pipe_fp;
        char *strings[MAXSTRS] = { "I", "am ", "testing",
                                  "popen ", "here"};

        /* Create one way pipe line with call to popen() */
        if (( pipe_fp = popen("sort", "w")) == NULL)
        {
                perror("popen");
                exit(1);
        }
					        /* Processing loop */
        for(cntr=0; cntr<MAXSTRS; cntr++) {
                fputs(strings[cntr], pipe_fp);	//writing into pipe pointer
                fputc('\n', pipe_fp);		//reading from pipe pointer 
        }					

        /* Close the pipe */
        pclose(pipe_fp);
        
        return(0);
}
  
