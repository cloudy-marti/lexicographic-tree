#include <stdio.h>
#include <stdlib.h>
#include "headers/structures.h"
#include "headers/treeManager.h"

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

	if((*word == '.') || (*word == ',') || (*word == ';') || (*word == '\'')){
		return createTree(&(*tree), word+1);
	}

	if(*tree == NULL){

		*tree = initializeTree(*word);
		if(*word != '\0'){
			return createTree(&(*tree)->leftChild, word+1);
		}else
			return 1;
	/* empty tree ; create the first node and its children */
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

/* search a word in our tree. */
int search(Tree tree, char* word){

	if(tree == NULL)
		return 0;    
	if(tree->letter == *word){
		if(*word == '\0')
			return 1;
		else 
			return search(tree->leftChild, word+1);
	}
	else if(tree->letter > *word)
			return 0;
		else 
			if(tree->letter < *word)
				return search(tree->rightBro, word);
			else 
				return 0;
}
/* Affichage à la console */

void printWord(Tree tree, char* buffer, int index, FILE* file, int mode){

	if(tree == NULL){
		return;
	}

	buffer[index] = tree->letter;

	if(tree->letter == '\0'){
		if(mode == 0){
			printf("%s\n", buffer);
		}else if(mode == 1){
			fprintf(file, "%s\n", buffer);
		}
	}else {
		printWord(tree->leftChild, buffer, index+1, file, mode);
	}

	printWord(tree->rightBro, buffer, index, file, mode);
}

void printWordFull(Tree tree, FILE* file, int mode){
	char* buffer = (char*)malloc(sizeof(char)*MAXWORD);
	printWord(tree, buffer, 0, file, mode);
	free(buffer);
}

void prefixSaveDico(Tree tree, FILE* file){

	if(tree == NULL){
		printf("\n");
		fprintf(file, "\n");
	}

	if(tree->letter == '\0'){
		printf(" ");
		fprintf(file, " ");
	}else{
		printf("%c", tree->letter);
		fprintf(file, "%c", tree->letter);
	}

	if(tree->leftChild != NULL){
		prefixSaveDico(tree->leftChild, file);
		printf("\n");
		fprintf(file, "\n");
	}

	if(tree->rightBro != NULL){
		prefixSaveDico(tree->rightBro, file);
	}
}

void createTreeFromDico(Tree* tree, FILE* fileName){
	char letter;

	if(fscanf(fileName, "%c", &letter) == EOF)
		return;

	switch(letter){
		case '\n':
			break;

		case ' ':
			*tree = initializeTree('\0');
			createTreeFromDico(&((*tree)->rightBro), fileName);
			break;

		default:
			*tree = initializeTree(letter);
			createTreeFromDico(&((*tree)->leftChild), fileName);
			createTreeFromDico(&((*tree)->rightBro), fileName);
			break;
	}
}