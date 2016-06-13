#include <stdio.h>

int main(){
	int myArray[3] = {25, 209, -12};
	
	int *ptr1 = &myArray[0];
	int *ptr2 = myArray;
	int *ptr3 = &myArray[1];
	
	//differences in array
	printf("%d is the address of the 0th entry in my Array\n", ptr1);
	printf("%d is the address of the 1st entry in my Array\n", ptr2);
	printf("%d is the address of the 2nd entry in my Array\n", ptr3);
	
	getchar();
	return 0;	
}
