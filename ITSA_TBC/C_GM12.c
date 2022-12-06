#include <stdio.h>
#include <stdlib.h>
#define MAXCOUNT 10

typedef struct{
  int X, Y;
  int cluster;
} Point;

int getSquaredDist(Point A, Point B){
  int x_sqdiff = (A.X - B.X) * (A.X - B.X);
  int y_sqdiff = (A.Y - B.Y) * (A.Y - B.Y);
  return (x_sqdiff + y_sqdiff);
}

int main (){
  Point precinct1, precinct2;
  scanf("%d %d",&precinct1.X ,&precinct1.Y);
  scanf("%d %d",&precinct2.X ,&precinct2.Y);

  Point *site = malloc(sizeof(int) * MAXCOUNT);
  for (int i = 0 ; i < MAXCOUNT ; i++){
    scanf("%d %d",&site[i].X ,&site[i].Y);
  }

  for (int i = 0 ; i < MAXCOUNT ; i++){
    int distTo1 = getSquaredDist(precinct1, site[i]);
    int distTo2 = getSquaredDist(precinct2, site[i]);
    if (distTo1 == distTo2)
      site[i].cluster = 1;
    else if (distTo1 < distTo2)
      site[i].cluster = 1;
    else if (distTo1 > distTo2)
      site[i].cluster = 2;
  }

  printf("cluster 1: (%d, %d)\n",precinct1.X ,precinct1.Y);
  for (int i = 0 ; i < MAXCOUNT ; i++){
    if(site[i].cluster == 1){
      printf("(%d, %d) ",site[i].X ,site[i].Y);
    }
  }
  printf("\n\n");

  printf("cluster 1: (%d, %d)\n",precinct2.X ,precinct2.Y);
  for (int i = 0 ; i < MAXCOUNT ; i++){
    if(site[i].cluster == 2);
    printf("(%d, %d) ",site[i].X ,site[i].Y);
  }
  printf("\n");

  return 0;
}