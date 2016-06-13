// final_2.c
#include <stdio.h>

// cramer-s rule - find determinant w/ user defined function
//test2 question2
#include <stdio.h>
float define_mat(int i, int j); 				// for populating input matrix
float getDet(int n, float matrix[][n]);		// for n > 2 matrices
void printMat(int rownum, int colnum, float (*input_matrix)[colnum]);
//float getsmallDet(int n, float matrix[][n]); // for n==1 or n==2 matrices

int main(void){
	int i, j, idx_col;						// counters
	int a_n = 3;					// defining matrix size (for matrix_A)
	//char tmp[10];					// where to tmp store row/column inputs w/ fgets
	float matrix_A[a_n][a_n], matrix_B[a_n];	//for storing input matrices
	float matrix_tmp[a_n][a_n];	// for tmp matrix storage calculations
	float det_A;					// var for storing output determinate
	float det_num[a_n];			// for storing determinants of numerators in Cramer's 'Rule
	float var_out[a_n];			// for storing variable output values

	//==============POPULATE============================================
	// populate matrix_A
	printf("Please define your %dx%d matrix A:\n", a_n, a_n);
	for (i = 0; i < a_n; i++){
		for (j = 0; j < a_n; j++){
			matrix_A[i][j] = define_mat(i, j);
		}
	}
	printf("Matrix A:\n");
	printMat(a_n, a_n, matrix_A);
	
	printf("Please define your %dx%d matrix B:\n", a_n, 1);
	for (i = 0; i < a_n; i++){
			matrix_B[i] = define_mat(i, 0); 	
	}
	printf("Matrix B:\n");
	for (i = 0; i < a_n; i++){
		printf("%4.2f\n", matrix_B[i]);
	}
	//==================================================================

	//DETERMINANT OF A==================================================
	// determinant of matrix_A
	det_A = getDet(a_n, matrix_A);
	//==================================================================

	// COL SWAP=========================================================
	for (idx_col = 0; idx_col < a_n; idx_col++){
		// replace row vector
		for (i = 0; i < a_n; i++){
			for (j = 0; j < a_n; j++){
				if (j != idx_col){
					matrix_tmp[i][j] = matrix_A[i][j];
				} else{
					matrix_tmp[i][j] = matrix_B[i]; 
				}
			}
		}
		printf("COL #%d SWAP MATRIX:\n", idx_col+1);
		printMat(a_n, a_n, matrix_tmp);		// # of rows in rowsum = 1 (# of loops = # of rows)	
		
		//DETERMINANT OF NUMERATOR======================================
		det_num[idx_col] = getDet(a_n, matrix_tmp);
		//==============================================================
	}
	//==================================================================
	
	// CALCULATE VARIABLE ==============================================
	// calculating variable output
	for (i = 0; i < a_n; i++){
		var_out[i] = det_num[i] / det_A;
		printf("Variable #%d: %4.2f\n", i+1, var_out[i]);
	}
	//printf("COL #%d SWAP MATRIX:\n", idx_col);
	//printMat(rownum, colnum, colswap_mat);		// # of rows in rowsum = 1 (# of loops = # of rows)	
	 //=================================================================
	getchar();
	return 0;
}


