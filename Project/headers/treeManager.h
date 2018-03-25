#ifndef TREEMANAGER__H
#define TREEMANAGER__H

Tree initializeTree(char letter);
int createTree(Tree* tree, char* word);
int search(Tree tree, char* word);
void printWord(Tree tree, char* buffer, int index, FILE* file, int mode);
void printWordFull(Tree tree, FILE* file, int mode);
void prefixSaveDico(Tree tree, FILE* file);
void createTreeFromDico(Tree* tree, FILE* fileName);

#endif