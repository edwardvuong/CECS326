#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

sem_t U, V;

// ordering of thread execution controlled by semaphores

void *thread1(void *arg)
{
//	sem_wait(&U);
	printf("Thread1\n");
	sem_post(&U);
	pthread_exit(0);
}

void *thread2(void *arg)
{
	sem_wait(&V);
	printf("Thread2\n");
//	sem_post(&U);
	pthread_exit(0);
}

void *thread3(void *arg)
{
	sem_wait(&U);
	printf("Thread3\n");
	sem_post(&V);
	pthread_exit(0);
}

int main(){
	sem_init(&U, 0, 0);	// sem_t *sem: the semaphore to initialize
						// int pshared: 0 if shared between thread
						//				1 if shared between processes
						// unsigned int value: initial semaphore value
	sem_init(&V, 0, 0);
	pthread_t t1, t2, t3;
	pthread_create(&t2, NULL, thread2, NULL);
	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t3, NULL, thread3, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	sem_destroy(&U);
	sem_destroy(&V);
	return 0;
}

