#include <stdio.h>
#include <stdlib.h>

void palindrome(int num){
  int digits[5], i = 0;
  while(num > 0){
    digits[i++] = num % 10;
    num /= 10;
  }
  if (digits[0] == digits[4] && digits[1] == digits[3])
    printf("True\n");
  else
    printf("False\n");
}

int main(){
  int numTests, num;
  scanf("%d",&numTests);

  for(int i = 0 ; i < numTests ; i++){
    scanf("%d", &num);
    palindrome(num);
  }

  //system("PAUSE");
  return 0;
}