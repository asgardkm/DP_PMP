#include <stdio.h>  /* concat.c  */
#include <string.h> /* For strcat() and strncat(). */

#define VARSIZE 50

int main (void) {
	
	/* Two name character arrays. */
	char name[VARSIZE];
	char last_name[VARSIZE];
	
	/* Prompt for and read in the first name. */
	printf("Enter your first name: "); 
	scanf("%48s", name);
	
	/* Prompt for and read in the last name. */
	printf("Enter your last name: "); 
	scanf("%49s", last_name);
	
	/* Add a space. */
	strcat(name, " ");
	
	/* Append the last name. */
	strncat(name, last_name, (VARSIZE - 1) - strlen(name));
	
	/* Print the result. */
	printf("You entered your name as %s.\n", name);	
	getchar();	
	getchar();
	return 0; 
}
