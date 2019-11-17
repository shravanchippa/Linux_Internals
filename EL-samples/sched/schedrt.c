/*
 *  systems calls related to real-time processes
*/

#include <sched.h>

int main(int argc, char **argv)
{
	int policy, cpolicy;
	struct sched_param p;
	int priority_min, priority_max, interval;
	struct timespec tp;
	
	p.sched_priority = 99;
	policy = SCHED_RR;
	sched_setscheduler(0, policy, &p);
	policy = sched_getscheduler(0);
	printf("policy = %d\n", policy);

	priority_min = sched_get_priority_min(policy);
	priority_max = sched_get_priority_max(policy);
	sched_rr_get_interval(0, &tp);
	printf("min = %d max = %d\n", priority_min, priority_max);
	printf("tv_sec = %d tv_nsec = %d\n", tp.tv_sec, tp.tv_nsec);
	
	return 0;
}

