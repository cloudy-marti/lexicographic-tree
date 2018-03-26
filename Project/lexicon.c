#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "headers/structures.h"
#include "headers/fileManager.h"
#include "headers/treeManager.h"

int main(int argc, char** argv){

	runLexicon(argc, argv);
	runFromDico(argv);

	return EXIT_SUCCESS;
}