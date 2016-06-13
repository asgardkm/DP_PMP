// hw_2_3b.c
#include <stdio.h>

int main(void){
	unsigned int start = 1, // 1! (start)
				 stop = 5,  // 5! (end)
				 sum;
				 
	for (sum = 0; start <= stop; stop--){
		sum = sum + stop;		
	}
	
	printf("Sum : %d", sum);
	
	getchar();
	return 0;
	
}
