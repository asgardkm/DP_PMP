// hw_7_2.c
#include <stdio.h>

float defineMat(int i, int j); 
void printMat(int rownum, int colnum, float (*input_matrix)[colnum]);
//float rowSum(int rownum, int colnum, float *input_mat[rownum]);
//float colSum(int rownum, int colnum, float input_mat[rownum][colnum]);
//float allSum(int rownum, int colnum, float input_mat[rownum][colnum]);
//float rowSwap(int rownum, int colnum, float input_mat[rownum][colnum]);
//float colSwap(int rownum, int colnum, float input_mat[rownum][colnum]);

//2. Create a script that will calculate the sum of row elements, the 
// sum of column elements, and replace the whole row or column by given 
// row or column vector.

int main(void){
	int rownum, colnum;		// terminal inputs for row and col lengths
	char tmp[10];			// where to tmp store row/column inputs w/ fgets
	float sum_tmp;
////////////////////////////////////////////////////////////////////////
// INPUTS:	
	// get dimensions
	// get # of rows in input mat
	printf("Please enter the number of rows in your matrix: ");
	fgets(tmp, sizeof(tmp) - 1, stdin);
	sscanf(tmp, "%d", &rownum);
	
	// get # of cols in input mat
	printf("Please enter the number of columns in your matrix: ");
	fgets(tmp, sizeof(tmp) - 1, stdin);
	sscanf(tmp, "%d", &colnum);
	
	
	// define sizes of matrices A and B
	float mat[rownum][colnum];			// input matrix variable
	float rowsum_mat[rownum][1];		// row sum matrix
	//float *rowsum_ptr;
	float colsum_mat[colnum][1];		// col sum matrix
	float sum_mat[rownum+1][colnum+1];	// mat w/ rowsum & colsum mats
	float rowswap_mat[rownum][colnum];	// swapping a row in mat
	float rowswap[colnum];				// actual swapped row
	float colswap_mat[rownum][colnum];// swapping a col in mat
	float colswap[rownum];
	int i, j, idx_row, idx_col;		// counters for populating mat
	
	// populate matrix
	for (i = 0; i < rownum; i++){
		for (j = 0; j <  colnum; j++){   
			mat[i][j] = defineMat(i, j); 	
		}
	}
	printf("INPUT MATRIX:\n");
	printMat(rownum, colnum, mat);
	
////////////////////////////////////////////////////////////////////////
// OUTPUTS:
	
	// ROW SUM:
	for (i = 0; i < rownum; i++){
		sum_tmp = 0;
		for (j = 0; j < colnum; j++){
			sum_tmp = mat[i][j] + sum_tmp;
		}
		*rowsum_mat[i] = sum_tmp;
	}
	printf("ROW SUM MATRIX:\n");
	printMat(i, 1, rowsum_mat);		// # of rows in rowsum = 1 (# of loops = # of rows)
	
	// COL SUM:
	for (j = 0; j < colnum; j++){
		sum_tmp = 0;
		for (i = 0; i < rownum; i++){
			sum_tmp = mat[i][j] + sum_tmp;
		}
		*colsum_mat[j] = sum_tmp;
	}
	printf("COL SUM MATRIX:\n");
	printMat(1, j, colsum_mat);		// # of rows in rowsum = 1 (# of loops = # of rows)	
	
	// ROW + COL SUM
	for (i = 0; i < rownum + 1; i++){
		if (i != rownum){
			for (j = 0; j < colnum + 1; j++){
				if (j != colnum){
					sum_mat[i][j] = mat[i][j];
				} else {
					sum_mat[i][colnum] = rowsum_mat[i-1][1];	// why do i need to subtract index by one in order for it to work?
				}
			} 				
	
		} else {
			for (j = 0; j < colnum + 1; j++){
				if (j != colnum){
					sum_mat[rownum][j] = colsum_mat[j-1][1];	// not really quite sure why, but it works
				} else {
					sum_mat[rownum][colnum] = 0;
				}
			}		
		}
	}
	printf("SUM MATRIX:\n");
	printMat(rownum + 1, colnum + 1, sum_mat);		// # of rows in rowsum = 1 (# of loops = # of rows)	
	
	// ROW SWAP
	printf("In order to swap a row in your input matrix, please define a %dx%d vector for replacing first\n", 1, colnum);
	for (j = 0; j < colnum; j++){
			rowswap[j] = defineMat(0, j); 	
	}
	getchar();
	printf("Please select which row to replace values for:\n");
	fgets(tmp, sizeof(tmp) - 1, stdin);
	sscanf(tmp, "%d", &idx_row);
	// replace row vector
	for (i = 0; i < rownum; i++){
		for (j = 0; j < colnum; j++){
			if (i != idx_row-1){
				rowswap_mat[i][j] = mat[i][j];
			} else{
				rowswap_mat[i][j] = rowswap[j]; 
			}
		}
	}
	printf("ROW #%d SWAP MATRIX:\n", idx_row);
	printMat(rownum, colnum, rowswap_mat);		// # of rows in rowsum = 1 (# of loops = # of rows)	
	
	// COL SWAP
	printf("In order to swap a column in your input matrix, please define a %dx%d vector for replacing first\n", rownum, 1);
	for (i = 0; i < rownum; i++){
			colswap[i] = defineMat(i, 0); 	
	}
	getchar();
	printf("Please select which column to replace values for:\n");
	fgets(tmp, sizeof(tmp) - 1, stdin);
	sscanf(tmp, "%d", &idx_col);
	// replace row vector
	for (i = 0; i < rownum; i++){
		for (j = 0; j < colnum; j++){
			if (j != idx_col-1){
				colswap_mat[i][j] = mat[i][j];
			} else{
				colswap_mat[i][j] = colswap[j]; 
			}
		}
	}
	printf("COL #%d SWAP MATRIX:\n", idx_col);
	printMat(rownum, colnum, colswap_mat);		// # of rows in rowsum = 1 (# of loops = # of rows)	
	
	getchar();
	return 0;
} // end of main()

