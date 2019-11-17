#include<stdio.h>
int getinput(void);
void printmessage(int counter,int input);

int main()
{
	int counter;
	int input;
	for(counter=0;counter< 200;counter++)
	{
		input=getinput();
		if(input==-1) exit(0);
		printmessage(counter,input);
	}
	return 0;
}


int getinput(void)
{
	int input;
	char *ptr;
	ptr[0] = 1;
	printf("enter an input (use -1 to exit)");
	scanf("%d",input);
	return input;
}

void printmessage(int counter,int input)
{
	printf("for counter %d you entered input \n",counter,input);
}
	
