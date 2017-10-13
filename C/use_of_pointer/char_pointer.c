#include<stdio.h>
#include<stdlib.h>

int main(){
  char *a = "hello world";
  char b[] = "hellow world";
  char *c = "hello world";
  printf("address of a: %d", a);
  printf("address of c: %d", c);
  printf("address of b: %d",b)
  return 0;
}
