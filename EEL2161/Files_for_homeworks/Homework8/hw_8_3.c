// hw8_3.c
#include <stdio.h>

// sort Z-A
/* sort.c - Script 11.6 - rewrite of copy.c (Script 11.5) */

#include <stdio.h>
#include <string.h> /* For strncmp() and strcmp(). */

void discard_input (void); /* Function prototype. */

#define NUM_STRINGS 10
#define STR_LEN 10

int main (void) {
	
	/* Define character array. */
	char words[NUM_STRINGS][STR_LEN];
	char input[STR_LEN]; /* For user input. */

	/* Pointers. */
	char *words_ptr[NUM_STRINGS];
	char *temp;
	
	int i, j; /* Loop counters. */
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
		
		/* Copy the address to the pointer. */
		words_ptr[i] = &words[i][0]; /*The &words[i][0]construct returns the address of the fist character in the newly added string. This address is assigned to the pointer, in the corresponding matrix. It will be these addresses that will be moved around in the sorting process. */
		
		/* Count another word entered. */
		++count;	} /* End of while loop. */

	 printf("A total of %d words were entered.\n", i);
	
	
	
	
	for (i = 0; i < (count - 1); ++i) { /* Loop through each word. */
		
        for (j = (i + 1); j < count; ++j) { /* Loop through each word again. */
			
            if (strcmp(words_ptr[i],words_ptr[j]) < 0) { /* Compare words. */
				
                temp = words_ptr[i]; /* Swap word 1 to the temp location. */
                words_ptr[i] = words_ptr[j]; /* Assign word 2 to word 1. */
                words_ptr[j] = temp; /* Assign temp (original word 1) to word 2. */
				
            } /* End of IF. */

        } /* End of inner FOR. */

    } /* End of outer FOR. */
	printf("In alphabetical order, the words are:\n");                                                                                                                                                 
	/* Print the numbers in a loop. */
	for (i = 0; i < count; i++) {
		printf("%s\n", words_ptr[i]);
	}
	
	getchar();	
	return 0;
	
} /* End of main() function. */

/* This function discards all of the input until a newline. */
void discard_input (void) {
	
	char junk; // To get rid of extra input.
	
	// Loop through the input and ignore it.
	while ( (junk = getchar()) != '\n' ) {
		continue;
	}
	
} /* End of discard_input() function. */

