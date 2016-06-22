// readRawText.c
// function: read raw data text files saved from MATLAB for loading in vector
// and matrix inputs
//
// input: 	char config_prefix	- prefix string to filename
//			char config_filename- string defining mainConfig.txt directory
//			int data_row		- number of rows input data has
//			int data_col		- nuomber of cols input data has
//
// outputs: *
//
// created on 20.June.2016 by Asgard Kaleb Marroquin
//

#include <stdio.h>
#include <string.h>				// for strcmp() and strtok() invocations
#include "readRawText.h"
#define BUF_SIZE 1024
double **readRawText(char *data_dir, char *config_prefix, char *config_filename, int data_row, int data_col, double buff[][data_col]) {
	
		FILE *fp;	// file pointer
	
		// need to allocate enough space for sinal final_filename
		char final_filename[250] = "";
		
		// concacenate
		strcat(final_filename, data_dir);
		strcat(final_filename, "/");
		strcat(final_filename, config_prefix);
		strcat(final_filename, ".");
		strcat(final_filename, config_filename);
		strcat(final_filename, ".txt");
		
		printf("final_filename:\n%s\n", final_filename);
	
		// string buffers for reading in data
		char line[BUF_SIZE];
		
		// loop counters
		int i = 0, j = 0;
		
		// define outloop array!
		static double **output_array;		
		output_array = &buff[0][0];
		
		fp = fopen(final_filename, "r");
		if (fp != NULL) { // file is open
				while (fgets(line, sizeof(line), fp)) {
						    char *data = line;
						    int offset = 0;
							for (i = 0; i < data_row; i++){ // looping through rows
									// reading through each colmn entry
								    while ((sscanf(data, "%lf%n", &buff[i][j], &offset) == 1) || (j < data_col)){
								        	data += offset;
			//					        	printf("buff[%d][%d]: %5f; offset = %5d\n", i, j, buff[i][j], offset);
								        	j++;
								    }
							}			    
				}
			
		} else { 
				printf ("The file could not be opened.\n");
		}
		if (fclose(fp) != 0) {
				printf ("The file could not be closed.\n");
		}
		printf("Press enter to finish\n");
		fclose(fp);
		
		return output_array;	
}
