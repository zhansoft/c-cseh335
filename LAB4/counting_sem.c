#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore1;

void *print_a(){
	sem_wait(&semaphore1);
	printf("A\n");
	return NULL;
}

void *print_b(){
	sem_wait(&semaphore1);
	printf("B\n");
	return NULL;
}

void *print_c(){
	sem_wait(&semaphore1);
	printf("C\n");
	return NULL;
}

int main(int argc, char* argv[]){
	if(argc != 1){
		exit(EXIT_FAILURE);
	}

	(void) argv[0];

	sem_init(&semaphore1, 1, 2);
	
	pthread_t tid[3];
	pthread_create(&tid[0], NULL, print_a, NULL);
	// FIX for code issue
	sem_post(&semaphore1);
	pthread_create(&tid[1], NULL, print_b, NULL);
	pthread_create(&tid[2], NULL, print_c, NULL);
	
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);

	exit(EXIT_SUCCESS);
}
