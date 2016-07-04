#include <stdio.h>
/* Set the file path and name. */
#define THEFILE "Distribution.txt"

int main (void) {
	
	/* Need a pointer of type FILE. */
    FILE *fp;
	
	/* Character array for reading the file. */
	char line[81];
	
	//float r00, r01, r02, r03, r04, r05, r06, r07, r08, r09; /* Temperatures. */
	float r0[10];
	float rr[100][100];
	float TH = 0.35;
	int i = 0, j, k = 0;
    //char date[11]; /* In the form of YYYY-MM-DD, plus \0 character. */

	/* Attempt to open the file for reading. */
	fp = fopen(THEFILE, "r");
	
	if (fp != NULL) { /* The file is open. */
		
		printf("%7s %7s %7s %7s %7s %7s %7s %7s %7s %7s\n", "0", "0.01", "0.02","0.03", "0.04", "0.05","0.06", "0.07", "0.08","0.09");
		
		while (fgets(line, sizeof(line), fp)) {			
			sscanf (line, "%f %f %f %f %f %f %f %f %f %f\n", &r0[0], &r0[1], &r0[2], &r0[3], &r0[4], &r0[5], &r0[6], &r0[7], &r0[8], &r0[9]);
			//sscanf (line, "%7f", &rr[0]);
			
			for (j = 0; j < 9; j++){
				rr[i][j] = r0[j];
				if (r0[j] < TH) {k = k+1;}
			}
			//printf("0.4f", FL);
			//printf()
			printf("%0.5f %0.5f %0.5f %0.5f %0.5f %0.5f %0.5f %0.5f %0.5f %0.5f\n", r0[0], r0[1], r0[2], r0[3], r0[4], r0[5], r0[6], r0[7], r0[8], r0[9]);
			//FL = FL + 0.1;
			
			//printf("% 0.5f", rr[i]);
			i++;			
		}
		printf("The entries of [0th row, 1st col] and [29th row, 8th col] are\n");
		printf("%0.5f %0.5f\n", rr[1][2], rr[30][9]);
		printf("%d entries in the table satisfy the threshold condition\n", k);
		
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
