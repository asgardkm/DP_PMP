// weather.c
#include <stdio.h>

int main(void){
	
	int temperature = 50; // Temperature in Fahrenheit
	
	if (temperature > 90) {
		printf("At %d degrees, it's hot, hot, hot outside!\n", temperature);
	}
	else if (temperature < 40) {
		printf("At %d degrees, it's %s outside!\n", temperature, (temperature < 20)? "freezing" : "cold");
	}
	else {
		printf("At %d degrees, it's a relatively temperate day\n", temperature);
	}
	getchar();
	return(0);
	
}
