#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int n;

//sem_t r_mutex, w_mutex;
pthread_mutex_t r_mutex, w_mutex;

void *print_write(void* arg){
	int* temp = (int*) arg;
	n = *temp;
	int i;
	for(i = 0; i < *temp; i++){
		pthread_mutex_lock(&w_mutex);
		n = rand() % *temp;
		printf("writer wrote: %d\n", n);
		pthread_mutex_unlock(&r_mutex);
	}
	return NULL;
}

int main(int argc, char* argv[]){
	if(argc != 2){
		exit(EXIT_FAILURE);
	}
	pthread_t tid[1];
	int read = atoi(argv[1]);
	if(read <= 0){
		exit(EXIT_FAILURE);
	}
	pthread_mutex_init(&w_mutex, NULL);
	pthread_mutex_init(&r_mutex, NULL);
	pthread_create(&tid[0], NULL, print_write,(void*)  &read);
	int i;
	sleep(1);
	for(i = 0; i <read; i++){
		pthread_mutex_lock(&r_mutex);
		printf("main read: %d\n", n);
		pthread_mutex_unlock(&w_mutex);
	}
	pthread_join(tid[0], NULL);
	exit(EXIT_SUCCESS);
}
