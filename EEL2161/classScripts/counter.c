// counter.c
#include <stdio.h>

void countdown(int start, int end);

int main(void){
	// call the countdown() function
	countdown(50,40);
	getchar();
	return 0;
}

void countdown(int start, int end){
	printf("Before: %d\n", start);
	
	--start; // decrement
	if (start > end){
		countdown(start, end);
	}
	
	printf("After: %d\n", start);
}
