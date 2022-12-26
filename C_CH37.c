#include <stdio.h>
#include <stdlib.h>

int main (){
  int numClasses, numStudents, maxClassID = -1, maxBoyCount = -1;
  scanf("%d %d",&numClasses ,&numStudents);

  int currentGender, currentBoyCount = 0, currentClassID;
  for(int i = 0 ; i < numClasses ; i++){
    currentClassID = i + 1;
    for (int j = 0; j < numStudents ; j++){
      scanf("%d",&currentGender);
      if(currentGender == 0)
        continue;
      else{
        currentBoyCount ++;
      }
    }

    if(currentBoyCount > maxBoyCount){
      maxBoyCount = currentBoyCount;
      maxClassID = currentClassID;
    }
    currentBoyCount = 0;
  }
  printf("Class %d has %d boys.\n", maxClassID, maxBoyCount);

  //system("PAUSE");
  return 0;
}