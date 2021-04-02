#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	if(argc > 2){
		exit(EXIT_FAILURE);
	}

	int fd[2];
	if(pipe(fd) < 0){
		exit(EXIT_FAILURE);
	}

	char term[50];
	int id = fork();
	if(id < 0){
		exit(EXIT_FAILURE);
	} else if(id > 0){
		write(fd[1], argv[1], 50);
		int exitc;
		wait(&exitc);
		close(fd[0]);
		close(fd[1]);
		if(exitc != 0){
			exit(EXIT_FAILURE);
		}

	} else{
		read(fd[0], term, 50);
		printf("%s\n", term);
	}
	
	exit(EXIT_SUCCESS);
}
