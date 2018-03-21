CC = gcc
CFLAGS = -g -Wall
HEADERS = structures.h treeManager.h userManager.h fileManager.h
FILE = lexicon.c treeManager.c userManager.c fileManager.c
EXE = lexicon

all: lexicon
	@echo "--------------------------------------------------------------"
	@echo "           to execute type: ./lexicon fileName.txt &"
	@echo "              txt file has to be in file/ folder"
	@echo "                 example : ./lexicon hp.txt &"
	@echo "--------------------------------------------------------------"

treeManager.o:
	gcc -c treeManager.c $(CFLAGS)

fileManager.o: treeManager.o
	gcc -c fileManager.c $(CFLAGS)
lexicon: treeManager.o userManager.o fileManager.o
	gcc lexicon.c $(CFLAGS) -o lexicon

clean:
	rm $(OBJ_FILES) lexicon