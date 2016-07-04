// HW 6.1
#include <stdio.h>
#include "./hw_6_1.h"			// readin header file which will do HW_2_1
#define R1 10.0
#define R2 20.0
#define R3 30.0

int main(void){
	float resistance;
	char answer;
	
	PRINT_PROMPT;				// print terminal prompt
	answer = ANSWER(void);		// read in user input
	
	
	if (answer == 'p'){			// select corresponsing resistance function
		resistance = RT_P(R1, R2, R3);
	} else if (answer == 'c'){
		resistance = RT_C(R1, R2, R3);
	} else {
		resistance = RT_S(R1, R2, R3);
	}
	
	/* would work if conditional directive could take nonconstant inputs*/
	//resistance = RT(R1, R2, R3);

	PRINT_CONFIG(answer);		// show what user selected
	PRINT_OUTPUT(resistance);	// print corresponding resistance
	
	getchar();
	return 0;
}
