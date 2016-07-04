// hw_9_1.c
// read in SNL_CAST.TXT (make sure .txt is in same dir as script)
//	and change all instances of "Michael" to "Mike" and rewrite
#include <stdio.h>
#include <string.h>
#define FILEPATH "SNL_CAST.txt"

struct castName{
	char firstName[300];
	char lastName[300];
};
	
int main(void){
	
	//read in the file
	FILE *fp;					//pointer to file
	fp = fopen(FILEPATH, "r");

	// buffer char array for saving each line of raw data
	char buff[BUFSIZ];
	
	// create a structure var for each name
	struct castName indivName;
	//char *ptr_first;
	//ptr_first = &indivName.firstName;
			
	if (fp != NULL){
		////check to make sure that there is still data @ line you are looking at
		while (fgets(buff, sizeof(buff), fp)) {
			// read in data from txt file line by line w/ sscanf
			sscanf(buff, "%s %s", indivName.firstName, indivName.lastName);
			
			// check for if name is name is michael - if so, change to mike
			if (strcmp(indivName.firstName, "Michael") == 0)
				strncpy(indivName.firstName, "Mike", sizeof(indivName.firstName));
				
			printf("Name: %s %s\n", indivName.firstName, indivName.lastName);
		}
	}
	
	getchar();
	return 0;
}
