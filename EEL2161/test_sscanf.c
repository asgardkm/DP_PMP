#include <stdio.h>
//#define BUFFSIZE 200

struct castName{
	char firstName[300];
	float numVal;
};

int main() {
	
	FILE *fp;
    struct castName tmpcast;
    char buff[BUFSIZ];
    if((fp=fopen("test.txt","r"))==NULL) {
        perror("File cannot be opened");
        getchar();
        return 1;
	}
	
	 while(fgets(buff,sizeof(buff),fp)!=NULL)  // read a single line from the file till i get EOF
    {
        if(sscanf(buff,"%s %f",tmpcast.firstName,&tmpcast.numVal) == 2) {  // getting the name and the number from the  buffer which was read from the file
        printf("%s %.2f\n",tmpcast.firstName, tmpcast.numVal);
        } else {
        printf("line cannot be printed\n");
		}
	}
	
     
    //sscanf(buff,"%s %f",tmpcast.firstName,&tmpcast.numVal);
     
    //printf("%s %.2f",tmpcast.firstName, tmpcast.numVal);
     
    getchar();
    return 0;
}
/*myouput
Sarah 111.20
*/
