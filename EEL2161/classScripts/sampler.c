#include <stdio.h>

int main(){
	int i, j, a, n, number[30];
	printf("Enter the value of N \n");
	scanf("%d", &n);
	
	printf("Enter the numbers \n");
	for (i = 0; i < n; i++){
		scanf("%d", &number[i]);
	}
	
	for (i = 0; i < n; i++){
		for (j = i + 1; j < n; j++){
			if(number[i] > number[j]){
				a = number[i];
				//printf("Before, order %d's number is %d\n", i, number[i]);
				number[i] = number[j];
				//printf("Now order %d's number is %d\n", i, number[j]);
				number[j] = a;
				//printf("After, order %d's number is %d\n", j, a);
			}	
		}	
	printf("Now the numbers are %d %d %d %d %d\n", number[0], number[1], number[2], number[3], number[4]);

	}

	printf("The numbers arranged in ascending order are given below \n");
	for (i = 0; i < n; i++){
		printf("%d ", number[i]);	
	}
	
	getchar();
	return 0;
}
