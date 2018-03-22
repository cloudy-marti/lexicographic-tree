#include <stdio.h>
#include <stdlib.h>
#include "headers/structures.h"

/* ici les fonctions qui vont gérer la structure de l'arbre */
/* !!! PAS DE FONCTION MAIN !!! */


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

void infix(Tree tree){

	if(tree->leftChild!=NULL){
		infix(tree->leftChild);
	}

	printf("%c ", tree->letter);

	if(tree->rightBro!=NULL){
		infix(tree->rightBro);
	}
}

void prefix(Tree tree){

	printf("%c ", tree->letter);

	if(tree->leftChild!=NULL){
		prefix(tree->leftChild);
	}

	if(tree->rightBro!=NULL){
		prefix(tree->rightBro);
	}
}

void postfix(Tree tree){
	
	if(tree->leftChild!=NULL){
		postfix(tree->leftChild);
	}

	if(tree->rightBro!=NULL){
		postfix(tree->rightBro);
	}

	printf("%c ", tree->letter);

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

// exemple nul de main en considérant que l'arbre est rempli
int main(int argc, char** argv){

   Tree tree;

   tree=initializeTree('c');
   tree->leftChild=initializeTree('e');
   tree->leftChild->leftChild=initializeTree('\0');
   tree->leftChild->leftChild->rightBro=initializeTree('s');
   tree->leftChild->leftChild->rightBro->leftChild=initializeTree('\0');
   tree->rightBro=initializeTree('d');
   tree->rightBro->leftChild=initializeTree('e');
   tree->rightBro->leftChild->leftChild=initializeTree('s');
   tree->rightBro->leftChild->leftChild->leftChild=initializeTree('\0');
   tree->rightBro->rightBro=initializeTree('l');
   tree->rightBro->rightBro->leftChild=initializeTree('e');
   tree->rightBro->rightBro->leftChild->leftChild=initializeTree('\0');
   tree->rightBro->rightBro->leftChild->leftChild->rightBro=initializeTree('s');
   tree->rightBro->rightBro->leftChild->leftChild->rightBro->leftChild=initializeTree('\0');
   tree->rightBro->rightBro->leftChild->leftChild->rightBro->rightBro=initializeTree('t');
   tree->rightBro->rightBro->leftChild->leftChild->rightBro->rightBro->leftChild=initializeTree('t');
   tree->rightBro->rightBro->leftChild->leftChild->rightBro->rightBro->leftChild->leftChild=initializeTree('r');
   tree->rightBro->rightBro->leftChild->leftChild->rightBro->rightBro->leftChild->leftChild->leftChild=initializeTree('e');
   tree->rightBro->rightBro->leftChild->leftChild->rightBro->rightBro->leftChild->leftChild->leftChild->leftChild=initializeTree('\0');

    char* word = (char*)malloc(sizeof(char)*MAXWORD); // MAXWORD : in structures.h -> 51
    char* buff = (char*)malloc(sizeof(char)*MAXWORD);

    int i=0;

    printf("\nHello. Which word would you like to search in our splendid lexical tree? \n");
    scanf("%s", word);
    
   if(search(tree, word))
		printf("%s present\n", word);

	else
		printf("%s absent\n", word);

	printWord(tree, buff, i);
	prefix(tree);
	printf("\n");

	// Tree newTree;
	// char* wiWord = (char*)malloc(sizeof(char)*MAXWORD);
	// char* newWord = (char*)malloc(sizeof(char)*MAXWORD);

	// printf("choose a word\n");
	// scanf("%s", wiWord);

	// int add = createTree(&newTree, wiWord);
	// printf("yep\n");

	// if(add == 0){
	// 	printf("oops problem\n");
	// }else
	// 	printf("word added successfully !\n");

	// printf("choose a word\n");
	// scanf("%s", newWord);

	// int add2 = createTree(&newTree, newWord);

	// if(add2 == 0){
	// 	printf("oops problem\n");
	// }else
	// 	printf("word added successfully !\n");

	// printWord(newTree, buff, i);

	return EXIT_SUCCESS;
}