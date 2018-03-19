CC = gcc
CFLAGS = -g -Wall
FILE = lexicon.c

all : lexicon
	@echo "--------------------------------------------------------------"
	@echo "            to execute type: ./lexicon fileName &"
	@echo "--------------------------------------------------------------"

projetC : 
	gcc $(FILE) $(CFLAGS) -o lexicon

clean :
	rm $(OBJ_FILES)