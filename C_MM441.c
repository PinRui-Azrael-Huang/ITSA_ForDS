#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* getDigit(int num){
  int* arr = malloc(sizeof(int) * 5);
  memset(arr, -1, sizeof(int) * 5);
  int i = 0;
  while(num > 0){
    arr[i++] = (num % 10);
    num /= 10;
  }
  return arr;
}

int main(){
  int numTests;
  scanf("%d",&numTests);
  int num;

  for(int i = 0 ; i < numTests ; i++){
    scanf("%d", &num);
    int *arr = getDigit(num);
    for(int j = 4 ; j >= 0 ; j--)
      if(arr[j] != -1){
        if(j != 0)
          printf("%d ",arr[j]);
        else
          printf("%d\n", arr[j]);
      }
    free(arr);
  }

  //system("PAUSE");
  return 0;
}