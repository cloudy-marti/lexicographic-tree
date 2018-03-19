#include <stdio.h>
#include <stdlib.h>

//w for word
// search a word in our tree
Tree search(Tree t, char *w, int i)
{
	if(t==NULL)
		return NULL;
    
	if(t->letter==w[i]){
		if(w[i]=='\0')
			return t;
		else 
			return search(t->fils, w, i+1);
	}
    
	else if(t->letter>w[i])
		return search(t->frg, w, i);
    
	else if(t->letter<w[i])
		return search(t->frd, w, i);
			
	else return NULL;
		
}

int main(int argc, char** argv){
    
	return EXIT_SUCCESS;
}