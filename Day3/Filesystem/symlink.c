# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
main(int argc, char**argv)
{
	int retval;
	if(argc!= 3){
		printf("Error in arguments\n"); exit(0);
	}	
	if((retval = symlink(argv[1], argv[2])) ==-1 )
		perror("Can not create link");
	system("ls -l");

	//unlink(argv[2]);
}
