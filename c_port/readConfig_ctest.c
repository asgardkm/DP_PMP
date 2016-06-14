// readConfig_ctest.c
// function: read in data parameters defined in mainConfig.txt
#include <stdio.h>
/* Set the file path and name. */
#define THEFILE "mainConfig.txt"
// define number of inputs in config

// define structure for input data from mainConfig
struct model_params{
		char name[70];
		float value;
};

int main (void) {
	//========= DEFINE VARIABLES ===============================
	    FILE *fp;						// pointer for FILE type
	    
		int i = 0;						// loop counter
			
		char  pname_mock[100];			// var for loading in parameter names
		float pvalue_mock;				// var for loading in parameter value
	
		// TOGGLE VARIABLES
		int toggle_read = 0;			// var for deciding to start reading in text data
		int toggle_start;				// var for activating readin when key is found
		int toggle_end;
		
		// PARAMETER NUM LENGTH VARIABLES
		char num_name[] = "numParams";	// define param name which defines # of of inputs
		int  num_length;				// var which will receive # length of inputs
		int  num_found;					// bool - shows when num_name has been found
		
		// TEMP READIN AND SCAN VARIABLES
		char line[500], tmp_line[500];
		
		// KEYWORDS
		char keyword_start[10] = "START",
			 keyword_end[10]   = "END";	
	//==========================================================
		
	//========= READ DATA (MOCK) ===============================
		// attempt to open the file for reading
		fp = fopen(THEFILE, "r");
		
		if (fp != NULL) { // file is open
					
				while (fgets(line, sizeof(line), fp)) {	
				
						// load in text data, look for when keyword is detected
						sscanf(line, "%s", tmp_line);
						
						// check for readin toggle
						toggle_start = strcmp(tmp_line, keyword_start);
						toggle_end	 = strcmp(tmp_line, keyword_end);
						
						if (toggle_start == 0) {	
								toggle_read = 1; 
						} else if (toggle_end == 0) {
								toggle_read = 0;
						}
			
						// read in config data once keyword has been detected
						if (toggle_read){
								sscanf(line, "%f, %s,", &pvalue_mock, pname_mock);
								strtok(pname_mock, ","); // get rid of the lingerning comma at end of each pname_mock
				
								// LOOK FOR numParams AND GET THE LENGTH VALUE
								num_found = strcmp(pname_mock, num_name);
								if (num_found == 0){
										num_length = pvalue_mock;
										toggle_read = 0; // reset toggle_read bool for next readin cycle
										break;
								}
						}
				}
	
		} else { // File couldn't be opened
				printf ("The file could not be opened.\n");
				return 1; // exit function
		}
		// close file
		if (fclose(fp) != 0) {
				printf ("The file could not be closed.\n");
		}
	//==========================================================
		
	//========= READ DATA (REAL) ===============================
		// define structure
		struct model_params input_struct[num_length];
		
		// attempt to open the file for reading
		fp = fopen(THEFILE, "r");
		
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
							sscanf(line, "%f, %s", &input_struct[i].value, input_struct[i].name);
							strtok(input_struct[i].name, ",");	
							i++;
					}
					
					// check if START has been found
					if (toggle_start == 0) {	
							toggle_read = 1; 
					}
				}
	
	
	
		} else { // file couldn't be opened
				printf ("The file could not be opened.\n");
				return 1; // exit function
		}
	
		// close file
		if (fclose(fp) != 0) {
				printf ("The file could not be closed.\n");
		}
	//==========================================================
		
	//========== PRINT STRUCT FOR CONFIRMATION =================
		printf("Inputs read from %s:\n\n", THEFILE);
		for (i = 0; i < num_length; i++)
			printf("	%s: %4.2f\n", input_struct[i].name, input_struct[i].value);
	//==========================================================

		getchar(); 
		return 0;
}
