#ifndef FILEMANAGER__H
#define FILEMANAGER__H

char* filePath(char* fileName, char* path);
void getLexicon(char* fileName, char* mode);
char* fileExt(char* fileName, char* extension);
void createFile(char* fileName, char* extension);

#endif