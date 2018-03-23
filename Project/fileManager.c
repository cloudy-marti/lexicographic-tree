#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "headers/structures.h"
#include "headers/fileManager.h"
#include "headers/treeManager.h"

char* filePath(char* fileName, char* path){

	printf("file name : %s\n", fileName);

	printf("The file %s is in the folder %s\n", fileName, path);

	strcat(path, fileName); // concatenate two strings
	printf("your path : %s\n", path);
	
	return path;
}
// this function above allow us to retrieve the file path in a char*

char* fileExt(char* fileName, char* extension){
	printf("file name : %s\n", fileName);

	printf("new extension of %s will be : %s\n", fileName, extension);

	strcat(fileName, extension);
	printf("name of file : %s\n", fileName);

	return fileName;
}

void getLexicon(char* fileName, char* mode, Tree tree){

	char folder[] = "txt/";
	char* path = filePath(fileName, folder);

	FILE* file;
	file = fopen(path, mode);

	char input[MAXWORD] = "";

	while(fscanf(file, "%51s", input) != EOF){
		*input = tolower(*input);
		printf("word -> %s\n", input);

		createTree(&tree, input);
		//createFile(fileName, ".L", input);
	}

	printWordFull(tree);

	fclose(file);
	printf("file closed\n");
}

void createFile(char* fileName, char* extension, char* input){

	char* path = filePath(fileExt(fileName, extension), "bin/");
	FILE* file;

	file = fopen(path, "a+");

	printf("%s\n", input);

	fclose(file);
	printf("file writen\n");
}