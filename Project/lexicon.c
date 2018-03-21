#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/structures.h"
#include "headers/fileManager.h"


int main(int argc, char** argv){
	/*char* word = initializeUserInput();
	printf("choose a word\n");
	userInput(word);*/

	FILE* file;

	char* fileName = "hp.txt";
	char* mode = "r";

	printf("file name : %s\n", fileName);

	char path[] = "files/";
	printf("The file %s is in the folder %s\n", fileName, path);

	strcat(path, fileName);
	printf("your path : %s\n", path);

	file = fopen(path, mode);

	char input[MAXWORD];

	while(fscanf(file, "%51s", input) != EOF){
		printf("word -> %s\n", input);
	}

	printf("end of program\n");

	fclose(file);

return EXIT_SUCCESS;

}