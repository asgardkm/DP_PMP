// Exchange Converter
#include <stdio.h>

int main(void){
	const int NUM = 10;
	float amounts[NUM];
	unsigned int i;
	
	printf("US Dollar to Japanese Yen Converter:\n\n");
	printf("%10s %10s\n", "Dollars", "Yen");
	
	// loop through array
	for(i = 0; i < 	NUM; i++){
		// assigning dollar amount to array
		amounts[i] = (i+1)*500;
		// converting indivudal dollar to Yen and display
		printf("%10.2f %10.2f\n", amounts[i], (amounts[i]*120.467));
	} // end of loop
	
	getchar();
	return 0;	
}
