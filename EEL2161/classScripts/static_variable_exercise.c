// static_variable_exercise
#include <stdio.h>

void call();

int main(){
	call();
	call();
	call();
	call();
	call();
	return 0;
}

void call(){
	static int count = 0;
	// int count = 0;
	count++;
	printf("%d\n", count);
}
