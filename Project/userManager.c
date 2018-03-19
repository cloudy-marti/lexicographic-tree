#include <stdio.h>
#include <stdlib.h>
#include "headers/structures.h"
#include <ctype.h>

/* !!! PAS DE FONCTION MAIN !!! */

char* initializeUserInput(){

	return (char*)malloc(sizeof(char)*MAXWORD);
}

char* userInput(char* input){

	scanf("%51s", input);
	printf("user has entered the word : %s\n", input);

	while(checkInput(input) == -1){
		printf("try again\n");
		scanf("%51s", input);
		printf("user has entered the word : %s\n", input);
	}

	return input;
}

int checkInput(char* input){

	int i;
	for(i = 0; input[i] != '\0'; i++){
		if(isalpha(input[i]) != 0){
			return -1;
		}else
			return 0;
	}
}