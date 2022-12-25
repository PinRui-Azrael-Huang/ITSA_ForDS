#include <stdio.h>
#include <stdlib.h>

int isUgly(int num){
  if (num == 1)
    return -1;
  while (num % 2 == 0)
    num /= 2;
  while (num % 3 == 0)
    num /= 3;
  while (num % 5 == 0)
    num /= 5;
  
  return num;
}

int findUgly(int nth){
  int num = 1;
  if (nth == 1)
    return 1;
  else{
    nth--;
    while (nth > 0){
      num++;
      if (isUgly(num) == 1)
        nth--;
    }
  }
  return num;
}

int main(){
  int nth;
  scanf("%d",&nth);
  int ans = findUgly(nth);
  printf("%d\n",ans);

  //system("PAUSE");
  return 0;
}