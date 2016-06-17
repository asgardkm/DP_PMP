// findNumVars.c
// function: find the number of varables define in mainConfig.txt
//
// input: 	char input_filename - string defining mainConfig.txt directory
//			char *key_start		- points to string defining readin starting keyword
//			char *key_end		- points to string defining readin ending keyword 
//
// output: 	int numVars 		- number of variable params defined in mainConfig.txt
//
// created 15.June.2016 by Asgard Kaleb Marroquin
#include <stdio.h>
#include "findNumVars.h"

int findNumVars(char *config_filename, char *key_start, char *key_end){
//int main(void){
	//========= DEFINE VARIABLES ===============================
		// FILE POINTERS
		FILE *fp;						// pointer for FILE type
				
		// TOGGLE VARIABLES
		int toggle_read = 0;			// var for deciding to start reading in text data
		int toggle_start;				// var for activating readin when key is found
		int toggle_end;
		
		// TEMP READIN AND SCAN VARIABLES
		char line[500], tmp_line[500];
		
		// PARAMETER NUM LENGTH VARIABLES
		int  numVars = 0;				// var which will receive # length of inputs
	//==========================================================
		
	//========= READ DATA (MOCK) ===============================
		// attempt to open the file for reading
		fp = fopen(config_filename, "r");
		
		if (fp != NULL) { // file is open
					
				while (fgets(line, sizeof(line), fp)) {	
				
						// load in text data, look for when keyword is detected
						sscanf(line, "%s", tmp_line);
						
						// check for readin toggle
						toggle_start = strcmp(tmp_line, key_start);
						toggle_end	 = strcmp(tmp_line, key_end);
						
						// check if END has been found
						if (toggle_end == 0) {
								toggle_read = 0;
						}
			
						// read in config data once keyword has been detected
						if (toggle_read){
								numVars++;
						}
						
						// check if START has been found
						if (toggle_start == 0) {	
								toggle_read = 1; 
						}
				
				}
	
		} else { // File couldn't be opened
				printf ("The file could not be opened.\n");
				return -1; // exit function
		}
		// close file
		if (fclose(fp) != 0) {
				printf ("The file could not be closed.\n");
		}
	//==========================================================
		// printf("Number of input variables: %d\n", numVars);
//			printf("Hi!\n");
//			int numVars = 20;
	return numVars;
}
