#ifndef ASIZE
	#define ASIZE 1000
#endif
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>



int main(int argc, char* argv[]){
	if(argc != 2){
		exit(EXIT_FAILURE);
	}

	// create 1d array of size ASIZE
	int array[ASIZE];

	// initiliaze
	int i;
	for(i = 0; i < ASIZE; i++){
		array[i] = i*atoi(argv[1]);
	}

	// create a child process fork
	int sum;
	int fd[2];

	if(pipe(fd) <0){
		exit(EXIT_FAILURE);
	}
	int id = fork();
	if(id > 0){
		for(i = 0; i < ASIZE/2; i++){
			sum += array[i];
		}
		write(fd[1], &sum, sizeof(sum));
		int exitc;
		wait(&exitc);
		close(fd[1]);
		close(fd[0]);
	}else if(id ==0){
		read(fd[0], &sum, sizeof(sum));
		for(i = ASIZE/2; i < ASIZE; i++){
			sum += array[i];
		}
		printf("%d\n", sum);
		close(fd[1]);
		close(fd[0]);
		
	}else{
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
