#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/structures.h"

/* !!! PAS DE FONCTION MAIN !!! */

char* filePath(char* fileName){
	printf("file name : %s\n", fileName);

	char* path = "files/";
	printf("The file %s is in the folder %s\n", fileName, path);

	strcat(path, fileName); // concatenate two strings
	printf("your path : %s\n", path);
	
	return path;
}
// this function above allow us to retrieve the file path in a char*

void getLexicon(char* fileName, char* mode){

	char* path = filePath(fileName);

	FILE* file;
	file = fopen(path, mode);

	char* input = (char*)malloc(sizeof(char)*MAXWORD);

	while(fscanf(file, "%51s", input) != EOF){
		printf("word -> %s\n", input);
		// addWord(tree, input);
	}

	fclose(file);
}

void saveLexicon(Tree tree){

}

void closeFile(FILE* file){
	fclose(file);
	printf("end of program\n");
}