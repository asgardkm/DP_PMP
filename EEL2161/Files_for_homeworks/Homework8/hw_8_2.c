// hw_8_2.c
#include <stdio.h>
// display the dragon ball z power levels w/ pointers

int main(void){
	
	char names[3][30] = {{"Frieza"}, {"Vegeta"}, {"Songoku"}};
	char *name_ptr[3] = {names[0], names[1], names[2]};
	
	int i;
	int power[3] = {530, 20, 8};
	int *power_ptr[3] = {&power[0], &power[1], &power[2]};
	
	// prompt before chaning values
	printf("Before the Nemekian Saga, %s's power level was %dK\n", name_ptr[0], *power_ptr[0]);
	printf("%s's power level was %dK\n", name_ptr[1], *power_ptr[1]);
	printf("and %s's power level was %dK without KaioKen\n\n", name_ptr[2], *power_ptr[2]);
	
	// changing values
	*power_ptr[0] = 30000;
	*power_ptr[1] = 20000;
	*power_ptr[2] = 10000;
	
	for (i = 0; i < 3; i++){
		printf("%s's power level is now %dK\n", name_ptr[i], *power_ptr[i]);
	}
	getchar();
	return 0;
}
