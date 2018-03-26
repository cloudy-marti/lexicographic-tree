#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "headers/structures.h"
#include "headers/fileManager.h"
#include "headers/treeManager.h"

int main(int argc, char** argv){

	runLexicon(argc, argv);

	/*Tree tree = NULL;

	FILE* dicoFile;
	dicoFile = fopen("hp.txt.DICO", "r");
	printf("what\n");

	FILE* outFile;
	outFile = fopen("bin/hp.txt.DICO.L", "a+");

	createTreeFromDico(&tree, dicoFile);
	printWordFull(tree, outFile, 1);*/

	return EXIT_SUCCESS;
}