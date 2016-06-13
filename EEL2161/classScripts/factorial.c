// factorial.c
#include <stdio.h>

int main(void){
	unsigned int num = 5;
	unsigned int sum = 1;
	unsigned int multiplier = 1;
	
	while (multiplier <= num) {
			sum = sum * multiplier; // sum *= multiplier
			++multiplier;
	}
	printf("%d! is %d\n", num, sum);
	getchar();
	return(0);	
	
}
