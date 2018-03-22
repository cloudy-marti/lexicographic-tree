#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/structures.h"
#include "headers/fileManager.h"

Tree initializeTree(char letter){
	Tree newtree = (Tree)malloc(sizeof(Node));

	if(newtree == NULL){
		printf("ERROR : tree not initialized\n");
		exit(EXIT_FAILURE);
	}
	
	newtree->leftChild = NULL;
	newtree->rightBro = NULL;
	newtree->letter = letter;

	return newtree;
}

int createTree(Tree* tree, char* word){
	if(*tree == NULL){
		printf("so far\n");
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

void printWord(Tree tree, char* buffer, int index){

	if(tree != NULL){
		buffer[index]=tree->letter;

		if(tree->letter == '\0')
			printf("%s\n", buffer);

		else 
			printWord(tree->leftChild, buffer, index+1);

		printWord(tree->rightBro, buffer, index);
	}
}

// int createTree(Tree* tree, char* word){

// 	printf("beginning of function : %c\n", *word);

// 	*tree = initializeTree(*word);
// 	if(*word != '\0'){
// 		printf("creating tree\n");
// 		return createTree(&(*tree)->leftChild, word+1);
// 	}
// 	else
// 		printf("condition return 1\n");
// 		return 1;
	
// 	// if(*tree == NULL){
// 	// empty tree ; create the first node and its children

// 	if(*tree != NULL){
// 		if((*tree)->letter < *word){
// 			printf("tree->letter smaller than word\n");
// 			return createTree(&(*tree)->rightBro, word);

// 		}else if((*tree)->letter > *word){
// 			printf("tree->letter bigger than word\n");
// 			initializeTree((*tree)->letter);
// 			(*tree)->rightBro = *tree;
// 			return createTree(&(*tree)->leftChild, word+1);

// 		}else
// 			printf("condition return 0\n");
// 			return 0;
// 		}else
// 			return 0;
// }

int main(int argc, char** argv){
	/*char* word = initializeUserInput();
	printf("choose a word\n");
	userInput(word);*/

	// FILE* file;

	// char* fileName = "hp.txt";
	// char* mode = "r";

	// printf("file name : %s\n", fileName);

	// char path[] = "files/";
	// printf("The file %s is in the folder %s\n", fileName, path);

	// strcat(path, fileName);
	// printf("your path : %s\n", path);

	// file = fopen(path, mode);

	// char input[MAXWORD];

	// while(fscanf(file, "%51s", input) != EOF){
	// 	printf("word -> %s\n", input);
	// }

	// printf("end of program\n");

	// fclose(file);

	char* word = (char*)malloc(sizeof(char)*MAXWORD); // MAXWORD : in structures.h -> 51
    char* buff = (char*)malloc(sizeof(char)*MAXWORD);

    int i=0;

	Tree newTree;
	char* wiWord = (char*)malloc(sizeof(char)*MAXWORD);
	char* newWord = (char*)malloc(sizeof(char)*MAXWORD);

	printf("choose a word\n");
	scanf("%s", wiWord);

	int add = createTree(&newTree, wiWord);
	printf("yep\n");

	if(add == 0){
		printf("oops problem\n");
	}else
		printf("word added successfully !\n");

	printf("choose a word\n");
	scanf("%s", newWord);

	int add2 = createTree(&newTree, newWord);

	if(add2 == 0){
		printf("oops problem\n");
	}else
		printf("word added successfully !\n");

	printWord(newTree, buff, i);

return EXIT_SUCCESS;

}