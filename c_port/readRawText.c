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
<<<<<<< HEAD
#define BUF_SIZE 16384
//#define BUF_SIZE 100000
double *readRawText(char *data_dir, char *config_filename, int data_row, int data_col, double *buffer) {
=======
#define BUF_SIZE 1024
double *readRawText(char *data_dir, char *config_filename, int data_row, int data_col, double *memory_pointer) {
>>>>>>> parent of 0f2749b... ITS ALIVE MHUAHAHAHAH1111 1xdxdd
	
		// file pointer
		FILE *fp;
		// need to allocate enough space for sinal final_filename
<<<<<<< HEAD
		char final_filename[1024] = "";
=======
		char final_filename[250] = "";
>>>>>>> parent of 0f2749b... ITS ALIVE MHUAHAHAHAH1111 1xdxdd
		
		// concacenate
		strcat(final_filename, data_dir);
		strcat(final_filename, ".");
		strcat(final_filename, config_filename);
		strcat(final_filename, ".txt");
//		printf("Final_filename: %s\n", final_filename);
		
//		printf("final_filename:\n%s\n", final_filename);
	
		// string buffers for reading in data
		char line[BUF_SIZE];
		
		// loop counters
		int i = 0, j = 0;
		
		fp = fopen(final_filename, "r");
		if (fp != NULL) { // file is open
				while (fgets(line, sizeof(line), fp)) {
<<<<<<< HEAD
						char *data = line;
						int offset = 0;
						j = 0;
						for (i = 0; i < data_row; i++) { // looping through rows
								// reading through each column entry
//							    while ((sscanf(data, "%lf%n", (buffer+i*data_col+j), &offset) == 1) || (j < data_col)) {
							    while (sscanf(data, "%lf%n", (buffer+i*data_col+j), &offset) == 1) {
=======
					    char *data = line;
					    int offset = 0;
						for (i = 0; i < data_row; i++){ // looping through rows
								// reading through each column entry
							    while ((sscanf(data, "%lf%n", (memory_pointer+i*data_col+j), &offset) == 1) || (j < data_col)){
>>>>>>> parent of 0f2749b... ITS ALIVE MHUAHAHAHAH1111 1xdxdd
							        	data += offset;
//							        	printf("buff[%d][%d]: %4.2f; offset = %5d\n", i, j, *(memory_pointer+i*data_col+j), offset);
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
		
<<<<<<< HEAD
		return (double *)buffer;	
=======
		return (double *)memory_pointer;	
>>>>>>> parent of 0f2749b... ITS ALIVE MHUAHAHAHAH1111 1xdxdd
}
