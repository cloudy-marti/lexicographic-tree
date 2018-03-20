CC = gcc
CFLAGS = -g -Wall
FILE = lexicon.c treeManager.c userManager.c fileManager.c
EXE = lexicon

all : lexicon
	@echo "--------------------------------------------------------------"
	@echo "           to execute type: ./lexicon fileName.txt &"
	@echo "              txt file has to be in file/ folder"
	@echo "                 example : ./lexicon hp.txt &"
	@echo "--------------------------------------------------------------"

lexicon : 
	gcc $(FILE) $(CFLAGS) -o lexicon

clean :
	rm $(OBJ_FILES) lexicon