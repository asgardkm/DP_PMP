#include <stdio.h>

int main(void){
	int age;
	printf("Enter your age:");
	scanf("%d", &age);
	printf("Your %d years is equivalent to %d years of days\n", age, age*365);
	
	getchar();
	return(0);

}
