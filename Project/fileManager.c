#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/structures.h"

/* !!! PAS DE FONCTION MAIN !!! */

/*void openFile(char* fileName, char* mode){

	FILE* file;

	printf("file name : %s\n", fileName);

	char path[] = "files/";
	printf("The file %s is in the folder %s\n", fileName, path);

	strcat(path, fileName);
	printf("your path : %s\n", path);

	file = fopen(path, mode);

	int line = 0;
	char input[800];

	while(fgets(input, 800, file)){
		line++;
		printf("line %d -> %s\n", line, input);
	}

	printf("end of program\n");

	fclose(file);

}*/