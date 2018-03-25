CC = gcc
CFLAGS = -ansi -g -Wall
HEADERS = structures.h treeManager.h fileManager.h
FILE = lexicon.c treeManager.c fileManager.c
EXE = lexicon

all : lexicon clean
	@echo "--------------------------------------------------------------"
	@echo "  hello, this is Marti Emilie and Sajdak Laurine's c project"
	@echo "                     Lexicon Dictionary"
	@echo ""
	@echo "           to execute type: ./lexicon fileName.txt &"
	@echo "               .txt file must be in file/ folder"
	@echo "                example : ./lexicon -s hp.txt &"
	@echo ""
	@echo "           .L and .DICO files will be in bin/ folder"
	@echo "--------------------------------------------------------------"

treeManager.o :
	@echo "compile treeManager"
	gcc $(CFLAGS) -c treeManager.c
	@echo "done ..."

fileManager.o :
	@echo "compile fileManager"
	gcc $(CFLAGS) -c fileManager.c
	@echo "done ..."

lexicon.o :
	@echo "compile lexicon"
	gcc $(CFLAGS) -c lexicon.c
	@echo "done ..."
	
lexicon : treeManager.o fileManager.o lexicon.o
	gcc treeManager.o fileManager.o lexicon.o -o lexicon

clean:
	rm -f *.o