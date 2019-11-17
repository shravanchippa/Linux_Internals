/* file sh_library.c */
#include <stdio.h>

void _init()
{
        printf("Inside _init()\n"); 
}

void _fini()
{
        printf("Inside _fini()\n");
}

int dynamic_library_function(char *msg)
{
	printf("\nMessage from the dynamic library\n");
        printf("%s\n", msg);
        printf("=================================\n");
        return 0;
	return 0;
}

