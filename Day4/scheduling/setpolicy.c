/*******************************************************************************
                 setpolicy.c  -  description
                       -------------------
           begin                : Wed Jul 23 2003
           author               : (C) 2003 by Vikas
           email                : vikas@vsquareinfotech.com
	   Description: This program illustrates how we can set the policy 
		Round Robin for  this process
*********************************************************************************/
#include<sched.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/resource.h>

main()
{
	struct sched_param p1,p2;
	
	p1.sched_priority=14; /*Setting the priority*/

	if(sched_setscheduler(0,SCHED_RR,&p1)==-1) {
//	if(sched_setscheduler(0,SCHED_FIFO,&p1)==-1) {
		 /*setting the scheduling policy*/
		perror("sched_setscheduler");
		exit(1);
	}
		
	/*Getting the policy used and priority to the variable p2*/
        sched_getparam(0,&p2); 
	
	printf("priority of this program after setting policy:%d\n",\
	p2.sched_priority);
	
	printf("scheduler of this program after setting policy:%d\n",\
	sched_getscheduler(0));
}
