//headache.c
#include <stdio.h>
#define COUNT 5

int main(void){
	char a[] = {3, 23, 14, 7, 12};
	int i; char *b;		// define a char position variable
	b = a;		// save base address of the char * array in the char pointer
	
	for (i = 0; i < COUNT; i++){
		printf("%d\n", (int)a[i]);
	}
	printf("Using pointer\n");
	for (i = 0; i < COUNT; i++){
		printf("%d\n", (int)b);	// pointer does not need indexing
		b++;
	}
	getchar();
	return 0;
}
