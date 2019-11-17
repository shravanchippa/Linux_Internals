#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int prime(int num);
int faster(int num);

int main()
{
	int i;
	int colcnt = 0;
	for (i=2;i<=50000;i++)
		if (prime(i))
		{
			colcnt++;
			if(colcnt % 9 == 0)
			{
				printf ("%5d\n",i);	
				colcnt = 0;
			}
			else
				printf ("%5d ",i);
		}
		putchar('\n');
		return 0;
}

int prime(int num)
{
	/*Check to see if the number is a prime?*/

int i;
for(i=2;i <= faster(num);i++)
	if(num % i == 0)
		return 0;
	return 1;
}

int faster(int num)
{
	return (int) sqrt( (float) num);
}
