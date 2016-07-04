// gender.c
#include <stdio.h>

int main(void){
	char gender = 'A';
	
	switch(gender){
		case 'B':
		case 'b':
			printf("I suggest you to buy new Starwars toys for your boy.\n");
			break;
		case 'G':
			printf("How about new line of Hello Kitty Dolls? \n");
			break;
		default :
		//case 'U':
			printf("Kids love Thomas and Friends train set. A must item for every boy and every girl!\n");
			break;
		}
	getchar();
	return(0);

}
