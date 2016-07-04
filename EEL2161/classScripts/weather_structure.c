/* weather_structure.c - Script 13.1 */

#include <stdio.h>

/* Set the file path and name. */
#define THEFILE "weather.txt"

int main (void) {
	
	/* Define a structure and create a variable of that type. */
	struct weather_record {
		char date[11]; /* YYYY-MM-DD */
		int high;
		int low;
	};
	
	struct weather_record today; /* One structure variable of type weather_record. */
	
	/* Need a pointer of type FILE. */
    FILE *fp;
	
	/* Attempt to open the file for appended binary writing. */
	fp = fopen(THEFILE, "ar");
	
	if (fp != NULL) { /* The file is open. */
		
		/* Prompt the user. */
		printf ("Enter a date, the high temperature, and the low temperature.\n(YYYY-MM-DD ## ##): ");
		
		/* Handle the input, assigning it to the structure fields. */
		//if (scanf("%s %d %d", weather_record.date, &weather_record.high, &weather_record.low) == 3) {
		if (scanf("%s %d %d", today.date, &today.high, &today.low) == 3) {

			/* Write the data. */
			fwrite (&today, sizeof(struct weather_record), 1, fp);
			printf ("The data has been written.\n");
			
		} else {
			printf ("The data was not in the proper format.\n");
		}
		
	} else {
		printf ("The file could not be opened.\n");
		return 1; /* Exit the function/application. */
	}

	/* Close the file. */
	if (fclose(fp) != 0) {
		printf ("The file could not be closed.\n");
	}

	getchar(); /* Pause. */
	getchar(); /* Pause. */
	return 0;

}
