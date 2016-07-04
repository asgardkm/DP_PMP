#include <stdio.h>
#include <string.h> /* For strncmp() and strcmp(). */

void discard_input (void); /* Function prototype. */

#define NUM_STRINGS 10
#define STR_LEN 10
int main (void) { //Please Replace “HERE” of copy_template.c	
	/* Define character array. */
	char words[NUM_STRINGS][STR_LEN];
	char input[STR_LEN]; /* For user input. */
	
	int i; /* Loop counter. */
	int count = 0; /* To count number of words entered. */
	
	/* Get up to NUM_STRINGS words. */
	for (i = 0; i < NUM_STRINGS; ++i) {
		/* Prompt and read in word. */
		printf("Enter a word (or 0 to quit): ");
		scanf("%9s", input);
		discard_input();
		/* Check for a 0. */
		if (input[0] == '0') break;
		/* Copy the input to the array. */
		strncpy(words[i], input, (STR_LEN - 1));
		printf("The input was %s and it was copied to the SPECIAL Vault as %s\n", input, words[i]);
		/* Count another word entered. */
		++count;
		
	} /* End of for loop. */
	printf("A total of %d words were entered.\n", count);	getchar();	return 0;}


/* This function discards all of the input until a newline. */
void discard_input (void) {
	
	char junk; // To get rid of extra input.
	
	// Loop through the input and ignore it.
	while ( (junk = getchar()) != '\n' ) {
		continue;
	}
	
} /* End of discard_input() function. */
