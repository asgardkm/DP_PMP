// Test 1 Problem 1
#include <stdio.h>

int main(){

	char firstname[15], firstname_tmp[15];  // defining tmp string for stdin input
											// and string for saving input
	
	printf("Enter your first name : ");		// promt user to input name
	fgets(firstname_tmp, sizeof(firstname_tmp) - 1, stdin); // read in input
	sscanf(firstname_tmp, " %s", firstname); // save input value as string
	
	// print out results
	printf("Hello my dear %s,\nBest of luck with your First Exam.\n", firstname);
	getchar();		// hit enter to continue;
	return 0;
}
