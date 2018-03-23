#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "headers/structures.h"
#include "headers/fileManager.h"
#include "headers/treeManager.h"

char* joinString(char* lastWord, char* firstWord){

	printf("file name : %s\n", lastWord);

	printf("we will unite %s and %s\n", lastWord, firstWord);

	strcat(firstWord, lastWord); // concatenate two strings
	printf("new file name : %s\n", firstWord);
	
	return firstWord;
}
// this function above allow us to retrieve the file path in a char*

void getLexicon(char* fileName, char* mode, Tree tree){

	char folder[] = "txt/";
	//char extension[] = ".L";

	char* path = joinString(fileName, folder);
	//char* newFile = joinString(fileName, extension);

	FILE* file;
	file = fopen(path, mode);

	FILE* outFile;
	outFile = fopen("bin/hp.txt.L", "a+");

	char input[MAXWORD] = "";

	while(fscanf(file, "%51s", input) != EOF){
		*input = tolower(*input);
		printf("word -> %s\n", input);
		createTree(&tree, input);
	}

	printWordFull(tree, outFile);

	fclose(file);
	printf("file closed\n");
}