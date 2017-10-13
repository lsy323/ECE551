#include<stdio.h>
#include<stdlib.h>

int main(){
	double d_23[2][3] = {{1,2,3},{4,5,6}};
	double d_3[3] = {1,2,3};
	const char * str1 = "str1";
	char str2[] = "str2";
	printf("the size of d_23: %lu\n",sizeof(d_23));
	printf("the size of d_23[1]: %lu\n",sizeof(d_23[1]));
	printf("the size of d_3: %lu\n",sizeof(d_3));
	printf("the size of str1: %lu\n",sizeof(str1));
	printf("the size of *str1: %lu\n",sizeof(*str1));
	printf("the size of str2: %lu\n",sizeof(str2));
	return EXIT_SUCCESS;
}
