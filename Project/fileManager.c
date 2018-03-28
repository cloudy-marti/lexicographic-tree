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
	outFile = fopen(outputFile, "w");

	char input[MAXWORD] = "";

	printf("\nReading text :\n\n");

	while(fscanf(file, "%51s", input) != EOF){
		printf("%s ", input);
		*input = tolower(*input);
		createTree(&tree, input);
	}
	printf("\n\n");

	if(strcmp(command, "-r") == 0){
		printf("searching word ...\n");
		*word = tolower(*word);
		if(search(tree, word) == 1){
			printf("the word '%s' is here ! :3\n", word);
		}else{
			printf("the word '%s' isn't here ...\n", word);
		}
		remove(outputFile);
	}else if(strcmp(command, "-S") == 0){
		FILE* outDico;
		outDico = fopen(outputDicoFile, "w");
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
}

int getCommandIndex(char** argv){
	if(argv[1] == NULL){
		return 0;
	}else{
		if(*argv[1] == '-'){
			return 1;
		}else
			return 0;
	}
}

int getFileNameIndex(char** argv){
	if(argv[1] == NULL){
		return 0;
	}else{
		if(*argv[1] == '-'){
			if(strcmp(argv[1], "-r") == 0){
				return 3;
			}else
				return 2;
		}else
			return 1;
	}
}

void runLexicon(int argc, char** argv){
	Tree newTree = NULL;

	int commandIndex = getCommandIndex(argv);
	int fileNameIndex = getFileNameIndex(argv);

	if(commandIndex != 0){
		if(argv[fileNameIndex] == NULL){
			printf("check your arguments ...\n");
		}else{
			printf("your file : %s\n", argv[2]);
			getLexicon(argv[fileNameIndex], argv[commandIndex], newTree, argv[fileNameIndex - 1]);
		}
	}
}

void runFromDico(){
	Tree tree = NULL;

	FILE* outFile;

	int userInput = 0;
	char path[MAXWORD] = " ";
	char* commandInput = (char*)malloc(sizeof(char)*2);
	char* word = (char*)malloc(sizeof(char)*MAXWORD);
	
	char outputFile[] = ".L";
	strcat(outputFile, path);
	outFile = fopen(outputFile, "w");

	printf("would you like to read a .DICO file ?\n1 = Yes\n0 = Nope\n");
	scanf("%d", &userInput);

	switch(userInput){
		case 1 :
			printf("OK let's do this\nPut your .DICO file in the main folder (Project/) and write its name :\n");
			scanf("%s", path);

			FILE* dicoFile;
			if((dicoFile = fopen(path, "r")) == NULL){
				printf("we didn't find your file :( ...\n");
				return;
			}

			createTreeFromDico(&tree, dicoFile);

			printf("what is your command ?\n-r = search a word\n-l = display all words\n-s = save words in .L file\n");
			scanf("%2s", commandInput);

			if(strcmp(commandInput, "-r") == 0){
				printf("type the word you want to search :\n");
				scanf("%51s", word);
				if(search(tree, word) == 1){
					printf("the word '%s' is here ! :3\n", word);
				}else{
					printf("the word '%s' isn't here ...\n", word);
				}
			}else if(strcmp(commandInput, "-s")){
				printWordFull(tree, outFile, 1);
				fclose(outFile);
			}else if(strcmp(commandInput, "-l")){
				printWordFull(tree, outFile, 0);
				remove(outputFile);
			}else{
				printf("wrong command ... bye\n");
				return;
			}
			break;

		case 0 :
			printf("ok bye\n");
			break;

		default :
			printf("your answer wasn't valid.bye\n");
			break;		
	}
}
