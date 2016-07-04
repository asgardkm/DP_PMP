/* binary_write.c - Script 12.5 */

#include <stdio.h>
#include <stdlib.h> /* For rand() and srand(). */
#include <time.h> /* For time(), used with srand(). */

/* Set the file path and name. */
#define THEFILE "numbers.txt"                                                                                                                   
/* Number of items being written. */
#define ITEMS 50

int main (void) {
	
	/* Need a pointer of type FILE. */
    FILE *fp;
	
	int i; /* Loop counter. */
	int numbers[ITEMS]; /* Array of numbers. */
	
	/* Attempt to open the file for binary writing. */
	fp = fopen(THEFILE, "wb");
	
	
	if (fp != NULL){
		srand((unsigned)time(NULL));
	
	for (i = 0; i < ITEMS; i++){
		numbers[i] = rand() % 100;
	}
	                                                                                                                                            
		/* Write the array elements to the file. */
		fwrite(numbers, sizeof(int), ITEMS, fp);
		printf ("The data has been written.\n");
		
	} else { 
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
