// HW 3_4
#include <stdio.h>

int main(){
	
	int i;					// loop counter
	 
	char yes_or_no = 'y',	// char which decides to run code again or to exit w/ 'n'
		 value[10],			// where tmp str val from std is stored
		 letters[6] = {'a', 'b', 'c', 'd', 'e', 'f'}; // char array of letters a-f 
													  // variables from equation	
	float coeff[6],			// coefficient inputs (this loads value as float)
		  ans_x,			// result x from inputting equation
		  ans_y;			// result y from inputting equation
	
	// run loop while yes_or_no char is not 'n'
	while(yes_or_no != 'n') {
		
		// loop through each variable a-f
		for (i = 0; i <= 5; i++){
			// print prompt to terminal for user to input number for var
			printf("Enter the value of %c \n", letters[i]); 
			// store in stdio input
			fgets(value, sizeof(value)-1, stdin);
			// save value as float in coefficient array			
			sscanf(value, "%f", &coeff[i]);
		}
	// calculate x value (x = (ce-bf) / (ae-bd))
	ans_x = (coeff[2]*coeff[4] - coeff[1]*coeff[5]) / (coeff[0]*coeff[4] - coeff[1]*coeff[3]);
	// calculate y value (y = (af-cd) / (ae-bd))
	ans_y = (coeff[0]*coeff[5] - coeff[2]*coeff[3]) / (coeff[0]*coeff[4] - coeff[1]*coeff[3]);
	
	// print result x and y output to user
	printf("The value of X is %f and the value of Y is %f.\n", ans_x, ans_y);
	
	// print offer to user to run code again (can exit by pressing 'n'
	printf("Do you want to play more? Press Any Key\nIf not, Press \"n\" then Enter please\n");	
	// save user's char input for deciding loop continuation
	yes_or_no = getchar();	
		
	}
	
	getchar();
	return 0;

}
