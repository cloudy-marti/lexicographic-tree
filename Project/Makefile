CC = gcc
CFLAGS = -g -Wall
HEADERS = structures.h treeManager.h fileManager.h
FILE = lexicon.c treeManager.c fileManager.c
EXE = lexicon

all : lexicon clean
	@echo "--------------------------------------------------------------"
	@echo "  hello, this is Marti Emilie And Sajdak Laurine's C project"
	@echo "                     Lexicon Dictionary"
	@echo ""
	@echo "           to execute type: ./lexicon fileName.txt &"
	@echo "              txt file has to be in file/ folder"
	@echo "                 example : ./lexicon hp.txt &"
	@echo ""
	@echo "           .L and .DICO files will be in bin/ folder"
	@echo "--------------------------------------------------------------"

treeManager.o :
	@echo "compile treeManager"
	gcc $(CFLAGS) -c treeManager.c
	@echo "done ..."

fileManager.o : treeManager.o
	@echo "compile fileManager"
	gcc $(CFLAGS) -c fileManager.c
	@echo "done ..."

lexicon.o : treeManager.o
	@echo "compile lexicon"
	gcc $(CFLAGS) -c lexicon.c
	@echo "done ..."
	
lexicon : lexicon.o treeManager.o fileManager.o
	gcc lexicon.c -o lexicon

clean:
	rm -f *.o