#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]){

	// putting this in here if the args is incorrect
	if(argc > 3 || argc == 1){
		exit(EXIT_FAILURE);
	}

	// if the input is printf
	else if(strcmp(argv[1], "printf") == 0){
		printf("You entered: %s", argv[2]);
	}

	// if the input is fprintf
	else if(strcmp(argv[1], "fprintf") == 0){
		FILE *f;
		f = fopen("print.txt", "w+");
		fprintf(f, "%s", argv[2]);
		fclose(f);
	}

	// if the input is scanf
	else if(strcmp(argv[1], "scanf") == 0){
		char second[50];		
		printf("Please enter your input: ");
		scanf("%49s", second);
		printf("You entered: %s\n", second);
	}
	else if(strcmp(argv[1], "scanf") != 0 && strcmp(argv[1], "fprintf") != 0 && strcmp(argv[1], "printf") != 0){
	printf("Error: Incorrect first argument\n");
	exit(EXIT_FAILURE);	
}
	exit(EXIT_SUCCESS);

}





