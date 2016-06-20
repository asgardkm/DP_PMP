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
float *readRawText(char *data_dir, char *config_prefix, char *config_filename, int data_row, int data_col) {
	
	FILE *fp;	// file pointer

//	// concatenate strings for defining string directory
//	// input 1
//	char config_prefix[] = "FZG";
//	// input 2
//	char config_filename[] = "iceTrqMaxCof.txt";
//	// target string holding concactenation
	char final_filename[200] = "";
	
	// concacenate
	strcat(final_filename, data_dir);
	strcat(final_filename, "/");
	strcat(final_filename, config_prefix);
	strcat(final_filename, ".");
	strcat(final_filename, config_filename);
	strcat(final_filename, ".txt");
	
	printf("final_filename:\n%s\n", final_filename);

	// string buffers for reading in data
	char line[500];
	
	// loop counters
	int i = 0, j = 0;
	
	// define outloop array!
	float output_array[data_row][data_col];
	float *output_pointer;
	output_pointer = &output_array[0][0];
	
	fp = fopen(final_filename, "r");
	
	if (fp != NULL) { // file is open
		while (fgets(line, sizeof(line), fp)) {		
			
			    char *data = line;
			    int offset;
				for (i = 0; i <= data_row; i++){ // looping through rows
				
						// reading through each colmn entry
					    while (sscanf(data, " %f%n", &output_array[i][j], &offset) == 1){
					        	data += offset;
					        	printf("read: %5d; offset = %5d\n", output_array[i][j], offset);
					        	j++;
					    }
				}			    
		}
		
	} else { /* File could not be opened. */
		printf ("The file could not be opened.\n");
		return 1; /* Exit the function/application. */
	}

	/* Close the file. */
	if (fclose(fp) != 0) {
		printf ("The file could not be closed.\n");
	}
	printf("Press enter to finish\n");
	fclose(fp);
	
	// print out array
	for (i = 0; i < data_row; i++){
		for (j = 0; j < data_col; j++){
			printf("output_array[%d][%d]: %4.8f\n", i, j, output_array[i][j]);
		}
	}
	getchar();
	return output_array;	
}

