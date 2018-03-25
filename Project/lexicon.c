#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/structures.h"
#include "headers/fileManager.h"
#include "headers/treeManager.h"


int main(int argc, char** argv){

	Tree newTree = NULL;
	int i;

	for(i = 1; i < argc; i++){
		getLexicon(argv[i], newTree);
	}

return EXIT_SUCCESS;

}