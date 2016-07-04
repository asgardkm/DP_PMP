// HW 8_1a.c
#include <stdio.h>
int *changeGrade(int length, int *grades_ptr[length]);		// function declaration
// make script that will reorganize grades - w/ function

int main(void){
	char names[3][10] = {{"Kenny"}, {"Stan"}, {"Kyle"}};
	char *name_ptr[3] = {names[0], names[1], names[2]};
	int grades[3] = {60, 70, 80};
	int *grades_ptr[3] = {&grades[0], &grades[1], &grades[2]};
	int i;
	
	printf("Initial grades:\n");
	for (i = 0; i < 3; i++)
		printf("%s : %d\n", name_ptr[i], *grades_ptr[i]);
	
	// run function
	*grades_ptr = changeGrade(3, grades_ptr);
	printf("\nNew grades:\n");
	for (i = 0; i < 3; i++)
		printf("%s : %d\n", name_ptr[i], *grades_ptr[i]);
	
	getchar();
	return 0;	
	
}

// changeGrade() function

int *changeGrade(int length, int *grades_ptr[length]){
	int i, j, *tmp_address;

	// bubble method - will sort as 80,70,60
	for (i = 0; i < length-1; ++i) { /* Loop through each word. */
		
		for (j = (i + 1); j < length; ++j) { /* Loop through each word again. */

			if (*grades_ptr[i] - *grades_ptr[j] < 0) { /* Compare words. */
				tmp_address = grades_ptr[i]; /* Swap word 1 to the temp location. */
				grades_ptr[i] = grades_ptr[j]; /* Assign word 2 to word 1. */
				grades_ptr[j] = tmp_address; /* Assign temp (original word 1) to word 2. */
			} /* End of IF. */
		}
    } 
	// switch val 2 and 3
	tmp_address = grades_ptr[1];
	grades_ptr[1] = grades_ptr[2];
	grades_ptr[2] = tmp_address;
	
	return (*grades_ptr);
	}
