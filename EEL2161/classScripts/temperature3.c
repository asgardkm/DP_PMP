// temperature3.c
#include <stdio.h>

int main(void){
	float temp_c1, temp_c2, temp_f; // F-Fahrenheit, C-Celsius
	
	// Make Conversion
	temp_f = 451.0;
	temp_c1 = (temp_f-32) * 5.0/9.0;
	temp_c2 = (temp_f-32) * (5.0/9.0);
	// print results
	printf("%d degrees fahrenheit is %d degrees Celsius\n", (int) temp_f, (int) temp_c1);
	printf("When I put Parethsis over 5.0/9.0 I got this result : %0.1f\n which is equivalent to the previous results\n", temp_c2);
	printf("Does the number 451 ring a bell?");
	
	getchar();
	return(0);
	
	
	
	}
