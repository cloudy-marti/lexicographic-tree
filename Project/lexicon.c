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

void printWord(Tree tree, char* buffer, int index){

	if(tree == NULL){
		return;
	}

	buffer[index]=tree->letter;

	if(tree->letter == '\0'){
		printf("%s\n", buffer);
	}else {
		printWord(tree->leftChild, buffer, index+1);
	}

	printWord(tree->rightBro, buffer, index);
}

void printWordFull(Tree tree){
	char* buffer = (char*)malloc(sizeof(char)*MAXWORD);
	printWord(tree, buffer, 0);
}

int createTree(Tree* tree, char* word){


	if(*tree == NULL){
		*tree = initializeTree(*word);
		if(*word != '\0'){
			return createTree(&(*tree)->leftChild, word+1);
		}else
			return 1;
	// empty tree ; create the first node and its children
	}else if((*tree)->letter == *word){
		return createTree(&(*tree)->leftChild, word+1);
	}else if((*tree)->letter < *word){
		return createTree(&(*tree)->rightBro, word);
	}else if((*tree)->letter > *word){

		Tree oldTree = *tree;
		*tree = initializeTree(*word);
		(*tree)->rightBro = oldTree;	
	
		if(word[0] != '\0'){
			return createTree(&(*tree)->leftChild, word+1);
		}
		return 1;
	}else{
		return 0;
	}
}


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
    // char* buff = (char*)malloc(sizeof(char)*MAXWORD);

    // int i = 0;

	Tree newTree;
	char* wiWord = (char*)malloc(sizeof(char)*MAXWORD);
	char* newWord = (char*)malloc(sizeof(char)*MAXWORD);

	printf("choose a word\n");
	scanf("%s", word);

	int add = createTree(&newTree, word);
	printf("yep\n");

	if(add == 0){
		printf("oops problem\n");
	}else
		printf("word added successfully !\n");

	// printWord(newTree, buff, i);

	printWordFull(newTree);

	printf("choose a word\n");
	scanf("%s", wiWord);

	int add1 = createTree(&newTree, wiWord);
	printf("yep\n");

	if(add1 == 0){
		printf("oops problem\n");
	}else
		printf("word added successfully !\n");

	// printWord(newTree, buff, i);
	printWordFull(newTree);

	printf("choose a word\n");
	scanf("%s", newWord);

	int add2 = createTree(&newTree, newWord);

	if(add2 == 0){
		printf("oops problem\n");
	}else
		printf("word added successfully !\n");

	// printWord(newTree, buff, i);
	printWordFull(newTree);


return EXIT_SUCCESS;

}