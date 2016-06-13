// hw_2_3a.c
#include <stdio.h>

int main(void){
	unsigned int start = 1, 
				 stop = 100, 
				 sum;
				 
	for (sum = 0; start <= stop; start++){
		sum = sum + start;		
	}
	
	printf("Sum : %d", sum);
	
	getchar();
	return 0;
	
}
