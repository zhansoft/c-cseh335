#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	if(argc > 3){
		exit(EXIT_FAILURE);
	}
	
	int fd[2];
	if(pipe(fd) <0){
		exit(EXIT_FAILURE);
	}
	write(fd[1], argv[1], 50);
	write(fd[1], argv[2], 50);
	char term1[50];
	char term2[50];
	read(fd[0], term1, 50);
	read(fd[0], term2, 50);
	printf("%s\n", term1);
	printf("%s\n", term2);
	exit(EXIT_SUCCESS);

}