// function for defining matrix based on user terminal input
float defineMat(int i, int j){
	float output;	// define matrix to fill up
	printf("Please type [%d %d] element of your input matrix:\n", i+1, j+1);
	scanf("%f", &output);
	return output;
} // end of defineMat()

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


//float rowSum(int rownum, int colnum, float *input_mat[rownum]){
	//int i;								// counter
	//float rowsum;
	//rowsum = 0;							// (re)set sum var
	//for (i = 0; i < colnum; i++){		// loop through rows
		//rowsum = input_mat[][colnum] + rowsum;
	//}
	//printf("Rowsum\n: %4.2f", rowsum);
	//return rowsum;
//}





	
		
	//// create output matrix C (C = A*B)
	//float outmat[rownum[0]][colnum[1]];	// define output mult matrix
	//int innerdim = rownum[1];
	//float sum;
	//int k, l, p;						// counters for filling up mat3
	//for(k = 0; k < rownum[0]; ++k){
		//for(l = 0; l < colnum[1]; ++l){
			//sum = 0.0;
			//for(p = 0; p < innerdim; ++p){
				//sum = sum + mat1[k][p] * mat2[p][l];
			//}
			//outmat[k][l] = sum;
		//}
	//}
	
	
	//// displaymatrices
	//for(k = 0; k <= 2; k++){
		//if (k != 2){ // for printing input A and B mats
			//printf("Your [%d] X [%d] input #%d matrix is:\n", rownum[k], colnum[k], k+1);
			//for (i = 0; i < rownum[k]; i++){
				//printf("|  ");
				//for (j = 0; j < colnum[k]; j++){
					//printf("%5.2f  ", (k == 0)? mat1[i][j] : mat2[i][j]);
				//}
				//printf("  |\n");
			//}
		//} else	{ // for printing output C mat (C = A*B)
			//printf("Your [%d] X [%d] output matrix is:\n", rownum[0], colnum[1]);
			//for (i = 0; i < rownum[0]; i++){
				//printf("|  ");
				//for (j = 0; j < colnum[1]; j++){
					//printf(" %5.2f ", outmat[i][j]);
				//}
				//printf("  |\n");
			//}
		//} // end of if-else
	//} // end of k forloop
