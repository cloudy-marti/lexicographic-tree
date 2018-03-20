#ifndef STRUCTURES__H
#define STRUCTURES__H

#define MAXWORD 51

typedef struct node{
	unsigned char letter;
	struct node *leftChild, *rightBro;
}Node, *Tree;

#endif