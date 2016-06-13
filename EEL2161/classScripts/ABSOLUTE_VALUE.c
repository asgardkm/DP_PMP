// ABSOLUTE_VALUE.C
#include <stdio.h>
#include "./my_abs.h"

int main(){
	float num1, num2;
	
	num2 = 0.9;
	num1 = 6554.1;
	
	printf("The absolute value of of %.1f - %.1f is %.1f.\n", num1, num2, OPE(num1, num2));

	getchar();
	return 0;	
}
