#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int terminal;

int main(int argc, char* argv[]){
	if(argc > 2){
		  exit(EXIT_FAILURE);
	}

	terminal = atoi(argv[1]);
	int id = fork();
	printf("Hello World \n");

	if(id > 0){
		printf("Parent: %d\n", terminal+1);
	}else if(id == 0){
		printf("Child: %d\n", terminal-1);
	}else{
		  exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
