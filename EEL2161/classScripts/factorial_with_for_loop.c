// factorial_with_for_loop.c
#include <stdio.h>

int main(void){
		unsigned int num = 5;
		unsigned int sum;
		unsigned int i; 	// multiplier to be used in calculating factorial
			
		for (sum=1, i=1; i<=num; ++i){
			sum *= i; 		// multiply the current sum by the multiplier	
		} 					// end of loop

		printf("The factorial of %d is %d.\n", num, sum);
		
		getchar();
		return(0);
	
}
