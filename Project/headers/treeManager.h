#ifndef TREEMANAGER__H
#define TREEMANAGER__H

Tree initializeTree(char letter);
int createTree(Tree* tree, char* word);
int search(Tree tree, char* word);
void printWord(Tree tree, char* buffer, int index, FILE* file);
void printWordFull(Tree tree, FILE* file);
void prefixSaveDico(Tree tree, FILE* file);

#endif