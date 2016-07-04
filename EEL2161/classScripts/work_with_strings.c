#include <stdio.h>

int main(void){
	char name[] = "Marc";
	char *name_address;
	name_address = &name;
	
	printf("String: %s \nPointer: %p \nAddress: %p", name, name, name_address);
	
	getchar();
	return 0;
}
