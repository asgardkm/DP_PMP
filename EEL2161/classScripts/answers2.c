// answers2.c
#include <stdio.h>

int main(void){
	unsigned int answers[] = {1, 3, 2, 3, 9}; //array to store 5 ans
	
	//assigning values to array
	printf("Hey Student A, what is the answer for questions %d %d and %d\n", 1, 3, 5);
	
	printf("The answers are %d, %d, and %d\n", answers[0], answers[2], answers[4]);
	
	getchar();
	return 0;

}
