#include <stdio.h>
#include <stdlib.h>
#include "headers/structures.h"
#include "headers/treeManager.h"

/* ici les fonctions qui vont gérer la structure de l'arbre */

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

// search a word in our tree.
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

void prefixSaveDico(Tree tree){

	printf("%c", tree->letter);

	if(tree->leftChild == NULL)
		printf(" ");
	if(tree->leftChild != NULL){
		prefix(tree->leftChild);
		printf("'%cn'", 92);
	}

	if(tree->rightBro != NULL){
		prefix(tree->rightBro);
	}
}


/* Affichage à la console */

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
