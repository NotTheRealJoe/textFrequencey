#include <stdio.h>

/**
 * Get the number of words delimited by any non alphabetical or numberical character in a file
 * @param fd File descriptor for the file to read
 * @return The number of words in the file specified by fd
 */
int wordCount(char* path) {
  FILE *stream = fopen(path, "r");
  char c = fgetc(stream);
  int lastCharIsLetter = 0;
  int wordsInBook = 0;
  while(c != EOF) {
    if((c >= 97 && c <= 122) || (c >=65 && c <= 122) || (c >= 48 && c <= 57) || c == 39) {
      lastCharIsLetter = 1;
    } else {
      if(lastCharIsLetter > 0) {
	wordsInBook++;
	lastCharIsLetter = 0;
      }
    }
    c = fgetc(stream);
  }
  fclose(stream);
  return wordsInBook;
}

