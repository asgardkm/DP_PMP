// test2 question1
#include <stdio.h>

int incrementUp(unsigned int start, unsigned int stop); 	// part(a) function declaration
//int incrementDown(unsigned int start, unsigned int stop);	// part(b) function declaration

// MAKE IT RETURN A VALUE!
int main(void){
	
	int start, stop, sum;
	char tmp[10];						// where to tmp store row/column inputs w/ fgets

	// script description
	printf("This function will add all integers between two user specified integer inputs\n\n");
	// user input for start
	printf("Please enter your first integer\n");
	fgets(tmp, sizeof(tmp) - 1, stdin);
	sscanf(tmp, "%d", &start);
	
	//user input for stop
	printf("Please enter your second integer\n");
	fgets(tmp, sizeof(tmp) - 1, stdin);
	sscanf(tmp, "%d", &stop);
	sum = incrementUp(start, stop);
	//incrementDown(START, STOP);				// part(b) function declaration
	printf("Sum of values between %d and %d: %d\n", start, stop, sum);
	getchar();
	return 0;
}

// note : could have chosen for function to return integer var sum,
// but is unneccessary for the main function. Since the prompt only asks
// to display the factorial result and doesn't do anything with the
// output sum, it is unnecessary to declare it in the main function.

// part(a) function definition
int incrementUp(unsigned int start, unsigned int stop){
	unsigned int sum;
				 
	for (sum = 0; start <= stop; start++){
		sum = sum + start;		
	}
	return sum;
}

//// part(b) function definition
//int incrementDown(unsigned int start, unsigned int stop){
	//unsigned int sum;
				 
	//for (sum = 0; start <= stop; stop--){
		//sum = sum + stop;		
	//}
	//return sum;
//}
