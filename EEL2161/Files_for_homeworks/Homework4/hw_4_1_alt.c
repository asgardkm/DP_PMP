// HW 4.1altc
#include <stdio.h>
#include <math.h>

int main(void){
	int i, k, p, q, tmp, l_sql = 3, threshold = .0005;	 	// loop counters, and tmp val for ordering, and length of sql
	char location[10];							 	// used as tmp stdin input
	float point_x[l_sql+1];					 	 	// array for storing input x coords of triangle
	float point_y[l_sql+1];							// array for storing input y coords of triangle
	float ortho[2][3], sql[l_sql-1][l_sql], lengths[2][2];  	// for storing side lengths (squared legs/hypot from 3 corners and actual pgram sides)
	float area;										// var for area
	int   sq_bool;	    				// bool for checking shape (rect / sq)
	// display general problem info to terminal
	printf("Hello, please input the xy coords for 4 vertices of your input parallelogram\n Code will test if input parallelogram is a square and/or rectangle\n");
	printf("Press Enter to proceed\n\n");
	getchar(); // user presses enter (or any char) and code proceeds
	
		// loop three times to get three vertices of triangle
	for (i = 0; i <= 3; i++){
		// GETTING X COORDS :
		// print to user to input in x coord of vertex
		printf("Enter the x value of of vertex #%d: ", i+1);
		// load in user input's xcoord
		fgets(location, sizeof(location)-1, stdin);
		// save input as float to element in point_x array
		sscanf(location, "%f", &point_x[i]);
		
		// GETTING Y COORDS:
		// print to user to input in y coord of vertex
		printf("Enter the y value of vertex #%d: ", i+1);
		// load in user input's ycoord
		fgets(location, sizeof(location)-1, stdin);
		// save input as float to element in point_y array
		sscanf(location, "%f", &point_y[i]);	
	}
	
	// check for orthagonality - dot product
	ortho[0][0] = (point_x[1] - point_x[0]) * (point_x[1] - point_x[2]) + (point_y[1] - point_y[0]) * (point_y[1] - point_y[2]);
	ortho[0][1] = (point_x[1] - point_x[3]) * (point_x[1] - point_x[2]) + (point_y[1] - point_y[3]) * (point_y[1] - point_y[2]);
	ortho[0][2] = (point_x[1] - point_x[0]) * (point_x[1] - point_x[3]) + (point_y[1] - point_y[0]) * (point_y[1] - point_y[3]);

	ortho[1][0] = (point_x[0] - point_x[1]) * (point_x[0] - point_x[3]) + (point_y[0] - point_y[1]) * (point_y[0] - point_y[3]);
	ortho[1][1] = (point_x[0] - point_x[2]) * (point_x[0] - point_x[3]) + (point_y[0] - point_y[2]) * (point_y[0] - point_y[3]);
	ortho[1][2] = (point_x[0] - point_x[1]) * (point_x[0] - point_x[2]) + (point_y[0] - point_y[1]) * (point_y[0] - point_y[2]);

	ortho[2][0] = (point_x[2] - point_x[1]) * (point_x[2] - point_x[3]) + (point_y[2] - point_y[1]) * (point_y[2] - point_y[3]);
	ortho[2][1] = (point_x[2] - point_x[0]) * (point_x[2] - point_x[3]) + (point_y[2] - point_y[0]) * (point_y[2] - point_y[3]);
	ortho[2][2] = (point_x[2] - point_x[1]) * (point_x[2] - point_x[0]) + (point_y[2] - point_y[1]) * (point_y[2] - point_y[0]);

	// if orthogonal - trigger rect_bool
	printf("\nInput parallelogram is a rectangle\n");

	if ((ortho[0][1] < threshold || ortho[0][1] || ortho[0][2]) && 
		(ortho[1][0] < threshold || ortho[1][1] || ortho[1][2]) && 
		(ortho[2][0] < threshold || ortho[2][1] || ortho[2][2])) {
		
		// now find out if sides are equal in order to trigger sq_bool - get lengths
		sql[0][0] = (point_x[0] - point_x[1]) * (point_x[0] - point_x[1]) + (point_y[0] - point_y[1]) * (point_y[0] - point_y[1]);
		sql[0][1] = (point_x[0] - point_x[2]) * (point_x[0] - point_x[2]) + (point_y[0] - point_y[2]) * (point_y[0] - point_y[2]);
		sql[0][2] = (point_x[0] - point_x[3]) * (point_x[0] - point_x[3]) + (point_y[0] - point_y[3]) * (point_y[0] - point_y[3]);
		
		sql[1][0] = (point_x[1] - point_x[0]) * (point_x[1] - point_x[0]) + (point_y[1] - point_y[0]) * (point_y[1] - point_y[0]);
		sql[1][1] = (point_x[1] - point_x[2]) * (point_x[1] - point_x[2]) + (point_y[1] - point_y[2]) * (point_y[1] - point_y[2]);
		sql[1][2] = (point_x[1] - point_x[3]) * (point_x[1] - point_x[3]) + (point_y[1] - point_y[3]) * (point_y[1] - point_y[3]);
		
	for(k = 0; k <= 1; k++){
		// sorting
		for (p = 0; p < l_sql; p++){
			
			for (q = p + 1; q < l_sql; q++){
				
				if(sql[k][p] > sql[k][q]){
					tmp = sql[k][p];				
					sql[k][p] = sql[k][q];
					sql[k][q] = tmp;
				}	
				
			}	// end of q loop
		}	// end of p loop
	} // endof k loop
		
		// get side lengths - special condition for last length, want to get dist btwn 1st and last elements in array
		for (k = 0; k <= 1; k++){
			for (i = 0; i <= 1 ; i++){
				lengths[k][i] = sqrt(sql[k][i]);
				printf("lengths[%d][%d] = %4.2f\n", k, i, lengths[k][i]);
			}
		}
		printf("Diff in lengths [0][0] - [0][1] = %4.8f\n", lengths[0][0] - lengths[0][1]);
		printf("Diff in lengths [0][0] - [1][0] = %4.8f\n", lengths[0][0] - lengths[1][0]);
		printf("Diff in lengths [0][0] - [1][1] = %4.8f\n", lengths[0][0] - lengths[1][1]);

		// test for sq_bool
		if (((lengths[0][0] - lengths[0][1]) < threshold) &&
			((lengths[0][0] - lengths[1][0]) < threshold) &&
			((lengths[0][0] - lengths[1][1]) < threshold)){
			sq_bool = 1;
			printf("Input parallelogram is also a square.\n");
		} else {
			sq_bool = 0;
			printf("Input parallelogram is not a square however.\n");
		}
		// calculate area and print
		// first check - find area if shape is a rectangle
		if (sq_bool!= 1){
			
			// if sides 3 and 0 are the same size
			if (lengths[1][1] - lengths[0][0] < threshold){ 
				
				// if sides 3 and 1 are the same size - so mult 3 and 2 for area
				if (lengths[1][1] - lengths[0][1] < threshold){
					area = lengths[1][1] * lengths[1][0]; 
				} else { // sides 3 and 1 aren't the same then - can find area
					area = lengths[1][1] * lengths[0][1];
				}
				
			} else { // dies 3 and 0 aren't the same then - can find area
					area = lengths[1][1] * lengths[0][0];
			}
			
		//calculate area if square
		} else {
			area = lengths[1][1] * lengths[1][0];
		}
		
		printf("Area Size = %4.3f\n", area);
		
		
		
	} else {
		printf("\nInput parallelogram is not a rectangle.\n");
	}

	
	getchar();
	return 0;
	
}
