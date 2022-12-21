#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int flipNum(int num){
  int hun,ten,one;
  one = num / 100;
  hun = num % 10;
  ten = ((num % 100) / 10);
  return (hun * 100) + (ten * 10) + one ;
}

int main(){
  int num;
  scanf("%d",&num);
  int flippedNum = flipNum(num);
  int diff1 = abs(num - flippedNum);
  int diff2 = flipNum (diff1);

  

  int result = (diff1 + diff2) * 40;
  int divider = 10000;
  int digit = 0;
  if (result / divider == 0){
    digit = 4;
    divider /= 10;
  }
  else
    digit = 5;

  char answer[32];
  memset(answer, '\0', sizeof(char) * 32);
  int i = 0;
  while (divider >= 1){
    if (result / divider == 0)
      answer[i] = 'C';
    else if (result / divider == 1)
      answer[i] = 'E';
    else if (result / divider == 2)
      answer[i] = 'L';
    else if (result / divider == 3)
      answer[i] = 'A';
    else if (result / divider == 4)
      answer[i] = 'M';
    else if (result / divider == 5)
      answer[i] = 'G';
    else if (result / divider == 6)
      answer[i] = 'I';
    else if (result / divider == 7)
      answer[i] = 'G';
    else if (result / divider == 8)
      answer[i] = 'O';
    else if (result / divider == 9)
      answer[i] = 'O';  

    result = result % divider;
    divider /=10;
    i++;
  }
  printf("%s\n", answer);

  //system("PAUSE");
  return 0;
}