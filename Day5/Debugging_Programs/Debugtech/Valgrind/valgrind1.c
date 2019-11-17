#include <stdio.h>
#include <stdlib.h>

void get_mem()
{
	char *ptr;
	ptr = (char *) malloc(10);  /*memory not freed */
}

int main(void)
{
	char *ptr1,*ptr2;
	int i;
		
	ptr1 = (char *) malloc(512);
	ptr2 = (char *) malloc(512);
	free(ptr2);
	free(ptr1);
	
	for (i=0;i<512;i++)
	{
		get_mem();
	}
}
