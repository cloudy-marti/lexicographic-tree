#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "headers/structures.h"
#include "headers/fileManager.h"
#include "headers/treeManager.h"

char* joinString(char* lastWord, char* firstWord){
	strcat(firstWord, lastWord); /*concatenate two strings */
	return firstWord;
}
/* this function above allow us to retrieve the file path in a char* */

void getLexicon(char* fileName, char* command, Tree tree, char* word){

	if(strlen(fileName) > 11){
		printf("the name of the file is too long. Please rename it with 7 characters max + .txt\n");
		printf("end of program\n");
		return;
	}

	char inputFolder[] = "txt/";
	char outputFolder[] = "bin/";
	char outputDicoFolder[] = "bin/";

	char* inputPath = joinString(fileName, inputFolder);
	char* outputPath = joinString(fileName, outputFolder);
	char* outputDico = joinString(fileName, outputDicoFolder);

	char* outputFile = joinString(".L", outputPath);
	char* outputDicoFile = joinString(".DICO", outputDico);

	FILE* file;
	file = fopen(inputPath, "r");

	if(file == NULL){
		printf("this file doesn't exist or it isn't in the right folder\n");
		printf("end of program\n");
		return;
	}

	FILE* outFile;
	outFile = fopen(outputFile, "a+");

	char input[MAXWORD] = "";

	printf("\nReading text :\n\n");

	while(fscanf(file, "%51s", input) != EOF){
		printf("%s ", input);
		*input = tolower(*input);
		createTree(&tree, input);
	}
	printf("\n\n");

	if(strcmp(command, "-r") == 0){
		if(search(tree, word) == 1){
			printf("the word '%s' is here ! :3\n", word);
		}else{
			printf("the word '%s' isn't here ...\n", word);
		}
		remove(outputFile);
	}else if(strcmp(command, "-S") == 0){
		FILE* outDico;
		outDico = fopen(outputDicoFile, "a");
		prefixSaveDico(tree, outDico);
		remove(outputFile);
		fclose(outDico);
		printf("check your new amazing file in the bin/ folder !\n");
	}else if(strcmp(command, "-s") == 0){
		printWordFull(tree, outFile, 1);
		fclose(outFile);
		printf("check your new amazing file in the bin/ folder !\n");
	}else if(strcmp(command, "-l") == 0){
		printWordFull(tree, outFile, 0);
		remove(outputFile);
	}else{
		printf("something is missing\n");
	}

	fclose(file);
	printf("end of program\n");
}

void runLexicon(int argc, char** argv){
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
				return;
			}
		}else{
			if(argc != 3){
				printf("check your arguments ...\n");
				return;
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
				return;
			}
		}else{
			if(argc != 2){
				printf("check your arguments ...\n");
				return;
			}else{
				printf("your file : %s\n", argv[1]);
				getLexicon(argv[1], newCommand, newTree, "trash");
			}
		}
	}
}