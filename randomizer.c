#include <stdio.h>
#include <stdlib.h>

char randomizer(int *range){

  
  int rr =  rand() % (range[25] + 1);

  for(int i = 0; i < 26; i++){
    if( i == 0){
      if(rr >= 0 && rr <= range[i]){
	return 'a' + i;
      } // if
    } // if
    else {
      if(rr > range[i-1] && rr <= range[i]){
	return 'a'+ i;
      } // if
    } // else
  } // for
  
  return -1; // failure
}
