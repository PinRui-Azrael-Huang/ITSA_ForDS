#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
  int power, weight, rank;
} Person;

int main (){
  int numPeople;
  scanf("%d", &numPeople);
  Person *contestant = malloc(sizeof(Person) * numPeople);
  for(int i = 0 ; i < numPeople; i++){
    scanf("%d", &contestant[i].power);
    scanf("%d", &contestant[i].weight);
    contestant[i].rank = contestant[i].power / contestant[i].weight;
  }

  int teamS1 = 0, teamS2 = 0;
  int rankDiff;
  teamS1 += contestant[0].rank;
  int numS1 = 1, numS2 = 0;
  for(int i = 1 ; i < numPeople ; i++){
    if (teamS1 > teamS2){
      teamS2 += contestant[i].rank;
      numS2++;
    } else  if (teamS1 < teamS2){
      teamS1 += contestant[i].rank;
      numS1++;
    } else {
      if (numS1 >= numS2){
        teamS2 += contestant[i].rank;
        numS2++;
      } else if (numS1 < numS2){
        teamS1 += contestant[i].rank;
        numS1++;
      }
    }
  }
  
  if (teamS1 >= teamS2){
    rankDiff = teamS1 - teamS2;
    printf("%d\n", rankDiff);
  } else {
    rankDiff = teamS2 - teamS1;
    printf("%d\n", rankDiff);
  }

  if (numS1 > numS2)
    printf("%d\n",numS2);
  else
    printf("%d\n",numS1);
  
  //system("PAUSE");
  return 0;
}