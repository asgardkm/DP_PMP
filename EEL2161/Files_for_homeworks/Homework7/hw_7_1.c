// hw_7_1.c
#include <stdio.h>

//recursively find the factorial of an input number
int findFact(int input);

int main(void){
	int input, output;		// define number to do factorial for & where to store the factorial
	char tmp[10];				// where to tmp store input w/ fgets
	
	// get input number
	printf("Please enter the a number to find the factorial for:\n");
	fgets(tmp, sizeof(tmp) - 1, stdin);
	sscanf(tmp, "%d", &input);
	
	// find factorial
	output = findFact(input);
	
	// display result
	printf("Result: %d! = %d", input, output);
	
	getchar();
	return 0;
} // end of main()

// function for finding factorial of an input
int findFact(int input){
	if (input > 1){
		return input * findFact(input-1);
	} else if (input == 1){
		return input;
	} else{
		printf("Please enter a positive integer value (Value inputted: %d)\n", input);
		return -999;			// error value if n is < 1
	}
} // end of findFact()
