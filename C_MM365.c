#include <stdio.h>
#include <stdlib.h>

int getCharWeight(char ch){
  if (ch == 'A' || ch == 'a')
    return 1;
  else if (ch == 'B' || ch == 'b')
    return 10;
  else if (ch == 'C' || ch == 'c')
    return 19;
  else if (ch == 'D' || ch == 'd')
    return 28;
  else if (ch == 'E' || ch == 'e')
    return 37;
  else if (ch == 'F' || ch == 'f')
    return 46;
  else if (ch == 'G' || ch == 'g')
    return 55;
  else if (ch == 'H' || ch == 'h')
    return 64;
  else if (ch == 'I' || ch == 'i')
    return 39;
  else if (ch == 'J' || ch == 'j')
    return 73;
  else if (ch == 'K' || ch == 'k')
    return 82;
  else if (ch == 'L' || ch == 'l')
    return 2;
  else if (ch == 'M' || ch == 'm')
    return 11;
  else if (ch == 'N' || ch == 'n')
    return 20;
  else if (ch == 'O' || ch == 'o')
    return 48;
  else if (ch == 'P' || ch == 'p')
    return 29;
  else if (ch == 'Q' || ch == 'q')
    return 38;
  else if (ch == 'R' || ch == 'r')
    return 47;
  else if (ch == 'S' || ch == 's')
    return 56;
  else if (ch == 'T' || ch == 't')
    return 65;
  else if (ch == 'U' || ch == 'u')
    return 74;
  else if (ch == 'V' || ch == 'v')
    return 83;
  else if (ch == 'W' || ch == 'w')
    return 21;
  else if (ch == 'X' || ch == 'x')
    return 3;
  else if (ch == 'Y' || ch == 'y')
    return 12;
  else if (ch == 'Z' || ch == 'z')
    return 30;
}

int main(){
  int numID;
  scanf("%d",&numID);
  
  for (int i =0 ; i < numID ; i++){
    char* id = malloc(sizeof(char) * 11);
    scanf("%s",id);

    int weight = 0;
    weight += getCharWeight(id[0]);
    for (int j = 1 ; j < 10 ; j++){
      if (9-j >= 1)
        weight += (9-j) * (id[j] - '0');
      else
        weight += (id[j]-'0');
    }

    if(weight % 10 == 0)
      printf("%d ID check OK\n",i+1 );
    else
      printf("%d ID check XX\n",i+1 );
  }

  return 0;
}