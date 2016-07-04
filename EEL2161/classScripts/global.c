// global.c
#include <stdio.h>

int g_num = 100;			// global variable
void other_function(void);	// prototype of function

int main (void){
	int num = 20;			// local variable
	printf("Inside the main function, the global g_num is %d. The local num is %d.\n", g_num, num);
	other_function();
	
	printf("After calling the other_function, the global g_num is %d. The local num is %d.\n", g_num, num);
	
	getchar();
	return 0;
}

void other_function(void){
	int num = 600;
	g_num   = 0;
	return;	// since this function returns no value - return nothing
}
