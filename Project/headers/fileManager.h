#ifndef FILEMANAGER__H
#define FILEMANAGER__H

char* filePath(char* fileName, char* path);
char* fileExt(char* fileName, char* extension);
void getLexicon(char* fileName, char* mode, Tree tree);
void createFile(char* fileName, char* extension, char* input);

#endif