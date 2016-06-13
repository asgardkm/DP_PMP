// smaller.c
#include <stdio.h>
#define MIN(X,Y) ((X<Y)? X:Y)	// trinary returning the smaller num

int main(void){
	float num1, num2;
	
	num1 = 20.0;
	num2 = 103.9;
	
	printf("The smaller of %.1f and %.1f is %.1f.\n", num1, num2, MIN(num1, num2));
	
	getchar();
	return 0;	
}
