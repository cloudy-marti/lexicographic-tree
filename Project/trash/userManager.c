#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/structures.h"
#include "headers/userManager.h"
#include <ctype.h>

/* !!! PAS DE FONCTION MAIN !!! */

char* initializeUserInput(){

	return (char*)malloc(sizeof(char)*MAXWORD);
}

char* userInput(char* input){

	scanf("%51s", input);
	printf("user has entered the word : %s\n", input);

	char* userInput = initializeUserInput();

	strcpy(userInput, input);

	fixInput(input);

	if(*input != '\0' && strcmp(input, userInput) != 0){
		printf("without user's bs we have the word : %s\n", input);
	}else if(strcmp(input, userInput) == 0){
		printf("ok\n");
	}else
		printf("what\n");

	return input;
}

void fixInput(char* input){

	int i;
	for(i = 0; input[i] != '\0'; i++){
		while(!( (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') /*|| (input[i] >= 'ü' && input[i] <= 'ù') || 
			input[i] == '\0' */)){
			// for(j = i; input[j] != '\0'; j++){
			// 	input[j] = input[j+1];
			// 	printf("ok\n");
			// }
			// input[j] = '\0';
		}
	}
}

// this function above will take off all the non alphabetical-characters from the strain
// considering that the user may enter whatever he wants
// we'll keep only the letters