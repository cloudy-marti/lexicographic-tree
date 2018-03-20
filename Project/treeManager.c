#include <stdio.h>
#include <stdlib.h>
#include "headers/structures.h"

/* ici les fonctions qui vont gérer la structure de l'arbre */
/* !!! PAS DE FONCTION MAIN !!! */
// fonction placée à l'arrache, à déplacer le temps voulu
// search a word in our tree.
Tree search(Tree tree, char* word){

	if(tree == NULL)
		return NULL;    
	if(tree->letter == *word){
		if(*word == '\0')
			return tree;
		else 
			return search(tree->leftChild, word++);
	}else if(tree->letter < *word){
		return NULL;
	}else if(tree->letter > *word){
		return search(tree->rightBro, word++);
	}else 
		return NULL;
} // est-ce qu'on ne retourne pas plutôt un int ? pour dire oui ou non le mot est là

// exemple nul de main en considérant que l'arbre est rempli
// int main(int argc, char** argv){
//     Tree a;
//     char word[20]; // au hasard balathazar
//     int cmpt=0; //va servir pour aller de case en case dans notre fonction search. 
//     printf("\nHello. Which word would you like to search in our splendid lexical tree? \n");
//     scanf("%d", &word);
    
//     if((search(a, word, cmpt))!=NULL)
// 			printf("%d is in our tree. Cool!\n", word);

// 		else 
//             printf("%d isn'tree in our tree. Sad.", word);
    
// 	return EXIT_SUCCESS;
// }