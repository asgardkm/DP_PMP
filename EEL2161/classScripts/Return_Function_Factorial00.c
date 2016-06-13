//Return_Function_Factorial.c

#include <stdio.h>
unsigned long long int return_factorial(unsigned int num);
int main(void){
	
	char input[3];
	int number;
	
	//prompt the user
	printf("Enter a positive integer for which the factorial will be calculated:");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%d", &number);
	
	//check the inpout as a conditional
	if (number >0){
		printf("The factorial of %d is %llu.\n", number, return_factorial(number));
	} else {
		printf("You must enter a positive integer!\n");
	}	
	getchar();
	
	return 0;
}
	
unsigned long long int return_factorial(unsigned int num){
	
	unsigned long long int sum = 1;	// initialization
	unsigned int i; 					// multiplier to be used
	
	for(sum = 1, i = 1; i <= num; i++){
		sum *= i;
	}
	
	return sum;
	
}	// end of return_factorial() function

