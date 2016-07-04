// let_it_flow.c
#include <stdio.h>
#include <limits.h>	// for integer limits
#include <float.h>	// for float limits

int main(void){
	short int 	short_max = SHRT_MAX; 		// LARGEST SHORT INTEGERS
	int 		integer_min = INT_MIN;		// Smallest integer
	double 		double_max = DBL_MAX;		// Largest double
	
	// let it flow
	short_max++;					// add one to short_max
	integer_min *= 2;				// double the negative number to make it smaller
	double_max *= 10;				// make the double later
	
	// print results
	
	printf("The maximum short integer is %d. Overflowed. It looks like %d.\n", SHRT_MAX, short_max);
	printf("The minimum integer is %d. Underflowed, it looks like %d.\n", INT_MIN, integer_min);
	printf("The maximum double is %f. Overflowed, it looks like %f\n", DBL_MAX, double_max);
	
	getchar();
	return(0);	
}
