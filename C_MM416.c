#include <stdio.h>
#include <stdlib.h>

int main (){
  int size, numConversion;
  scanf("%d",&size);
  scanf("%d",&numConversion);
  int matrix[size][size], result[size][size];
  for (int i = 0 ; i < size ; i++){
    for (int j = 0 ; j < size ; j++){
      scanf("%d",&matrix[i][j]);
      result[i][j] = matrix[i][j];
    }
  }
    
  
  int border = size / 2;
  int a, b;
  for(int count = 0; count < numConversion ; count++){
    // shift the result to matrix again.
    for(int i = 0 ; i < size ; i++)
      for(int j = 0 ; j < size ; j++)
        matrix[i][j] = result[i][j];

    if (count % 2 == 0){  // Horizontal
      for (int row = 0 ; row < size ; row++){
        for (int col = 0 ; col < size / 2 ; col++){
          a = matrix[row][(2 * col)];
          b = matrix[row][(2 * col) + 1];
          result[row][col] = a + b;
          result[row][col + border] = a - b;
        }
      }
    }
    else{ // Vertical
      for (int col = 0 ; col < size ; col++){
        for (int row = 0 ; row < size / 2 ; row++){
          a = matrix[(2 * row)][col];
          b = matrix[(2 * row) + 1][col];
          result[row][col] = a + b;
          result[row + border][col] = a - b;
        }
      }
    }
  }

  for(int i = 0 ; i < size ; i++){
    for(int j = 0 ; j < size ; j++){
      if(j != size - 1)
        printf("%d ", result[i][j]);
      else
        printf("%d\n", result[i][j]);
    }
  }

  //system("PAUSE");
  return 0;
}