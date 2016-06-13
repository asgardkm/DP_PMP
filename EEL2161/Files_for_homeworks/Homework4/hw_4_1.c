// HW 4.1
#include <stdio.h>
#include <math.h>

int main(void){
	int i, k, p, q, tmp, l_sql = 3, threshold = .0005;	 	// loop counters, and tmp val for ordering, and length of sql
	char location[10];							 	// used as tmp stdin input
	float point_x[l_sql+1];					 	 	// array for storing input x coords of triangle
	float point_y[l_sql+1];							// array for storing input y coords of triangle
	float sql[l_sql-1][l_sql], lengths[l_sql+1][l_sql+1];  	// for storing side lengths (squared legs/hypot from 3 corners and actual pgram sides)
	float area;										// var for area
	int   sq_bool[2], rect_bool[2];	    			// bool array for checking if pythagoras is satisfied (rect / sq)
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
	
	
		sql[0][0] = (point_x[0] - point_x[1]) * (point_x[0] - point_x[1]) + (point_y[0] - point_y[1]) * (point_y[0] - point_y[1]);
		sql[0][1] = (point_x[0] - point_x[2]) * (point_x[0] - point_x[2]) + (point_y[0] - point_y[2]) * (point_y[0] - point_y[2]);
		sql[0][2] = (point_x[0] - point_x[3]) * (point_x[0] - point_x[3]) + (point_y[0] - point_y[3]) * (point_y[0] - point_y[3]);
		
		sql[1][0] = (point_x[1] - point_x[0]) * (point_x[1] - point_x[0]) + (point_y[1] - point_y[0]) * (point_y[1] - point_y[0]);
		sql[1][1] = (point_x[1] - point_x[2]) * (point_x[1] - point_x[2]) + (point_y[1] - point_y[2]) * (point_y[1] - point_y[2]);
		sql[1][2] = (point_x[1] - point_x[3]) * (point_x[1] - point_x[3]) + (point_y[1] - point_y[3]) * (point_y[1] - point_y[3]);
		
	// calculate the square lengths of triangle sides from one corner (do twice)
	for(k = 0; k <= 1; k++){
		printf("k = %d\n", k);


		// calculate three lengths from the specified vertex - doesn't work
	//	for(i = k+1; i <= k+3; i++){
	//		printf("i = %d\n", i);
	//
	//		if(i == k+3){ // at end of loop - calculate hypotensuse
	//			sql[k][i-1] = (point_x[i-1] - point_x[i-2]) * (point_x[i-1] - point_x[i-2]) + (point_y[i-1] - point_y[i-2]) * (point_y[i-1] - point_y[i-2]);
	//		} else{		  // otherwise, calculate leg lengths
	//			sql[k][i-1] = (point_x[k] - point_x[i]) * (point_x[k] - point_x[i]) + (point_y[k] - point_y[i]) * (point_y[k] - point_y[i]);
	//		}
	//	}	// end of i loop
		
	// see if pythagorean theorem is solved w/ three sides in each k val
		printf("Previously %4.2f %4.2f %4.2f\n", sql[k][0], sql[k][1], sql[k][2]);

		// first need to sort the values in sql[k] - sampler from class
		for (p = 0; p < l_sql; p++){
			
			for (q = p + 1; q < l_sql; q++){
				
				if(sql[k][p] > sql[k][q]){
					tmp = sql[k][p];				
					sql[k][p] = sql[k][q];
					sql[k][q] = tmp;
				}	
				
			}	// end of q loop
		}	// end of p loop
			printf("Now the numbers are %4.2f %4.2f %4.2f\n", sql[k][0], sql[k][1], sql[k][2]);

		
		
		// print out ordered sql[k]
		for(i = 0; i <= 2; i++){
			printf("sql[%d][%d] = %4.2f\n", k, i, sql[k][i]);
		}

		// sql[k] should now be ordered - highest val will be last
		//run pythagoras - if satisfied, triffer rect_bool
	} // end of k loop
	for(k = 0; k <= 1; k++){

		if (sql[k][2] - sql[k][1] - sql[k][0] <= threshold){
			rect_bool[k] = 1;
			
			// check if sides of triangle are same - if so, trigger sq_bool
			if (sql[k][0] - sql[k][1] <= threshold && sql[0][k] - sql[1][k] <= threshold){
				sq_bool[k] = 1;
			} else{
				sq_bool[k] = 0;
			}
			
		} else{
			rect_bool[k] = 0;
		}
		printf("rect_bool[%d] = %d\n", k, rect_bool[k]);
		printf("sq_bool[%d] = %d\n", k, sq_bool[k]);

	} // end of k loop

	// print to terminal shape output - calculate areas
	if(rect_bool[0] == 1 && rect_bool[1] == 1){
		
		printf("\nInput parallelogram is a rectangle\n");
		if(sq_bool[0] == 1 && sq_bool[1] == 1){
			printf("Input parallelogram is also a square.\n");
		} else {
			printf("Input parallelogram is not a square however.\n");
		}
			
		// get side lengths - special condition for last length, want to get dist btwn 1st and last elements in array
		for (k = 0; k <= 1; k++){
			for (i = 0; i <= 1 ; i++){
				lengths[k][i] = sqrt(sql[k][i]);
			}
		}
		//	if (i == 3){	
		//		lengths[3] = sqrt((point_x[i]-point_x[0])*(point_x[i]-point_x[0]) + (point_y[i]-point_y[0])*(point_y[i]-point_y[0]));
		//	} else {
		//		lengths[i] = sqrt((point_x[i+1]-point_x[i])*(point_x[i+1]-point_x[i]) + (point_y[i+1]-point_y[i])*(point_y[i+1]-point_y[i]));
		//	}
		for (k = 0; k <= 1; k++){
			for (i = 0; i <= 1; i++){	
				printf("Length of side %d = %4.3f\n", 2*k+i, lengths[k][i]);
			}
		}
		// calculate area and print
		// first check - find area if shape is a rectangle
		if (sq_bool[0] != 1 || sq_bool[1] != 1){
			
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
	
	} else { // if not rectangle - tell terminal and stop
		printf("\nInput parallelogram is not a rectangle.\n");
	}
	
	getchar();
	return 0;
	
}
