// circle_area.c
#include <stdio.h>

int main(void){
	int NUM = 5;
	float radius[5] = {1.0, 2.0, 2.5, 3.0, 5.0};
	int i;
	char ANS;
	float radius2 = 1.0;
	
	for(i = 0; i < NUM; i++){
		printf("The area of a circle with %0.2f radius is %0.2f\n\n", radius[i], radius[i]*radius[i]*3.14);		
	}
	
	printf("Would you like to play with the program a little bit more? Y/N : ");
	scanf("%c", &ANS);
	
	if(ANS == 'Y'){
		do{
			printf("What is the radius? ##.## Use 0.0 if you want to stop.\n");
			scanf("%f", &radius2);
			printf("The area of a circle with %0.2f radius is %0.2f. \n\n", radius2, radius2*radius2*3.14);
			getchar();
		} while(radius2 != 0.0);
	}
	
	getchar();
	return 0;	
}
