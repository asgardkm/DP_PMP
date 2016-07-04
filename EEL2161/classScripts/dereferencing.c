// dereferencing.c
#include <stdio.h>

int main(void){
	int  a = 456;
	int  *x;
	x = &a;
	
	printf("Address of a: %p\n\n", x);
	
	printf("a at start:%d\n", a);
	printf("*x at start: %d\n\n", *x);

	// value changing
	*x = 123;		// we are not changing a directly!
	
	printf("a at start:%d\n", a);
	printf("*x at start: %d\n", *x);

	getchar();
	return 0;
}
