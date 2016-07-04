// swap_better.c
#include <stdio.h>

void swap(int *first, int *second);

int main(void){
	int a = 5;
	int b = 10;
	
	printf("At first, a = %d and b = %d\n", a, b);
	swap(&a,&b);
	printf("After swapping, a = %d and b = %d\n", a, b);
	
	getchar();
	return 0;	
}

void swap(int *first, int *second){
	int temp = *first;
	*first = *second;
	*second = temp;
}
