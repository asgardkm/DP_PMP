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

#include <stdio.h>
#include <string.h>				// for strcmp() and strtok() invocations
#include "readRawText.h"

#define BUF_SIZE 16384
double *readRawText(char *data_dir, char *config_filename, int data_col, double *buffer) {

		// file pointer
		FILE *fp;
		// need to allocate enough space for final final_filename
		char final_filename[1024] = "";
		// concacenate
		strcat(final_filename, data_dir);
		strcat(final_filename, ".");
		strcat(final_filename, config_filename);
		strcat(final_filename, ".txt");		
		// printf("final_filename:\n%s\n", final_filename);
	
		double *memory_pointer = &buffer[0];
		// string buffers for reading in data
		char line[BUF_SIZE];
		
		// loop counters
		int i = 0, j = 0;
		
		// attempt to open file
		fp = fopen(final_filename, "r");
		if (fp != NULL) { // file is open
				// begin reading in data line by line
				while (fgets(line, sizeof(line), fp)) {
						// pointer holding place in line from data element to data element
						char *data = line;
						// reset offset for defining space between each data element in raw text file
						int offset = 0;
						// reading through each column entry - parse it by delimited spaces 
					    while ((sscanf(data, "%lf%n", (buffer+i*data_col+j), &offset) == 1) || (j < data_col)) {
					    		// after reading in each word, add to offset to reach next word in next while iteration
					        	data += offset;
								// printf("buff[%d]: %4.2f; offset = %5d\n", j, *(buffer+i*data_col+j), offset);
					        	j++;
					    }
				}
				
		} else { 
				printf ("The file could not be opened.\n");
		}
		if (fclose(fp) != 0) {
				printf ("The file could not be closed.\n");
		}
		fclose(fp);
		// return pointer containing all the raw readin data
		return (double *)buffer;	
}
