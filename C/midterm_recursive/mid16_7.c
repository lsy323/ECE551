#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void count_line(char * line, char *c, size_t *t, size_t n){
  while(*line != '\n'){
    for(int i = 0; i < n; i++){
      if(c[i] == *line){
	t[i]++;
      }
    }
    line++;
  }
}

int main(int argc, char ** argv){
  FILE * f = fopen(argv[1], "r");
  char * count_char = argv[2];
  size_t len = strlen(count_char);
  char * line = NULL;
  ssize_t l = 0;
  size_t sz = 0;
  size_t *count_table = malloc(len * sizeof(*count_table));
  for(int i = 0; i < len; i++){
    count_table[i] = 0;
  }
  while((l = getline(&line, &sz, f)) >= 0){
    count_line(line, count_char, count_table, len);
  }
  free(line);
  for(int i = 0; i < len; i++){
    printf("%c:%lu\n", count_char[i], count_table[i]);
  }
}
