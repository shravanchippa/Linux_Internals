/***********************************************************************        ****
                          fpe.c  -  description
                                    -------------------
           begin                : Wed Jul 23 2003
***********************************************************************        ****/
#include<signal.h>
void handle(void);

main()
{
	int j;
	signal(SIGFPE,handle);
	j = 8/0;
}

void handle(void)
{
	printf(" Floating Point Error\n");
	exit(0);
}			
