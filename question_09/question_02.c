#include "stdio.h"

void chline(char ,int ,int);


int main(void){
  chline('*',2,4);
}

void chline(char ch ,int x ,int y){
  for(int i = 0;i<=x;i++){
    for(int m = 0 ;m<=y;m++){
      printf("%c",ch);
    }
    printf("\n");
  }
}
