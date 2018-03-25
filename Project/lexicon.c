#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "headers/structures.h"
#include "headers/fileManager.h"
#include "headers/treeManager.h"


int main(int argc, char** argv){

	Tree newTree = NULL;
	char* command = argv[1];
	char* newCommand = (char*)malloc(sizeof(char)*2);

	if(*argv[1] == '-'){
		command = argv[1];
		printf("your command : %s\n", argv[1]);
		if(strcmp(argv[1], "-r") == 0){
			if(argc == 4){
				printf("your file : %s\nyour word : %s\n", argv[3], argv[2]);
				*argv[2] = tolower(*argv[2]);
				getLexicon(argv[3], command, newTree, argv[2]);
			}else{
				printf("check your arguments ...\n");
				return EXIT_FAILURE;
			}
		}else{
			if(argc != 3){
				printf("check your arguments ...\n");
				return EXIT_FAILURE;
			}else{
				printf("your file : %s\n", argv[2]);
				getLexicon(argv[2], command, newTree, "trash");
			}
		}
	}else{
		printf("menu :\ndisplay lexicon -> type '-l'\nsave lexicon -> type '-s'\nsearch word -> type '-r'\nsave tree -> type '-S'\n\n");
		scanf("%s", newCommand);
		if(strcmp(newCommand, "-r") == 0){
			if(argc == 3){
				printf("your file : %s\nyour word : %s\n", argv[2], argv[1]);
				*argv[1] = tolower(*argv[1]);
				getLexicon(argv[2], newCommand, newTree, argv[1]);
			}else{
				printf("check your arguments ...\n");
				return EXIT_FAILURE;
			}
		}else{
			if(argc != 2){
				printf("check your arguments ...\n");
				return EXIT_FAILURE;
			}else{
				printf("your file : %s\n", argv[1]);
				getLexicon(argv[1], newCommand, newTree, "trash");
			}
		}
	}




	return EXIT_SUCCESS;
}