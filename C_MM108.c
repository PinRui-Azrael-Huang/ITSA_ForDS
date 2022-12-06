#include <stdio.h>
#include <stdlib.h>
#define MAXPOWER 32

int main (){
  int num;
  scanf("%d",&num);
  int binary[MAXPOWER];
  for (int i = 0 ; i < MAXPOWER ; i++)
    binary[MAXPOWER] = -1;

  int digit = 0;
  while(num > 0){
    binary[digit++] = num%2;
    num /= 2;
  }

  int bitIs1 = 0;
  for (int i = 0 ; i < MAXPOWER ; i++){
    if(binary[i] == 1)
      bitIs1++;
    if(binary[i] == -1)
      break;
  }
  printf("The number of bits is %d.\n", bitIs1);

  system("PAUSE");
  return 0;
}