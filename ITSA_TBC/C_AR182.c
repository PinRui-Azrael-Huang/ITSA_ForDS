#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTRINGLEN 20

void printMatrix(int **matrix, int size){
  for (int i = 0; i < size ; i++){
    for (int j = 0; j < size ; j++){
      if (j == size - 1)
        printf("%d", matrix[i][j]);
      else
        printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void verticalFlip(int **matrix, int  size){
  for (int i = 0 ; i < size / 2 ; i++){
    for (int j = 0 ; j < size ; j++){
      int temp = matrix[size - i - 1][j];
      matrix[size - i - 1][j] = matrix[i][j];
      matrix[i][j] = temp;
    }
  }
}

void horizontalFlip(int **matrix, int size){
  for (int i = 0 ; i < size / 2 ; i++){
    for (int j = 0 ; j < size ; j++){
      int temp = matrix[j][i];
      matrix[j][i] = matrix[j][size - i - 1];
      matrix[j][size - i - 1] = temp;
    }
  }
}

void diagonalFlip(int **matrix, int size){
  for (int i = 0 ; i < size ; i++){
    for (int j = 0 ; j < i ; j++){
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
}

int main (){
  int N;
  scanf("%d",&N);
  int **matrix = malloc(sizeof(int) * N);
  for (int i = 0; i < N ; i++)
    matrix[i] = malloc(sizeof(int) * N);
  
  int count = 1;
  for (int i = 0; i < N ; i++){
    for (int j = 0; j < N ; j++)
      matrix[i][j] = count++;
  }

  char* operation = malloc(sizeof(char) * (MAXSTRINGLEN + 1));
  memset(operation, '\0', sizeof(char) * (MAXSTRINGLEN + 1));
  scanf("%s",operation);

  int i = 0;
  while(operation[i] != '\0'){
    if (operation[i] == 'H')
      horizontalFlip(matrix, N);
    else if (operation[i] == 'V')
      verticalFlip(matrix, N);
    else if (operation[i] == 'D')
      diagonalFlip(matrix, N);
    i++;
  }

  printMatrix(matrix, N);
  return 0;
}