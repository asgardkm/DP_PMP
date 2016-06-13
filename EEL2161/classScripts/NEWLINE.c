// NEWLINE.c
#include <stdio.h>
#define NL printf("\n")
#define ANNA_LONG printf("Here I stand \
in the light of day \
Let the storm rage on, \
The cold never bothered me anyway!\n")

int main(void){
	printf("This is some text");
	NL;
	printf("This will show up on the next line.");
	NL;
	NL;
	printf("This will show up two lines later.\n");
	NL;
	ANNA_LONG;
	
	getchar();
	return 0;
		
}
