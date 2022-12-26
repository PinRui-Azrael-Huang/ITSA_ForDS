#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51

int main (){
  char string[MAX],new[MAX];
  memset(string, 0, sizeof(char) * MAX);
  scanf("%s",string);

  int count = 1;
  int newLen = 0;
  int i = 0;

  new[newLen++] = string[i++];
  while(string[i] != '\0'){
    if(string[i] == string[i - 1]){
      count++;
    } else {
      new[newLen++] = '0' + count;
      count = 1;
      new[newLen++] = string[i];
    }
    i++;
  }
  new[newLen++] = '0' + count;
  new[newLen++] = '\0';

  printf("%s\n",new);
  //system("PAUSE");
  return 0;
}