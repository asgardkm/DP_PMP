//final_3.c
#include <stdio.h>
#define INPUTFILE "Sensor_Record.txt"
#define OUTPUTFILE "Sensor_Record_Modified.txt"
void printMat(int rownum, int colnum, float (*input_matrix)[colnum]);

int main(void){	
	/* Need a pointer of type FILE. */
    FILE  *fp_in;
    FILE *fp_out;
	int j, i = 0;
	int neg_counter = 0; // for counting number of negatives in file
	//int k = 0, row = 0, col = 0, nxt_row, nxt_col;
	//float FL = 0;
	//float TH = 0.00001;
	//float input_area; 		// for storing user input for table
	//float z_row, z_col, z_nrow, z_ncol, z_total, z_ntotal;
	//int neg_check = 1, toggle_row = 0, exact_match = 0;		// in case input above is <0.5, and for moving to next row
	/* Chaacter array for reading the file. */
	char line[500];
	float r[10][10], rr[10][10];
	//char date[11]; /* In the form of YYYY-MM-DD, plus \0 character. */

	/* Attempt to open the file for reading. */
	fp_in = fopen(INPUTFILE, "r");
	
	if (fp_in != NULL) { /* The file is open. */
		
		//printf("%7s %7s %7s %7s %7s %7s %7s %7s %7s %7s\n", "0", "0.1", "0.2", "0.3", "0.4", "0.5", "0.6", "0.7", "0.8", "0.9");
		
		while (fgets(line, sizeof(line), fp_in)) {			
			sscanf (line, "%f %f %f %f %f %f %f %f %f %f", &r[i][0], &r[i][1], &r[i][2], &r[i][3], &r[i][4], &r[i][5], &r[i][6], &r[i][7], &r[i][8], &r[i][9]);
			for (j = 0; j <= 9; j++){
				// adding 0.5 to all values to create proper z table
				
				// how many entries satisfy condition?
				if (r[i][j] < 0){
					rr[i][j] = r[i][j] * -1;
					neg_counter = neg_counter + 1;
				} else {
					rr[i][j] = r[i][j];
					}		
						
				}
			
			//printf("%0.5f %0.5f %0.5f %0.5f %0.5f %0.5f %0.5f %0.5f %0.5f %0.5f\n", rr[i][0], rr[i][1], rr[i][2], rr[i][3], rr[i][4], rr[i][5], rr[i][6], rr[i][7], rr[i][8], rr[i][9]);
			//FL = FL+0.1;
			++i;
			//printf("%10s %5d %5d\n", date, high, low);
		}
		fclose(fp_in);
		// write new data
		fp_out = fopen(OUTPUTFILE, "w");
		for (i = 0; i < 9; i++){
			fprintf(fp_out, "%4.2f %4.2f %4.2f %4.2f %4.2f %4.2f %4.2f %4.2f %4.2f %4.2f\n", rr[i][0], rr[i][1], rr[i][2], rr[i][3], rr[i][4], rr[i][5], rr[i][6], rr[i][7], rr[i][8], rr[i][9]);
		}
		
		// print old and new data
		printf("This is the original Sensor Record with Glitches\n");
		printMat(10, 10, r);
		printf("After running the script\n");
		printMat(10, 10, rr);
		printf("There were %d negative values but replaced to positive values\n", neg_counter);
		printf("The result is saved in %s\n", OUTPUTFILE);
		
	} else { /* File could not be opened. */
		printf ("The file could not be opened.\n");
		return 1; /* Exit the function/application. */
	}

	/* Close the file. */
	if (fclose(fp_in) != 0) {
		printf ("The file could not be closed.\n");
	}

	getchar(); /* Pause. */
	return 0;
}

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
