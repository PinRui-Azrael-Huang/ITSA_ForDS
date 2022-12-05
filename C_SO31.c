#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{
  int income;
  int percentage;
  double rate;
} Person;

void getRate(int numPeople, Person *personArr){
  for(int i = 0 ; i < numPeople ; i++){
    int perc = personArr[i].percentage;
    if (perc <= 10 && perc >= 0){
      personArr[i].rate = 0.40;
    }
    else if (perc <= 30 && perc >= 11){
      personArr[i].rate = 0.30;
    }
    else if (perc <= 60 && perc >= 31){
      personArr[i].rate = 0.20;
    }
    else if (perc <= 80 && perc >= 61){
      personArr[i].rate = 0.10;
    }
    else
      personArr[i].rate = 0;
  }
}

void getPercentRate(int numPeople, Person *personArr){
  int curIncome = personArr[0].income;
  double curPercentage = 0;
  personArr[0].percentage = 0;

  for (int i = 1 ; i < numPeople ; i++){
    if (personArr[i].income == curIncome)
      personArr[i].percentage = curPercentage;
    else{
      curIncome = personArr[i].income;
      double percent = (double)i / numPeople;
      curPercentage = ceil(percent * 100);
      personArr[i].percentage = curPercentage;
    }
  }
  getRate(numPeople, personArr);
}

int calcFax(int numPeople, Person *personArr){
  double fax = 0;
  getPercentRate(numPeople, personArr);
  for (int i = 0 ; i < numPeople ; i++){
    fax += personArr[i].rate * personArr[i].income;
  }
  return round(fax);
}

cmpIncome (const void *a, const void *b){
  Person *A = (Person *) a;
  Person *B = (Person *) b;
  
  return B->income - A->income;
}

int main (){
  int numTests, numPeople;
  scanf("%d",&numTests);
  for (int i = 0 ; i < numTests ; i++){
    scanf("%d",&numPeople);
    Person *personArr = malloc(sizeof(Person) * numPeople);
    memset(personArr, 0, sizeof(personArr));

    for (int j = 0 ; j < numPeople; j++){
      scanf("%d",&personArr[j].income);
    }
    qsort(personArr, numPeople, sizeof(Person), cmpIncome);
    int fax = round(calcFax(numPeople, personArr));
    printf("%d\n",fax);
  }

  system("PAUSE");
  return 0;
}