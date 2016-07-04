#include <stdio.h>
 
int main()
{
   int array[100], position, c, n, x;
	n = 4;
   //printf("Enter number of elements in array\n");
   //scanf("%d", &n);
 
   //printf("Enter %d elements\n", n);
	for (x = 0; x < n; x++){
		printf("x = %d\n", x);
		for ( c = 0 ; c < n ; c++ ){
		  array[c] = c;
		  printf("array[%d] = %d\n", c, array[c]);
		}

		//printf("Enter the location where you wish to delete element\n");
		//scanf("%d", &position);
		position = x ;
		printf("Removing position %d\n", position);
		if ( position >= n+1 ){
		  printf("Deletion not possible.\n");
		} else {
			for ( c = position ; c < n - 1 ; c++ ){
				array[c] = array[c+1];
			}
			
			
			// printing result
			printf("Resultant array is\n")
			for( c = 0 ; c < n - 1 ; c++ ){
				printf("%d\n", array[c]);
			}
		}
	}
 
   return 0;
}
