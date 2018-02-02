#include "wordFrequencyTester.h"
#include <stdio.h>
#include <string.h>
#define DEBUG 0

hsearch_data* wordFrequency(int fd) {
  //Open the file as a stream and check for errors
  FILE *stream;
  stream = fdopen(fd, "r");

  if(!stream) {
    perror("fopen");
  }
  if(DEBUG) printf("stream opened successfully\n");
  
  int c;
  char* word = '\0';

  //First, get the number of words in the book to properly allocate the hash table
  if(DEBUG) printf("begin wordCount...\n");
  int words = wordCount(fd);
  if(DEBUG) printf("wordCount success. %i words.\n", words);

  //Create the hash table for storing the words
  //This version of hcreate() allows use of only one hash table at a time but that's ok because this implmentation needs only one
  ENTRY newEntry;
  if(DEBUG) printf("newEntry allocation success.\n");
  
  ENTRY *newEntry_p;
  if(DEBUG) printf("newEntry_p allocation success.\n");
  
  hsearch_data *htab;
  if(DEBUG) printf("*htab allocation success.\n");
  
  hcreate_r(words, htab);
  if(DEBUG) printf("hash table create success.\n");
  
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
	//TODO: check hsearch_r for errors
	hsearch_r(newEntry, ENTER, &newEntry_p, htab);
	newEntry.data++;
      }
    }
    c = fgetc(stream);
  }

  return htab;
}
