#include <stdio.h>
#include <stdlib.h>

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
