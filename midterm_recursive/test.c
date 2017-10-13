#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strfill(char * p, size_t n, char c) {
  for (size_t i = 0; i < n; i++) {
    p[i] = c;
  }
  p[n] = '\0';
}
char * rexpand(const char * str, size_t * counts) {
  if (*str == '\0') {
    return strdup("");
  }
  char * temp = rexpand(str+1, counts+1);
  size_t len = strlen(temp);
  size_t newsize = len + *counts +1;
  temp = realloc(temp,  newsize * sizeof(*temp));
  strfill(temp + len, *counts, *str);
  return temp;
}

int main(){
  char * str = "Helloworld";
  size_t counts[10] = {0};
  char * res = rexpand(str, counts);
  printf("%s\n", res);
  return 0;
}
  
