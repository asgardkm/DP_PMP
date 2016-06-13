// hw_6_2.c
#include <stdio.h>
#define START 3
#define STOP 7

void incrementUp(unsigned int start, unsigned int stop); 	// part(a) function declaration
void incrementDown(unsigned int start, unsigned int stop);	// part(b) function declaration

// MAKE IT RETURN A VALUE!
int main(void){
	incrementUp(START, STOP);		// part(a) function declaration
	incrementDown(START, STOP);		// part(b) function declaration
	getchar();
	return 0;
}

// note : could have chosen for function to return integer var sum,
// but is unneccessary for the main function. Since the prompt only asks
// to display the factorial result and doesn't do anything with the
// output sum, it is unnecessary to declare it in the main function.

// part(a) function definition
void incrementUp(unsigned int start, unsigned int stop){
	unsigned int sum;
				 
	for (sum = 0; start <= stop; start++){
		sum = sum + start;		
	}
	printf("Sum (when incrementing up) : %d\n", sum);
}

// part(b) function definition
void incrementDown(unsigned int start, unsigned int stop){
	unsigned int sum;
				 
	for (sum = 0; start <= stop; stop--){
		sum = sum + stop;		
	}
	printf("Sum (when incrementing down) : %d\n", sum);
}
