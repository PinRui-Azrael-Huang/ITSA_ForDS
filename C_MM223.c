#include <stdio.h>
#include <stdlib.h>

// WTF IS THIS QUESTION ???????????????????

typedef struct{
  int startH, startM, endH, endM;
  int wage, days;
  int salary;
} Work;

int main (){
  int numPeople;
  scanf("%d",&numPeople);
  Work people[numPeople];

  for(int i = 0; i < numPeople; i++){
    scanf("%d %d %d %d %d %d",
           &people[i].startH,&people[i].startM,&people[i].endH,&people[i].endM
          ,&people[i].wage, &people[i].days);
    int totalHours;
    
    if (people[i].startM <= people[i].endM){
      if (people[i].startM != people[i].endM)
        totalHours = people[i].endH - people[i].startH + 1;
      else
        totalHours = people[i].endH - people[i].startH;
    }
    else                          
      totalHours = people[i].endH - people[i].startH;

    people[i].salary = people[i].wage * people[i].days * totalHours;
    printf("%d\n",people[i].salary);
  }
  // for(int i = 0; i < numPeople; i++){
  //   if( i != numPeople - 1)
  //     printf("%d ",people[i].salary);
  //   else
  //     printf("%d\n",people[i].salary);
  // }

  //system("PAUSE");
  return 0;
}