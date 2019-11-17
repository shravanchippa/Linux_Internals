//Thread Function to Process Jobs from the Queue
#include <malloc.h>
# include <pthread.h>

struct job {
				/* Link field for linked list. */
	struct job* next;
	int data;		/* Other fields describing work to be done... */
};

void process_job(struct job *);
void* thread_function (void* arg);
/* A linked list of pending jobs. */
struct job* job_queue = NULL;

main()
{
	pthread_t thread_id;
	struct job* queue;
	int i = 0;
	job_queue    = (struct job  *)malloc(sizeof(struct job));
	job_queue -> data = 1;
	job_queue ->next = NULL;

	queue = job_queue;	
	
	for(i = 1;i < 10; i++){
		queue = queue -> next;
		queue  = (struct job  *)malloc(sizeof(struct job));
		queue ->data = i;
		queue->next = NULL;
	}
	pthread_create(&thread_id,NULL, thread_function,NULL);
	pthread_join(thread_id, NULL);
}
	/* Process queued jobs until the queue is empty. */

void* thread_function (void* arg)
{
		struct job* next_job = job_queue;
	while (next_job != NULL) {
				/* Get the next available job. */
				/* Carry out the work. */
		//process_job(next_job);
	printf("The job is in process........");
	sleep(1);
	printf("The job output is %d\n",next_job ->data);
				/* Remove this job from the list. */
		//job_queue = job_queue->next;
		next_job = next_job -> next;

				/* Clean up. */
		//free (next_job);
	}
	return NULL;
}
/*
void process_job(struct job *Next_job)
{
	printf("The job is in process........");
	sleep(1);
	printf("The job output is %d\n",Next_job ->data);
}*/
