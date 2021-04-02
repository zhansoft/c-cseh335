#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n;

void *print_write(void* arg){
	int* temp = (int*) arg;
	n = *temp;
	int i;
	for(i = 0; i < *temp; i++){
		n = rand() % *temp;
		printf("writer wrote: %d\n", n);
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
	pthread_create(&tid[0], NULL, print_write, (void*) &read);
	int i;
	for(i = 0; i <read; i++){
		printf("main read: %d\n", n);
	}
	pthread_join(tid[0], NULL);
	exit(EXIT_SUCCESS);
}
