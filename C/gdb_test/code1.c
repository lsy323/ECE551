#include<stdio.h>
#include<stdlib.h>
int max(int a, int b){
  if(a>b){
    return a;
  }
  else return b;
}
int main() {
  int a = 0;
  int b = 5;
  int c = max(a,b);
  printf("c=%d",c);
  return EXIT_SUCCESS;
}
