#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

char global[5];
pthread_mutex_t r_mutex;
sem_t sem1, sem2;
int w, r;

void *print_lower(void* arg){
	int* id = (int*) arg;
	int i;
	for(i = 0; i < 5; i++){
		sem_wait(&sem1);
		pthread_mutex_lock(&r_mutex);
		global[w] = rand() % 26 + 97;
		printf("writer ID: %d, char written: %c\n", *id, global[w]);
		w = (w + 1) % 5;
		pthread_mutex_unlock(&r_mutex);
		sem_post(&sem2);
	}
	return NULL;
}

void *print_upper(void* arg){
	int* id = (int*) arg;
	int i;
	for(i = 0; i < 5; i++){
		sem_wait(&sem1);
		pthread_mutex_lock(&r_mutex);
		global[w] = rand() % 26 + 65;
		printf("writer ID: %d, char written: %c\n", *id, global[w]);
		w = (w + 1) % 5;
		pthread_mutex_unlock(&r_mutex);
		sem_post(&sem2);
	}
	return NULL;
}

void *read_buffer(void* arg){
	int* id = (int*) arg;
	int i;
	for(i = 0; i < 5; i++){
		sem_wait(&sem2);
		pthread_mutex_lock(&r_mutex);
		printf("reader ID: %d, char read: %c\n", *id, global[r]);
		r = (r + 1) % 5;
		pthread_mutex_unlock(&r_mutex);
		sem_post(&sem1);
	}
	return NULL;
}

int main(int argc, char* argv[]){
	if(argc != 1){
		exit(EXIT_FAILURE);
	}
	sem_init(&sem1, 1, 5);
	sem_init(&sem2, 1, 0);
	pthread_mutex_init(&r_mutex, NULL);
	
	(void)argv[0];

	pthread_t tid[8];
	w = 0;
	r = 0;
	int zero = 0;
	int one = 1;
	int two = 2;
	int three = 3;
	pthread_create(&tid[0], NULL, print_lower, (void*) &zero);
	pthread_create(&tid[1], NULL, print_lower, (void*) &one);
	pthread_create(&tid[2], NULL, print_upper, (void*) &two);
	pthread_create(&tid[3], NULL, print_upper, (void*) &three);
	pthread_create(&tid[4], NULL, read_buffer, (void*) &zero);
	pthread_create(&tid[5], NULL, read_buffer, (void*) &one);
	pthread_create(&tid[6], NULL, read_buffer, (void*) &two);
	pthread_create(&tid[7], NULL, read_buffer, (void*) &three);
	int i ;
	for(i = 0; i < 8; i++){
		pthread_join(tid[i], NULL);
	}
	exit(EXIT_SUCCESS);
}
