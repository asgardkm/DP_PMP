// quick test
#include <stdio.h>
float define_mat(int i, int j); 
float getDet(int n, float matrix[][n]);

int main(void){
	
	int n, i, j;						// terminal inputs for length of sq matrix
	char tmp[10];				// where to tmp store row/column inputs w/ fgets
	float determinate;
	
	// step 1 - get dimensions from user (is square)
	// get # of rows in input mat
	printf("Please enter the length of your square matrix : ");
	fgets(tmp, sizeof(tmp) - 1, stdin);
	sscanf(tmp, "%d", &n);
	
	float matrix[n][n];		   
	// define a quick matrix
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			matrix[i][j] = define_mat(i, j);
		}
	}
	printf("Your [%d] X [%d] input square matrix is:\n", n, n);
	for (i = 0; i < n; i++){
		printf("|  ");
		for (j = 0; j < n; j++){
			printf("%5.2f  ", matrix[i][j]);
		}
		printf("  |\n");
	}
	 
	determinate = getDet(n, matrix);
	printf("\n\n=================================================\n");
	printf("Resultant determinate: %5.2f\n", determinate);
	printf("=================================================\n");
	getchar();
	return 0;
}


float getDet(int n, float matrix[][n]){
	float minor_det, mult_cofact, sum_det = 0;					// to store determinant output
	int idx_n[n], idx_row[n], pos_row = 0, pos_col; 	 // counters	
	int new_n, x, i, j;							
	new_n = n - 1;									// defining new mat length
	//float minor; 									// for saving minor calc
	//float small_mat[new_n][new_n];				// defining actual new mat
	//float det, sum_det;							// storing determinant vars
	//int minus_one = -1;
	
	// LOOPING
	 for (x = 0; x < n; x++){ // for looping through each position w/ x
		float small_matrix[new_n][new_n];			// defining actual new mat
		int minus_one = -1;

		pos_col = x;
		// define an array that will be length of n
		// do for both columns and row
		printf("\n=========================\nx = %d\n=========================\n", x);
		printf("----------------BEFORE-----------------------\n");
		for (i = 0; i < n; i++){
		  idx_n[i] = i;
		  idx_row[i] = i;
		}
		for (i = 0; i < n; i++){
			printf("idx_row[%d]: %d\n", i, idx_row[i]);
		}
		for (i = 0; i < n; i++){
			printf("idx_n[%d]: %d\n", i, idx_n[i]);
		}
		
	   
	   printf("\n----------------AFTER-----------------------\n");
		for (i = pos_row; i < new_n; i++){
			idx_row[i] = idx_row[i+1];
		}
		// row position : (removing position 1 w/ rows, defining pos_col to be 1, can change ofc)
		for (i = pos_col; i < new_n; i++){
			idx_n[i] = idx_n[i+1]; // this is what deletes element from array
		}

				
		// print idx_n to terminal
		for (i = 0; i < new_n; i++){
			printf("Row position idx_row[%d]: %d\n", i, idx_row[i]);
		}
		printf("\n");
		for (i = 0; i < new_n; i++){
			printf("Column position idx_n[%d]: %d\n", i, idx_n[i]);
		}
		printf("\n\n");
		
		// try to assign idx_row and idx_n values to a new matrix
		
		for (i = 0; i < new_n; i++){
			for (j = 0; j < new_n; j++){
				small_matrix[i][j] = matrix[idx_row[i]][idx_n[j]];
			}
		}	
		printf("Your new [%d] X [%d] minor matrix from point [%d %d] is:\n", new_n, new_n, pos_row, pos_col);
		for (i = 0; i < new_n; i++){
			printf("|  ");
			for (j = 0; j < new_n; j++){
				printf("%5.2f  ", small_matrix[i][j]);
			}
			printf("  |\n");
		}
		printf("\n");
		
		// check if new_n is 2 - if it is, find minor_det
		if (new_n == 2){
			minor_det = small_matrix[0][0]*small_matrix[1][1] - small_matrix[1][0]*small_matrix[0][1];
			printf("Minor determinant of [%d][%d]: %5.2f\n\n", pos_row, pos_col, minor_det);
		} else {
			minor_det = getDet(new_n, small_matrix); // call function again then if n isn't 2 yet until it is
		}
		
		// find the negative value
		for (i = 1; i <= (pos_row+pos_col+1); i++){
			minus_one = minus_one * -1;
		}
		printf("Sign value for [%d][%d]: %d\n", pos_row, pos_col, minus_one);
		
		// find value of cofactor*matrix element
		mult_cofact = minor_det*minus_one*matrix[pos_row][pos_col];
		printf("Minor determinate(%5.2f) * sign value (%d) * matrix[%d][%d] (%5.2f): %5.2f\n", minor_det, minus_one, pos_row, pos_col, matrix[pos_row][pos_col], mult_cofact);
		
		// add up mult_cofacts over each loop iteration for determinate
		sum_det = sum_det + mult_cofact;
	}
	return(sum_det);
} // end of getDet()

// function for defining matrix based on user terminal input
float define_mat(int i, int j){
	float output;	// define matrix to fill up
	printf("Please type [%d %d] element of your matrix:\n", i, j);
	scanf("%f", &output);
	return output;
} // end of define_mat()
