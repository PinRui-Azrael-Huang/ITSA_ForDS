#include <stdlib.h>
#include <stdio.h>

int main(){
  int answer[4] = {4, 8, 0, 1};
  int *guess = malloc(sizeof(int) * 4);
  int A = 0, B = 0;

  while (1){
    scanf ("%d %d %d %d",&guess[0] ,&guess[1] ,&guess[2] ,&guess[3]);
    if (guess[0] == 0 && guess[0] == guess[1] && 
        guess[1] == guess[2] && guess[2] == guess[3]){
      break;
    }

    for (int i = 0 ; i < 4 ; i++){
      for (int j = 0 ; j < 4 ; j++){
        if (answer[i] == guess[j]){
          if (i == j)
            A++;
          else
            B++;
        }
      }
    }
    printf("%dA%dB\n",A,B);
    A = B = 0;
  }
  
  return 0;
}