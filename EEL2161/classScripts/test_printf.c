#include <stdio.h>

int main (void){
	
printf("|%d|\n", 626);
printf("|%6d|\n", 626);
printf("|%06d|\n", 626);
printf("|%-6d|\n", 626);
printf("|%-6d|\n", 626);
printf("|%+6d|\n", -626);
printf("|%+-6d|\n", -626);

getchar();

return 0;
}
