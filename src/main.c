#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Huffman/Huffman.h"

#define MAX_CHAR 256

int main()
{
    char input[1024];
    printf("Enter some text to encode: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
    {
        input[len - 1] = '\0';
    }

    Huffman *huffmanEncoder = Huffman_create(); // Create a Huffman object
    // Encode the input text
    char *encodedText = (char *)Huffman_encode(huffmanEncoder, input, strlen(input));

    HuffmanTree *tree = Huffman_getTree(huffmanEncoder);

    Huffman *huffmanDecoder = Huffman_create(); // Create a Huffman object
    Huffman_setTree(huffmanDecoder, tree);

    // Decode the encoded text
    char *decodedText = Huffman_decode(huffmanDecoder, encodedText, strlen(encodedText));

    // Verify correctness by comparing the original text with the decoded text
    if (strcmp(input, decodedText) == 0)
    {
        printf("Decoding successful! The original text matches the decoded text.\n");
    }
    else
    {
        printf("Decoding failed! The original text does not match the decoded text.\n");
    }

    // Calculate the size of the Huffman tree in bits
    size_t treeSize = Huffman_getTreeSize(huffmanDecoder);

    // Calculate and print the compression rate
    size_t originalSize = strlen(input) * 8;   // Original size in bits
    size_t encodedSize = strlen(encodedText);  // Encoded size in bits
    size_t totalSize = encodedSize + treeSize; // Total size including tree

    printf("Original size: %zu bits\n", originalSize);
    printf("Encoded size: %zu bits\n", encodedSize);
    printf("Tree size: %zu bits\n", treeSize);
    printf("Total size (encoded text + tree): %zu bits\n", totalSize);

    double compressionRate = 100.0 * (1 - (double)totalSize / originalSize);
    printf("Compression rate: %.2f%%\n", compressionRate);

    // Cleanup
    free(encodedText);
    free(decodedText);
    Huffman_destroy(huffmanEncoder);
    Huffman_destroy(huffmanDecoder);
    return 0;
}