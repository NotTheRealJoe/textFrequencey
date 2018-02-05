#include "joeBSTTester.h"
#include <stdio.h>
#define DEBUG 1

int main(int argc, char** argv) {
	struct jb_Node root;
	root.key = "HELLO";
	root.value = 1;
	root.left = NULL;
	root.right = NULL;
	if(DEBUG) printf("jb_Node root allocation and definition successful\n");

	struct jb_Node new;
	new.key = "JOE";
	new.value = 1;
	if(DEBUG) printf("jb_Node new allocation and definition successful\n");

	insertRaw(&root, &new);
	if(DEBUG) printf("insert raw successful\n");

	insert(&root, "MEME", 1);
	if(DEBUG) printf("insert successful\n");

	insert(&root, "FUCK", 1);
	if(DEBUG) printf("insert with lefts successful\n");
}
