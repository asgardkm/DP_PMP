// test_macros.c
#include <stdio.h>			// include directrive
#define MY_NAME "Steve"		// macro directive
// #define MY_NAME "Steve"	// i am not insane yet!

int main(void){
	
	#undef MY_NAME
	char MY_NAME[] = "BRUCE";
	
	// Refer to the defined macro
	printf("Hey %s.", MY_NAME);
	//
	getchar();
	return 0;	
	
}
