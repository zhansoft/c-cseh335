#ifndef ASIZE
	#define ASIZE 1000
#endif
#ifndef NTHREADS
	#define NTHREADS 2
#endif

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int sum = 0;
int array[ASIZE];

struct start_end{
	int s;
	int e;
};

typedef struct start_end arr;

void* sum_array(void* arg){
	arr* args = (arr*) arg;
	int i;
	for(i = args->s; i < args->e; i++){
		sum += array[i];
	}
	return NULL;
}



int main(int argc, char* argv[]){
	if(argc != 2){
		exit(EXIT_FAILURE);
	}

	// array
	int i;
	for(i = 0; i < ASIZE; i++){
		array[i] = i*atoi(argv[1]);
	}

	// create the nTHREADS
	pthread_t tid[NTHREADS];
	arr threads[NTHREADS];
	for(i = 0; i < NTHREADS; i++){
		threads[i].s = (ASIZE * i)/NTHREADS;
		threads[i].e = (ASIZE * (i+1))/NTHREADS;
		pthread_create(&tid[i], NULL, sum_array, (void*) &threads[i]);
	}
	for(i =0; i < NTHREADS; i++){
		pthread_join(tid[i], NULL);
	}
	printf("%d\n", sum);

	// PROFIT
	exit(EXIT_SUCCESS);
}
