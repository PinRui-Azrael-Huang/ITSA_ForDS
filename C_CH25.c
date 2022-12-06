#include <stdio.h>
#include <stdlib.h>
#define ROOMSIZE 7

typedef struct{
  int row, col;
} Pos;

int main (){
  int **room = malloc(sizeof(int*) * ROOMSIZE);
  for (int i = 0 ; i < ROOMSIZE ; i++)
    room[i] = malloc(sizeof(int) * ROOMSIZE);

  for(int i = 0 ; i < ROOMSIZE ; i++){
    for(int j = 0; j < ROOMSIZE ; j++){
      scanf("%d",&room[i][j]);
    }
  }

  Pos *lightPos = malloc(sizeof(Pos) * (ROOMSIZE * ROOMSIZE));
  for (int i = 0 ; i < ROOMSIZE * ROOMSIZE ; i++)
    lightPos[i].row = lightPos[i].col = -1;

  int count = 0;
  for(int i = 0 ; i < ROOMSIZE ; i++){
    for(int j = 0; j < ROOMSIZE ; j++){
      if (room[i][j] == 2){
        lightPos[count].row = i;
        lightPos[count++].col = j;
      }
    }
  }

  Pos cur, origin;
  for (int i = 0; i < count ; i++){
    origin = lightPos[i];
    cur = origin ;

    // UPWARD
    while(cur.row - 1 >= 0 && room[cur.row - 1][cur.col] != 1){
      cur.row--;
      room[cur.row][cur.col] = 3; 
    }
    cur = origin;

    // DOWNWARD
    while(cur.row + 1 <= 6 && room[cur.row + 1][cur.col] != 1){
      cur.row++;
      room[cur.row][cur.col] = 3; 
    }
    cur = origin;

    // LEFT
    while(cur.col - 1 >= 0 && room[cur.row][cur.col - 1] != 1){
      cur.col--;
      room[cur.row][cur.col] = 3; 
    }
    cur = origin;

    // RIGHT
    while(cur.col + 1 <= 6 && room[cur.row][cur.col + 1] != 1){
      cur.col++;
      room[cur.row][cur.col] = 3; 
    }
  }

  int darkCount = 0;
  for(int i = 0; i < ROOMSIZE ; i++){
    for(int j = 0 ; j < ROOMSIZE ; j++){
      if(room[i][j] == 0)
        darkCount++;
    }
  }
  printf("%d\n",darkCount);

  return 0;
}