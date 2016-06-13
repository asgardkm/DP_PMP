// GPA2.c
#include <stdio.h>

int main(void){
	float gpa = 3.2;
	
	if (gpa >= 3.9){
		printf("You are graduating summa cum laude with a %0.2f GPA!\n", gpa);
		}
	if (gpa >= 3.75){
		printf("You are graduating magna cum laude with a %0.2f GPA!\n", gpa);
	}
	if (gpa >= 3.5){
		printf("You are graduating cum laude with a %0.2f GPA!\n", gpa);
	}
	else{
		printf("There is more to life than grades\n");
	}
	getchar();
	return(0);
	
	
	}
