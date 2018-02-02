#include "wordFrequencyTester.h"

hsearch_data* wordFrequency(int fd) {
  //Open the file as a stream and check for errors
  FILE *stream;
  stream = fdopen(fd, "r");

  if(!stream) {
    perror("fopen");
  }

  int c;
  char* word = '\0';
  char** book;

  //First, get the number of words in the book to properly allocate the hash table
  int wordCount = wordCount(fd);

  //Create the hash table for storing the words
  //This version of hcreate() allows use of only one hash table at a time but that's ok because this implmentation needs only one
  ENTRY newEntry, *curEntry;
  hsearch_data *htab;
  hcreate_r(wordCount, htab);
  
  while(c != EOF) {
    if(c >= 97 && c <= 122) {
      //If letter is lower case (ASCII 97 to 122 inclusive), convert to upper and add to word
      *word++ = c-32;
      *word = '\0';
    } else if (c >= 65 && c <= 122) {
      //If letter is upper case (ASCII 65 to 90 inclusive), just add to word
      *word++ = c;
      *word = '\0';
    } else if (c == 39) {
      //If the character is an apostrophie, ignore it but don't break the word
      // (do nothing)
    } else {
      //If the character is anything other than a letter, break the work, or ignore it if the word is 0 letters long
      if(strlen(word) > 0) {
	newEntry.key = word;
	newEntry.data = 0;
	curEntry = hsearch_r(newEntry, ENTER, htab);
	curEntry.data++;
      }
    }
    c = fgetc(stream);
  }

  return htab;
}
