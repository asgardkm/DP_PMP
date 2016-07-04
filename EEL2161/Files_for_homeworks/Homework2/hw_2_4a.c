// hw_2_4a.c
#include <stdio.h>

int main(void){
	int a[] = {1,1},
		b[] = {-4, -4},
		c[] = {3, 4},
		x, i,
		loopmax = 20,
		y[loopmax],
		zeroidx;
		
		// loop for two types of a, b, c

		for (i = 0; i < 2; i++){
			for (x=0; x<loopmax; x++){
			y[x] = a[i]*x*x + b[i]*x + c[i];
			
				if (y[x]==0){// find value which is zero
					zeroidx = x;
				}
			printf("y(%d) = %d*%d^2 + %d*%d + %d = %d\n", x, a[i], x, b[i], x, c[i], y[x]);
				
			}
			
			printf("Value x which makes y = 0 : %d\n\n", zeroidx);	
		
		}
	
	getchar();
	return 0;
}
