// Celsius to Fahrenheit CTOF.c
// F = (9/5)C + 32
#include <stdio.h>

int main(void){
	int Celsius = 100;
	
	// Creating two constant valued variables
	const float RATIO = 9.0/5.0;
	const int   ADDER = 32;
	
	printf("The temperature %d in Celsius is %0.2f in Fahrenheit.\n",
			Celsius, RATIO*Celsius + ADDER);	
			
	getchar();
	return(0);		
}
			
			
