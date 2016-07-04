// yards.c
#include <stdio.h>
#define NUM_ELEMENT 10 			// number of array elements
#define CONVERSION 0.9144
int main(void){
	
	unsigned int yards[NUM_ELEMENT];
	int i;
	for (i = 0; i < NUM_ELEMENT; i++){
		yards[i] = (i+1)*5;
	}	
	
	// printing header
	printf("%10s %10s \n", "Yards", "Meters");
	
	// print to meters
	for (i = 0; i < NUM_ELEMENT; i++){
		printf("%10d %10.2f\n", yards[i], yards[i]*CONVERSION);
	}
	getchar();
	return 0;	
}
