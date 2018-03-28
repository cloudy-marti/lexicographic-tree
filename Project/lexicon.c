#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "headers/structures.h"
#include "headers/fileManager.h"
#include "headers/treeManager.h"

int main(int argc, char** argv){

	int command = getCommandIndex(argv);

	if(command == 1){
		printf("your command : index %d, %s\n", command, argv[command]);	
		runLexicon(argc, argv);
	}else{
		printf("no command\n");
	}

	int fileIndex = getFileNameIndex(argv);

	if(fileIndex != 0){
		printf("your file has index %d and its name is %s\n", fileIndex, argv[fileIndex]);
	}else{
		printf("no fileName\n");
	}

	runFromDico();

	return EXIT_SUCCESS;
}