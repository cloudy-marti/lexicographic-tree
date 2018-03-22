#ifndef TREEMANAGER__H
#define TREEMANAGER__H

Tree initializeTree(char letter);
int search(Tree tree, char* word);
void printWord(Tree a, char* buffer, int index);
void infix(Tree tree);
void prefix(Tree tree);
void postfix(Tree tree);
int createTree(Tree* tree, char* word);

#endif