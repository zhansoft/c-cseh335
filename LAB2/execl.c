#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
	if(argc > 3){
		exit(EXIT_FAILURE);
	}
	char path[50] = "/bin/";
	strcat(path, argv[1]);
	execl(path, argv[1], argv[2], NULL);
	exit(EXIT_SUCCESS);
}
