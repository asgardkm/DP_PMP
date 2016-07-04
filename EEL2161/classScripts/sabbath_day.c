// sabbath_day.c
#include <stdio.h>

int main(void){
	char religion; // single char to store - [C]hristianity, [I]slam, [J]udaism,
					//	[B]uddhism, [A]theist
	
	printf("What is your religion?\n Please make a choice\n [C]hristianity, [I]slam, [J]udaism, [B]uddhism, [A]theist\n");
	religion = getchar();
	
	switch(religion){
			case 'C': case 'c':
				printf("Do not come to work on Sundays.\n");
				break;
				
			case 'I': case 'i':
				printf("Do not come to work on Fridays.\n");
				break;
			
			case 'J': case 'j':
				printf("Do not come to work on Saturdays.\n");
				break;
				
			case 'B': case 'b': case 'A': case 'a':
				printf("Feel free to choose any day of the week.\n");
				break;
	
	}
	getchar();
	getchar();
	return(0);
}
