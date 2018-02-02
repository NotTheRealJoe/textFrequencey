#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "wordCountTester.h"

void main(int argc, char** argv) {
  //int myFile = open("wordCountTester.in", O_RDONLY);

  int n = wordCount("wordCountTester.in");

  printf("%i\n", n);
}
