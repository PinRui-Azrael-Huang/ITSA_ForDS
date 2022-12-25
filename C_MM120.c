#include <stdio.h>
#include <stdlib.h>

void primeFactorization(int num){
  printf("%d=",num);
  int factor = 2;
  if (num == 1){
    printf("%d\n",num);
    return;
  }
  while(num >= 1){
    if (num % factor == 0 && num / factor != 1){
      printf("%d*",factor);
      num /= factor;
    }
    else if (num % factor == 0 && num / factor == 1){
      printf("%d\n",factor);
      num /= factor;
      break;
    }
    else if (num % factor != 0)
      factor++;
  }
}

int main(){
  int num;
  while(scanf("%d",&num)!=EOF)
    primeFactorization(num);

  //system("PAUSE");
  return 0;
}