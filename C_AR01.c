#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(){
  int num;
  int len = 0;
  int arr[MAX];
  while(scanf("%d",&num) != EOF){
    arr[len++] = num;
  }

  for(int i = len - 1; i >= 0 ; i--){
    if (i != 0)
      printf("%d ",arr[i]);
    else
      printf("%d\n",arr[i]);
  }

  system("PAUSE");
  return 0;
}