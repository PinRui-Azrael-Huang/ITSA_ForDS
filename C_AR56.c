#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x,y;
} Pos;

char **init(int size){
  char **mtx = malloc(sizeof (int*) * size);
  for (int i = 0 ; i < size ; i++){
    mtx[i] = malloc(sizeof(int) * size);
  }
  char ch;
  for (int i = 0 ; i<size ; i++){
    for (int j = 0 ; j < size; j++){
      ch = getchar();
      mtx[i][j] = ch;
    }
    ch = getchar();
  }
  return mtx;
}

int boundaryCheck(Pos curMatch, int size, int direction){
  if (direction == 0)       // Up
    return curMatch.x < size && curMatch.y - 1 < size &&
           curMatch.x >= 0   && curMatch.y - 1 >= 0;
  else if (direction == 1)  // Right
    return curMatch.x + 1 < size && curMatch.y  < size &&
           curMatch.x + 1 >= 0   && curMatch.y  >= 0;
  else if (direction == 2)  // Down
    return curMatch.x < size && curMatch.y + 1 < size &&
           curMatch.x >= 0   && curMatch.y + 1 >= 0;
  else if (direction == 3)  // Left
    return curMatch.x - 1 < size && curMatch.y < size &&
           curMatch.x - 1 >= 0   && curMatch.y >= 0;
}

int compare(int size, char** mtx, char *target, Pos *firstMatch, int curMatch){
  int len = strlen(target);
  int curLen = 2;
  char* curSubString = malloc(sizeof(char) * 101);
  memset(curSubString, '\0', 101);

  while (curLen <= len){
    for (int i = 0; i < 4 ; i++){
      if (boundaryCheck(firstMatch[curMatch], size, i)){


      }
    }
  }
}

int solve(int size, char** mtx, char *target){
  int i = 0 ,j = 0;
  int matches = 0;
  Pos *firstMatch = malloc(sizeof(Pos) * (size * size));
  for(int i = 0 ; i < size*size ; i++){
    firstMatch[i].x = firstMatch[i].y = -1;
  }

  for (int i = 0; i <size ; i++){
    for (int j = 0; j < size ; j++){
      if (target[0] == mtx[i][j]){
        firstMatch[matches].x = i;
        firstMatch[matches++].y = j;
      }
    }
  }
  int count = 0;
  while(count < matches){
    if (compare(size, mtx, target, firstMatch, count))
      return 1;
    else
      count++;
  }
  return 0;
}

int main (){
  int size, numTargets;
  scanf("%d %d",&size ,&numTargets);
  char ch = getchar();
  char **mtx = init(size);

  for(int i = 0 ; i < numTargets ; i++){
    char* target = malloc(sizeof(char) * 101);
    scanf("%s",target);
    if(solve(size, mtx, target))
      printf("yes\n");
    else
      printf("no\n");
  }

  system("PAUSE");
  return 0;
}