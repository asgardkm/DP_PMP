//test_script.c
#include <stdio.h>

int main(void){
	float a = 1.00;
	float b = 3.60;
	float c = 2.80;
	
	printf("3*%4.2f - 2*%4.2f + %4.2f:%4.2f\n", a, b, c, 3*a-2*b+c);
	
	getchar();
	return 0;
}
