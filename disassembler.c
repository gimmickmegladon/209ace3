
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 16
// Changed this to char as I receive char *answer in promptUser
char memory[4096];

//functions
void promptUser(char *message, char *answer);
int binToDec(char binary[], int decimal);
void decToBin(int dec);
char binary[size];
int dec = 31;
int main(void) {

 decToBin(dec);
char binary[] = {'0','0','0','0','0','0','0','0','0','0','0','1','1','1','1','1'};
int decimal = 0;
printf("%d \n", binToDec(binary, decimal) ); 

    char *message;
    char *answer;
    char memoryContents;
    answer = &memoryContents;
    promptUser(message, answer);
    return 0;
}

int binToDec(char binary[], int decimal){
    int i;

    int index = 1;
    
    for(i = 15; i >= 0; i-- ){
    if (binary[i] == '1'){
            decimal = index + decimal ;
        }
    index = index * 2;
    }
return decimal;
}


// Still have to save the bin number as an array.
void decToBin(int dec) {

    int j = 0;
    if(0 <= dec && dec <= 65535) {
        for(int j = 0; j < size + 1; j++) {
            if (dec % 2 == 0) {
                binary[j] = '0';
            } else {
                binary[j] = '1';
            }
            dec = dec / 2;
        }
    }
    for(int x = size - 1; x >= 0; x--){
       printf("%c", binary[x]);
    }
printf("\n");
}
/*
*	Load instructions from file and put them into memory
*/
void loadFile(FILE *fp){
	char buffer[255];
	int count = 0;
char *filename = "testfile.txt";

	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("Could not find file %s.\n", filename);
		exit(0);
	}
	
while(fgets(buffer, 255, (FILE*) fp)) {
	
if(buffer != NULL){

*(memory+count*16) = buffer;
}
else{
	printf("File %s is empty.", filename);
		}
count++;	
}
fclose(fp);
}


/*
 Prompts the user to input the memory contents, reads the input in & stores it into the memory
*/
void promptUser(char *message, char *answer) {
    char memoryContents;
    int length = strlen(answer);
    message = ("Please enter the current memory contents. Enter 'E' at any time to exit the program.\n");
    printf("%s", message);
        
    for (int i = 0; i < 16; i++) {
        printf("Enter the %ith element of memory, i.e. 0 or 1\n", i + 1);
        scanf("%s", answer);

        while (*answer != '0' && *answer != '1' && *answer != 'E') {
            if (*answer == '0' || *answer == '1') {
                break;
            }
            printf("You must enter valid memory contents, i.e. 0 or 1. Try again. Enter 'E' at any time to exit the program.\n");
            scanf("%s", answer);
        }
        
        length = strlen(answer);
        while (length > 1) {
            if (length == 1) {
                break;
            }
            printf("You must enter only one character, i.e. '0' or '1'. Try again. Enter 'E' at any time to exit the program.\n");
            scanf("%s", answer);
            length = strlen(answer);
        }

        while (*answer == 'E') {
            exit(0);
        }

        memory[i] = *answer;
    }

    printf("Here is what is now stored in memory: %s\n", memory);
}

