// Pulling_Hair.c
#include <stdio.h>

int main(void){
	int n1, n2;
	
	// Postfix arithmetic
	n1 = 1;
	n2 = 1;
	printf("At first, n1 is %d and n2 is %d\n", n1, n2);
	n2 = n1++;
	printf("After n2 = n1++, n1 is %d and n2 is %d\n", n1, n2);
	n2 = n1--;
	printf("After n2 = n1--, n1 is %d and n2 is %d\n", n1, n2);
	
	// Reset
	n1 = 1;
	n2 = 1;
	
	printf("After resetting, n1 is %d and n2 is %d\n", n1, n2);
	
	// Prefix arithmetic
	n2 = ++n1;
	printf("After n2 = ++n1, n1 is %d and n2 is %d\n", n1, n2);
	n2 = --n1;
	printf("After n2 = --n1, n1 is %d and n2 is %d\n", n1, n2);

	
	
	getchar();
	return(0);
}
