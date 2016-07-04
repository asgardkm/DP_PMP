// Test 1 Problem 2
#include <stdio.h>

int main(){
	int i,			// loop counter
		j;			// input integer
		
	// tmp_var not needed when using scanf
	// char tmp_var[10];	// tmp variable for storing input integer w/ stdio
		
	// show prompt
	printf("Please enter an integer.\n");
	scanf("%d", &j); // using scanf
	
	// not using fgets and sscanf
	//fgets(tmp_var, sizeof(tmp_var) - 1, stdin);
	//sscanf(tmp_var, " %d", &j);
	
	// print more things to screen
	printf("Thank you for the input!\nHERE IT IS!\n");
	
	// loop through integers 1-9
	for (i = 1; i <= 9; i++){
		// print input and its product w/ each 1-9 integer
		printf("%d X %d is %d\n", j, i, j*i);
		
	}
	
	getchar();
	return 0;	
	
}
