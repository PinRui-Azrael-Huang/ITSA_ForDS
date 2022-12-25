#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int height, isPeak;
} Mountain;

int main (){
  int numMtns;
  scanf("%d",&numMtns);
  Mountain mtns[numMtns];

  int current = -1;
  for(int i = 0; i < numMtns; i++){
    scanf("%d",&mtns[i].height);
    mtns[i].isPeak = 0;
  }

  int numPeaks = 0;
  for(int i = 1; i < numMtns - 1; i++){
    if (mtns[i].height > mtns[i + 1].height && mtns[i].height > mtns[i - 1].height){
      numPeaks++;
      mtns[i].isPeak = 1;
    }
  }

  printf("%d\n",numPeaks);
  for(int i = 0; i < numMtns; i++){
    printf("%d",mtns[i].height);
    if (mtns[i].isPeak){
      printf(">>>>>");
    }
    printf("\n");
  }

  //system("PAUSE");
  return 0;
}