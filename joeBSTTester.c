#include "joeBSTTester.h"

int main(int argc, char** argv) {
	struct jb_Node root;
	root.key = "HELLO";
	root.value = 1;

	struct jb_Node new;
	new.key = "JOE";
	new.value = 1;

	insert(root, new);
}
