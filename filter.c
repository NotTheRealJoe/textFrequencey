
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main( int argc, char** argv ) {

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  char letters[26] = {0};

  //printf( "Enter string below [ctrl-D to quit]\n" );

  FILE * inputStream = fopen( "tale-of-two-cities.txt", "r" );

  while( (read = getline(&line, &len, inputStream)) != -1 ) {
    if( read > 0 ) {
      for (int i = 0; i < len; i++) { 
	char c = tolower(line[i]);
	if (c >= 'a' && c <= 'z') {
	  printf ("%c", c);
	}
      }
      printf( "\n=> %s\n", line );
    } // if

    //printf( "Enter string below [ctrl-D to quit]\n" );
  } // while

  fclose( inputStream );
  free( line );
  return 0;

} // main( int, char** )
