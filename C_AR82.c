#include <stdio.h>
#include <stdlib.h>

int main (){
  int numTests, numStudents;
  scanf("%d %d", &numTests , &numStudents);
  int grade[numStudents][numTests];
  float ratio[numTests], sum;
  
  for(int i = 0 ; i < numTests ; i++)
    scanf("%f",&ratio[i]);
  
  for(int i = 0 ; i < numStudents ; i++){
    for(int j = 0 ; j < numTests ; j++){
      scanf("%d",&grade[i][j]);
      sum += ratio[j] * grade[i][j];
    }
  }
  sum /= numStudents;
  printf("%.2f\n",sum);
  
  //system("PAUSE");
  return 0;
}