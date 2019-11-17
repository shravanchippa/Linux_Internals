/*************************************************************************

                          pipe1.c  -  description
                             -------------------

    used system calls are :
	int pipe(int fildes[2])
	read()
	write()
    version : 1.2
    Author : vikaskaranth@gmail.com
    Description :This program describs how pipe is used to read and write 
			in singe process.
    it under the terms of the GNU General Public License as published by  
    the Free Software Foundation; either version 2 of the License, or     
    (at your option) any later version.                                   
                                                                         
***************************************************************************/

main()
{
	int 	pipefd[2],   n;
	char	buff[100];

	if(pipe(pipefd) < 0) //create a pipe with two descriptors
		perror("filed in openning pipe\n");
	printf("read fd = %d, write fd = %d\n",pipefd[0],pipefd[1]);
	
	//write into the pipe's write decriptor
	if(write(pipefd[1],"hello world.....!",18)!= 18)
		perror("filed in writing pipe\n");

	//read from the pipe's read decriptor
	if((n = read(pipefd[0],buff,sizeof(buff))) < 0)
		perror("filed in writing pipe\n");
	
	write(1 , buff, n);	//write to the stdout
	exit(0);
}
