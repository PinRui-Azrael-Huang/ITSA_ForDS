#include <stdio.h>
#include <stdlib.h>

int main (){
  int numTests, direction;
  char target, ch;
  int posR, posC;
  scanf("%d" ,&numTests);
  ch = getchar();

  char keyboardBot[4][10] = 
  {{'1','2','3','4','5','6','7','8','9','0'},
  {'Q','W','E','R','T','Y','U','I','O','P'},
  {'A','S','D','F','G','H','J','K','L',';'},
  {'Z','X','C','V','B','N','M',',','.','/'}}; 

  char keyboardTop[4][10] = 
  {{'!','@','#','$','%','^','&','*','(',')'},
  {'Q','W','E','R','T','Y','U','I','O','P'},
  {'A','S','D','F','G','H','J','K','L',':'},
  {'Z','X','C','V','B','N','M','<','>','?'}}; 

  for(int t = 0 ; t < numTests ; t++){
    scanf("%c %d",&target ,&direction);
    ch = getchar();
    for(int i = 0; i < 4 ; i++){
      for(int j = 0; j < 10 ; j++){
        if (target == keyboardTop[i][j] || target == keyboardBot[i][j]){
          posR = i;
          posC = j;
        }
      }
    }

    if (direction == 1){      // Up
      posR--;
      if(posR == -1)
        posR = 3;
    }
    else if (direction == 2){ // Down
      posR++;
      if(posR == 4)
        posR  = 0;
    }
    else if (direction == 3){ // Right
      posC++;
      if(posC == 10)
        posC  = 0;
    }
    else if (direction == 4){ // Left
      posC--;
      if(posC == -1)
        posC  = 9;
    }

    printf("%c\n",keyboardBot[posR][posC]);
  }

  system("PAUSE");
  return 0;
}