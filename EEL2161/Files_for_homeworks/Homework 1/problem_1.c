// HW1 problem_1.c
#include <stdio.h>

int main(void){
	
	// define exam_value and avg var
	float exam[2]; 
	float avg;
	
	// assign exam score variables input values
	exam[0] = 75.0;
	exam[1] = 80.0;
	exam[2] = 85.0;
	
	// calculate average
	avg = (exam[0] + exam[1] + exam[2]) / 3;
	
	// print to terminal
	printf("Your average test score is %.2f\n", avg);
	
	// finish script
	getchar();
	return(0);
}
