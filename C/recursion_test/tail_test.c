#include<stdio.h>
#include<stdlib.h>
unsigned powerHelper(unsigned x, unsigned y, unsigned result) {
  if (y == 0) {
    return result;
  } else if (y % 2 == 1) {
    result = result * x;
  }
  return powerHelper(x * x, y / 2, result);
}
unsigned power(unsigned x, unsigned y) {
  return powerHelper(x, y, 1);
}
int main(){
  printf("%d",power(2,7));
  return EXIT_SUCCESS;
}
