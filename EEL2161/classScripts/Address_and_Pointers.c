// Address_and_Pointers.c
#include <stdio.h>

int main(void){
	int  a = 456;
	char b = 'j';
	
	// create two pointers, properly typed, and 
	//store the addresses of the pointers
	int  *x = &a;
	char *y = &b;
	
	printf("Address of a: %p\n", &a);
	printf("Address of a: %p\n", x);
	printf("Address of b: %p\n", &b);
	printf("Address of b: %p\n", y);
	
	//check size
	// NOTE: sizeof(x) is the size of the pointer (8bits)
	// and sizeof(*x) is size of what it's pointing to (4bits, or sizeof(a))
	printf("Size of a:%d\n", sizeof(a));
	printf("Size of b:%d\n", sizeof(b));
	printf("Size of x:%d\n", sizeof(x));	
	printf("Size of y:%d\n", sizeof(y));


	getchar();
	return 0;
}
