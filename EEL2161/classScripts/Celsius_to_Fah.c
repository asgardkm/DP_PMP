//Celsius_to_Fah.c
#include <stdio.h>

int main(void){
	//float temp_f, temp_c;
	float temp_i, temp_o;
	char which_i, which_o;
	//char input[10];
	
	printf("Enter a temperature and indicate whether if it's Fahrenheit or Celsius [C/F] :");
	scanf("%f %c", &temp_i, &which_i);
	
	switch(which_i){
			case 'C': case 'c':
				temp_o = temp_i*(9.0/5.0) + 32;
				which_o = 'F';
				break;
			case 'F': case 'f':
				temp_o = (temp_i-32)*(5.0/9.0);
				which_o = 'C';
				break;
			default:	
				which_o = 0;
				break;
			}
	
	//fgets(input, sizeof(input)-1, stdin);
	//sscanf(input, "%f", &temp_c);
	
	//temp_f = temp_c * 9.0/5.0 + 32;
	printf ("Output : %0.2f %c", temp_o, which_o);
	//printf("%0.1f degrees Celsius is %0.1f Fahrenheit. \n", temp_c, temp_f);
	
	getchar();
	
	return 0;

}
