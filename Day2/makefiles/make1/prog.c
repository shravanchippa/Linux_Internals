# include "myhead.h"

main()
{
	int num[10];
	int i,sum,prod,diff;
	float Mean;
	printf("enter 10 ints\n");
	for(i=0;i<5;i++)
		scanf("%d",&num[i]);
	sum=add(num);

	Mean=mean(sum,5);

	prod=mul(num[0],num[2]);

	diff=sub(num[1],num[2]);

	printf("sum=%d\n mean=%f\n prod=%d\n diff=%d\n",sum,Mean,prod,diff);
}
