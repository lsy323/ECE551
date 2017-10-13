#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

char * getkey(char * line, char * split){
  size_t offset = split - line;
  char * key = malloc((offset + 1) * sizeof(*key));
  for(int i = 0; i < offset; ++i){
    key[i] = line[i];
  }
  key[offset] = '\0';
  return key;
}
char * getvalue(char * line, char * split, ssize_t len){
  size_t len_v = len - (split - line + 1) - 1;
  char * v = malloc((len_v + 1)* sizeof(*v));
  for(int i = 0; i < len_v; ++i){
    v[i] = split[i+1];
  }
  v[len_v] = '\0';
  return v;
}
kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE *f = fopen(fname, "r");
  if (f == NULL) {
    fprintf(stderr, "error open file\n");
    exit(EXIT_FAILURE);
  }
  kvarray_t * kvarray = malloc(sizeof(*kvarray));
  kvarray->numKvpair = 0;
  kvarray->kvpair = NULL;
  size_t sz = 0;
  ssize_t len = 0;
  char * line = NULL;
  while((len = getline(&line, &sz, f)) >= 0){
    char * split = strchr(line, '=');
    kvarray->numKvpair++;
    kvarray->kvpair = realloc(kvarray->kvpair, kvarray->numKvpair * sizeof(*kvarray->kvpair));
    kvarray->kvpair[kvarray->numKvpair - 1] = malloc(sizeof(*kvarray->kvpair[kvarray->numKvpair - 1]));
    kvarray->kvpair[kvarray->numKvpair - 1]->k = getkey(line, split);
    kvarray->kvpair[kvarray->numKvpair - 1]->v = getvalue(line, split, len);
  }
  free(line);
  fclose(f);
  return kvarray;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i = 0; i < pairs->numKvpair; ++i){
    free(pairs->kvpair[i]->k);
    free(pairs->kvpair[i]->v);
    free(pairs->kvpair[i]);
  }
  free(pairs->kvpair);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i = 0; i < pairs->numKvpair; ++i){
    printf("key = '%s' value = '%s'\n", pairs->kvpair[i]->k, pairs->kvpair[i]->v);
  }
}

int isequal(const char *a, const char *b){
  const char *tmpa = a;
  const char *tmpb = b;
  while(*tmpa == *tmpb){
    if(*tmpa == '\0'){
      return 1;
    }
    tmpa++;
    tmpb++;
  }
  return 0;
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  char * value = NULL;
  for(int i = 0; i < pairs->numKvpair; i++){
    if(isequal(pairs->kvpair[i]->k, key)){
      value = pairs->kvpair[i]->v;
    }
  }  
  return value;
}
