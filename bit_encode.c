#include <stdio.h>

/* Dakota Getty */

/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE 
** WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS 
** FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR 
** OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE 
** OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.*/ 

/* This program is an 8-bit cipher that has the ability to produce up to 200 characters in ciphered 
** hexadecimal text based upon user entered data along with a 4-bit binary code from the user. */

int main(void)
{
	char message[200];			/* Delared space for the inputted message. */
	char encrypted[200];			/* Declared space for the encrypted message. */
	int maxEntries = 200;			/* Maximum number of user inputted characters. */
	int i;					/* Control integer variable used in for loop to track number of entries. */
	int interval = 0;			/* Integer variable to track number of hexadecimal values printed per line. */
	int returnValue;			/* Declared to hold each individual inputted char from getchar(). */
	char key[4];				/* Declared space for the inputted 4-bit key. */

	int encode_key = 0x00;			/* Integer variables that will deterime which bit to activate from the 4-bit key. */
	int encode_key0 = 0x00;	
	int encode_key1 = 0x00;	
	int encode_key2 = 0x00;	
	int encode_key3 = 0x00;	
	
	const int xorEmpty = 0x00;		/* Integer constants to help turn the 4-bit to an 8-bit key. */
	const int xorConstant0 = 0x11;	
	const int xorConstant1 = 0x22;	
	const int xorConstant2 = 0x44;
	const int xorConstant3 = 0x88;
	
#ifdef PROMPT 
	printf("Enter clear text to be ciphered within a size of 200:\n");
#endif
	/* Read input from user character by character. */
	for (i = 0; i < maxEntries; i++){
		returnValue = getchar();
		if (returnValue == '\n'){	/* Catches if user enters less than 200 characters. */
			maxEntries = i;
			break;
		}
		message[i] = (char)returnValue;
	}
	
	if (maxEntries == 200){
		getchar();			/* Removes the '\n' from the input to avoid conflict with input for 4-bit key. See README #3 for more detail. */	
	}

	/* Outputs the user entered text and hexadecimal equivalant values only if PROMPT is defined. 
	** The 4-bit key is also requested within the ifdef. */

#ifdef PROMPT 
	printf("Text Entered: ");

	for (i = 0; i < maxEntries; i++){
		printf("%c", message[i]);
	}

	printf("\nHex encoding is as follows... \n");
	
	for (i = 0 ; i < maxEntries; i++){
		printf("%02x " , message[i]);
		interval++;
		if (interval == 10) {
			interval = 0;
			printf("\n");
		}
	}

	printf("\nEnter a 4 bit key: ");

#endif

	/* A series of if-statements are used to take in the 4-bit key and turn it into an 8-bit key.
	** Each statement checks an input character for a 1 or 0 and assigns an empty integer variable 
	** which represents the bits: 0 and 4, 1 and 5, 2 and 6, or 3 and 7.  */

	if (key[0] = getchar() == '1'){
		encode_key3 = xorConstant3;				
	}
	if (key[1] = getchar() == '1'){
		encode_key2 = xorConstant2;				
	}
	if (key[2] = getchar() == '1'){
		encode_key1 = xorConstant1;				
	}
	if (key[3] = getchar() == '1'){
		encode_key0 = xorConstant0;				
	}

	/* The biwtwise XOR operator is used to activate whichever bits were previously activated by the
	** above if-statements and assign it to one integer variable. */

	encode_key = encode_key3 ^ encode_key2 ^ encode_key1 ^ encode_key0;	

	for (i = 0; i < maxEntries; i++){
		encrypted[i] = message[i] ^ encode_key;
	}

	/* Cipher text is printed. Format of output depends on PROMPT definition. If PROMPT is defined, hex
	** numbers are printed in rows of 10, otherwise all on one line. */

#ifdef PROMPT
	printf("Hex cipher is as follows... \n");

	interval = 0;
	for (i = 0 ; i < maxEntries; i++){
		printf("%02x " , encrypted[i]);
		interval++;
		if (interval == 10) {
			interval = 0;
			printf("\n");
		}
	}
#else
	for (i = 0 ; i < maxEntries; i++){
		printf("%02x " , encrypted[i]);
	}
#endif
}	
