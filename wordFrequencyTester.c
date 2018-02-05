#define _GNU_SOURCE
#include <stdio.h>
#include "wordFrequencyTester.h"

void main(int argc, char** argv) {
  wordFrequency("in/twain_mark/74-0.txt");
  wordFrequency("wordCountTester.in");
}
