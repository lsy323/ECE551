#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t * mycounts = malloc(sizeof(*mycounts));
  mycounts->one_count = NULL;
  mycounts->num_one_count = 0;
  return mycounts;
}
void addnull(counts_t * c){
  int if_find = 0;
  for(size_t i = 0; i < c->num_one_count; i++){
    if(c->one_count[i]->key == NULL){
      if_find = 1;
      c->one_count[i]->count++;
    }
  }
  if(!if_find){
    c->num_one_count++;
    c->one_count = realloc(c->one_count, c->num_one_count * sizeof(*c->one_count));
    c->one_count[c->num_one_count - 1] = NULL;
    c->one_count[c->num_one_count - 1] = realloc(c->one_count[c->num_one_count - 1], sizeof(*c->one_count[c->num_one_count - 1]));
    c->one_count[c->num_one_count - 1]->key = NULL;
    c->one_count[c->num_one_count - 1]->count = 1;
  }
}
int isequal(const char * str1, const char * str2){
  const char * tmp1 = str1;
  const char * tmp2 = str2;
  while(*tmp1 == *tmp2){
    if(*tmp1 == '\0'){
      return 1;
    }
    tmp1++;
    tmp2++;
  }
  return 0;
}
char * namecopy(const char * name){
  int len = strlen(name);
  char * c = malloc((len + 1) * sizeof(char));
  for(int i = 0; i < len; i++){
    c[i] = name[i];
  }
  c[len] = '\0';
  return c;
}
void addname(counts_t *c, const char * name){
  int if_find = 0;
  for(size_t i = 0; i < c->num_one_count; i++){
    if(c->one_count[i]->key != NULL){
      if(isequal(c->one_count[i]->key, name)){
	if_find = 1;
	c->one_count[i]->count++;
      }
    }
  }
  if(!if_find){
    c->num_one_count++;
    c->one_count = realloc(c->one_count, c->num_one_count * sizeof(*c->one_count));
    c->one_count[c->num_one_count - 1] = NULL;
    c->one_count[c->num_one_count - 1] = realloc(c->one_count[c->num_one_count - 1], sizeof(*c->one_count[c->num_one_count - 1]));
    c->one_count[c->num_one_count - 1]->key = namecopy(name);
    c->one_count[c->num_one_count - 1]->count = 1;
  }
}						
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if(name == NULL){
    addnull(c);
  }
  else{
    addname(c, name);
  }		   
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  int null_exist = 0;
  int count_null = 0;
  //printf("%lu", c->num_one_count);
  if(outFile == NULL){
    fprintf(stderr, "error write file\n");
    exit(EXIT_FAILURE);
  }
  for(size_t i = 0; i < c->num_one_count; i++){
    if(c->one_count[i]->key == NULL){
      count_null = c->one_count[i]->count;
      null_exist = 1;
    }
    else{
      fprintf(outFile,"%s: %lu\n", c->one_count[i]->key, c->one_count[i]->count);
    }
  }
  if(null_exist){
    fprintf(outFile,"<unknown>: %u\n", count_null);
  }
  fclose(outFile);
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for(size_t i = 0; i < c->num_one_count; i++){
    free(c->one_count[i]->key);
    free(c->one_count[i]);
  }
  free(c->one_count);
  free(c);
}
