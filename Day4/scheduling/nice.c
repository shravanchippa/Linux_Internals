# include <stdio.h>
main()
{
	//for(;;);//default nice value may be 0 and priority is 25

	//The process heigher the nice value, more kind to others

//	nice(12);     //inc nice value by 12 priority is 37
//	for(;;);
	
	//Lower the nice value best candidate to be scheduled
	nice(-12);// inc nice value by -12 priority will be 13
	for(;;);

}
