#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main(){
  int arr[20];
  memset(arr, -1, sizeof(int) * 20);

  int len = 0, sum = 0;
  while(scanf("%d",&arr[len])!= EOF){
    sum += arr[len];
    len++;
  }

  int min = INT_MAX, maxID = 0;
  for(int j = 0; j < len ; j++){
    if (arr[j] < min)
      min = arr[j];
    if (arr[j] > arr[maxID])
      maxID = j;
  }
  printf("%d %d %d\n",min, maxID, sum);

  //system("PAUSE");
  return 0;
}