// HW 3.2
#include <stdio.h>

int main(){
	float 	r[3],			// input resistance array
			rt;				// output rt
	char connect,			// char defined from terminal for determining circuit
		resistance[10], 	// string array for saving stdinput resistor val
		last_name_tmp[15],	// string array for saving stdinput name
		last_name[15];		// what input name is saved as
	int i;					// used for running for loop
	
	// input name and print to terminal
	printf("Enter your last name : ");
	fgets(last_name_tmp, sizeof(last_name_tmp) - 1, stdin);
	sscanf(last_name_tmp, " %s", last_name);
	
	//select topology
	printf("Select circuit configuration : \n [s]eries, [p]arallel, [c]ombination\n");
	connect = getchar();								// get char from terminal input
	getchar();											// getchar() terminal buffer so that first 
														// 	i loop isn't "eaten" by connect's getchar()
	
	// input resistance values from terminal
	for (i = 0; i<=2; i = i + 1){ 						// loop for each resistor
	printf("Input resistor %d value : ", i+1); 			// print to terminal
	fgets(resistance, sizeof(resistance)-1, stdin); 	// get input value
	sscanf(resistance, " %f", &r[i]); printf("\n");  	// turn input to float in r array
	}
	
	switch(connect){
	// if series :
	case 's': case 'S':
		rt = r[0] + r[1] + r[2]; 						// all in series	
		// print output to terminal
		printf("Dear Mr or Ms %s, the total resistance is %0.2f ohms since the connection is in series\n", last_name, rt);
	break;
	
	// if parallel :
	case 'p': case 'P':
		rt = 1 / ((1/r[0]) + (1/r[1]) + (1/r[2]));		// all in parallel
		// print output to terminal
		printf("Dear Mr or Ms %s, the total resistance is %0.2f ohms since the connection is in parallel\n", last_name, rt);
	break;
	
	// if combo
	case 'c': case 'C':
		rt = r[0] + (r[1]*r[2]) / (r[1]+r[2]);			// r1 in series, r2 and r3 in parallel
		// print output to terminal
		printf("Dear Mr or Ms %s, the total resistance is %0.2f ohms since the connection is in combination\n", last_name, rt);
	break;
	}
	getchar();
	return(0);
}
