
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "header.h"

int letterSum = 0; // counter of letters read

void accumulatedDistribution (int *letters, int *letters_range) {
  for (int i = 0; i < 26; i++) {
    letterSum += letters[i];
    letters_range[i] = letterSum;
  }
} // accumulatedDistribution

/**
 * Prints the array provided to the screen.
 * @param array pointer to the array to be printed.
 */
void printArray(int *array) {
  for (int i = 0; i < 26; i++) {
    printf("%c = %d\n", 'a' + i, array[i]);
  } // for
} // printArray

int main( int argc, char** argv ) {

  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int letters_range[26] = {0};
  int letters[26] = {0};
  int check = 0;
  //printf( "Enter string below [ctrl-D to quit]\n" );

  // set the seed for rand()
  time_t t;
  srand((unsigned) time(&t));
  
  FILE * inputStream = fopen( "tale-of-two-cities.txt", "r" );

  while( (read = getline(&line, &len, inputStream)) != -1 ) {
    
    if( read > 0 ) {
      
      for (int i = 0; i < strlen(line); i++) {
	char c = tolower(line[i]);
	if ('a' <= c && c <= 'z') {
	  printf ("%c", c);
	  letters[c-'a']++;
	  check++;
	} //if
      } //for

      printf( "\n=> %s\n", line );
    } // if

    //printf( "Enter string below [ctrl-D to quit]\n" );
  } // while

  fclose( inputStream );
  free( line );

  // print the frequences for each letter
  printArray(letters);

  printf("\n\n\n\n\n");
  
  // print the accumulated values
  accumulatedDistribution(letters, letters_range);
  printArray(letters_range);

  // printf("%d\n", check);

  //randomly generate a letter
  for(int i = 0; i < letterSum; i++){
    char a = randChar(letters_range);
    //printf("%c", a);
  }
  return 0;

} // main( int, char** )
