#ifndef STRUCTURES__H
#define STRUCTURES__H

typedef struct node{
	unsigned char letter;
	struct node *leftChild, *rightBro;
}Node, *Tree;

#endif