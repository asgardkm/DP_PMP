#include <stdio.h>

int main(void){
	char *name[2] = {"Kim", "Kardashian"};
	printf("String:%s \n2nd String: %s\n", name[0], name[1]);
	printf("Pointer: %d\n2nd Pointer: %d", name[0], name[1]);
	getchar();
	return 0;
}
