// hw_5.c
#include <stdio.h>

// define functions
float define_mat(int i, int j, char numbermat); 
//void displaymatrix(); // i tried
//float mult_mat(float mat1, float mat2, int rowmat1, int colmat2, int innerdim); // also tried, to no avail

int main(void){
	int rownum[2], colnum[2], i;		// terminal inputs for row and col lengths of 2 matrices, and loop counter
	char tmp[10];						// where to tmp store row/column inputs w/ fgets
	
	// get dimensions
	for (i = 0; i < 2; i++){
		// get # of rows in input mat
		printf("Please enter the number of rows in your matrix %d : ", i+1);
		fgets(tmp, sizeof(tmp) - 1, stdin);
		sscanf(tmp, "%d", &rownum[i]);
		//getchar();
		
		// get # of cols in input mat
		printf("Please enter the number of columns in your matrix %d : ", i+1);
		fgets(tmp, sizeof(tmp) - 1, stdin);
		sscanf(tmp, "%d", &colnum[i]);
		//getchar();
	}
	
	// decide if two input matrices are compatible for multiplication
	if (rownum[1] != colnum[0]){	// not compatible
		printf("ERROR : number of columns in matrix 1 (%d) does NOT match number of rows in matrix 2 (%d).\n", colnum[0], rownum[1]);	
	} else {						// compatible
		
		// define sizes of matrices A and B
		float mat1[rownum[0]][colnum[0]], mat2[rownum[1]][colnum[1]];		   
		int i, j; 					// counters for filling up matrix
		
		// define first matrix A
		for (i = 0; i < rownum[0]; i++){
			for (j = 0; j <  colnum[0]; j++){   
				mat1[i][j] = define_mat(i, j, '1'); 	
			}
		}
		
		// define second matrix B
		for (i = 0; i < rownum[1]; i++){
			for (j = 0; j <  colnum[1]; j++){   
				mat2[i][j] = define_mat(i, j, '2'); 	
			}
		}
		
		// create output matrix C (C = A*B)
		float outmat[rownum[0]][colnum[1]];	// define output mult matrix
		int innerdim = rownum[1];
		float sum;
		int k, l, p;						// counters for filling up mat3
		for(k = 0; k < rownum[0]; ++k){
			for(l = 0; l < colnum[1]; ++l){
				sum = 0.0;
				for(p = 0; p < innerdim; ++p){
					sum = sum + mat1[k][p] * mat2[p][l];
				}
				outmat[k][l] = sum;
			}
		}
		
		
		// displaymatrices
		for(k = 0; k <= 2; k++){
			if (k != 2){ // for printing input A and B mats
				printf("Your [%d] X [%d] input #%d matrix is:\n", rownum[k], colnum[k], k+1);
				for (i = 0; i < rownum[k]; i++){
					printf("|  ");
					for (j = 0; j < colnum[k]; j++){
						printf("%5.2f  ", (k == 0)? mat1[i][j] : mat2[i][j]);
					}
					printf("  |\n");
				}
			} else	{ // for printing output C mat (C = A*B)
				printf("Your [%d] X [%d] output matrix is:\n", rownum[0], colnum[1]);
				for (i = 0; i < rownum[0]; i++){
					printf("|  ");
					for (j = 0; j < colnum[1]; j++){
						printf(" %5.2f ", outmat[i][j]);
					}
					printf("  |\n");
				}
			} // end of if-else
		} // end of k forloop
	} // end of huge if-else conditional for mat dim matching
	
	getchar();
	return 0;

}

// function for defining matrix based on user terminal input
float define_mat(int i, int j, char numbermat){
	float output;	// define matrix to fill up
	printf("Please type [%d %d] element of the matrix #%c:\n", i+1, j+1, numbermat);
	scanf("%f", &output);
	return output;
}

// function for display matrix to terminal
//void displaymatrix(int rownum, int colnum, char string){
	//int i, j;		// counters
	//printf("Your [%d] X [%d] %s matrix is:\n", rownum, colnum, string);
	//for (i = 0; i < rownum; i++){
	//	printf("|  ");
		//for (j = 0; j < colnum; j++){
	//		printf("%5.2f", MATRIX[i][j]);
	//	}
	//	printf("  |\n");
	//}
//	return void;
//}
