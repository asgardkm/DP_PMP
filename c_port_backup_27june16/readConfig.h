// readConfig.h
// - header file for readConfig.c
// - is also read by mainScript.m for struct declaration

#include "./codegen/lib/clcDP_port/clcDP_port_types.h" // include input structs declared in clcDP_port_types.h

#ifndef CONFIG_H		// include guard
#define CONFIG_H

// define structure for input data from mainConfig.txz
struct model_params {
		char name[300];
		double value;
} model_struct;

//readConfig function declaration
struct model_params *readConfig(char *config_filename, int num_length, char *key_start, char *key_end, struct model_params buff[]);
#endif					// CONFIG_H
