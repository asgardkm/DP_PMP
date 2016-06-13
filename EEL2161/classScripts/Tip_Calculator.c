// Tip_Calculator.c
#include <stdio.h>

int main(void){
	float i; //var for loop
	
	//print header
	printf("Tip calculator for various amount:\n\n");
	printf("%10s %9d%% %9d%%\n", "Bill", 15, 20);
	
	// Look for tip calculation
	
	for (i=10.00; i <=100.00; i+=5){
			//print original amt, the 15% tip, and the 20% tip
			printf("%10.2f %10.2f %10.2f\n", i, (i*0.15), (i*0.20));
	}
	getchar();
	return 0;

}
