#define _GNU_SOURCE
#include <stdio.h>
#include "wordFrequencyTester.h"
#define DEBUG 1

void main(int argc, char** argv) {  
  struct hsearch_data htab;
  if(DEBUG) printf("htab allocation success\n");
  
  hsearch_data *htab_p;
  if(DEBUG) printf("htab_p allocation success\n");
  
  //htab = wordFrequency("in/twain_mark/74-0.txt");
  htab = wordFrequency("wordCountTester.in");
  if(DEBUG) printf("htab_p = wordFrequency() success\n");


}
