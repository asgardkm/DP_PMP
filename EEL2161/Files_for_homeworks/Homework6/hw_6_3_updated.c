// hw_6_3.c
#include <stdio.h>
float define_mat(int i, int j); 				// for populating input matrix
float getDet(int n, float matrix[][n]);		// for n > 2 matrices
float getsmallDet(int n, float matrix[][n]); // for n==1 or n==2 matrices
void printMat(int rownum, int colnum, float (*input_matrix)[colnum]);

// find determinant of square matrix
// calculation of determinant should be in user-defined function
// cofactor expansion
int main(void){
	
	int n, i, j;			// terminal inputs for length of sq matrix
	char tmp[10];			// where to tmp store row/column inputs w/ fgets
	float determinate;		// var for storing output determinate
	
	// step 1 - get dimensions from user (is square)
	// get # of rows in input mat
	printf("Please enter the length of your square matrix : ");
	fgets(tmp, sizeof(tmp) - 1, stdin);
	sscanf(tmp, "%d", &n);
	
	float matrix[n][n];		   
	// populate your matrix
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			matrix[i][j] = define_mat(i, j);
		}
	}
	// print out your populated matrix
	printf("Your [%d] X [%d] input square matrix is:\n", n, n);
	for (i = 0; i < n; i++){
		printf("|  ");
		for (j = 0; j < n; j++){
			printf("%5.2f  ", matrix[i][j]);
		}
		printf("  |\n");
	}
	 // call function to get determinate of your input matrix
	if ( n > 2){ // if n is > 2
	determinate = getDet(n, matrix);
	} else { // if n == 1 or n == 2 - call a different function
	determinate = getsmallDet(n, matrix);
	}
	// output your determinate value to terminal
	printf("\n\n=================================================\n");
	printf("Resultant determinate: %5.2f\n", determinate);
	printf("=================================================\n");
	
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
			printf("Row position idx_row[%d]: %d\n", i, idx_row[i]);
		}
		printf("\n");
		for (i = 0; i < new_n; i++){
			printf("Column position idx_n[%d]: %d\n", i, idx_n[i]);
		}
		printf("\n\n");
		
		// assign idx_row and idx_n indexes from input matrix to submatrix
		for (i = 0; i < new_n; i++){
			for (j = 0; j < new_n; j++){
				small_matrix[i][j] = matrix[idx_row[i]][idx_n[j]];
			}
		}	
		
		// print new submatrix
		printf("Your new [%d] X [%d] minor matrix from point [%d %d] is:\n", new_n, new_n, pos_row, pos_col);
		for (i = 0; i < new_n; i++){
			printf("|  ");
			for (j = 0; j < new_n; j++){
				printf("%5.2f  ", small_matrix[i][j]);
			}
			printf("  |\n");
		}
		printf("\n");
		
		// check if new_n (size of submatrix)==2 - if it is, find minor_det
		if (new_n == 2){
			minor_det = small_matrix[0][0]*small_matrix[1][1] - small_matrix[1][0]*small_matrix[0][1];
			printf("Minor determinant of [%d][%d]: %5.2f\n\n", pos_row, pos_col, minor_det);
		} else {
			minor_det = getDet(new_n, small_matrix); // call function again then if n isn't 2 yet until it is
		}
		
		// find sign of current loop matrix address
		for (i = 1; i <= (pos_row+pos_col+1); i++){
			minus_one = minus_one * -1;
		}
		// print sign 
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

// for finding determinants of 2x2 or 1x1 matrices
float getsmallDet(int n, float matrix[][n]){
	float sum_det;			// output vars
	// if input matrix size is n = 2
	if (n == 2){
		sum_det = matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1];
		printf("Determinant: %5.2f\n\n", sum_det);
	} else if (n == 1){
		sum_det = matrix[0][0];
		printf("Determinant: %5.2f\n\n", sum_det);
	} else { // if n is zero or negative
		sum_det = -1.0;
		printf("Why is the length of your square matrix not a nonzero positive integer???\n");
	}
	return sum_det;
}

// NOTES (general ideas while brainstorming script)
	// ex, say we want to do minor of [1,1] and n=3 - have to send the elements
	// [2,2], [2,3], [3,2], and [3,3] to a new array.
	// once you have a 2x2 mat, then can find determinant w/ [1,1]*[2,2] - [2,1]*[1,2]
	
	// need to go through each column number
	// assuming that will be doing cofactor along the first row, that way, there's less 
	// code to write by assuming minor calculations for [:,1] elements
 
	// determinant equation : 
	// det(A) = a[i,1]*A[i,1] + a[i,2]*A[i,2] + ... + a[i,n]*A[i,n]
	// where A[i,n] is matrix element, and
	// a[i,n] is determinant of the minor A[i,n]
	// in this case, will always be assuming that i = 1 of input matrix;

	// NEED TO DEFINE POSITION - have it loop through! -how?
	// can do as function? - call it in a loop and find determinant of minor
	// when it runs through the loop?
	// but if called recusively, how to access those recursive minors?
