#include <stdio.h>
#include <stdlib.h>

void solve(int length, int direction){
  int starPos;
  int hasPrintStar = 0;

  if (direction == 1){
    starPos = length - 1;
    for(int i = 0 ; i < length ; i++){
      for (int j = 0 ; j < length ; j++){
        if (j != starPos){
          if (j != length - 1)
            printf("x ");
          else
            printf("x");
        }
        else{
          if (j!= length - 1)
            printf("* ");
          else
            printf("*");
          starPos--;
        }
      }
      printf("\n");
    }
  }
   else if (direction == 2){
    starPos = 0;
    for(int i = 0 ; i < length ; i++){
      for (int j = 0 ; j < length ; j++){
        if (j != starPos || hasPrintStar){
          if (j != length - 1)
            printf("x ");
          else
            printf("x");
        }
        else{
          if (j!= length - 1)
            printf("* ");
          else
            printf("*");
          hasPrintStar = 1;
          starPos++;
        }
      }
      printf("\n");
      hasPrintStar = 0;
    }
  }
  else if (direction == 3){
    starPos = length - 1;
    for(int i = 0 ; i < length ; i++){
      for (int j = 0 ; j < length ; j++){
        if (j != starPos ){
          if (j != length - 1)
            printf("x ");
          else
            printf("x");
        }
        else{
          if (j!= length - 1)
            printf("* ");
          else
            printf("*");
        }
      }
      printf("\n");
    }
  }
  else if (direction == 4){
    starPos = 0;
    for(int i = 0 ; i < length ; i++){
      for (int j = 0 ; j < length ; j++){
        if (j != starPos ){
          if (j != length - 1)
            printf("x ");
          else
            printf("x");
        }
        else{
          if (j!= length - 1)
            printf("* ");
          else
            printf("*");
        }
      }
      printf("\n");
    }
  }
}

int main (){
  int numTests, length, direction;
  scanf("%d",&numTests);
  for (int t = 0; t < numTests ; t++){

    scanf("%d %d",&length ,&direction);
    solve(length, direction);
  }
  return 0;
}