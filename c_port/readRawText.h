// readRawText.h
// - header file for readRawText.c

#ifndef READRAW_H		// include guard
#define READRAW_H
//readRawText.c function declaration
//double *readRawText(char *data_dir, char *config_filename, int data_row, int data_col, double *buffer);
//double *readRawText(char *data_dir, char *config_filename,
//					int data_row, int data_col, double *memory_pointer);
double *readRawText(char *data_dir, char *config_filename, int data_col, double *buffer);

#endif					// CONFIG_H

