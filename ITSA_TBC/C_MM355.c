#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAXSTRINGLEN 10

typedef struct{
  char* string;
  int count;
} StringCount;

int main (){
  int num;
  scanf("%d",&num);
  char **stringArr = malloc(sizeof(char*) * num);
  for(int i = 0 ; i < num ; i++){
    stringArr[i] = malloc(sizeof(char*) * MAXSTRINGLEN + 1);
  }

  for(int i = 0 ; i < num ; i++){
    scanf("%s",stringArr[i]);
  }

  int numStrings = (num / 2); 
  StringCount *count = malloc(sizeof(StringCount) * numStrings);
  for(int i = 0 ; i < numStrings ; i++){
    count[i].string = malloc(sizeof(char)* (MAXSTRINGLEN + 1));
    memset(count[i].string, '\0', (MAXSTRINGLEN + 1));
    count[i].count = 0;
  }

  strcpy(count[0].string, stringArr[0]);
  count[0].count++;
  for(int i = 1 ; i < num ; i++){
    for(int j = 0; j < numStrings ; j++){
      if (strcmp(count[j].string, stringArr[i]) == 0){
        count[j].count++;
        if(count[j].count == 3){
          printf("%s\n",count[j].string);
          break;
        }
        break;  
      } 
      else{
        if (count[j].string[0] == '\0'){
          strcpy(count[j].string, stringArr[i]);
          count[j].count++;
          break;
        }
      }
    }
  }
  system("PAUSE");
  return 0;
}