#include <stdio.h>
#include <stdlib.h>

int getBomb(int n, int map[n][n], int i, int j){
  if(map[i][j] == 1)
    return 0;
  int bomb = map[i - 1][j - 1] + map[i - 1][j] + map[i - 1][j + 1] + map[i][j - 1] + map[i][j + 1]
           + map[i + 1][j - 1] + map[i + 1][j] + map[i + 1][j + 1];
  return bomb;
}

int main(){
  int n;
  scanf("%d",&n);
  int map[n+2][n+2];
  int bomb[n+2][n+2];

  for(int i = 0 ; i < n + 2; i++){
    for(int j = 0 ; j < n + 2; j++){
      map[i][j] = 0;
      bomb[i][j] = 0;
    }
  }

  for(int i=1; i <= n ; i++)
    for(int j=1 ; j <= n ; j++)
      scanf("%d",&map[i][j]);
    
  for(int i=1; i <= n ; i++)
    for(int j=1 ; j <= n ; j++)
      bomb[i][j] = getBomb(n+2, map, i, j);

  for(int i=1; i <= n ; i++){
    for(int j=1 ; j <= n ; j++){
      if (j != n)
        printf("%d ",bomb[i][j]);
      else
        printf("%d",bomb[i][j]);
    }
    printf("\n");
  }

  //system("PAUSE");
  return 0;
}