//script001.c
#include <stdio.h>
#include <string.h>

#define CHAPTER0 "Introduction"
#define CHAPTER1 "Getting Stated with C"
#define CHAPTER2 "Introduction to Data Types"
#define CHAPTER3 "Working with Numbers"
#define CHAPTER4 "Control Structures"

int main(void){
	char chapters[5][27] = {{CHAPTER0}, {CHAPTER1}, {CHAPTER2}, {CHAPTER3}, {CHAPTER4}};
	/* Create an array of character pointers. */
	/*Switch the location o "//" for the following two lines and see the differences.*/
	char *chapters_ptr[5] = {CHAPTER0, CHAPTER1, CHAPTER2, CHAPTER3, CHAPTER4};
	/* Print the memory requirements of each variable. */
	printf ("The chapters array uses %lu bytes of memory.\n", sizeof(chapters));
	printf ("The chapters_ptr array uses %lu bytes of memory.\n", sizeof(chapters_ptr));
	printf ("%s\n", chapters_ptr[0]);
	
	/* Declare three integers. */
	int i; /* Loop counter. */
	int chapters_count = 0, ptr_count = 0; /* Character counters. */

	/* Determine the total string length. */
	for (i = 0; i < 5; ++i) {
		chapters_count += strlen(chapters[i]);
	}
	
	/* Print the number of characters. */
	printf ("The chapters array contains %d characters.\n", chapters_count);

	/* Calculate the memory being used by the pointer array. */
	ptr_count = sizeof(chapters_ptr) + chapters_count + 5; /* Pointer size plus number of characters plus 5 (for the \0). */

	/* Print that result. */
	printf ("The chapters_ptr array -actually- uses %d bytes of memory.\n", ptr_count);
	
	getchar();	
	return 0;
}
