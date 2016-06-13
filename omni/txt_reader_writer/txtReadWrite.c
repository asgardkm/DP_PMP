// txtReadWrite.c
#include <stdio.h>
#include <stdlib.h>
#define CHUNK 4096
FILE *file;

int main(void){
	
	//// method 1
	//int c;
	//file = fopen("test.txt", "r");
	//if (file) {
		//while ((c = getc(file)) != EOF){
			//// data is stored in c
			////putchar(c);	// both these functions print to terminal
			//printf("%c", c); // but can only print while in the whileloop
		//}
		
		//fclose(file);
	//}

	///////////////////////////////////////////////////////////////////

	// method 2
	char buf[CHUNK];
	//FILE *file;
	size_t nread;

	file = fopen("test.txt", "r");
	if (file) {
		while ((nread = fread(buf, 1, sizeof buf, file)) > 0)
			fwrite(buf, 1, nread, stdout);
		if (ferror(file)) {
			/* deal with error */
		}
		fclose(file);
	}	
	
	getchar();
	return 0;	
	
}
