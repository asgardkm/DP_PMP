/* read_weather.c - Script 12.3 */

#include <stdio.h>

/* Set the file path and name. */
#define THEFILE "weather.txt"

int main (void) {
	// de	fine the structure
	struct weather_record{
		char date[11];
		int high;
		int low;
	};
	
	// use typedefto create an alias
	struct weather_record wr_test;
	typedef struct weather_record wr;
	
	char tmp_string[100];
	// create structure variable
	wr day;
	/* Need a pointer of type FILE. */
    FILE *fp;
	
	//char line[30];
	
	fp = fopen(THEFILE, "r");
	if (fp != NULL){
		printf("The contents of the 'weather.txt' file:\n\n");
		
		while (fgets(&tmp_string[0], sizeof(wr_test), fp)) {
			sscanf(&tmp_string[0], "%s %d %d", day.date, &day.low, &day.high);
			printf("Date: %s\nHigh: %5d\nLow: %d\n\n", day.date, day.low, day.high);
		}
	} else {
		printf("The file could not be opened.\n");
		return 1;
	}
	
	if (fclose(fp) != 0){
		printf("The file could not be closed.\n");
	}
	
	getchar(); /* Pause. */
	return 0;
	
}
