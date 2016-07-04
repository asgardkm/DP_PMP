// even or odd?
#include <stdio.h>

int main(void){
	int Testnumber = 21;
	printf("The number %d is odd or not? The answer will be O for an odd number or E for an even number. \n", Testnumber);
	char even_odd;
	even_odd = ((Testnumber % 2) == 0)? 'E' : 'O';
	printf("It is %c.\n", even_odd);
	getchar();
	return(0);
	}
