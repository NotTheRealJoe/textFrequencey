
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main( int argc, char** argv ) {

  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int letters_range[26] = {0};
  int letters[26] = {0};
  int sum = 0;
  int check = 0;
  //printf( "Enter string below [ctrl-D to quit]\n" );

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
  for(int i = 0; i < 26; i++){
    printf("%c = %d\n", 'a' + i, letters[i]);
    sum = sum + letters[i];
    letters_range[i] = sum;
    printf("%c = %d\n", 'a' + i, letters_range[i]);
  }
  printf("%d\n", check);
  return 0;

} // main( int, char** )
