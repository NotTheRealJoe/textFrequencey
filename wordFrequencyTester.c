#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "wordFrequencyTester.h"
#define DEBUG 0

void main(int argc, char** argv) {
  //int inFd = open("in/twain_mark/74-0.txt", O_RDONLY);
  //if(inFd < 0) {
  //  perror("open");
  //}
  //if(DEBUG) printf("inFd open success\n");
  
  hsearch_data htab;
  if(DEBUG) printf("htab allocation success\n");
  
  hsearch_data *htab_p;
  if(DEBUG) printf("htab_p allocation success\n");
  
  htab_p = wordFrequency("in/twain_mark/74-0.txt");
  if(DEBUG) printf("htab_p = wordFrequency() success\n");
  
  if(close(inFd) < 0) {
    perror("close");
  }

  // Wrtie the data to file
  int outFd = open("htable.dat", O_WRONLY | O_CREAT | O_TRUNC);
  //TODO: Error check on write()
  write(outFd, htab_p, sizeof(*htab_p));
  //TODO: Error check on close()
  close(outFd);

  //Close the stream
}
