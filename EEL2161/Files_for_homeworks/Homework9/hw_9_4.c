//hw_9_4.c
// store sailor warrior names and their gpas in struct and write to txt
#include <stdio.h>
#define THEFILE "sailorWarriorNamesGPA.txt"
#define NUMWARRIORS 7

struct castName{
		char firstName[300];
		char lastName[300];
		float gpa;
};

int main (void)
{	
		FILE *fp;					//pointer to file
		struct castName warrInfo[NUMWARRIORS];
		int i;
		
		fp = fopen(THEFILE, "a");
		
		if (fp != NULL) { /* The file is open. */
		
		        /* Prompt the user. */
		        printf("Total number of warriors to input information for: %d\n\n", NUMWARRIORS);
		        for (i = 0; i < NUMWARRIORS; i++){
						printf ("Enter the first name, last name, and gpa for warrior number %d:\n", i+1);
						
						/* Handle the input, assigning it to the structure fields. */
						//if (scanf("%s %d %d", weather_record.date, &weather_record.high, &weather_record.low) == 3) {
						if (scanf("%s %s %f", warrInfo[i].firstName, warrInfo[i].lastName, &warrInfo[i].gpa) == 3) {		
								printf ("The data has been written.\n\n");
								fprintf(fp,"%s %s %4.2f\n", warrInfo[i].firstName, warrInfo[i].lastName, warrInfo[i].gpa);

							
						} else {
								printf ("The data was not in the proper format.\n");
							}
					}
					
				for (i = 0; i < NUMWARRIORS; i++){
					printf("Warrior Number %d: %s %s %4.2f\n", i, warrInfo[i].firstName, warrInfo[i].lastName, warrInfo[i].gpa);
					}
		
		} else {
				printf ("The file could not be opened.\n");
				return 1; /* Exit the function/application. */
			}

		/* Close the file. */
		//fclose(fp);
		if (fclose(fp) != 0) {
				printf ("The file could not be closed.\n");
			}
	
		getchar();
		return 0;
}
