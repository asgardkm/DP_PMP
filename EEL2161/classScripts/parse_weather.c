/* parse_weather.c - Script 12.4 - rework of read_weather.c (Script 12.3) */
#include <stdio.h>
/* Set the file path and name. */
#define THEFILE "Distribution.txt"

int main (void) {
	
	/* Need a pointer of type FILE. */
    FILE *fp;
	int j, i = 0, k = 0;
	float FL = 0.0, TH = 0.00001;
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
				rr[i][j] = r[j];
				
				// how many entries satisfy condition?
				if (r[j] < TH){k = k + 1;}			
				}
			
			//printf("%0.5f", FL);
			printf("%0.5f %0.5f %0.5f %0.5f %0.5f %0.5f %0.5f %0.5f %0.5f %0.5f\n", r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7], r[8], r[9]);
			FL = FL+0.1;
			++i;
			//printf("%10s %5d %5d\n", date, high, low);
		}
		
		printf("The entries of the [0th row, 1st column]\nand [29th row, 8th column] are ");
		printf("%0.5f %0.5f\n", rr[0][1], rr[29][8]);
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
