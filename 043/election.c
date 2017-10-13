#include "election.h"
#include <stdio.h>
#include <stdlib.h>
//include any other headers you need here...

state_t parseLine(const char * line) {
  //STEP 1: write me
  if (line == NULL){
    fprintf(stderr, "error");
    exit(EXIT_FAILURE);
  }
  state_t parsed;
  parsed.population = 0;
  parsed.electoralVotes = 0;
  const char * ptr = line;
  int colon_count = 0;
  int offset = 0;
  while(*ptr != '\0'){
    if(*ptr == ':'){
      colon_count++;
      ptr++;
    }
    switch(colon_count){
    case 0:
      parsed.name[offset] = *ptr;
      offset++;
      break;
    case 1:
      parsed.population = parsed.population * 10 + *ptr - '0';
      break;
    case 2:
      parsed.electoralVotes = parsed.electoralVotes * 10 + *ptr -'0';
      break;
    default:
      exit(EXIT_FAILURE);
    }
    ptr++;
  }
  parsed.name[offset] = '\0';
  return parsed;
}
unsigned int countElectoralVotes(state_t * stateData, 
				 uint64_t * voteCounts, 
				 size_t nStates) {
  //STEP 2: write me
  unsigned int total = 0;
  for (size_t i = 0; i < nStates; i++){
    if(stateData[i].population < voteCounts[i]*2)
      total += stateData[i].electoralVotes;
  } 
  return total;
}

void printRecounts(state_t * stateData, 
		   uint64_t * voteCounts, 
		   size_t nStates) {
  //STEP 3: write me
  //printf("sizeof(unsigned int): %lu\n",sizeof(unsigned int));
  //printf("sizeof(uint64_t): %lu\n",sizeof(uint64_t));
  for (size_t i = 0; i < nStates; i++){
    double percentage = (double)voteCounts[i]/stateData[i].population;
    if(percentage >= 0.495 && percentage <= 0.505)
      printf("%s requires a recount (Candidate A has %.2f%% of the vote)\n", stateData[i].name, percentage);
  }
}
void printLargestWin(state_t * stateData, 
		     uint64_t * voteCounts, 
		     size_t nStates) {
  //STEP 4: write me
  double max = 0;
  size_t index = 0;
  for (size_t i = 0; i < nStates; i++){
    double percentage = (double)voteCounts[i]/stateData[i].population;
    if(percentage > max){
      max = percentage;
      index = i;
    }
  }
  printf("Candidate A won %s with %.2f%% of the vote\n", stateData[index].name, max);
}
