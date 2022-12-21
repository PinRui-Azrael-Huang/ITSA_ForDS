#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

void printArr(int arr[MAX], int len){
  for(int i = 0 ; i < len ; i++){
    if (i != len - 1)
      printf("%d,",arr[i]);
    else
      printf("%d\n",arr[i]);
  }
}

void selectionAndPrint(int arr[MAX], int len){
  int maxID;
  printArr(arr, len);
  for (int i = 0 ; i < len - 1 ; i++){
    maxID = i;
    for (int j = i + 1 ; j < len ; j++){
      if (arr[j] > arr[maxID]){
        maxID = j;
      }
    }
    if (maxID != i){
      int temp = arr[maxID];
      arr[maxID] = arr[i];
      arr[i] = temp;
      printArr(arr, len);
    }
  }
}

int main(){
  int num;
  int len = 0;
  int arr[MAX];
  while(scanf("%d",&num) != EOF){
    arr[len++] = num;
  }
  selectionAndPrint(arr, len);

  //system("PAUSE");
  return 0;
}