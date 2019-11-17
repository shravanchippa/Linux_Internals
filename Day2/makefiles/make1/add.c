//# include "myhead.h"
int add(int *num)
{
	int i,total=0;
	for(i=0;i<5;i++)
		total += *(num+i);
	return total;
}
