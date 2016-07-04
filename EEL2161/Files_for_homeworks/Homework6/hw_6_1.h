// header file for hw_6_1.c
// for finding total resistance of three elements 
	// can be in series, parallel, or a combo (first element is in series with the other two that are in parallel)
#ifndef MY_CIRCUIT // insuring macro is defined only once

	#define MY_CIRCUIT

	// print config options to terminal
	#define PRINT_PROMPT (printf("Select circuit configuration : \n [s]eries (DEFAULT), [p]arallel, [c]ombination\n"))
	
	// let user select config
	#define ANSWER(void) (getchar())

	// define resistance combinations
	// Note : conditional directives require CONSTANT expressions - they
	// cannot have VARIABLES as inputs (such as below) - otherwise, compiler
	// returns an implication function declaration error, since the directives
	// are run before compilation, the variable input has not yet been declared when the
	// directive #if is being processed, so the nested functions can't be defined properly
	/* which is why the code below does not work */
	//#if   (ANSWER=='p')
		//#define RT(R1, R2, R3) (1 / ((1/R1) + (1/R2) + (1/R3)))
	//#elif (ANSWER=='c')
		//#define RT(R1, R2, R3) (R1 + (R2*R3) / (R2+R3))
	//#elif (ANSWER == 's')
		//#define RT(R1, R2, R3) (R1 +R2 +R3)
	//#endif
	
	/* instead, define each of the three possible options, and call them
	 * in the script w/ user input chars in terminal */
	#define RT_S(R1, R2, R3) (R1 +R2 +R3)
	#define RT_P(R1, R2, R3) (1 / ((1/R1) + (1/R2) + (1/R3)))
	#define RT_C(R1, R2, R3) (R1 + (R2*R3) / (R2+R3))

	// promt for printing input configuration to terminal
	#define PRINT_CONFIG(answer) (printf("Circuit orientation selected : %c\n", (answer == 's' || answer == 'p' || answer == 'c')? answer : 's'))

	// print out the output
	#define PRINT_OUTPUT(RT) (printf("Total resistance : %0.3f ohms\n", RT))
	
#endif
