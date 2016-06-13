// answers.c
#include <stdio.h>

int main(void){
	unsigned int answers[5]; //array to store 5 ans
	
	//assigning values to array
	answers[0] = 1;
	answers[1] = 3;
	answers[2] = 2;
	answers[3] = 3;
	answers[4] = 9;
	
	printf("Hey Student A, what is the answer for questions %d %d and %d\n", 1, 3, 5);
	
	printf("The answers are %d, %d, and %d\n", answers[0], answers[2], answers[4]);
	
	getchar();
	return 0;

}
