// Where_is_Walldo.c
#include <stdio.h>

int main(void){
	int 	a = -40, 
			b = 7853;
	char 	c = 74,
			d = 19;
	int	 	e = 449378;
		// character's numerical value
		
	// print out the address of all variables
	printf("Address of a: %p\n", &a);	
	printf("Address of b: %p\n", &b);
	printf("Address of c: %p\n", &c);
	printf("Address of d: %p\n", &d);
	printf("Address of e: %p\n", &e);

	getchar();
	return 0;	
}
