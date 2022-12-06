#include <stdlib.h>
#include <stdio.h>

typedef struct{
  int numBoys, numGirls
} Class;

int main (){
  int numClasses, numPeople;
  scanf("%d %d",&numClasses ,&numPeople);
  Class *class = malloc(sizeof(Class) * numClasses);
  for(int i = 0 ; i < numClasses ; i++){
    class[i].numBoys = class[i].numGirls = 0;
  }
  for (int i = 0 ; i < numClasses ; i++){
    int gender;
    for(int j = 0; j < numPeople ; j++){
      scanf("%d",&gender);
      if(gender ==  1)
        class[i].numBoys++;
      else
        class[i].numGirls++;
    }
  }

  int maxClass = -1;
  int maxCount = -1;
  for(int i = 0 ; i < numClasses ; i++){
    if (maxCount < class[i].numBoys){
      maxClass = i;
      maxCount = class[i].numBoys;
    }
  }

  printf("Class %d has %d boys.\n",maxClass+1, class[maxClass].numBoys);
  system("PAUSE");
  return 0;
}