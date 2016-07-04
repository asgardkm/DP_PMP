// HW1 Problem_2.c
#include <stdio.h>

// find power dissipated by resistor 3

int main(void){
	
	// define current variables
	float i_t = 12.0; 	// total current
	float i_1;      	// current 1 (unknown)
	float i_2 = 3.0;	// current 2
	float i_3;			// current 3 (unknown)
	
	// define voltage var
	// 		all elements are in parallel, so there is 
	// 		only one voltage value for each element
	float v;			// voltage drop across each element (unknown)
	
	// define resistance variables
	float r1 = 3.0; 	// resistor1 = 3 ohms
	float r2 = 8.0;	// resistor2 = 8 ohms
	float r3;			// resistor3 = ?
	
	
	// define power_3 variable
	float P3;			// power dissipated in resistor3
	
	// find voltage in branch2 (and for all elements) w/ ohm's law
	v = i_2 * r2;
	
	// find i_1 (ohm's law)
	i_1 = v / r1;
	
	// find i_3 (KCL)
	i_3 = i_t - i_1 - i_2;
	
	// find r3 (ohm's law)
	r3 = v / i_3;
	
	// find power dissipated in r3 (p=i*v)
	P3 = i_3 * v;
	
	
	// print out P3 to terminal
	printf("i_1 : %.2f\n", i_1);
	printf("i_3 : %.2f\n", i_3);
	printf("r3 : %.2f\n", r3);
	printf("v : %.2f\n", v);
	printf("Power dissipated in resistor 3 : %.2f watts\n", P3);
	
	// finish script
	getchar();
	return(0);
}
