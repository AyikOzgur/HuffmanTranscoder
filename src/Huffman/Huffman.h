#pragma once
#include "HuffmanInternals.h"

typedef struct Huffman Huffman;
typedef struct HuffmanTree HuffmanTree;

Huffman* Huffman_create(HuffmanType type);

void* Huffman_encode(Huffman *self, char *input, size_t size);

HuffmanTree* Huffman_getTree(Huffman *self);

char* Huffman_decode(Huffman *self, void *input, size_t size);

void Huffman_setTree(Huffman *self, HuffmanTree *tree);
