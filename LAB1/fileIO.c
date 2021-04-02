#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]){
	// storing vars
	FILE *fp;
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters; // returns in negative or positive

	int count = 0;
	
	// error for incorrect number of arguments
	if(argc != 3){
		printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}
	
	// opens the file
	fp = fopen(argv[1], "r");
	if(fp == NULL){
		exit(EXIT_FAILURE);
	}

	// reads file line by line
	while((characters = getline(&buffer, &bufsize, fp)) != -1){
		if(strstr(buffer, argv[2]) != '\0'){
			count++;
		}  	
	}	
	// count the number of lines that contain at least one occurences
	// prints the number of lines that contain
	printf("%d\n", count);
 
	// closes the file
	fclose(fp);
	exit(EXIT_SUCCESS);
}
