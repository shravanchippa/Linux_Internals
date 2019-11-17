# include <unistd.h>
main()
{
	if(fork() == 0){
		int i = 0;
		for(; i < 100; i++)
			printf("%d\t",i);
	sleep(10);
	}
	else{
		printf("**********");
		exit(0);
		printf("&&&&&&&&&&&");
	}
}
