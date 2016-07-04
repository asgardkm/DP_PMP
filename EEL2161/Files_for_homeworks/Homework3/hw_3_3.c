// HW 3.3
#include <stdio.h>
#include <math.h>

int main(){
	int i;					// loop counter
	char location[10];		// used as tmp stdin input
	float point_x[3];		// array for storing input x coords of triangle
	float point_y[3];		// array for storing input y coords of triangle
	float length_a, length_b, length_c, s_length, trisize; // for storing side lengths, s value, and area
	
	// display general problem info to terminal
	printf("Hello, please follow this simple rule.\nThe distance between the second and the third vertices has to be\nthe longest side of the triangle\n");
	printf("Press Enter to proceed\n\n\n");
	getchar(); // user presses enter (or any char) and code proceeds
	
	// loop three times to get three vertices of triangle
	for (i = 0; i <= 2; i++){
		// GETTING X COORDS :
		// print to user to input in x coord of vertex
		printf("Enter the x value of the %d vertex: ", i+1);
		// load in user input's xcoord
		fgets(location, sizeof(location)-1, stdin);
		// save input as float to element in point_x array
		sscanf(location, "%f", &point_x[i]);
		
		// GETTING Y COORDS:
		// GETTING X COORDS :
		// print to user to input in y coord of vertex
		printf("Enter the y value of the %d vertex: ", i+1);
		// load in user input's ycoord
		fgets(location, sizeof(location)-1, stdin);
		// save input as float to element in point_y array
		sscanf(location, "%f", &point_y[i]);	
	}
	// find lengths of each side based on vertex locs
	// length/distance formula : length = sqrt((x2-x1)^2 + (y2-y1)^2)
	length_a = sqrt((point_x[1]-point_x[0])*(point_x[1]-point_x[0]) + (point_y[1]-point_y[0])*(point_y[1]-point_y[0]));
	length_b = sqrt((point_x[2]-point_x[1])*(point_x[2]-point_x[1]) + (point_y[2]-point_y[1])*(point_y[2]-point_y[1]));
	length_c = sqrt((point_x[0]-point_x[2])*(point_x[0]-point_x[2]) + (point_y[0]-point_y[2])*(point_y[0]-point_y[2]));

	// Determine if triangle is right (c^2-b^2-a^2 = 0, w/ some leeway)
	if(length_b*length_b - length_a*length_a - length_c*length_c <= 0.002){
		printf("This triangle is a right triangle.\n");
	} else {
		printf("This triangle is not a right triangle.\n");
	}
	// determine if trinagle has two equal side - makes it isosceles
	if(length_a == length_c || length_a == length_b || length_b == length_c){
		printf("This triangle is isosceles.\n");
	} else{
		printf("this triangle is not isosceles.\n");
	}
	
	// find s-value of triangle
	s_length = (length_a + length_b + length_c) / 2.0;
	
	// find triangle area (sqrt(s*(s-a)*(s-b)*(s-c)))
	trisize = sqrt(s_length*(s_length-length_a)*(s_length-length_b)*(s_length-length_c));
	printf("The area of the triangle is %0.2f.\n", trisize);	//print area
	
	getchar();
	return 0;	
}
