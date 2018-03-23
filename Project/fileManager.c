#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/structures.h"
#include "headers/treeManager.h"

int createTree(Tree* tree, char* word){
	if(*tree == NULL){
		*tree = initializeTree(*word);
		if(*word != '\0'){
			return createTree(&(*tree)->leftChild, word+1);
		}else
			return 1;
	// empty tree ; create the first node and its children
	}else if((*tree)->letter < *word){
		return createTree(&(*tree)->rightBro, word);
	}else if((*tree)->letter > *word){
		initializeTree((*tree)->letter);
		(*tree)->rightBro = *tree;
		return createTree(&(*tree)->rightBro, word);
	}else
		return 0;
}

char* filePath(char* fileName, char* path){
	printf("file name : %s\n", fileName);

	printf("The file %s is in the folder %s\n", fileName, path);

	strcat(path, fileName); // concatenate two strings
	printf("your path : %s\n", path);
	
	return path;
}
// this function above allow us to retrieve the file path in a char*

void getLexicon(char* fileName, char* mode){

	char* path = filePath(fileName, "files/");

	FILE* file;
	file = fopen(path, mode);

	char* input = (char*)malloc(sizeof(char)*MAXWORD);

	while(fscanf(file, "%51s", input) != EOF){
		printf("word -> %s\n", input);
		// createTree(tree, input);
	}

	fclose(file);
	printf("file closed\n");
}

char* fileExt(char* fileName, char* extension){
	printf("file name : %s\n", fileName);

	printf("new extension of %s will be : %s\n", fileName, extension);

	strcat(fileName, extension);
	printf("name of file : %s\n", fileName);

	return fileName;
}

void createFile(char* fileName, char* extension){

	char* path = filePath(fileExt(fileName, extension), "bin/");

	FILE* newFile;
	
}

void saveLexicon(Tree tree){

}