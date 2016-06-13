// Variable Exercise 004
#include <stdio.h>
int main(void){
	int age; 			// How old are you?
	float hourly_wage; 	/* How much do you make? */
	char gender;		// gender character var
	
	age = 17;
	hourly_wage = 7.5;	// Is this correct min. wage?
	gender = 'M';		// Male, Female, or Other
	
	// Print variable
	printf("You are %d years old.\n", age);
	printf("Your hourly wage is $%0.2f. This translates into approximately $%0.2f per year.\n", hourly_wage, hourly_wage*40*52);
	printf("Your gender was listed as %c.\n", gender);
	
	getchar();			// Works like "Press Enter to Proceed"
	return(0);
}
