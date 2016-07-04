// hw_2_4b.c - QUADRATIC W/ 3 CASES
#include <stdio.h>

int main(void){
	float a[] = {1.0, 1.0, 1.0},
		  b[] = {4.0, 4.0, 4.0},
		  c[] = {3.0, 5.0, 4.0};
	int i;
	float REAL1, IMAG1, IMAG2;
		
		// loop for two types of a, b, c

		for (i = 0; i < 3; i++){
			
			REAL1 = -b[i]/2.0;
			IMAG1 = b[i]*b[i] - 4.0*a[i]*c[i]; 
			IMAG2 = 4.0*a[i]*c[i] - b[i]*b[i];
			
			// no  j when IMAG1 > IMAG2
			// yes j when IMAG1 < IMAG2
			// rep roots when IMAG1 = IMAG2
			if (IMAG1 > IMAG2){
				printf("Roots of %4.2f*x^2 + %4.2f*x + %4.2f : %4.2f (+/-)SQRT(%4.2f)/2\n",
								 a[i], 	b[i],    c[i],REAL1, 		IMAG1);
			} else if (IMAG1 < IMAG2) {
				printf("Roots of %4.2f*x^2 + %4.2f*x + %4.2f : %4.2f (+/-)j SQRT(%4.2f)/2\n",
								 a[i], 	b[i],    c[i],REAL1, 		IMAG2);
			} else {
				printf("Roots of %4.2f*x^2 + %4.2f*x + %4.2f : Repeating %4.2f\n",
								 a[i], 	b[i],    c[i], 			REAL1);
			}
						
		}
				
			
	getchar();
	return 0;
}
