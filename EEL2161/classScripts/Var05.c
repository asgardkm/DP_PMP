// Variable Exercise 005
#include <stdio.h>
int main(void){
	int age; 			// How old are you?
	float hourly_wage; 	/* How much do you make? */
	char gender;		// gender character var
	char name[] = "Oliver Twist";
	
	age = 17;
	hourly_wage = 7.5;	// Is this correct min. wage?
	gender = 'M';		// Male, Female, or Other
	
	// Print variable
	printf("Hello, my name is %s, and my gender is %c.\n I am %d years old and I make $%0.2f an hour which translates into approximately $%0.2f per year.\n Please, Sir, I want some more\n", 
			name, gender, age, hourly_wage, hourly_wage*40*52);
	
	getchar();			// Works like "Press Enter to Proceed"
	return(0);
}
