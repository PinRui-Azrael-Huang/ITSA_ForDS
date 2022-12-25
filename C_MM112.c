#include <stdio.h>

int main(){
  int num = 100;
  while(num <= 999){
    int hun = num / 100;
    int ten = (num % 100) > 10 ? (num%100)/10 : 0;
    int one = num % 10;
    if(hun*hun*hun + ten*ten*ten + one*one*one == num)
      printf("%d\n",num);
    num++;
  }
  return 0;
}