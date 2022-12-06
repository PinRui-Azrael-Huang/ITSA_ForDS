#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int front, rear;
} Line;

int cmpPoint(const void *a , const void *b){
  Line *A = (Line*) a;
  Line *B = (Line*) b;
  
  if (A->front > B-> front){
    return 1;
  } else if (A->front < B->front){
    return -1;
  } else {
    if (A->rear > B->rear)
      return 1;
    else if (A->rear < B->rear)
      return -1;
  }
}

int main (){
  int numTest;
  scanf("%d" ,&numTest);

  for (int i = 0 ; i < numTest ; i++){
    int numLine;
    int len = 0;
    scanf("%d" ,&numLine);

    Line *lines = malloc((sizeof(Line) * numLine));
    for(int j = 0 ; j < numLine ; j++){
      scanf("%d %d", &lines[j].front, &lines[j].rear);
    }
    qsort(lines, numLine, sizeof(Line), cmpPoint);

    int overlap = 0;
    for(int k = 0 ; k < numLine - 1; k++){
      int origin = k;
      while (lines[k].rear > lines[k+1].front){
        if (k + 1 >= numLine)
          break;
        k++;
      }
      // TODO 全部線段重疊問題
      overlap = (lines[k].rear - lines[origin].front);
      if (overlap)
      len += overlap;
      overlap = 0;
      if (k + 1 == numLine - 1){
        len += (lines[k+1].rear - lines[k+1].front);
      }
    }

    printf("%d\n",len);
  }

  system("PAUSE");
  return 0;
}