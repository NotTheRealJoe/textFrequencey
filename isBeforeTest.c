#include "JoeBST.h"
#include <stdio.h>

void main(int argc, char** argv) {
	// 0 = B is first
	// 1 = A is first
	// -1 = They are the same
	int out = isBefore("ANYBODY CAN SCREW YOUR MOM", "NOBODY CAN SEE YOUR PEE PEE");
	printf("%i\n", out);
}
