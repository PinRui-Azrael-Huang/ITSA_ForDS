#include <stdio.h>
#include <stdlib.h>

int calc(int num){
  int result = num;
  while(num > 0){
    result += (num % 10);
    num /= 10;
  }
  return result;
}

int main(){
  int numTests;
  scanf("%d",&numTests);
  int start, end, sum;
  int current;  

  for(int i = 0 ; i < numTests ; i++){
    scanf("%d %d", &start, &end);
    sum = start;
    current = start;

    while(current < end){
      current = calc(current);
      if (current > end)
        break;
      else
        sum += current;
    }
    printf("%d\n",sum);
  }

  //system("PAUSE");
  return 0;
}