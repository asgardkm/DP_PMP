// Inverse of 2x2 matrix
#include <stdio.h>

int main(void){
	const int NUM = 2;
	float MATRIX[NUM][NUM];
	int i, j;
	
	for (i = 0; i < NUM; i++){
		for (j = 0; j <  NUM; j++){
			printf("Please type [%d %d] element of the matrix:\n", i, j);
			scanf("%f", &MATRIX[i][j]);
		}		
	}
	
	printf("Your [%d] X [%d] matrix is:\n", NUM, NUM);
	for (i = 0; i < NUM; i++){
		printf("|  ");
		for (j = 0; j < NUM; j++){
			printf("%5.2f", MATRIX[i][j]);
		}
		printf("  |\n");
	}
	
	getchar();
	return 0;
	
}
