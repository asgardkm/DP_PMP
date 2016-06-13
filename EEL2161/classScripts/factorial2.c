// factorial2.c
#include <stdio.h>

int main(void){
	unsigned int num = 50;
	unsigned int sum = 1;
	unsigned int multiplier = 1;
	
	while (multiplier <= num) {
			sum = sum * multiplier; // sum *= multiplier
			++multiplier;
			
			if (sum > 50000) {
				printf("Overflow took place. Please do not trust the result!\n");
				break;
			}
	}
	printf("%d! is %d\n", num, sum);
	getchar();
	return(0);	
	
}
