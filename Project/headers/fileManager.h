#ifndef FILEMANAGER__H
#define FILEMANAGER__H

char* joinString(char* fileName, char* path);
void getLexicon(char* fileName, char* command, Tree tree, char* word);
void runLexicon(int argc, char** argv);
void runFromDico(char** argv);

#endif