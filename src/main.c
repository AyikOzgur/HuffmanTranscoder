#include <stdio.h>
#include "Huffman/Huffman.h"

int main()
{
	HuffmanType myType = ENCODER;
	Huffman *myHuf = Huffman_create(myType);
	return 0;
}
