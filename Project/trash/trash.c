void infix(Tree tree){

	if(tree->leftChild!=NULL){
		infix(tree->leftChild);
	}

	printf("%c ", tree->letter);

	if(tree->rightBro!=NULL){
		infix(tree->rightBro);
	}
}

void prefix(Tree tree){

	printf("%c ", tree->letter);

	if(tree->leftChild!=NULL){
		prefix(tree->leftChild);
	}

	if(tree->rightBro!=NULL){
		prefix(tree->rightBro);
	}
}

void postfix(Tree tree){
	
	if(tree->leftChild!=NULL){
		postfix(tree->leftChild);
	}

	if(tree->rightBro!=NULL){
		postfix(tree->rightBro);
	}

	printf("%c ", tree->letter);

}

int createTree(Tree* tree, char* word){

	printf("beginning of function : %c\n", *word);

	*tree = initializeTree(*word);
	if(*word != '\0'){
		printf("creating tree\n");
		return createTree(&(*tree)->leftChild, word+1);
	}
	else
		printf("condition return 1\n");
		return 1;
	
	// if(*tree == NULL){
	// empty tree ; create the first node and its children

	if(*tree != NULL){
		if((*tree)->letter < *word){
			printf("tree->letter smaller than word\n");
			return createTree(&(*tree)->rightBro, word);

		}else if((*tree)->letter > *word){
			printf("tree->letter bigger than word\n");
			initializeTree((*tree)->letter);
			(*tree)->rightBro = *tree;
			return createTree(&(*tree)->leftChild, word+1);

		}else
			printf("condition return 0\n");
			return 0;
		}else
			return 0;
}


//exemple nul de main en considérant que l'arbre est rempli
int main(int argc, char** argv){

   Tree tree;

   tree=initializeTree('c');
   tree->leftChild=initializeTree('e');
   tree->leftChild->leftChild=initializeTree('\0');
   tree->leftChild->leftChild->rightBro=initializeTree('s');
   tree->leftChild->leftChild->rightBro->leftChild=initializeTree('\0');
   tree->rightBro=initializeTree('d');
   tree->rightBro->leftChild=initializeTree('e');
   tree->rightBro->leftChild->leftChild=initializeTree('s');
   tree->rightBro->leftChild->leftChild->leftChild=initializeTree('\0');
   tree->rightBro->rightBro=initializeTree('l');
   tree->rightBro->rightBro->leftChild=initializeTree('e');
   tree->rightBro->rightBro->leftChild->leftChild=initializeTree('\0');
   tree->rightBro->rightBro->leftChild->leftChild->rightBro=initializeTree('s');
   tree->rightBro->rightBro->leftChild->leftChild->rightBro->leftChild=initializeTree('\0');
   tree->rightBro->rightBro->leftChild->leftChild->rightBro->rightBro=initializeTree('t');
   tree->rightBro->rightBro->leftChild->leftChild->rightBro->rightBro->leftChild=initializeTree('t');
   tree->rightBro->rightBro->leftChild->leftChild->rightBro->rightBro->leftChild->leftChild=initializeTree('r');
   tree->rightBro->rightBro->leftChild->leftChild->rightBro->rightBro->leftChild->leftChild->leftChild=initializeTree('e');
   tree->rightBro->rightBro->leftChild->leftChild->rightBro->rightBro->leftChild->leftChild->leftChild->leftChild=initializeTree('\0');

    char* word = (char*)malloc(sizeof(char)*MAXWORD); // MAXWORD : in structures.h -> 51
    char* buff = (char*)malloc(sizeof(char)*MAXWORD);

    int i=0;

    printf("\nHello. Which word would you like to search in our splendid lexical tree? \n");
    scanf("%s", word);
    
   if(search(tree, word))
		printf("%s present\n", word);

	else
		printf("%s absent\n", word);

	printWord(tree, buff, i);
	prefix(tree);
	printf("\n");

	Tree newTree;
	char* wiWord = (char*)malloc(sizeof(char)*MAXWORD);
	char* newWord = (char*)malloc(sizeof(char)*MAXWORD);

	printf("choose a word\n");
	scanf("%s", wiWord);

	int add = createTree(&newTree, wiWord);
	printf("yep\n");

	if(add == 0){
		printf("oops problem\n");
	}else
		printf("word added successfully !\n");

	printf("choose a word\n");
	scanf("%s", newWord);

	int add2 = createTree(&newTree, newWord);

	if(add2 == 0){
		printf("oops problem\n");
	}else
		printf("word added successfully !\n");

	printWord(newTree, buff, i);

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


	/*void runLexicon(int argc, char** argv){
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
}*/
	return EXIT_SUCCESS;
}