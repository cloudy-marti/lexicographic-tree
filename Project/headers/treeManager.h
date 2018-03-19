#ifndef TREEMANAGER__H
#define TREEMANAGER__H


#endif

// fonction placée à l'arrache, à déplacer le temps voulu
// search a word in our tree.
Tree search(Tree t, char *w, int cmpt)
{
	if(t==NULL)
		return NULL;
    
	if(t->letter==w[cmpt]){
		if(w[i]=='\0')
			return t;
		else 
			return search(t->leftChild, w, cmpt+1);
	}
    
	else if(t->letter<w[cmpt])
		return NULL;
    
	else if(t->letter>w[cmpt])
		return search(t->rightBro, w, cmpt);
			
	else return NULL;
}

// exemple nul de main en considérant que l'arbre est rempli
int main(int argc, char** argv){
    Tree a;
    char word[20]; // au hasard balathazar
    int cmpt=0; //va servir pour aller de case en case dans notre fonction search. 
    printf("\nHello. Which word would you like to search in our splendid lexical tree? \n");
    scanf("%d", &word);
    
    if((search(a, word, cmpt))!=NULL)
			printf("%d is in our tree. Cool!\n", word);

		else 
            printf("%d isn't in our tree. Sad.", word);
    
	return EXIT_SUCCESS;
}