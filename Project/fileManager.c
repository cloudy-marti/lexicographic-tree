#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "headers/structures.h"
#include "headers/fileManager.h"
#include "headers/treeManager.h"

char* joinString(char* lastWord, char* firstWord){
	strcat(firstWord, lastWord); // concatenate two strings
	return firstWord;
}
// this function above allow us to retrieve the file path in a char*

void getLexicon(char* fileName, char* command, Tree tree){

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

	FILE* outFile;
	outFile = fopen(outputFile, "a+");

	FILE* outDico;
	outDico = fopen(outputDicoFile, "a+");

	char input[MAXWORD] = "";

	printf("Reading text :\n\n");

	while(fscanf(file, "%51s", input) != EOF){
		printf("%s ", input);
		*input = tolower(*input);
		createTree(&tree, input);
	}
	printf("\n\n");

	printWordFull(tree, outFile);
	prefixSaveDico(tree, outDico);

	fclose(file);
	fclose(outFile);
	fclose(outDico);
	printf("file closed\n");
}