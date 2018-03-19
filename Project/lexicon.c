#include <stdio.h>
#include <stdlib.h>
#include "headers/structures.h"
#include "headers/userManager.h"

int main(int argc, char** argv){

	char* word = initializeUserInput();
	printf("choose a word\n");
	userInput(word);

	return EXIT_SUCCESS;
}