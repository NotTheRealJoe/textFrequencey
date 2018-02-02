#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "wordFrequencyTester.h"

void main(int argc, char** argv) {
  int inFd = open("wordCountTester.in", O_RDONLY);
  
  hsearch_data* htab = wordFrequency(inFd);


  // Wrtie the data to file
  int outFd = open("htable.dat", O_WRONLY | O_CREAT | O_TRUNC);
  //TODO: Error check on write()
  write(outFd, htab, sizeof(htab));
  //TODO: Error check on close()
  close(outFd);

  //Close the stream
  fclose(stream);
}
