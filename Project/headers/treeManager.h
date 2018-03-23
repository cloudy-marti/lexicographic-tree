#ifndef TREEMANAGER__H
#define TREEMANAGER__H

Tree initializeTree(char letter);
int createTree(Tree* tree, char* word);
int search(Tree tree, char* word);
void prefix(Tree tree);
void printWord(Tree a, char* buffer, int index);
void printWordFull(Tree tree);
void prefixSaveDico(Tree tree);

#endif