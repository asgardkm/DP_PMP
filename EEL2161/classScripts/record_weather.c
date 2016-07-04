/* record_weather.c - Script 12.2 */
#include <stdio.h>
/* Set the file path and name. */
#define THEFILE "weather.txt"

int main (void) {
	
	/* Need a pointer of type FILE. */
    FILE *fp;
	 
	int high, low; /* Temperatures. */
	char date[11]; /* In the form of YYYY-MM-DD, plus \0 character. */
	
	fp = fopen(THEFILE, "a");
	if (fp != NULL) {
		printf("Enter a date, the high temperature, and the low temperature.\n(YYYY-MM-DD ## ##):");
		
		if (scanf("%s %d %d", date, &high, &low)==3) {
			fprintf(fp, "%s %d %d\n", date, high, low);
			printf("The data has been written.\n");
		} else {
			printf("The data was not in the proper format.\n");
		}
		
	} else {
		printf("The file could not be opened.\n");
		return 1;
	}
	if (fclose(fp) != 0){
		printf("The file could not be closed.\n");
	}
	
	getchar(); /* Pause. */
	getchar(); /* Pause. */
	return 0;
	
}
