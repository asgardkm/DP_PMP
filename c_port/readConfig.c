// readConfig.c
// function: read in data parameters defined in mainConfig.txt
//
// input: 	char *config_filename 	- points to string defining mainConfig.txt directory
//			int num_length 			- num. of vars returned by findNumVars() invocation
//			char *key_start			- points to string defining readin starting keyword
//			char *key_end			- points to string defining readin ending keyword 
//
// output: struct *input_struct		- points to struct. array (length=num_length) containing grp's mainConfig input vars
//
// created 14.June.2016 by Asgard Kaleb Marroquin

#include <stdio.h>
#include <string.h>				// for strcmp() and strtok() invocations
#include "readConfig.h"			// this function's header file

struct model_params *readConfig(char *config_filename, int num_length, char *key_start, char *key_end, struct model_params buff[]){
	//========= DEFINE VARIABLES ===============================
		// FILE POINTERS
	    FILE *fp;						// pointer for FILE type
		int i = 0;
		
		// TOGGLE VARIABLES
		int toggle_read = 0;			// var for deciding to start reading in text data
		int toggle_start;				// var for activating readin when key is found
		int toggle_end;
		
		// TEMP READIN AND SCAN VARIABLES
		char line[500], tmp_line[500];
	//==========================================================
	
	//========= READ DATA ======================================
		// define structure
//		struct model_params input_struct[num_length+1];
		static struct model_params *input_pointer;
//		input_pointer = &input_struct[0];
		input_pointer = &buff[0];
		
		if (buff == 0)
				printf("ERROR: out of memory\n");
		
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
								sscanf(line, "%lf, %s", &buff[i].value, buff[i].name);
								strtok(buff[i].name, ",");	
								i++;
						}
						
						// check if START has been found
						if (toggle_start == 0) {	
								toggle_read = 1; 
						}
				}
				
	
		} else { // file couldn't be opened
				printf ("The file could not be opened.\n");
		}
	
		// close file
		if (fclose(fp) != 0) {
				printf ("The file could not be closed.\n");
		}
	//==========================================================
		
	//========== PRINT STRUCT FOR CONFIRMATION =================
//		printf("Inputs read from %s:\n\n", config_filename);
//		for (i = 0; i < num_length; i++)
//			printf("	%s: %4.2f\n", input_pointer[i].name, input_pointer[i].value);
	//==========================================================

		return input_pointer;
}
