// HW 2.2
#include <stdio.h>

int main(void){
	float 	r1 = 10.0, 
			r2 = 20.0,
			r3 = 30.0,
			rt;
	char connect;
	
	
	printf("Select circuit configuration : \n [s]eries, [p]arallel, [c]ombination\n");
	connect = getchar();
	
	switch(connect) {
		case 's': case 'S':  // if series : 
			rt = r1 + r2 + r3;	
			break;
		
		case 'p': case 'P':	 // if parallel :
			rt = 1 / ((1/r1) + (1/r2) + (1/r3));
			break;
		default: 			 // combo (default)
			rt = r1 + (r2*r3) / (r2+r3);
			break;
	}
	
	printf("Circuit orientation selected : %c\n", connect);
	printf("Total resistance : %0.3f ohms\n", rt);
	
	getchar();
	getchar();
	return(0);
}
