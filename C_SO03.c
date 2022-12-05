#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int x, y ;
} Point;

int dist(Point a, Point b){
  return (((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
}

int main(){
  int numTest, numPoints;
  scanf("%d",& numTest);

  int curMax = 0;
  for (int i = 0 ; i < numTest ; i++){
    scanf("%d" ,& numPoints);
    Point *pointArr = malloc(sizeof(Point) * numPoints);
    for (int j = 0 ; j < numPoints ; j++){
      scanf("%d",&pointArr[j].x);
      scanf("%d",&pointArr[j].y);
    }

    for (int i = 0 ; i < numPoints ; i++){
      for (int j = 1 ; j < numPoints ; j++){
        if (dist(pointArr[i], pointArr[j])> curMax){
          curMax = dist(pointArr[i], pointArr[j]);
        }
      }
    }
    printf("%d\n",curMax);
    curMax = 0;
  }

  return 0;
}