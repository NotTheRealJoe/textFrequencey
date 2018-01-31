
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include "header.h"

int letterSum = 0; // counter of letters read
int letters_range[26] = {0};
int letters[26] = {0};

void accumulatedDistribution(int *letters, int *letters_range) {
  for (int i = 0; i < 26; i++) {
    letterSum += letters[i];
    letters_range[i] = letterSum;
  }
} // accumulatedDistribution(int *letters, int *letters_range)

/**
 * Prints the array provided to the screen.
 * @param array pointer to the array to be printed.
 */
void printArray(int *array) {
  for (int i = 0; i < 26; i++) {
    printf("%c = %d\n", 'a' + i, array[i]);
  } // for
} // printArray(int *array)

/**
 * Create a histogram displaying the frequency of occurences for the values of a
 * character array. 
 * 
 * @param array integer array containing character counts.
 * @param maxLen the largest possible bar size.
 */
void drawHistogram(int *array, int maxLen) {
  int max = 0;
  for (int i = 0; i < 26; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  } // for

  // standardize each value to be between 0 - 40, and print histogram
  printf("\n");
  for (int i = 0; i < 26; i++) {
    int numOfStars = (int) (((double) array[i] / (double) max) * maxLen);
    printf("%c: ", 'a' + i);
    
    for (int j = 0; j < numOfStars; j++) {
      printf("*");
    } // inner for
    printf("\n");
  } // outer for
  
} // drawHistogram (int *array, int maxLen)

/**
 * Given a filename and a pointer to an array, this method will count the frequence of 
 * occurences for each character in the file, and update the corresponding position in the
 * array. 
 *
 * For the array, position 0 corresponds to 'a' and position 25 corresponds to 'z'.
 *
 * @param filename the name of a text file to be read from.
 * @param letters pointer to an int array of size 26.
 *
 */
void frequencyOfCharacters(char *filename, int *letters) {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  
  int check = 0;
  //printf( "Enter string below [ctrl-D to quit]\n" );

  // set the seed for rand()
  time_t t;
  srand((unsigned) time(&t));
  
  FILE * inputStream = fopen( filename, "r" );

  while( (read = getline(&line, &len, inputStream)) != -1 ) {

    if( read > 0 ) {
      
      for (int i = 0; i < strlen(line); i++) {
	char c = tolower(line[i]);
	if ('a' <= c && c <= 'z') {
	  //printf ("%c", c);
	  letters[c-'a']++;
	  check++;
	} //if
      } //for

      //printf( "\n=> %s\n", line );
    } // if

    //printf( "Enter string below [ctrl-D to quit]\n" );
  } // while

  
  // printf("%d\n", check);
  fclose( inputStream );
  free( line );
} // frequencyOfCharacters(char *filename, int *letters)

int main( int argc, char** argv ) {

  frequencyOfCharacters("tale-of-two-cities.txt", letters);

  /* // print the frequences for each letter */
  /* printf("Frequencies for letters in original\n"); */
  /* printArray(letters); */

  /* printf("\n\n\n\n\n"); */
  
  /* // print the accumulated values */
   accumulatedDistribution(letters, letters_range); 
  /* printf("Accumulated values for original file\n"); */
  /* printArray(letters_range); */

  printf("original file histogram\n");
  drawHistogram(letters, 100);
  
  int numOfLines = (letterSum / 100) + 60;
  char randomChars[letterSum + numOfLines];

  memset(randomChars, 0, sizeof(randomChars));
  generateRandChars(randomChars, letters_range, letterSum + numOfLines);
  //printChars(randomChars);
  toTextFile(randomChars);



  // compare the file created
  int compLetters[26] = {0};
  int compLetter_ranges[26] = {0};

  frequencyOfCharacters("randomCharacters.txt", compLetters);
  /* printf("Frequencies for letters in random generation\n"); */
  /* printArray(compLetters); */

  /* letterSum = 0; */
  /* printf("Accumulated values for random generation\n"); */
  /* accumulatedDistribution(compLetters, compLetter_ranges); */
  /* printArray(compLetter_ranges); */

  printf("random generated letters histogram\n");
  drawHistogram(compLetters, 100);
  return 0;

} // main( int, char** )
