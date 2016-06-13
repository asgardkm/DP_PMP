#include <stdio.h>

int ADDER(int); // function?
int A, i, SUM;

int main(){
	printf("What is your input number that you want to add?\n");
	scanf("%d", &A);
	printf("\n");
	// ADDER(A);
	printf("The result is %d\n", ADDER(A));

	getchar();
	return 0;
}

int ADDER (int x){
	if (x==0){
		printf("x is now %d\n", x);
		return 0;
	} else {
		printf("%d\n", x);
		return ADDER(x-1)+x;	// recursive call to function
	}
}
