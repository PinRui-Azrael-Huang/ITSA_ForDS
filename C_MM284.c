#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  int arr[n];
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", &arr[i]);
  
  int consumption = 0;
  for (int i = 0 ; i < n - 1 ; i++){
    if (arr[i] >= arr[i + 1])
      consumption += arr[i];
    else
      consumption += arr[i + 1];
  }
  printf("%d\n",consumption);

  system("PAUSE");
  return 0;
}