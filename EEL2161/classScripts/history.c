// history.c
#include <stdio.h>

int main(void){
	unsigned int answer[] = {2, 1939, 1945}; //array for 3 numbers
	char input[10];				// for keyboard input
	int user_answer;			// store the user's answer
	char junk;					// collecting extra to get rid of them

	// ask questions
	
	printf("In what year did Japan surrender in WWII?\n");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%d", &user_answer);
	
	if(user_answer == answer[2]){printf("History buff!\n");
	} else {printf("It was %d. Read some books, will you?\n", answer[2]);
	}
	
	//discard extra input
	do {
		junk = getchar();
	} while (junk != '\n');
	
	getchar();
	return(0);

}
