#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[]){
	// storing vars
	FILE *fp;
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters;
	int count1 = 0, count2 = 0;
	clock_t begin, end;
	double time;
	int searchl;

	// error for incorrect arguments
	if(argc != 5){
		printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}

	// time start?
	begin = clock();	

	// open 1st file and read line by line
	fp = fopen(argv[1], "r");
	if(fp == NULL){
		exit(EXIT_FAILURE);
	}
	// finding the length of the argv[2] :(
	for(searchl = 0; argv[2][searchl] != '\0'; searchl++); 

	// search for the word
	while((characters = getline(&buffer, &bufsize, fp)) != -1){
		char* temp = buffer;
		while(1){
			temp = strstr(temp, argv[2]);
			if(temp != '\0'){
				count1++;
				temp = temp + searchl;
			}else{
				break;
			}
		}
	}
	fclose(fp);
	
	// open 1st file and read line by line
	fp = fopen(argv[3], "r");
	if(fp == NULL){
		exit(EXIT_FAILURE);
	}
	// finding the length of the argv[2] :(
	for(searchl = 0; argv[4][searchl] != '\0'; searchl++); 

	// search for the word
	while((characters = getline(&buffer, &bufsize, fp)) != -1){
		char* temp = buffer;
		while(1){
			temp = strstr(temp, argv[4]);
			if(temp != '\0'){
				count2++;
				temp = temp + searchl;
			}else{
				break;
			}
		}
	}
	fclose(fp);
	// search for the word
	// print the count
	printf("%s Count: %d\n", argv[2], count1);
	printf("%s Count: %d\n", argv[4], count2);
	// time end
	end = clock();
	// find elapsed time and create readme.md and record the time taken
	time = (double) (end-begin);
	fp = fopen("README.md", "w+");
	fprintf(fp, "Time: %lf", time);
	fclose(fp);
	exit(EXIT_SUCCESS);
}
