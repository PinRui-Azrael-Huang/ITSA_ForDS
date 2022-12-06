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
    return curMatch.x - 1< size && curMatch.y < size &&
           curMatch.x - 1 >= 0   && curMatch.y >= 0;
  else if (direction == 1)  // Right
    return curMatch.x < size && curMatch.y + 1 < size &&
           curMatch.x >= 0   && curMatch.y + 1 >= 0;
  else if (direction == 2)  // Down
    return curMatch.x + 1 < size && curMatch.y < size &&
           curMatch.x + 1 >= 0   && curMatch.y >= 0;
  else if (direction == 3)  // Left
    return curMatch.x < size && curMatch.y - 1 < size &&
           curMatch.x >= 0   && curMatch.y - 1 >= 0;
}

Pos getPos(Pos pos, int direction){
  if (direction == 0)      // Up
    pos.x--;       
  else if (direction == 1) // Right
    pos.y++;
  else if (direction == 2) // Down
    pos.x++;
  else if (direction == 3) // Left
    pos.y--;

  return pos;
}

int compare(int size, char** mtx, char *target, Pos *firstMatch, int curMatch){
  int** visited = malloc(sizeof(int*) * size);
  for(int i = 0 ; i < size ; i++)
    visited[i] = malloc(sizeof(int) * size);
  for(int i = 0 ; i < size ; i++)
    for(int j = 0 ; j < size ; j++)
      visited[i][j] = 0;

  char* curSubString = malloc(sizeof(char) * 101);
  memset(curSubString, '\0', 101);
  curSubString[0] = target[0];

  int len = strlen(target);
  int curLen = 2;
  Pos curPos = firstMatch[curMatch];
  Pos lastPos;
  visited[curPos.x][curPos.y] = 1;


  while (curLen <= len){
    for (int i = 0; i < 4 ; i++){
      if (boundaryCheck(curPos, size, i)){
        lastPos = curPos;
        curPos = getPos(curPos, i);
        if (!visited[curPos.x][curPos.y]){
          visited[curPos.x][curPos.y] = 1;
          curSubString[curLen - 1] = mtx[curPos.x][curPos.y];
          if (strncmp(curSubString, target, curLen) == 0){
            curLen++;
            i = -1;
            if (curLen == len + 1){
              return 1;
            }
          }
          else{
            visited[curPos.x][curPos.y] = 0;
            curPos = lastPos;
            if (i == 3)
              return 0;
          }
        }
        else {
          curPos = lastPos;
        }
      }
    }
    return 0;
  }
  return 0;
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

  return 0;
}