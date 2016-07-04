//backwards.c
#include <stdio.h>
#include <ctype.h> // need in order to use isalpha()

int main(void){
	char input[10]; // for keyed input
	int i;			// index variable
	char junk;		// to get rid of extra variable
	
	// prompt the user
	printf("Enter a word up to ten characters long:");
	
	// read input
	scanf("%10s", input);
	
	// print it backwards
	printf("The word %s is '", input);
	
	// loop through the input in reverse
	for(i = 9; i >=0; i--){
		// only print letters
		if(isalpha(input[i])){
			printf("%c", input[i]);
		}
	} // end of while loop
	
	printf("' spelled backwards.\n");
	
	// discard any extra input and make the user press Enter once more
	while ((junk = getchar()) != '\n'){
		continue;
	}
	getchar();
	return 0;

}
