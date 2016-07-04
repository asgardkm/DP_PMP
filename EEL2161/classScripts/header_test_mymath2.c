#include <stdio.h>
#include "./my_math2.h"

int main(){
	float num1, num2;
	
	num1 = 0.9;
	num2 = 6554.1;
	
	printf("The smaller of %.1f and %.1f is %.1f.\n", num1, num2, MIN(num1, num2));
	printf("The larger of %.1f and %.1f is %.1f.\n", num1, num2, MAX(num1, num2));
	printf("The average of %.1f and %.1f is %.1f.\n", num1, num2, AVG(num1, num2));
	printf("The average of %.1f and %.1f is %.1f.\n", num1, num2, PRODUCT(num1, num2));


	getchar();
	return 0;	
}
