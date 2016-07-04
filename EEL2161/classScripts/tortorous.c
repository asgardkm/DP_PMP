// Torturous.c Created by Larry Ullman. 
#include <stdio.h>

/* The main function takes two arguments, * an integer and an array of char pointers. */
int main(int argc, char *argv[]) {
			
	/* Declare an integer variable to
	 * be used as loop index. */
	int i;

	/* Print the number in the argc parameter. */
	printf("Number of arguments received: %d\n", argc);

	/* Print the base address of the argv array. */
	printf("argv base address: %p\n\n", argv);

	/* Print the values of all elements
	 * of the argv array. Each element is a 
	 * pointer to a character string, so point that
	 * out too using the %s format sequence. */
	printf("Address --> Value\n");
	for (i = 0; i < argc; i++) {
		printf("%p --> %s\n", argv[i], argv[i]);
	}
	getchar();	return 0;}
