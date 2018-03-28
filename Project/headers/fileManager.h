#ifndef FILEMANAGER__H
#define FILEMANAGER__H

char* joinString(char* fileName, char* path);
void getLexicon(char* fileName, char* command, Tree tree, char* word);
int getCommandIndex(char** argv);
int getFileNameIndex(char** argv);
void runLexicon(int argc, char** argv);
void runFromDico();

#endif