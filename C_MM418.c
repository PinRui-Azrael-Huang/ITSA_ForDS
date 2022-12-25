#include <stdio.h>
#include <stdlib.h>

int main(){
  int numTests;
  scanf("%d",&numTests);

  float x, y, temp1, temp2, I1, I2, I3, I4, resultI;
  for (int i=0; i<numTests; i++){
    scanf("%f %f", &x, &y);
    scanf("%f %f %f %f", &I1, &I2, &I3, &I4);

    temp1 = I1 * (1-y) + I2 * y;
    temp2 = I3 * (1-y) + I4 * y;
    resultI = temp1 * (1-x) + temp2 * x;
    printf("%.0f\n",resultI);
  }

  //system("PAUSE");
  return 0;
}