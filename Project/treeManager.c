#include <stdio.h>
#include <stdlib.h>
#include "headers/structures.h"

/* ici les fonctions qui vont gérer la structure de l'arbre */
/* !!! PAS DE FONCTION MAIN !!! */


Tree initializeTree(char letter){
	Tree newtree=(Tree)malloc(sizeof(Node));
	if (newtree != NULL) {
		newtree->leftChild=NULL;
		newtree->rightBro=NULL;
		newtree->letter=letter;
	}
	return newtree;
}


// fonction placée à l'arrache, à déplacer le temps voulu
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


void printWord(Tree a, char* buffer, int index)
{
	if(a!=NULL)
	{
		buffer[index]=a->letter;

		if(a->letter=='\0')
			printf("%s\n", buffer);

		else 
			printWord(a->leftChild, buffer, index+1);

		printWord(a->rightBro, buffer, index);
	}
}

void infix(Tree tree)
{

	if(tree->leftChild!=NULL)
	{
		infix(tree->leftChild);
	}
	printf("%c ", tree->letter);
	if(tree->rightBro!=NULL)
	{
		infix(tree->rightBro);
	}
}

void prefix(Tree tree)
{
	printf("%c ", tree->letter);
	if(tree->leftChild!=NULL)
	{
		prefix(tree->leftChild);
	}

	if(tree->rightBro!=NULL)
	{
		prefix(tree->rightBro);
	}

}
void postfix(Tree tree)
{
	
	if(tree->leftChild!=NULL)
	{
		postfix(tree->leftChild);
	}

	if(tree->rightBro!=NULL)
	{
		postfix(tree->rightBro);
	}
	printf("%c ", tree->letter);

}





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
    char word[20]; // au hasard balathazar
    char buff[20];
    int i=0;
    printf("\nHello. Which word would you like to search in our splendid lexical tree? \n");
    scanf("%s", word);
    
   if(search(tree, word))
		printf("%s present\n", word);

	else
		printf("%s absent\n", word);

	printWord(tree, buff, i);
	prefix(tree);

	return EXIT_SUCCESS;
}