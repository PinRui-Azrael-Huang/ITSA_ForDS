#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int coefX, coefY, coefC;
} Equation;

int checkSol(Equation *eq, int x, int y){
  return (eq->coefX * x )+ (eq->coefY * y) == eq->coefC;
}

int main (){
  Equation *eq = malloc(sizeof(Equation));
  scanf("%d,%d,%d",&eq->coefX ,&eq->coefY ,&eq->coefC);
  int x = 0, y = 0;

  while ((eq->coefX * x )+ (eq->coefY * y) <= eq->coefC){
    while(eq->coefC - (eq->coefX * x ) >= 0 ){
      while (eq->coefY * y <= eq->coefC - (eq->coefX * x )){
        if (checkSol(eq, x, y)){
          printf("%d,%d\n", x, y);
          y++;
        } else {
          y++;
        }
      }
      y = 0;
      x++;
    }
  }
  return 0;
}