#include "wordFrequencyTester.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define DEBUG 0

jb_Node wordFrequency(char* path) {
	//First, get the number of words in the book to properly allocate the hash table
	int words = wordCount(path);
	if(DEBUG) printf("Successfully obtained word count\n");

	//Open the file as a stream and check for errors
	FILE *stream;
	stream = fopen(path, "r");
	if(!stream) {
		perror("fopen");
	}
	if(DEBUG) printf("stream opened successfully\n");

	//Get a character from the file and check for errors
	int c;
	c = fgetc(stream);
	if(c == EOF) {
		printf("ERROR: First character in file is EOF!\n");
		exit(1);
	}

	//Variable that will hold a pointer the root node
	struct jb_Node root;
	root.key = NULL;

	//Store the current word in the process of being built.
	char* word	= (char*)calloc(64, sizeof(char));

	//This flag is set to true as soon as we encounter a valid letter character
	int isValidWord = 0;

	//Keep track of our position in the word
	int index = 0;

	//Main loop that reads characters from the file
	while(c != EOF) {
		if(DEBUG) printf("wordFrequency(): Enter loop\n");

		if(c >= 97 && c <= 122) {
			//If letter is lower case (ASCII 97 to 122 inclusive), convert to upper and add to word
			if(DEBUG) printf("wordFrequency(): Lower case letter found: %c\n", c);
			word[index] = (c-32);
			if(DEBUG) printf("wordFrequency(): Added to word. Word is now %s\n", word);
			index++;
			isValidWord = 1;
			if(DEBUG) printf("wordFrequency(): Add letter %c\n", c-32);
		} else if (c >= 65 && c <= 122) {
			//If letter is upper case (ASCII 65 to 90 inclusive), just add to word
			if(DEBUG) printf("wordFrequency(): Upper case letter found: %c\n", c);
			word[index] = c;
			if(DEBUG) printf("wordFrequency(): Added character to word. Word is now %s\n", word);
			index++;
			isValidWord = 1;
			if(DEBUG) printf("wordFrequency(): Add letter %c\n", c);
		} else if (c == 39) {
			if(DEBUG) printf("wordFrequency(): Apostrophie found\n");
			//If the character is an apostrophie, ignore it but don't break the word
			// (do nothing)
			if(DEBUG) printf("wordFrequency(): Apostrophie, continue to next letter\n");
		} else {
			//If the character is anything other than a letter, break the work, or ignore it if the word is 0 letters long
			if(DEBUG) printf("wordFrequency(): Word-breaking character found\n");
			if(isValidWord > 0) {
				if(DEBUG) printf("wordFrequency(): Add word %s\n", word);

				//If the root node exists, insert, otherwise create the root node
				if(root.key) {
					if(DEBUG) printf("wordFrequency(): Insert into table\n");
					insert(&root, word, 1);
					if(DEBUG) printf("wordFrequency(): Insertion successful\n");
				} else {
					if(DEBUG) printf("wordFrequency(): Root does not exist yet, creating.\n");
					root = create(word, 1);
					if(DEBUG) printf("wordFrequency(): Creation success\n");
				}
			} else {
				if(DEBUG) printf("wordFrequency(): No valid characters currently in word. Continuing without adding\n");
			}
			//Reset variables to prepare for the next word
			isValidWord = 0;
			index=0;

			if(DEBUG) printf("wordFrequency(): Clearing word memory\n");
			//Clear word memory
			memset(word, '\0', 64 * sizeof(char));
		}
		if(DEBUG) printf("wordFrequency(): Done, getting next character\n");
		c = fgetc(stream);
	}
	if(DEBUG) printf("wordFrequency(): EOF Reached!\n");

	//Close the input file
	if(fclose(stream) != 0) {
		perror("fclose");
	}
	if(DEBUG) printf("wordFrequency(): Closed input file successfully\n");

	return root;
}
