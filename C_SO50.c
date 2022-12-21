#include <stdio.h>
#include <stdlib.h>
#define UNITSIZE 3

int cmpNum (const void *a, const void *b){
  int *A = (int*) a;
  int *B = (int*) b;
  return *A - *B;
}

int getMedian(int *unit){
  qsort(unit, UNITSIZE, sizeof(int), cmpNum);
  return unit[UNITSIZE / 2];
}

void medianFilter(int *img, int size){
  int i = 0;
  int targetBit = 1 ;
  int *unit = malloc(sizeof(int) * UNITSIZE);
  while(i < size){
    for(int j = 0 ; j < UNITSIZE ; j++)
      unit[j] = img[i++];

    i-=2;
    int median = getMedian(unit);
    img[targetBit++] = median;
  }
  
  for(int j = 0 ; j < size ; j++){
    if (j != size - 1)
      printf("%d ",img[j]);
    else
      printf("%d\n",img[j]);
  }
}

int main (){
  int size;
  scanf("%d", &size);
  int *img = malloc(sizeof(int) * size);
  for(int i = 0 ; i < size; i++){
    scanf("%d",&img[i]);
  }
  medianFilter(img, size);

  return 0;
}
