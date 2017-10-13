#include <stdio.h>
#include <stdlib.h>
#include "roster.h"

int main(int argc, char ** argv) {
	if(argc != 2){
		fprintf(stderr, "input error\n");
		return EXIT_FAILURE;
	}
	roster * the_roster = readInput(argv[1]);
	if(the_roster == NULL){
		fprintf(stderr, "could not read roster info\n");
		return EXIT_FAILURE;
	}
	classes_t * unique_classes = getClassList(the_roster);
	writeAllFIles(unique_classes, the_roster);
	freeClasses(unique_classes);
	freeRoster(the_roster);
	return EXIT_SUCCESS;
}