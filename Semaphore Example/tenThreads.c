#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

sem_t U;

// semaphore controls number of threads that can be in CS

void *runner(void *arg)
{
	printf("Thread created\n");
	sleep(2);
	sem_wait(&U);
	printf("Thread in CS\n");
	sleep(2);
	printf("Thread leaving CS\n");
	sem_post(&U);
	pthread_exit(0);
}

int main(){
	int i;
	sem_init(&U, 0, 3);	// sem_t *sem: the semaphore to initialize
						// int pshared: 0 if shared between thread
						//				1 if shared between processes
						// unsigned int value: initial semaphore value
//	sem_init(&V, 0, 0);
	pthread_t tids[10];
	for(i = 0; i < 10; i++){
		pthread_create(&tids[i], NULL, runner, NULL);
	}
	for(i = 0; i < 10; i++){
		pthread_join(tids[i], NULL);
	}

	sem_destroy(&U);
	return 0;
}

