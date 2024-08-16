#include <stdlib.h>
#include "HuffmanInternals.h"

#define MAX_CHAR 256 // Assume that it is ASCII

typedef struct 
{
	char data;
	unsigned freq;
	struct Node *left, *right;
}Node;

typedef struct{
	HuffmanType type;
}Huffman;

typedef struct{
	int test;
}HuffmanTree;


Node* createNode(char data, unsigned freq)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->freq = freq;
	newNode->left = newNode->right = NULL;
	return newNode;
}


void scanText(char *text, Node *nodes[], int *size)
{
	unsigned freq[MAX_CHAR] = {0};

	// Count the frequency of each character in the text
	for (int i = 0; text[i] != '\0'; i++)
	{
		freq[(unsigned char)text[i]]++;
	}

	// Create nodes for each character that appears in the etxt
	for (int i = 0; i < MAX_CHAR; i++)
	{
		if (freq[i] > 0)
		{
			// Keep going from here
		}
	}

}


//////////////////////////////////////////////
Huffman* Huffman_create(HuffmanType type)
{
	Huffman *huffman = (Huffman*)malloc(sizeof(Huffman));
	huffman->type = type;
	return huffman;
}

void * Huffman_encode(Huffman *self, char *input, size_t size)
{

}

HuffmanTree* Huffman_getTree(Huffman *self)
{

}

char* Huffman_decode(Huffman *self, void *input, size_t size)
{

}

void Huffman_setTree(Huffman *self, HuffmanTree *tree)
{

}
