#include <stdio.h>
#include <string.h>
// store sailor warrior names and their gpas in struct and write to txt
#define THEFILE "voltageCurrentDrop.txt"
#define NUM 

struct resistorAll{
		float voltage;
		float current;
};

int main (void)
{	
		FILE *fp;					//pointer to file
		
		// bool for determining to continue inputting resistors
		int input_bool = 1;
		
		struct resistorAll resistor[999]; // make really big structure - so that user can always add more, unlikely to hit 999
		int i, j;
		
		fp = fopen(THEFILE, "a");
		
		if (fp != NULL) { /* The file is open. */
		
		        /* Prompt the user. */
		        //printf("Total number of resistors to input values for: %d\n\n", n);
		        for (i = 0; i < 999; i++){
						printf ("Enter the voltage and current values for the resistor number %d:\n", i+1);
						
						/* Handle the input, assigning it to the structure fields. */
						//if (scanf("%s %d %d", weather_record.date, &weather_record.high, &weather_record.low) == 3) {
						if (scanf("%f %f", &resistor[i].voltage, &resistor[i].current) == 2) {		
								printf ("The data has been written.\n\n");
								fprintf(fp,"%4.2f %4.2f\n", resistor[i].voltage, resistor[i].current);
							
						} else {
								printf ("The data was not in the proper format.\n");
							}
							
							// advise user to stop inputting (default: Yes)
							printf("Would you like to continue inputting data? If not please press enter 0 to exit; otherwise, please input any other value to continue\n");
							scanf("%d", &input_bool);
							//fgets(tmp_input_bool, sizeof(tmp_input_bool)-1, stdin);
							//sscanf(tmp_input_bool, "%d", &input_bool);
							getchar();
							printf("Input: %d\n\n", input_bool);
							
							if (input_bool == 0){	// if not n - continue
								break;
							}
					}
					
				printf("%d resistors added to %s:\n", i+1, THEFILE);
				for (j = 0; j <= i; j++){
					printf("Resistor %d: Voltage=%4.2f and Current=%4.2f\n", j+1, resistor[j].voltage, resistor[j].current);
					}
		
		} else {
				printf ("The file could not be opened.\n");
				return 1; /* Exit the function/application. */
			}

		/* Close the file. */
		if (fclose(fp) != 0) {
				printf ("The file could not be closed.\n");
			}
	
		getchar();
		return 0;
}
