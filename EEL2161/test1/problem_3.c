// Test 1 Problem 3
#include <stdio.h>
#include <math.h>


int main(){
	int i;					// loop counter
	char location[10];		// used as tmp stdin input
	float lengths[3];		// array for storing input triangle lengths
	float s_length, trisize; // for storing s value and area
	
	// display general problem info to terminal
	printf("Hello, please follow this simple rule.\nNo triangle side can be larger than the sum of the other two sides\n");
	printf("Press Enter to proceed\n\n");
	getchar(); // user presses enter (or any char) and code proceeds
	
	// loop three times to input three sides of triangle
	for (i = 0; i <= 2; i++){
		// GETTING X COORDS :
		// print to user to input in triangle length
		printf("Enter the length of side length %d: ", i+1);
		// load in user input's length val
		fgets(location, sizeof(location)-1, stdin);
		// save input as float to element in lengths array
		sscanf(location, "%f", &lengths[i]);
	}

	// find s-value of triangle
	s_length = (lengths[0] + lengths[1] + lengths[2]) / 2.0;
	
	// find triangle area (sqrt(s*(s-a)*(s-b)*(s-c)))
	trisize = sqrt(s_length*(s_length-lengths[0])*(s_length-lengths[1])*(s_length-lengths[2]));
	printf("The area of the triangle is %0.3f.\n", trisize);	//print area
	
	getchar();
	return 0;	
}
