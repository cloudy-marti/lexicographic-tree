#ifndef TREEMANAGER__H
#define TREEMANAGER__H

Tree initializeTree(char letter);
int search(Tree tree, char* word);
void printWord(Tree a, char* buffer, int index);

#endif

