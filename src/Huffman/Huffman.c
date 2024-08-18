#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HuffmanInternals.h"

#define MAX_CHAR 256 // Assume that it is ASCII

typedef struct 
{
	char data;
	unsigned freq;
    struct Node *left, *right;
}Node;

typedef struct
{
	Node *node;
	size_t size;
}HuffmanTree;

typedef struct
{
	HuffmanType type;
	HuffmanTree *tree;
}Huffman;

// Function to calculate the size of the Huffman tree in bits
size_t calculateTreeSize(Node *root)
{
    if (!root) 
		return 1;  // 1 bit to represent a NULL child ('#')

    return 1 + calculateTreeSize(root->left) + calculateTreeSize(root->right);
}

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

	// Create nodes for each character that appears in the text.
	*size  = 0;
	for (int i = 0; i < MAX_CHAR; i++)
	{
		if (freq[i] > 0)
		{
			nodes[(*size)++] = createNode((char)i, freq[i]);
		}
	}
}

// Later use qsort from stdlib.
void sortNodes(Node* nodes[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
	{
        for (int j = 0; j < size - i - 1; j++) 
		{
            if (nodes[j]->freq > nodes[j + 1]->freq) 
			{
                // Swap the nodes
                Node* temp = nodes[j];
                nodes[j] = nodes[j + 1];
                nodes[j + 1] = temp;
            }
        }
    }
}

Node* buildHuffmanTree(Node* nodes[], int size) 
{
    while (size > 1) 
	{
        // Take the two nodes with the smallest frequency
        Node* left = nodes[0];
        Node* right = nodes[1];

        // Create a new internal node with these two nodes as children
        Node* newNode = createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        // Remove the two nodes from the array and insert the new node
        for (int i = 2; i < size; i++) 
		{
            nodes[i - 2] = nodes[i];
        }
        nodes[size - 2] = newNode;
        size--;

        // Sort the array again
        sortNodes(nodes, size);
    }

    // The remaining node is the root of the Huffman Tree
    return nodes[0];
}

void generateCodes(Node* root, int arr[], int top, char* codes[MAX_CHAR]) 
{
    if (root->left) 
	{
        arr[top] = 0;
        generateCodes(root->left, arr, top + 1, codes);
    }

    if (root->right) 
	{
        arr[top] = 1;
        generateCodes(root->right, arr, top + 1, codes);
    }

    if (!root->left && !root->right) 
	{
        char* code = (char*)malloc(top + 1);
        for (int i = 0; i < top; i++) 
		{
            code[i] = arr[i] + '0';  // Convert to character '0' or '1'
        }
        code[top] = '\0';
        codes[(unsigned char)root->data] = code;
    }
}

void encodeText(char* text, char* codes[MAX_CHAR], char* encodedText) 
{
    encodedText[0] = '\0';
    for (int i = 0; text[i] != '\0'; i++) 
	{
        strcat(encodedText, codes[(unsigned char)text[i]]);
    }
}

void writeTreeToFile(Node* root, FILE* file) 
{
    if (!root) 
	{
        fprintf(file, "%c", '#');  // # indicates a NULL child
        return;
    }
	
    fprintf(file, "%c", root->data);
    writeTreeToFile(root->left, file);
    writeTreeToFile(root->right, file);
}

Node* readTreeFromFile(FILE* file) 
{
    char ch = fgetc(file);
    if (ch == '#') 
		return NULL;  // # indicates a NULL child

    Node* root = createNode(ch, 0);
    root->left = readTreeFromFile(file);
    root->right = readTreeFromFile(file);
    return root;
}

void decodeText(Node* root, char* encodedText, char* decodedText) 
{
    Node* current = root;
    int j = 0;
    for (int i = 0; encodedText[i] != '\0'; i++) 
	{
        if (encodedText[i] == '0') 
		{
            current = current->left;
        } 
		else 
		{
            current = current->right;
        }

        // If it's a leaf node, we've found a character
        if (!current->left && !current->right) 
		{
            decodedText[j++] = current->data;
            current = root;  // Go back to the root for the next character
        }
    }
    decodedText[j] = '\0';  // Null-terminate the decoded string
}

void writeEncodedTextToFile(char* encodedText, FILE* file) 
{
    unsigned char byte = 0;
    int bitCount = 0;

    for (int i = 0; encodedText[i] != '\0'; i++) 
	{
        byte = (byte << 1) | (encodedText[i] - '0');
        bitCount++;

        if (bitCount == 8) 
		{
            fwrite(&byte, sizeof(unsigned char), 1, file);
            bitCount = 0;
            byte = 0;
        }
    }

    // Write any remaining bits
    if (bitCount > 0) 
	{
        byte <<= (8 - bitCount);  // Pad the remaining bits with 0s
        fwrite(&byte, sizeof(unsigned char), 1, file);
    }
}

void readEncodedTextFromFile(char* encodedText, FILE* file) 
{
    unsigned char byte;
    int bitCount = 0;

    while (fread(&byte, sizeof(unsigned char), 1, file)) 
	{
        for (int i = 7; i >= 0; i--) 
		{
            encodedText[bitCount++] = ((byte >> i) & 1) ? '1' : '0';
        }
    }
    encodedText[bitCount] = '\0';  // Null-terminate the string
}

//////////////////// Public methods //////////////////////////////////
Huffman* Huffman_create(HuffmanType type)
{
	Huffman *huffman = (Huffman*)malloc(sizeof(Huffman));
	huffman->type = type;
	return huffman;
}

void Huffman_destroy(Huffman *self)
{
    if (self->tree->node != nullptr)
    {
	    free(self->tree->node);
        self->tree->node = nullptr; 
    }

    if (self->tree->node != nullptr)
    {
	    free(self->tree);
        self->tree = nullptr;
    }

    if (self != nullptr)
    {
	    free(self);
        self = nullptr;
    }
}


void * Huffman_encode(Huffman *self, char *input, size_t size)
{
    Node *nodes[MAX_CHAR];
    int numNodes;
    scanText(input, nodes, &numNodes);

    // Build Huffman Tree
    Node *root = buildHuffmanTree(nodes, numNodes);

    // Generate Huffman codes
    char *codes[MAX_CHAR] = {0};
    int arr[MAX_CHAR], top = 0;
    generateCodes(root, arr, top, codes);

    // Encode the input text
    char *encodedText = (char *)malloc(size * MAX_CHAR); // Allocate enough memory
    encodeText(input, codes, encodedText);

    // Clean up generated codes
    for (int i = 0; i < MAX_CHAR; i++)
    {
        if (codes[i])
            free(codes[i]);
    }

    // Optionally store the tree or other data if needed
    // Store the tree if required later
    HuffmanTree *tree = (HuffmanTree *)malloc(sizeof(HuffmanTree));
    tree->node = root;
    Huffman_setTree(self, tree);

    return encodedText;
}

HuffmanTree* Huffman_getTree(Huffman *self)
{
    // Return the tree stored in the Huffman structure
    // Assuming the tree is stored within the structure, otherwise manage how you store the tree in the Huffman object.
    return self->tree;
}

size_t Huffman_getTreeSize(Huffman *self)
{
	return self->tree->size;
}

char* Huffman_decode(Huffman *self, void *input, size_t size)
{
    // Assuming the Huffman tree is stored in the self->tree
    HuffmanTree *tree = Huffman_getTree(self);
    Node *root = tree->node;

    // Decode the input encoded text
    char *decodedText = (char *)malloc(size * sizeof(char)); // Allocate memory
    decodeText(root, (char *)input, decodedText);

    return decodedText;
}

void Huffman_setTree(Huffman *self, HuffmanTree *tree)
{
    // Assuming self->tree is where you want to store the tree
    self->tree = tree;
	self->tree->size = calculateTreeSize(self->tree->node);
}
