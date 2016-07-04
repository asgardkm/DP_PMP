#include <stdio.h> /* sort.c */
#include <string.h> /* For strncmp() and strcmp(). */
void discard_input (void); /* Function prototype. */
#define NUM_STRINGS 10
#define STR_LEN 10
int main (void) {
	char words[NUM_STRINGS][STR_LEN]; /* Define character array. */
	char input[STR_LEN]; /* For user input. */
	/* Pointers. */
	char *words_ptr[NUM_STRINGS];
	char *temp;
	int i, j; /* Loop counters. */
	int count = 0; /* To count number of words entered. */
HERE I
	printf("A total of %d words were entered.\n", count);
HERE II
	printf("In alphabetical order, the words are:\n");

	/* Print the numbers in a loop. */
	for (i = 0; i < count; i++) {
		printf("%s\n", words_ptr[i]);} getchar(); return 0; } /* End of main() function. */
/* This function discards all of the input until a newline. */
void discard_input (void) {
	char junk; // To get rid of extra input.
	// Loop through the input and ignore it.
	while ( (junk = getchar()) != '\n' ) { continue;	}} 
