#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/structures.h"
#include "headers/fileManager.h"
#include "headers/treeManager.h"


int main(int argc, char** argv){

	//printf("your path : %s\n", filePath("hp.txt", "txt/"));

	Tree newTree = NULL;
	getLexicon("hp.txt", "r", newTree);
	
	//printWordFull(newTree);
	// FILE* file;

	// char* fileName = "hp.txt";
	// char* mode = "r";

	// printf("file name : %s\n", fileName);

	// char path[] = "txt/";
	// printf("The file %s is in the folder %s\n", fileName, path);

	// strcat(path, fileName);
	// printf("your path : %s\n", path);

	// file = fopen(path, mode);

	// char input[MAXWORD];

	// while(fscanf(file, "%51s", input) != EOF){
	// 	printf("word -> %s\n", input);
	// }

	// printf("end of program\n");

	// fclose(file);

	// char* word = (char*)malloc(sizeof(char)*MAXWORD); // MAXWORD : in structures.h -> 51
    // char* buff = (char*)malloc(sizeof(char)*MAXWORD);
	

 //    char* word = (char*)malloc(sizeof(char)*MAXWORD);
	// char* wiWord = (char*)malloc(sizeof(char)*MAXWORD);
	// char* newWord = (char*)malloc(sizeof(char)*MAXWORD);

	// printf("choose a word\n");
	// scanf("%s", word);

	// int add = createTree(&newTree, word);
	// printf("yep\n");

	// if(add == 0){
	// 	printf("oops problem\n");
	// }else
	// 	printf("word added successfully !\n");

	// // printWord(newTree, buff, i);

	// printWordFull(newTree);

	// printf("choose a word\n");
	// scanf("%s", wiWord);

	// int add1 = createTree(&newTree, wiWord);
	// printf("yep\n");

	// if(add1 == 0){
	// 	printf("oops problem\n");
	// }else
	// 	printf("word added successfully !\n");

	// // printWord(newTree, buff, i);
	// printWordFull(newTree);

	// printf("choose a word\n");
	// scanf("%s", newWord);

	// int add2 = createTree(&newTree, newWord);

	// if(add2 == 0){
	// 	printf("oops problem\n");
	// }else
	// 	printf("word added successfully !\n");

	// printWord(newTree, buff, i);


return EXIT_SUCCESS;

}