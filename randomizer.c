#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

char randChar(int *range){

  char result;
  int randChar =  rand() % (range[25] + 1);

  for(int i = 0; i < 26; i++){
    if( i == 0){
      if(randChar >= 0 && randChar <= range[i]){
	result = 'a' + i;
      } // if
    } // if
    else {
      if(randChar > range[i-1] && randChar <= range[i]){
	result = 'a'+ i;
      } // if
    } // else
  } // for
  
  return result;
}

void generateRandChars(char *randomChars, int *letters_range, int size) {

  //randomly generate a letter
  for(int i = 0; i < size; i++){
    if (i % 100 == 0) {
      randomChars[i] = '\n';
    }
    else {
      char a = randChar(letters_range);
      randomChars[i] = a;
    }
  } // for

} // generateRandChars(int n);

void printChars(char *array) {
  printf("size: %ld\n", strlen(array));
  printf("%s", array);
  //  for (int i = 0; i < array[i] != '\0'; i++) {
  //   printf("%c", array[i]);
  //  } // for
} // printChars(char *array)

void toTextFile(char *randomChars) {
  int fd = open("randomCharacters.txt", O_RDWR | O_CREAT | O_TRUNC, 0664);
  if (fd == -1) {
    perror("open");
  } // if

  int dprintfRet = dprintf(fd, "%s", randomChars);
  if (dprintfRet < 0) {
      perror("dprintf");
  } // if
  close(fd);
}
