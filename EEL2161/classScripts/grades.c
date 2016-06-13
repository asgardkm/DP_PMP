/* grades.c - Script 13.3 */

#include <stdio.h>
#include <string.h> /* For string functions. */

#define STR_LEN 20

#define NUM_STUDENTS 10

int main (void) {
	
// Here 1
	// define structure
	struct student_grade{
		char first_name[STR_LEN];
		char last_name[STR_LEN];
		float grade;
	};
	char junk;
	
	// rename the strucutre syntax
	typedef struct student_grade sg;
	
	// create an array of structures
	sg class[NUM_STUDENTS];
	// end here1
	
	/* Need some counters. */
	int i, num;
	int count = 0;
	
	/* Need a temporary float. */
	float g; /* grade */

	/* Need some strings to handle the input. */
	char classname[30], fn[STR_LEN], ln[STR_LEN];
	
	/* Prompt the user. */
	printf ("Enter the classname (without spaces): ");
	scanf ("%30s", classname);
	
		//Discard extra input
	do{junk = getchar();
} while (junk!='\n');

	
	/* Insert a check on the classname, if you want. */
	
	/* Loop to read in all the student data. */
	for (i = 0; i < NUM_STUDENTS; ++i) {
		
		/* Prompt the user. */
		printf ("Enter the student's name and their grade. Enter 0 0 0 to quit.\n(First Last #.#): ");
		
		/* Read in the input. */
		num = scanf ("%11s %11s %f", fn, ln, &g);
		
		/* Check if the user is done. */
		if (fn[0] == '0') {
			break;
		}
		
//HERE 2
if(num == 3){
	strncpy(class[i].first_name, fn, STR_LEN - 1);
	strncpy(class[i].last_name, ln, STR_LEN - 1);
	class[i].grade = g;
	++count;	
}
 else { 
			printf ("The data was not in the proper format.\n");
			break; 
		}
	}
// end here2

//HERE 3
// print data
printf("Students and grades for the class %s:\n", classname);
for(i = 0; i < count; i++){
	printf("%s %s %0.1f\n", class[i].first_name, class[i].last_name, class[i].grade);
}
		
	getchar(); /* Pause. */
	getchar(); /* Pause. */
	return 0;

}
