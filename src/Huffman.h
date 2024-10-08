#pragma once

typedef struct Huffman Huffman;
typedef struct HuffmanTree HuffmanTree;
typedef struct Node Node;

Huffman *Huffman_create(void);

void Huffman_destroy(Huffman *self);

void *Huffman_encode(Huffman *self, char *input, size_t size);

HuffmanTree *Huffman_getTree(Huffman *self);

size_t Huffman_getTreeSize(Huffman *self);

char *Huffman_decode(Huffman *self, void *input, size_t size);

void Huffman_setTree(Huffman *self, HuffmanTree *tree);