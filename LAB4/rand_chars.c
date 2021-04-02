#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_lower(){
	printf("%c\n", rand() % 26 + 97);
}

void print_cap(){
	printf("%c\n", rand() % 26 + 65);
}

int main(int argc, char* argv[]){
	if(argc != 2){
		exit(EXIT_FAILURE);
	}

	char* c = argv[1];
	int i;

	for(i = 0 ; i < 10; i++){
		if(strcmp("-u", c) == 0){
			print_cap();
		}
		else if(strcmp("-l", c) == 0){
			print_lower();
		}else{
			printf("mom");
			exit(EXIT_FAILURE);
		}
	}

	exit(EXIT_SUCCESS);
}
