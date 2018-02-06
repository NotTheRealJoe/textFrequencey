#include <stdio.h>
#include "wordFrequency.h"

void main(int argc, char** argv) {
	struct jb_Node fail;
	fail.value = -1;

  struct jb_Node testTree = wordFrequency("wordCountTester.in");
	printf("Tree creation success\n");

	//jb_Node* result = find(&testTree, "LAZY", &fail);
	int nodeCount = countNodes(&testTree);

	printf("%i\n", nodeCount);
}
