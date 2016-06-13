// hw_9_2.c
#include <stdio.h>
/* Set the file path and name. */
#define THEFILE "Distribution.txt"

int main (void) {
	
	/* Need a pointer of type FILE. */
    FILE *fp;
	int j, i = 0, k = 0, row = 0, col = 0, nxt_row, nxt_col;
	float FL = 0.0, TH = 0.00001;
	float input_area; 		// for storing user input for table
	float z_row, z_col, z_nrow, z_ncol, z_total, z_ntotal;
	int neg_check = 1, toggle_row = 0, exact_match = 0;		// in case input above is <0.5, and for moving to next row
	/* Chaacter array for reading the file. */
	char line[500];
	float r[10], rr[30][10];
	//char date[11]; /* In the form of YYYY-MM-DD, plus \0 character. */

	/* Attempt to open the file for reading. */
	fp = fopen(THEFILE, "r");
	
	if (fp != NULL) { /* The file is open. */
		
		printf("%7s %7s %7s %7s %7s %7s %7s %7s %7s %7s\n", "0", "0.1", "0.2", "0.3", "0.4", "0.5", "0.6", "0.7", "0.8", "0.9");
		
		while (fgets(line, sizeof(line), fp)) {			
			sscanf (line, "%f %f %f %f %f %f %f %f %f %f", &r[0], &r[1], &r[2], &r[3], &r[4], &r[5], &r[6], &r[7], &r[8], &r[9]);
			for (j = 0; j <= 9; j++){
				// adding 0.5 to all values to create proper z table
				rr[i][j] = r[j] + 0.5;
				
				// how many entries satisfy condition?
				if (r[j] < TH){k = k + 1;}			
				}
			
			printf("%0.5f %0.5f %0.5f %0.5f %0.5f %0.5f %0.5f %0.5f %0.5f %0.5f\n", rr[i][0], rr[i][1], rr[i][2], rr[i][3], rr[i][4], rr[i][5], rr[i][6], rr[i][7], rr[i][8], rr[i][9]);
			FL = FL+0.1;
			++i;
			//printf("%10s %5d %5d\n", date, high, low);
		}
		
		// have user input selected % of area selected under normal curve
		printf("Please input the percentage of area you wish to select from underneath the Gaussian normal curve (from 0.0000 to 1.0000):\n");
		scanf("%f", &input_area);
		
		// check if input is below 0.5. if so, subtract it from 1 and toggle neg_check
		if (input_area < 0.5000){
			input_area = 1 - input_area;
			neg_check = -1;
		}
		
		// now search for input_area by looping through table
		// first through rows - the "MSB" portion of the zvalue
		while(input_area > rr[row][0])
			row = row + 1;
		
		// then through columns
		while(input_area > rr[row-1][col])
			col = col + 1;
		
		row = row - 1;
		col = col - 1;
		
		// check if input is exact match to a value in table
		exact_match = (input_area - rr[row][col] < 0.001)? 1 : 0;
		printf("\n=====================================================\n");
		printf("Exact match: %d\n", exact_match);
		printf("Row value: %d\n", row);
		printf("Col value: %d\n", col);
		if (exact_match == 0){
			//define a target for lying in between current row/col and next (continuous vs discreet)
			if (col >= 9){
				nxt_col = 0;
				toggle_row = 1;
			} else {
				nxt_col = col+1;
			}
			nxt_row = (toggle_row == 1)? row+1 : row;
			printf("Nxt_Row value: %d\n", nxt_row);
			printf("Nxt_Col value: %d\n", nxt_col);
			//convert to z values
			z_row  = row * 0.1f;
			z_nrow = nxt_row * 0.1f; 
			printf("Z Row value: %4.4f\n", z_row);
			printf("Z Next-Row value: %4.4f\n", z_nrow);

			z_col  = col * 0.01f;
			z_ncol = nxt_col * 0.01f;
			printf("Z Col value: %4.4f\n", z_col);
			printf("Z Next-Col value: %4.4f\n", z_ncol);

			
			z_total  = (z_row + z_col) * neg_check;
			z_ntotal = (z_nrow + z_ncol) * neg_check; 
			printf("\nZ total value: %4.4f\n", z_total);
			printf("Z Next-total value: %4.4f\n", z_ntotal);
			printf("\n=====================================================\n");
			printf("Your input %4.4f area percentage value has a z-value\nbetween %4.4f and %4.4f\n", input_area, z_total, z_ntotal);
			printf("\n=====================================================\n");

		} else {
			z_row  = row * 0.1f;
			z_col  = col * 0.01f;
			z_total  = (z_row + z_col) * neg_check;
			printf("\n=====================================================\n");
			printf("Your input %4.4f area percentage value has a z-value of %4.4f\n", input_area, z_total);
			printf("\n=====================================================\n");
	
		}
		// define z value which input falls under
		//printf("The entries of the [0th row, 1st column]\nand [29th row, 8th column] are ");
		//printf("%0.5f %0.5f\n", rr[0][1], rr[29][8]);
		//printf("%d entries in the table satisfy the threshold condition\n", k);
		
	} else { /* File could not be opened. */
		printf ("The file could not be opened.\n");
		return 1; /* Exit the function/application. */
	}

	/* Close the file. */
	if (fclose(fp) != 0) {
		printf ("The file could not be closed.\n");
	}

	getchar(); /* Pause. */
	return 0;
}
