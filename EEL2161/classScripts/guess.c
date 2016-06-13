#include <stdio.h> /* guess.c - Script 11.4 */
#include <string.h> /* For strcasecmp(). */
void discard_input (void); /* Function prototype. */
int main (void) {
	/* Two character arrays. */
	char guess[10];	const char answer[] = "coy"; /* Word to guess. */
	
	/* Prompt for and read in an answer. */
	printf("Guess what three-letter word I'm thinking of: ");
	scanf("%9s", guess);	
	discard_input();
	
	/* Check for a match, re-prompt if wrong. */
	while (strcasecmp(answer, guess)) {
		printf("Incorrect! Guess again: ");
		scanf("%9s", guess);		
		discard_input();	}
	/* Must be correct to get here. */
	printf("You are correct!");	getchar();	return 0;}

void discard_input (void) {	/* This function discards all of the input until a newline. */
	char junk; // To get rid of extra input.
		// Loop through the input and ignore it.
	while ( (junk = getchar()) != '\n' ) {	continue;}
} /* End of discard_input() function. */
