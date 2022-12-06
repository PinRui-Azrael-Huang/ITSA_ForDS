#include <stdio.h>
#include <stdlib.h>

int main (){
  int date;
  scanf("%d",&date);
  int N = 0, S = 0;
  for(int i = 7 ; i >= 0 ; i--){
    int divider = 1;
    for(int j = 0 ; j < i ; j++)
      divider *= 10;

    N+= date / divider;
    date = date % divider;
  }

  for (int i = 1 ; i < N ; i++){
    if (N % i == 0)
      S+=i;
  }

  if (S > N)
    printf("-1\n");
  else if (S == N)
    printf("0\n");
  else if (S < N)
    printf("%d\n", N - S);

  system("PAUSE");
  return 0;
}