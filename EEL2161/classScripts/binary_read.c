/* binary_read.c - Script 12.6 */

#define THEFILE "numbers.txt"

/* Number of items being written. */
#define ITEMS 50

int main (void) {
	
	/* Need a pointer of type FILE. */
    FILE *fp;
	
	int i; /* Loop counter. */
	int numbers[ITEMS]; /* Array of numbers. */
	
    fp = fopen(THEFILE, "r");
    
    if (fp != NULL){
		printf("The contents in the number file:\n");
		fread(numbers, sizeof(int), ITEMS, fp);
		
		for (i = 0; i < ITEMS; i++){
			printf("%d\n", numbers[i]);
		}
	} else {
		printf("The file could not be opened.\n");
		return 1;
	}                                                                                                
	
	/* Close the file. */
	if (fclose(fp) != 0) {
		printf ("The file could not be closed.\n");
	}
	
	getchar(); /* Pause. */
	return 0;
}
