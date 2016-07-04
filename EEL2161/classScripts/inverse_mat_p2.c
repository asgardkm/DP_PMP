// Inverse of 2x2 matrix part 2
#include <stdio.h>

int main(void){
	const int NUM = 2;
	float MATRIX[NUM][NUM], D_MATRIX[NUM][NUM];
	int i, j;
	float DET;
	
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
	DET = MATRIX[0][0] * MATRIX[1][1] - MATRIX[1][0] * MATRIX[0][1];
	printf("The Determinant of this matrix is %0.2f.\n", DET);
	
	D_MATRIX[0][0] = MATRIX[1][1];
	D_MATRIX[1][1] = MATRIX[0][0];
	D_MATRIX[0][1] = -MATRIX[0][1];
	D_MATRIX[1][0] = -MATRIX[1][0];
	
	printf("Your inverse Matrix of [%d] X [%d] Matrix is:\n", NUM, NUM);
	
	for(i = 0; i < NUM; i++){
		printf("|  ");
		for (j = 0; j < NUM; j++){
			printf("%5.2f", D_MATRIX[i][j]/DET);
		}
		printf("  |\n");
	}
	getchar();
	return 0;
	
}
