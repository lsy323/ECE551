 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  const char* append = ".counts";
  const size_t suffix = strlen(append) + 1;
  size_t len = strlen(inputName);
  char * newname = NULL;
  newname = malloc((suffix + len) * sizeof(*newname));
  for(size_t i = 0; i < len+1; i++){
    newname[i] = inputName[i];
  }
  strcat(newname, append);
  return newname;
}
