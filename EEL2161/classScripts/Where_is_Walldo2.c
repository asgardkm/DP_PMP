// Where_is_Walldo2.c
#include <stdio.h>

int main(void){
	
	int a[5] = {-40, 7853, 74, 19, 449378}, i;
	for(i = 0; i <= 4; i++){
		printf("Address of a[%d]: %p\n", i, &a[i]);	
	}
	printf("\n");
	for(i = 0; i <= 4; i++){
		printf("Address of a[%d]: %p\n", i, &a[i]);	
	}
	//int 	a = -40, 
			//b = 7853;
	//char 	c = 74,
			//d = 19;
	//int	 	e = 449378;
	//// character's numerical value
	
	// print out the address of all variables
	//printf("\nAddress of a: %p\n", &a);	
	//printf("Address of b: %p\n", &b);
	//printf("Address of c: %p\n", &c);
	//printf("Address of d: %p\n", &d);
	//printf("Address of e: %p\n", &e);

	getchar();
	return 0;	
}
