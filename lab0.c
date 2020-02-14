 :#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>

 char* appendZero (char* inputString);


 int main (int argc, char *argv[]) {
    FILE* myFile;
    char charArray[100][100];
    char appendString[100] = "";
    int len = 0; 	// number of arguments = argc -1
    char ch;		// char to append to string
    int numOfOnes=0; 	// count the number of ones in each binary block for parity
    int decimalNum=0; 	// calculation decimal number of binary block
    int base = 7; 	// power of base starts at 7 from the left after the initial check bit
    int i=0; 

    if(argc == 2) {

	// for every input, increment len
 	myFile = open(argv[1], "r");

	while((ch = read(myFile)) != EOF) {   // reading changed fgetc to read idk
 	    if(ch != '\n'){
		strncat(appendString, &ch, 1);
	    }
	    // appending whatever is in ch to string
	}
	fclose(myFile);

	// get the first token, tokenization of string into parts and put into array

	const char s[2] = " ";
	char* token;

	token = strtok(appendString, s);

	while(token != NULL) {
	    strcpy(charArray[len], token);
	    len++;

	    token = strtok(NULL, s); 
	}

    }
    else if (argc > 2) {
	for(int i = 0; i<argc-1; i++) {
	    strcpy(charArray[i], argv[i+1]); 
	}
    }

    for(int i = 0; i < len; i++) {
	while(strlen(charArray[i]) < 8) {
	    strcpy(charArray[i], appendZero(charArray[i]));
	}
    }

    printf("\n");

    printf("Original ASCII    Decimal  Parity\n");
    printf("-------- -------- -------- --------\n");
    for(i=0; i<len; i++) {
	printf("%s\t", charArray[i]);
        if(i != 0) {
	    decimalNum += pow(2, base); 
	}
	printf("A\t");
	for(int j=0; j<8; j++) {

     	    if(charArray[i][j] == '1') {
	        numOfOnes++;
		base--;
	    }
	}
	printf("%d ", decimalNum);
 	if(numOfOnes%2) {
	    printf("\tODD");
	}
	else {
	    printf("\tEVEN");
	}
        numOfOnes = 0;
	decimalNum = 0;
	printf("\n");
    }



    return(0);
 }

char* appendZero (char* inputString) {

    while(strlen(inputString) < 8) {
	strncat(inputString, "0", 1);
    }

    return inputString;
}

