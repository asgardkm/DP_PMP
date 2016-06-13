/* test.c - Script 12.1 */

#include <stdio.h>

/* Set the file path and name. */
#define THEFILE "~/Documents/spring2016/EEL2161/classScripts/data.txt"

int main (void) {
	
	/* Need a pointer of type FILE. */
    FILE *fp;
	
	/* Attempt to open the file for writing. */
	fp = fopen(THEFILE, "w");
	
	/* Report on the success of file opening. */
	if (fp != NULL) { 
		printf ("The file is now open.\n");
	} else {
		printf ("The file could not be opened.\n");
		/* Abort the application, if you want. */
	}
	
	/* Close the file and report if a problem occurred. */
	if (fclose(fp) != 0) {
		printf ("The file could not be closed.\n");
	} else {
		printf ("The file is now closed.\n");
	}
	
	getchar(); /* Pause. */
	return 0;
}
