#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int id;
  int eng,math;
} Grade;

cmpGrade(const void *a, const void *b){
  Grade *A = (Grade*) a;
  Grade *B = (Grade*) b;

  if (A->math > B->math)
    return -1;
  else if (A->math < B->math)
    return 1;
  else{
    if (A->eng > B->eng)
      return -1;
    else
      return 1;
  }
}

int main(){
  int num;
  scanf("%d",&num);
  Grade *class = malloc(sizeof(Grade) * num);

  for (int i = 0 ; i < num ; i++){
    scanf("%d %d %d",&class[i].id ,&class[i].math ,&class[i].eng);
  }
  qsort(class, num, sizeof(Grade), cmpGrade);

  for (int i = 0 ; i < num ; i++){
    printf("%d %d %d\n",class[i].id ,class[i].math ,class[i].eng);
  }

  system("PAUSE");
  return 0;
}