#include <stdio.h>
#include <stdlib.h>

int main (){
  int size, numTest;
  scanf("%d %d", &size , &numTest);
  int bread[size][size];
  for (int i = 0 ; i < size ; i++)
    for (int j = 0 ; j < size ; j++)
      scanf("%d",&bread[i][j]);

  int startR, startC, endR, endC;
  int sum = 0;
  for(int test = 0 ; test < numTest ; test++){
    scanf("%d %d %d %d",&startR ,&startC ,&endR ,&endC);
    for (int i = startR - 1 ; i < endR ; i++){
      for (int j = startC - 1 ; j < endC; j++){
        sum += bread[i][j];
      }
    }
    printf("%d\n",sum);
    sum = 0;
  }

  system("PAUSE");
  return 0;
}