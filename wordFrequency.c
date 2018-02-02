#include "wordFrequencyTester.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define DEBUG 1

hsearch_data wordFrequency(char* path) {
  //Utility variables
  int r, newValue;
  ENTRY e, *ep;
  char* temp;
  
  //First, get the number of words in the book to properly allocate the hash table
  int words = wordCount(path);

  //Open the file as a stream and check for errors
  FILE *stream;
  stream = fopen(path, "r");
  if(!stream) {
    perror("fopen");
  }
  if(DEBUG) printf("stream opened successfully\n");

  //Create the hash table for storing the words
  struct hsearch_data htab;
  if(DEBUG) printf("*htab allocation success.\n");
  memset((void *)&htab, 0, sizeof(htab));
  r = hcreate_r(words, &htab);
  if(r == 0) {
    perror("hcreate_r");
  }
  if(DEBUG) printf("hash table create success.\n");

  //Get a character from the file
  int c;
  c = fgetc(stream);  
  if(c == EOF) {
    printf("ERROR: First character in file is EOF!\n");
    exit(1);
  }

  //Store the current word in the process of being built
  char* word  = (char*)calloc(64, sizeof(char));
  //This flag is set to true as soon as we encounter a valid letter character
  int isValidWord = 0;
  //Keep track of our position in the word
  int index = 0;
  while(c != EOF) {
    if(DEBUG) printf("Enter loop\n");
  
    if(c >= 97 && c <= 122) {
      if(DEBUG) printf("Lower case letter found: %c\n", c);
      //If letter is lower case (ASCII 97 to 122 inclusive), convert to upper and add to word
      word[index] = (c-32);
      if(DEBUG) printf("Added to word. Word is now %s\n", word);
      index++;
      isValidWord = 1;
      if(DEBUG) printf("Add letter %c\n", c-32);
    } else if (c >= 65 && c <= 122) {
      if(DEBUG) printf("Upper case letter found: %c\n", c);
      //If letter is upper case (ASCII 65 to 90 inclusive), just add to word
      word[index] = c;
      if(DEBUG) printf("Added character to word. Word is now %s\n", word);
      index++;
      isValidWord = 1;
      if(DEBUG) printf("Add letter %c\n", c);
    } else if (c == 39) {
      if(DEBUG) printf("Apostrophie found\n");
      //If the character is an apostrophie, ignore it but don't break the word
      // (do nothing)
      if(DEBUG) printf("Apostrophie, continue to next letter\n");
    } else {
      //If the character is anything other than a letter, break the work, or ignore it if the word is 0 letters long
      if(DEBUG) printf("Word-breaking character found\n");
      if(isValidWord > 0) {
	if(DEBUG) printf("Add word %s\n", word);

	//e.key = word;
	//*(int*)e.data = 0;
	//if(DEBUG) printf("Assigned data...\n");
	//if(DEBUG) printf("Assigned key and data to curEntry\nKey is %s, data is %i\n", e.key, *(int*)e.data);
	e.key = word;
	printf("Key is %s\n", e.key);
	e.data = malloc(sizeof(int));
	//Don't know how this works but this guy does: https://stackoverflow.com/questions/1327579/if-i-have-a-void-pointer-how-do-i-put-an-int-into-it
	*((int*)e.data) = 0;
	printf("Value is %i\n", *(int *)e.data);
  
	r = hsearch_r(e, ENTER, &ep, &htab);
	if(DEBUG) printf("hsearch successfully completed\n");
	if(!r) {
	  perror("hsearch_r");
	}
	if(DEBUG) printf("Stored key is %s\n", ep->key);
	if(DEBUG) printf("Stored value is %i\n", *(int *)(ep->data));
	//Dereference ep, get the data void pointer, cast it to an int pointer and then dereference the int pointer. Also you have to use += 1 instead of ++ for some reason
	*((int *)((*ep).data)) += 1;
	newValue = *(int *)(ep->data);
	if(DEBUG) printf("Updated value is %i\n", newValue);

	free(word);
	char* word  = (char*)calloc(64, sizeof(char));
	isValidWord = 0;
	index=0;
      } else {
	if(DEBUG) printf("No valid characters currently in word. Continuing without adding\n");
      }
    }
    if(DEBUG) printf("Done, getting next character\n");
    c = fgetc(stream);
  }
  if(DEBUG) printf("EOF Reached!\n");
  //TODO: check fclose for errors
  if(fclose(stream) != 0) {
    perror("fclose");
  }
  if(DEBUG) printf("Closed input file successfully\n");

  // Wrtie the data to file
  int outFd = open("htable.dat", O_WRONLY | O_CREAT | O_TRUNC, 0600);
  if(outFd == -1) {
    perror("open");
  }

  printf("%lu\n", sizeof(htab));
  
  if(write(outFd, &htab, sizeof(htab)) == -1) {
    perror("write");
  }

  if(close(outFd) == -1) {
    perror("close");
  }
  
  printf("%lu\n", sizeof(hlist));
  for(int i = 0; i < words; i++) {
    if(hlist[i] != NULL) {
      //      printf("%s => %i\n", hlist[i]->key, *(int *)(hlist[i]->data));
      printf("%s\n", hlist[i]->key);
    }
  }
  
  //hdestroy_r(&htab);
}
