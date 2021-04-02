#define _POSIX_C_SOURCE 200809L
#define NTHREADS 2
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// define the struct
struct input_args{
	char* a;
	char* b;
};

typedef struct input_args IA;

// function
// open a given file name
// read the file line by line and count for th enumber of times football is in there
// print the count
void* file_read(void *arg){
	IA* args = (IA*) arg;
	FILE *fp;
	char *buffer = NULL;
	char* tempbuffer = NULL;
	size_t bufsize = 0;
	ssize_t characters;
	int count=0;
	fp = fopen(args->a, "r");
	if(fp == NULL){
		exit(EXIT_FAILURE);
	}

	while((characters = getline(&buffer, &bufsize, fp) != -1)){
		tempbuffer = buffer;
		while((tempbuffer = strstr(tempbuffer, args->b)) != NULL){
			count +=1;
			*tempbuffer = *tempbuffer + strlen(args->b);
		}
		
	/*	while(1){
			temp = strstr(temp, args->b);
			if(temp != '\0'){
				count++;
				temp = temp + searchl;
			}
			else{
				break;
			}
		}*/

	}
	fclose(fp);
	printf("%s Count: %d\n", args->b, count);
	return NULL;
}


int main(int argc, char* argv[]){
	if(argc != 5 ){
		exit(EXIT_FAILURE);
	}

	// create the threads
	pthread_t tid[NTHREADS];
	// thread 1: clickstream football
	IA arg1 ={.a = argv[1], .b = argv[2]};
	pthread_create(&tid[0], NULL, file_read, (void*) &arg1);

	IA arg2 = {.a = argv[3], .b = argv[4]};
	// thread 2: enwik9 username lol
	pthread_create(&tid[1], NULL, file_read, (void*) &arg2);
	// close
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	exit(EXIT_SUCCESS);
}
