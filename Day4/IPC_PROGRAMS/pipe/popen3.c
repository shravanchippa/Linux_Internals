 /***************************************************************************** 
 	MODULE: 	popen3.c
	Description :   argv[1] is passed to popen function. Argv[2] is opened 
			in read mode content is put into readbuff.Content of
			readbuff is passed through pipe.	
	Running the program: a.out cat <file name> OR a.out head <fname>
	Comment send to :vikaskaranth@hotmail.com

# Version 2.0 
# 17 sept 2004, vikas karanth <vikaskaranth@gmail.com>
# written to use as  program to ipc using pipe
 *****************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
        FILE *pipe_fp, *infile;
        char readbuf[80];

        if( argc != 3) {
                fprintf(stderr, "USAGE:  popen3 [command] [filename]\n");       
                exit(1);
        }

        /* Open up input file */
        if (( infile = fopen(argv[2], "r")) == NULL)
        {
                perror("fopen");
                exit(1);        
        }

        /* Create one way pipe line with call to popen() */
        if (( pipe_fp = popen(argv[1], "w")) == NULL)
        {
                perror("popen");
                exit(1);
        }

        /* Processing loop */
        do { 
                fgets(readbuf, 80, infile);
                if(feof(infile)) break;

                fputs(readbuf, pipe_fp);
        } while(!feof(infile));

        fclose(infile); 
        pclose(pipe_fp);

        return(0);
}
  
