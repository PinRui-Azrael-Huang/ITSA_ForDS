#include <stdio.h>
#include <stdlib.h>

typedef struct{
  float real, imag;
} Complex;

int main(){
  Complex A, B;
  scanf("%f %f",&A.real ,&A.imag);
  scanf("%f %f",&B.real ,&B.imag);
  Complex add, sub, mul;
  add.real = A.real + B.real;
  add.imag = A.imag + B.imag;
  sub.real = A.real - B.real;
  sub.imag = A.imag - B.imag;
  mul.real = A.real * B.real + ((-1) * (A.imag * B.imag));
  mul.imag = A.imag * B.real + B.imag * A.real;

  printf("(%.2f)+(%.2f)i\n",add.real,add.imag);
  printf("(%.2f)+(%.2f)i\n",sub.real,sub.imag);
  printf("(%.2f)+(%.2f)i\n",mul.real,mul.imag);

  //system("PAUSE");
  return 0;
}