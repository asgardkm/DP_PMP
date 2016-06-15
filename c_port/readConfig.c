// readConfig.c
// function: read in data parameters defined in mainConfig.txt
//
// input: char config_filename - string defining mainConfig.txt directory
//
// output: NEED TO FIGURE OUT HOW TO PULL OUT STRUCTURE!
//
// created 14.June.2016 by Asgard Kaleb Marroquin
//
#include <stdio.h>
#include "readConfig.h"			// this function's header file
#include "findNumVars.h"		// for finding number of variables in mainConfig.txt

struct model_params *readConfig(char *config_filename) {
	//========= DEFINE VARIABLES ===============================
		// FILE POINTERS
	    FILE *fp;						// pointer for FILE type
		int i;
		// TOGGLE VARIABLES
		int toggle_read = 0;			// var for deciding to start reading in text data
		int toggle_start;				// var for activating readin when key is found
		int toggle_end;
		
		// NUMBER OF VARIABLE INPUTS
		int num_length;					// var will hold findNumVars() output
		
		// TEMP READIN AND SCAN VARIABLES
		char line[500], tmp_line[500];
		
		// KEYWORDS
		char keyword_start[10] = "START";
		char keyword_end[10]   = "END";	
	//==========================================================
		
	//========= READ DATA ======================================
		// call findNumVars(), find number of input variables
		num_length = findNumVars(config_filename);
		
		// define structure
		static struct model_params *input_struct;
//		static struct model_params *input_pointer;
//		input_pointer = &input_struct[0];

		
		// attempt to open the file for reading
		fp = fopen(config_filename, "r");
		
		if (fp != NULL) { // file is open
					
					
				while (fgets(line, sizeof(line), fp)) {	
				
					// load in text data, look for when keyword is detected
					sscanf(line, "%s", tmp_line);
					
					// check for readin toggle
					toggle_start = strcmp(tmp_line, keyword_start);
					toggle_end	 = strcmp(tmp_line, keyword_end);
					
					// check if END has been found
					if (toggle_end == 0) {
							toggle_read = 0;
					}
		
					// read in config data once keyword has been detected
					if (toggle_read){
							sscanf(line, "%f, %s", &input_struct[i]->value, input_struct[i]->name);
							strtok(input_struct[i]->name, ",");	
							i++;
					}
					
					// check if START has been found
					if (toggle_start == 0) {	
							toggle_read = 1; 
					}
				}
				
	
		} else { // file couldn't be opened
				printf ("The file could not be opened.\n");
//				return 1; // exit function
		}
	
		// close file
		if (fclose(fp) != 0) {
				printf ("The file could not be closed.\n");
		}
	//==========================================================
		
	//========== PRINT STRUCT FOR CONFIRMATION =================
//		printf("Inputs read from %s:\n\n", config_filename);
//		for (i = 0; i < num_length; i++)
//			printf("	%s: %4.2f\n", input_struct[i].name, input_struct[i].value);
	//==========================================================

//		getchar(); 
		return input_struct;
}