// function for calculating determinate of an input matrix-is recursive
float getDet(int n, float matrix[][n]){
	// UPDATE: need to add situations if n = 2 and/or n=1!
	float minor_det, mult_cofact, sum_det = 0;			// output vars
	int idx_n[n], idx_row[n], pos_row = 0, pos_col; 	// counters	(defining pos_row to be first row always-can change if you like)
	int new_n, x, i, j;								// counters
	new_n = n - 1;										// defining new mat length
	
	// LOOPING - through each 
	 for (x = 0; x < n; x++){ 							// for looping through each position w/ x
		float small_matrix[new_n][new_n];				// defining actual new mat
		int minus_one = -1;							// define sign var
		pos_col = x;									// send loop var to column position index
		
		// define an array that will be length of n w/ input [1:n]
		// do for both columns and row
		//printf("\n=========================\nx = %d\n=========================\n", x);
		//printf("----------------BEFORE-----------------------\n");
		for (i = 0; i < n; i++){
		  idx_n[i] = i;
		  idx_row[i] = i;
		}
		for (i = 0; i < n; i++){
			//printf("idx_row[%d]: %d\n", i, idx_row[i]);
		}
		for (i = 0; i < n; i++){
			//printf("idx_n[%d]: %d\n", i, idx_n[i]);
		}
		
	   
	   //printf("\n----------------AFTER-----------------------\n");
		// row position : defining pos_row to be 0, so that idx_row is always [1:n]
		for (i = pos_row; i < new_n; i++){
			idx_row[i] = idx_row[i+1];
		}
		// col position : removing index pos_col (loop var) from array idx_n 
		for (i = pos_col; i < new_n; i++){
			idx_n[i] = idx_n[i+1]; // this is what deletes element from array
		}
			
		// print idx_col and idx_n to terminal
		for (i = 0; i < new_n; i++){
			//printf("Row position idx_row[%d]: %d\n", i, idx_row[i]);
		}
		printf("\n");
		for (i = 0; i < new_n; i++){
			//printf("Column position idx_n[%d]: %d\n", i, idx_n[i]);
		}
		//printf("\n\n");
		
		// assign idx_row and idx_n indexes from input matrix to submatrix
		for (i = 0; i < new_n; i++){
			for (j = 0; j < new_n; j++){
				small_matrix[i][j] = matrix[idx_row[i]][idx_n[j]];
			}
		}	
		
		// print new submatrix
		//printf("Your new [%d] X [%d] minor matrix from point [%d %d] is:\n", new_n, new_n, pos_row, pos_col);
		//for (i = 0; i < new_n; i++){
			//printf("|  ");
			//for (j = 0; j < new_n; j++){
				//printf("%5.2f  ", small_matrix[i][j]);
			//}
			//printf("  |\n");
		//}
		//printf("\n");
		
		// check if new_n (size of submatrix)==2 - if it is, find minor_det
		if (new_n == 2){
			minor_det = small_matrix[0][0]*small_matrix[1][1] - small_matrix[1][0]*small_matrix[0][1];
			//printf("Minor determinant of [%d][%d]: %5.2f\n\n", pos_row, pos_col, minor_det);
		} else {
			minor_det = getDet(new_n, small_matrix); // call function again then if n isn't 2 yet until it is
		}
		
		// find sign of current loop matrix address
		for (i = 1; i <= (pos_row+pos_col+1); i++){
			minus_one = minus_one * -1;
		}
		// print sign 
		//printf("Sign value for [%d][%d]: %d\n", pos_row, pos_col, minus_one);
		
		// find value of cofactor*matrix element
		mult_cofact = minor_det*minus_one*matrix[pos_row][pos_col];
		//printf("Minor determinate(%5.2f) * sign value (%d) * matrix[%d][%d] (%5.2f): %5.2f\n", minor_det, minus_one, pos_row, pos_col, matrix[pos_row][pos_col], mult_cofact);
		
		// add up mult_cofacts over each loop iteration for determinate
		sum_det = sum_det + mult_cofact;
	}
	return(sum_det);
} // end of getDet()

// function for defining matrix based on user terminal input
float define_mat(int i, int j){
	float output;	// define matrix to fill up
	printf("Please type [%d %d] element of your matrix:\n", i+1, j+1);
	scanf("%f", &output);
	return output;
} // end of define_mat()

//// for finding determinants of 2x2 or 1x1 matrices
//float getsmallDet(int n, float matrix[][n]){
	//float sum_det;			// output vars
	//// if input matrix size is n = 2
	//if (n == 2){
		//sum_det = matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1];
		//printf("Determinant: %5.2f\n\n", sum_det);
	//} else if (n == 1){
		//sum_det = matrix[0][0];
		//printf("Determinant: %5.2f\n\n", sum_det);
	//} else { // if n is zero or negative
		//sum_det = -1.0;
		//printf("Why is the length of your square matrix not a nonzero positive integer???\n");
	//}
	//return sum_det;
//} // end of getsmallDet()

void printMat(int rownum, int colnum, float (*input_matrix)[colnum]){
	int i, j;			// counters
	// print new submatrix
	//printf("Your resultant [%d] X [%d] matrix is:\n", rownum, colnum);
	for (i = 0; i < rownum; i++){
		printf("|  ");
		for (j = 0; j < colnum; j++){
			printf("%5.2f  ", *(input_matrix[i] + j));	//MHUAHAHAHAHHA FIGURED OUT POINTER ALGEBRA!!! >:D
		}
		printf("  |\n");
	}
	printf("\n");
} // end of printMat()

