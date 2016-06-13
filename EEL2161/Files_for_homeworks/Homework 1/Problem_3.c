// HW Problem_3.c
#include <stdio.h>

int main(void){
	
	// current var
	float i_t = 10.0; 	// current out of voltage source
	float i_b;			// current in parallel branch2	
	
	// voltage var
	float v_t;			// voltage source's voltage val
	
	// resistor var
	float r_1 = 15.0;		// resistor1
	float r_2 = 30.0;		// resistor2
	float r_3 = 10.0;		// resistor3
	float r_4 = 70.0;		// resistor4
	float r_5 = 45.0;		// resistor5
	float r_6 = 65.0;		// resistor6
	float r_eq;			// little parallel eq
	float r_a;			// parallel branch 1
	float r_b;			// parallel branch 2
	float r_all;		// single eq resistor
	
	// find r_eq (parallel branch)
	r_eq = (r_1 * r_2) / (r_1 + r_2);
	printf("r_eq : %0.2f\n", r_eq);
	// find r_a (series)
	r_a = r_eq + r_3;
	printf("r_a : %0.2f\n", r_a);
	// find r_b (series)
	r_b = r_4 + r_5 + r_6;
	printf("r_b : %0.2f\n", r_b);
	// find single equivalent resistor (parallel
	r_all = (r_a * r_b) / (r_a + r_b);
	printf("r_all : %0.2f\n", r_all);
	// find voltage across r_all (ohm's law)
	v_t = r_all * i_t;
	printf("v_t : %0.2f\n", v_t);
	// find current in branch 2 (ohm's law)
	i_b = v_t / r_b;
	
	// print to terminal
	printf("Current i2 : %0.2f amps\n", i_b);
	
	// end of script
	getchar();
	return(0);
}
