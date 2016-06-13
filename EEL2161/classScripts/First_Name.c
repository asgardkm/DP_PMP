// First_Name.c
#include <stdio.h>

int main(void) {
	char first_name[10];
	
	printf("Enter your first name: ");
	scanf("%9s", first_name);
	printf("Thanks, %s, \n", first_name);
	
	getchar();
	getchar();
	
	return 0;
}
