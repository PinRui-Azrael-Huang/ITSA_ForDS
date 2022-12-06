#include <stdio.h>
#include <stdlib.h>

int main (){
  int numCards;
  scanf("%d",&numCards);
  numCards *=2;

  int *olddeck = malloc(sizeof(int) * numCards*2);
  for (int i = 0 ; i < numCards ; i++)
    olddeck[i] = i + 1;

  int *newdeck = malloc(sizeof(int) * numCards*2);
  for (int i = 0 ; i < numCards ; i++)
    newdeck[i] = i + 1;
  
  int first = olddeck[0];
  int count = 0;
  int front = 0, back = numCards / 2, cur = 0;
  do{
    for(int i = 0 ; i < numCards / 2 ; i++){
      newdeck[cur++] = olddeck[back++];
      newdeck[cur++] = olddeck[front++];
    }
    for(int i = 0 ; i < numCards ; i++)
      olddeck[i] = newdeck[i];
    
    cur = front = 0;
    back = numCards / 2;
    count++;
  } while(newdeck[0] != first);

  printf("%d\n",count);
  return 0;
}