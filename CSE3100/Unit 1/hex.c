//In this assignment, we write code to convert decimal integers into hexadecimal numbers
//We pratice using arrays in this assignment
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//convert the decimal integer d to hexadecimal, the result is stored in hex[]
void dec_hex(int d, char hex[])
{
	char digits[] ={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B',
					'C', 'D', 'E', 'F'};

	int k = 0;
	//Fill in your code below
	//It should not be hard to obtain the last digit of a hex number
	//Then what?
	//If we are getting the digits in a reverse order, what should we do in the end?
	int i = 1; 
	int temp;
	char temp_hex[80];
	temp_hex[0] = '\0';
	
	while ( d != 0) {
		temp = d % 16;
		temp_hex[i++] = digits[temp];
		d /= 16;
	}
	
	for(k = 1; k <= i; k++) {
	       hex[k] = temp_hex[i-k];
	}	       
	//Make sure the last character is a zero so that we can print the string correctly
		
}

// Do not change the code below
int main()
{
	int d;
	char hex[80];
	
	printf("Enter a positive integer : ");
	scanf("%d", &d); 
	dec_hex(d, hex);
	printf("0x%s\n", hex);
	return 0;
}

