#include <stdio.h>
#include <stdlib.h>
/*Program should be able to do the following to achieve full marks:
	- Encrypt a message using a rotation cipher given the message text and rotation amount
	- Decrypt a message using a rotation cipher given cipher text and rotation amount
	- Encrypt a message using a substitution cipher given message text and alphabet substitution
	- Decrypt a message encrypted using a substitution cipher given cipher text and substitutions
	- Decrypt a message encrypted using a rotation cipher given cipher text only
	- Decrypt a message encrypted with a subtitution cipher given cipher text only
*/

/*Function Headers
const char encryptRotation(char *input[]);
*/
void rotationEncryption(int cipher);
void substitutionEncryption();
void substitutionDecryption(int option, char str1[]);
char * rotationDecryption();
int mostCommonLetter();
int rotationCipherCalculator(int option, int a);
char *stringMakerOutput();
int wordChecker(); //returns 1 if the decrypted cipher creates a common word such as 'and' or 'the'
int readCipher();
int writeCipher(int option);
void plainTextWriter();
void writeKey();
int duplicateChecker(char * someString);
int subAnalysis();
int subWordComparison();
int randomNumber();
char *keyModifier(int option, char str[]);
char *subAnalysis2();
int keyLengthCheck(char key[]);
void keyCaseChange();
int run();
void rotEncChoice(char choice);
void rotDecChoice(char choice);
void subEncChoice(char choice);
void subDecChoice(char choice);
void unRotDecrypt();
void unSubDecrypt();
int *stringCount(char str[]);
void mainMenu();
void menu1();
void menu2();
void menu3();
void menu4();
char getChar();
int getNumber();

/*----------------------------------------------------------------------------------------------------------------------------------*/
int main()
{
	//variable used to control the loop, as the run function returns 0 when the user opts to finish
	int end = 1;
	//while(run()) could also work
	//run function is called repeatedly until user selects an option in the run() function that returns 0
	while(end != 0)
	{
		end = run();
	}

	return 0;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*Function returns 0 when the user opts to stop running, otherwise it runs in a continuous loop. The switch statement is used to 
control and call the various options available to the user, which are then called as their own individual functions. This was done 
to help reduce the density of the code in this particular function, as when the menu's and other extraneous lines were included the
code was quite long and difficult to read.
/*----------------------------------------------------------------------------------------------------------------------------------*/
int run()
{
	// choice used to control switch statement, end used to determine whether or not code will continue to run at end of loop
	int choice = 8, end;
	// stores users secondary choice as char a,b,c or d
	char secChoice = 0;

	//calls the function that displays the list of options available to the user
	mainMenu();
	
	//ensures that the while loop will initially execute, do while could also have been used
	end = 1;
	while (end != 0)
	{
		printf("Please select the corresponding number for the function you wish to use: ");
		//calls the function getNumber(), which will then store an int from stdin in choice. No strictly necessary as
		//scanf("%d", &choice could also have been used, but I thought it was a good opportunity to play around with various functions
		//that serve a relatively simple purpose
		choice = getNumber();
		//If the number entered by the user doesn't correspond to an option, the while loop will kick in and prompt the user to enter
		//in their preference again
		while (choice < 0 || choice > 7)
		{
			printf("There was an issue with your choice, please select the corresponding number for the function you wish to use: ");
			choice = getNumber();
		}
		//switch statement that will perform an action based on the preference the user entered earlier. For instance, selecting 1 will
		//run case 1, showing a submenu and then performing 1 of 4 variations to rotation encryption based on the users preference
		switch(choice) 
		{
			case 0:
				//sets end = to 0, redundant however as the return 0 should cause execution to break out of function and return to main
				end = 0;
				return 0;
			case 1:
				//This should call the function that will be used to encrypt rotation cipher
				//calls function menu1 which displays the various options for rotation encryption
				menu1();
				//user enters a char a,b,c or d which is then stored in secChoice
				secChoice = getChar();
				//If the value entered by user doesn't correspond with one listed above, user will be prompted to re-enter char until
				//a valid value is entered
				while (secChoice < 97 || secChoice > 100)
				{
					printf("Please enter a valid option\n");
					secChoice = getChar();
				}
				//calls another function containing a switch statement which calls functions relating specifically to rotation encryption
				//the variable secChoice is passed as an argument to the function and determines which case the function carries out
				rotEncChoice(secChoice);
				//stringMakerOutput() reads the contents of the encrypted file and stores it in char array, which is then returned at
				//the end of the function and can then be printed using statement below
				printf("\nThe resulting string is: '%s'", stringMakerOutput());
				//end is set to 1 to ensure that the program continues in the while loop after exiting th switch statement
				end = 1;
				break;
			case 2:
				//This should call the function that will be used to decrypt rotation cipher
				//calls function menu2 which displays the various options for rotation decryption
				menu2();
				//user enters a char a,b,c or d which is then stored in secChoice
				secChoice = getChar();
				//If the value entered by user doesn't correspond with one listed above, user will be prompted to re-enter char until
				//a valid value is entered
				while (secChoice < 97 || secChoice > 100)
				{
					printf("\nPlease enter a valid option:");
					scanf("\n%c", &secChoice);
				}
				//calls another function containing a switch statement which calls functions relating specifically to rotation decryption
				//the variable secChoice is passed as an argument to the function and determines which case the function carries out
				rotDecChoice(secChoice);
				//stringMakerOutput() reads the contents of the encrypted file and stores it in char array, which is then returned at
				//the end of the function and can then be printed using statement below
				printf("\nThe resulting string is: '%s'", stringMakerOutput());
				end = 1;
				break;
			case 3:
				//This should call the function that will be used to encrypt substitution cipher
				menu3();
				secChoice = getChar();
				while (secChoice < 97 || secChoice > 100)
				{
					if (secChoice < 97 || secChoice > 100)
					{
						printf("\nPlease enter a valid option:");
						scanf("\n%c", &secChoice);
					}
					else 
						break;
				}
				subEncChoice(secChoice);

				printf("\nThe resulting string is: '%s'", stringMakerOutput());
				end = 1;
				break;
			case 4:
				//This should call the function that will be used to decrypt substitution cipher
				menu4();
				secChoice = getChar();
				while (secChoice < 97 || secChoice> 100)
				{
					if (secChoice < 97 || secChoice > 100)
					{
						printf("\nPlease enter a valid option:");
						scanf("\n%c", &secChoice);
					}
					else 
						break;
				}
				subDecChoice(secChoice);
				printf("\nThe resulting string is: '%s'", stringMakerOutput());
				end = 1;
				break;
			case 5:
				unRotDecrypt();
				printf("\nThe resulting string is: '%s'\n", stringMakerOutput());
				end = 1;
				break;
			case 6:
				//This should call the functions required to decrypt an unknown substitution cipher
				unSubDecrypt();
				printf("\nThe resulting string isL '%s'\n", stringMakerOutput());
				end = 1;
				break;
			case 7:
				mainMenu();
				end = 1;
				break;
			default:
				//This will happen if user doesn't select an option from 1 to 4 or something else goes wrong
				printf("Something went wrong. You entered %d. Please enter 1, 2, 3, 4, 5 or 6 or cry because something is broken\n");
				scanf("%d", &choice);
				return 0;
		}
	}
	return 0;
}	
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*mainMenu() function is used to send the main menu with user preferences to be displayed in the console. It takes no arguments and
doesn't return anything, as it's purpose is only to reduce the size of the run() function and increase the portability of the menu
throughout the code. This means that the menu can now be called anywhere with one line of code, rather than having to retype the whole
menu*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
void mainMenu()
{	
	printf("Available functions\n");
	printf("	(1) Encrypt message using Rotation Cipher\n");
	printf("	(2) Decrypt message using Rotation Cipher\n");
	printf("	(3) Enccypt message using Substitution Cipher\n");
	printf("	(4) Decrypt message using Substitution Cipher\n");
	printf("	(5) Decrypt message using unknown rotation cipher\n");
	printf("	(6) Decrypt message using unknown substitution cipher\n");
	printf("	(7) Show Options\n");
	printf("	(0) End\n");
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*menu1() shares a similar purpose to mainMenu() and is intended to simply display a list of possible options to the user*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
void menu1()
{
	printf("\nYou selected 'Encrypt Rotation Cipher' You can choose from the following options:\n");
	printf("	(a) Read plain text from 'input.txt' and cipher key from 'cipher.txt'\n");
	printf("	(b) Read plain text from 'input.txt' and cipher key from stdin\n");
	printf("	(c) Read plain text from stdin and cipher key from 'cipher.txt'\n");
	printf("	(d) Read plain text and cipher key from stdin\n");
	printf("\nPlease enter a letter corresponding to your preference: ");	
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*menu2() shares a similar purpose to mainMenu() and is intended to simply display a list of possible options to the user*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
void menu2()
{
	printf("\nYou selected 'Decrypt Rotation Cipher' You can choose from the following options:\n");
	printf("	(a) Read plain text from 'input.txt' and cipher key from 'cipher.txt'\n");
	printf("	(b) Read plain text from 'input.txt' and cipher key from stdin\n");
	printf("	(c) Read plain text from stdin and cipher key from 'cipher.txt'\n");
	printf("	(d) Read plain text and cipher key from stdin\n");
	printf("Please enter a letter corresponding to your preference:");
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*menu3() shares a similar purpose to mainMenu() and is intended to simply display a list of possible options to the user*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
void menu3()
{
	printf("Encrypt Substitution Cipher");
	printf("\nYou selected 'Encrypt Substituion Cipher' You can choose from the following options:\n");
	printf("	(a) Read plain text from 'input.txt' and cipher key from 'key.txt'\n");
	printf("	(b) Read plain text from 'input.txt' and cipher key from stdin\n");
	printf("	(c) Read plain text from stdin and cipher key from 'cipher.txt'\n");
	printf("	(d) Read plain text and cipher key from stdin\n");
	printf("Please enter a letter corresponding to your preference:");	
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*menu4() shares a similar purpose to mainMenu() and is intended to simply display a list of possible options to the user*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
void menu4()
{
	printf("Decrypt Substitution Cipher");
	printf("\nYou selected 'Decrypt Substituion Cipher' You can choose from the following options:\n");
	printf("	(a) Read text from 'input.txt' and cipher key from 'key.txt'\n");
	printf("	(b) Read text from 'input.txt' and cipher key from stdin\n");
	printf("	(c) Read text from stdin and cipher key from 'cipher.txt'\n");
	printf("	(d) Read text and cipher key from stdin\n");
	printf("Please enter a letter corresponding to your preference:");
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*getNumber() retrieves an int from stdin and stores it in the variable number, which is then returned at the end of the function*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
int getNumber()
{
	//contains the integer entered by the user, which is then returned at the end of the function
	int number;
	//reads an int from console and stores it in number
	scanf("%d", &number);
	return number;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*getChar() retrieves a char from stdin and stores it in the variable character, which is then returned at the end of the function*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
char getChar()
{
	//contains the char entered by the user, which is then returned at the end of the function
	char character;
	//reads a char from console and stores it in character
	scanf("%s", &character);
	return character;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*rotEncChoice takes a char, intended to be a,b,c or d, as an argument and calls a function based on that char. This function
controls which variation of rotation encryption is completed. It does not have a return value, as any work done is stored in input, 
output or cipher files*/ 
/*----------------------------------------------------------------------------------------------------------------------------------*/
void rotEncChoice(char choice)
{
	//stores the integer that is passed as an argument to the function in case 98 and 100
	int cipher;
	switch (choice)
	{
		case 97:
			//this option reads both the text to be encrypted and the cipher from input.txt and cipher.txt respectively
			//readCipher() returns an integer from file cipher.txt, which is then passed to rotationEncryption() and used to encrypt
			//the text stored in input.txt
			rotationEncryption(readCipher());
			break;
		case 98:
			//this option allows the user to specify the cipher via stdin using the function writeCipher() and text via input.txt
			//1 is passed as an argument to writeCipher to control what the function prints to the screen if another number was used
			//it would ask for the cipher to be used to decrypt rather than encrypt text
			cipher = writeCipher(1);
			//calls the rotation encryption function which reads the text from input.txt, and encrypts it using the cipher which is 
			//passed as an argument of the function
			rotationEncryption(cipher);
			break;
		case 99:
			//this option allows user to specify the text that they would like to encrypt via the console, and cipher via cipher.txt
			//plainTextWriter() asks user to input the text that they wish to encrypt. It then writes the string input by the user to input.txt
			//where it can then be read by the rotation encryption function
			plainTextWriter();
			//behaves as in case 97 above, reading cipher from cipher.txt and text to encrypt from input.txt, which was just written
			//to by plainTextWriter()
			rotationEncryption(readCipher());
			break;
		case 100:
			//This option allows the user to specify the cipher and the text that they would like to encrypt via the console
			//plainTextWriter() asks user to input the text that they wish to encrypt. It then writes the string input by the user to input.txt
			//where it can then be read by the rotation encryption function
			plainTextWriter();
			//writeCipher(1) asks the user for the cipher that they would like to use to encrypt a piece of text. It is then returned
			//as an integer and stored in cipher, which can then be passed as an argument to rotationEncryption()
			cipher = writeCipher(1);
			//calls the rotation encryption function which reads the text from input.txt, and encrypts it using the cipher which is 
			//passed as an argument of the function
			rotationEncryption(cipher);
			break;
		default:
			//Prints to the screen if one of the above options was not passed to the function. There are multiple steps in place
			//to prevent this from happening, but you never know, and it's helpful to have some kind of output that can be traced
			//rather than simply have nothing happen.
			printf("Something went wrong");
			break;
	}
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*rotDecChoice takes a char, intended to be a,b,c or d, as an argument and calls a function based on that char. This function
controls which variation of rotation decryption is completed. It does not have a return value, as any work done is stored in input, 
output or cipher files. The rotationEncryption() function is reused as a rotation cipher can be decrypted following the same process
as encryption, but by reversing the sign of the cipher used during encryption*/ 
/*----------------------------------------------------------------------------------------------------------------------------------*/
void rotDecChoice(char choice)
{
	int cipher;
	switch(choice)
	{
		case 97:
			//case97 takes both the text to be decrypted and the cipher from input.txt and cipher.txt
			//the negative sign is placed in front of readCipher() to reverse the direction of the shift, hence decrypting the text
			rotationEncryption(-readCipher());
			break;
		case 98:
			//case98 allows the user to specify the cipher that was used to encrypt the text, while the text is read from input.txt
			//2 is passed as an argument of writeCipher() to ensure that the correct string is printed to the console, and that the
			//cipher is set to have the opposite sign of the original sign, thus allowing decryption
			cipher = writeCipher(2);
			//cipher is passed as an argument to rotationEncryption, text is read from input.txt, cipher doesn't need to be modified
			//as sign has already been set
			rotationEncryption(cipher);
			break;
		case 99:
			//case99 allows the user to specify the text that is being decrypted through stdin
			//plainTextWriter takes user input and stores it in input.txt, where it can then be read by rotationEncryption()
			plainTextWriter();
			//negative sign placed in argument for same reason as case97
			rotationEncryption(-readCipher());
			break;
		case 100:
			//case100 allows the user to specify both the text and cipher that will be used via stdin using writeCipher() and
			//plainTextWriter() as explained above
			cipher = writeCipher(2);
			plainTextWriter();
			//rotationEncryption carries out 'encryption' using cipher of opposite sign specified with writeCipher(2) and passed
			//as an argument to the function, thus decrypting the text.
			rotationEncryption(cipher);
			break;
	}
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*subEncChoice takes a char, intended to be a,b,c or d as an argument and calls a function based on that char. This function 
controls which variation of substitution encryption is completed. It does not have a return value, as any string manipulation is 
stored in input.txt, output.txt and key.txt, where it can then be read and manipulated by other functions as required.*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
void subEncChoice(char choice)
{
	//switch statement controls which function is called based on user input, which is passed to the function as an argument
	switch(choice)
	{
		//case97 results in the text to be encrypted and the key being used to be read from input.txt and key.txt respectively
		case 97:
			//substitutionEncryption()calls the function that carries out substitution encryption, while the argument of 1 specifies
			//that only a key/file and case check be carried out (see function for more)
			substitutionEncryption(1);
			break;
		//case98 results in the text to be encrypted being read from key.txt, and the key being read from stdin
		case 98:
			//same as 97, however, argument of 2 causes substitutionEncryption() to call another function that enables
			//the user to input a key (see function for more)
			substitutionEncryption(2);
			break;
		//case99 results in the text to be encrypted being read from stdin and the key being read from key.txt
		case 99:
			//same as 97, however, argument of 3 causes substitutionEncryption() to call another function that enables
			//the user to input plain text, which can then be encrypted (see function for more)
			substitutionEncryption(3);
			break;
		//case100 results in the text to be encrypted and the key being used to be read from stdin
		case 100:
			//same as 97, however, argument of 4 causes substitutionEncryption() to call functions that enable the user
			//to input key and plain text, as in case 98 and 99 respectively, before carrying out encryption (see function for more)
			substitutionEncryption(4);
			break;
	}
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*sunDecChoice takes a char, intended to be a,b,c or d as an argument and calls a function based on that char. This function
controls which verions of substitution decryption is completed. It does not have a return value, as any string manipulation is
stored in input.txt, output.txt or ket.txt, where it can then be read and manipulated by other functions as required.*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
void subDecChoice(char choice)
{
	switch(choice)
	{
		//case97 results in the text to be decrypted and the key being used to be read from input.txt and key.txt respectively
		case 97:
			//substitutionDecryption() calls the function that carrious out substitution decryption. The argument of 1 specifies
			//that only a key/file and case check be carried out, while the char array is left empty, as it isn't when the int
			//argument of the function is equal to 1. For more details see function
			substitutionDecryption(1, "");
			break;
		//case98 results in the text to be decrypted being read from input.txt and the key being read from stdin
		case 98:
			//argument of 2 specifies that key will be read from stdin using a function called within substitutionDecryption()
			//otherwise same as outlined above
			substitutionDecryption(2,"");
			break;
		//case99 results in the text to be decrypted being read from stdin and the key being read from ket.txt
		case 99:
			//argument of 3 specifies that text will be read from stdin using a function called within substitutionDecryption()
			//otherwise same as outlined above
			substitutionDecryption(3,"");
			break;
		//case100 results in the text to be decrypted and the key being used to be read from stdin
		case 100:
			//argument of 4 specifies that text and key will be read from stdin using functions called within substitutionDecryption()
			//otherwise same as outlined above
			substitutionDecryption(4,"");
			break;
	}
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*unRotDecrypt is the function called when a user specifies that they wish to complete rotation decryption on a piece of text in
for which the key is unknown. Analysis is carried out on the text to determine the most common letter. It is then assumed that this
letter is e and the rotation is calculated accordingly. A cipher of the opposite sign is calculated and decryption is completed.
The resulting string is then checked for common words, and if none are found, moves on to another key using rotationCipherCalculator()
, testing each one until text is produced that matches with common words. A result of 1 is then returned and the loop ends and 
decryption is complete./
/*----------------------------------------------------------------------------------------------------------------------------------*/
void unRotDecrypt()
{
	/*declaration of int variables used in function:
	 - m stores the result of calling mostCommonLetter(), which analyses text for the most common letter, e.g. a = 97
	 - cipher stores the cipher that will be passed as an argument to rotationEncryption()
	 - result stores the return value of wordChecker(), which is used to control the loop that repeats the process until decryption
	   is complete
	 - counter stores the number of times decryption has been attempted, and is passed as an argument to rotationCipherCalculator()
	   to help generate a value for cipher*/
	int m, cipher, result = 0, counter = 0;
	/*mostCommonLetter is called, with it's return value stored in m. This is then passed as an argument to rotationCipherCalculator()
	to help determine the initial value for cipher. Once the loop below has run once, m becomes redundant.*/
	m = mostCommonLetter();
	/*while loop that will repeat the decryption process until the text is identified as having been decrypted (result = 1), or all 
	possible cipher values (positive and negative) that can be generated by rotationCipherCalculator(see function for more info)
	have been tested*/
	while (result != 1 && counter < 52)
	{
		//rotationCipherCalculator() is called. Counter controls which cipher key is returned, while m helps generate the key
		cipher = (-1) * rotationCipherCalculator(counter, m);
		//decryption is carried out using cipher generated above
		rotationEncryption(cipher);
		/*the resulting string is tested. If it contains common english words, a value of 1 is returned which will end loop, otherwise
		0 is returned and loop will continue to run*/
		result = wordChecker();
		//counter is incremented to ensure that cipher value changes after each iteration of loop. Also assists with flow control
		counter++;
	}	
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
void unSubDecrypt()
{
	int score;
	subAnalysis();
	substitutionDecryption(1, "");
	score = subWordComparison();
	char *str1 = subAnalysis2();
	substitutionDecryption(0, str1);
	if (score < subWordComparison())
	{
		FILE *key = fopen("key.txt", "w");
		fprintf(key,"%s", str1);
		fclose(key);
	}
	printf("str1 = %s\n", str1);
	for (int n = 0; n < 10; n++)
	{
		char * str = keyModifier(0, str1);
		printf("str = %s\n", str);
		substitutionDecryption(0, str);
		//score = subWordComparison();
		if (score < subWordComparison())
		{
			for (int k=0; str[k] != 0; k++)
			{
				str1[k] = str[k];
			}
			printf("str1 = %s\n", str1);
		}
	}
	FILE *key = fopen("key.txt", "w");
	fprintf(key, "%s", str1);
	fclose(key);
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*rotationEncryption() is the function that performs the encryption and decryption of a piece of text. It reads the text to be
encrypted/decrypted from input.txt and writes it to output.txt, while the cipher is passed to the function as an argument.
/*----------------------------------------------------------------------------------------------------------------------------------*/
void rotationEncryption(int cipher)
{
	/*declaration of files that are used in the function, names are kept the same as file names for clarity. The text being encrypted
	is read from input, and once encrypted is written to output*/
	FILE *input;
	FILE *output;
	//opens the file input.txt, with read only permissions
	input = fopen("input.txt", "r");
	//opens the file output.txt with write only permissions, this deletes anything already in the file
	output = fopen("output.txt", "w");
	//variable used to control the while loop below
	int end = 0;
	//stores a single character from input.txt at a time, which is then modified and written to output.txt
	char str;
	//printf("%d\n", cipher);
	/*ensures that the loop continues to run until fgetc(input) reaches the end of the file, causing str to equal EOF, thus entering
	the if statement, setting the end equal to 1 resulting in the end!=1 becoming false, thus ending the while loop*/
	while (end != 1)
	{
		/*fgetc(input) retrieves a single char from input and stores it in str. With each iteration of the loop the char retrieved
		will move forward one space, thus ensuring the same char isn't retrieved an infinite number of times*/
		str = fgetc(input);
		/*if fgetc(input) is found to have reached the end of the file, then str will equal EOF, thus triggering the if statement,
		setting end equal to 1 and breaking out of the loop*/
		if(str == EOF)
		{
			end = 1;
			break;
		}
		else
		{
			/*if statement is triggered if the char read from input is a lower case letter, as they fall between the ASCII decimal
			range of 97 and 122(a = 97, z = 122). All other characters, such as spaces, apostrophes etc. are ignored*/
			if (str > 96 && str < 123)
			{
				/*subtracting 32 from ASCII character in range above will return the same character but in upper case as required
				in assessment specifications(a=97, A = 65)*/
				str = str - 32;
			}
			/*if statement is triggered if the char str is an upper case letter, as the fall between ASCII decimal range of 65 to 90.
			All other characters, such as spaces, apostrophes etc. are ignred and will be written to output without being modified*/
			if (str > 64 && str  < 91)
			{
				//adding the cipher value to str results in the str value changing, so A + 3 = D i.e. 97 + 3 = 100
				str = str + cipher;
				/*if the resulting value is greater than 90 it will not return a letter of the alphabet, so 26 must be subtracted
				so that the value will cycle back to the front of the alphabet. e.g. Z + 3 = ] i.e. 90 + 3 = 93. because the value
				is greater than 90, 26 is subtracted, so the initial Z+3 becomes Z + 3 - 26 = C i.i. 90 + 3 - 26 = 67*/
				if (str > 90)
					str = str - 26;
				/*same principal as if statement above, but in reverse, so that if cipher causes a number to go below 65, 26 will
				be added to return it to the end of the alphabet. e.g. A - 3 = >, A - 3 + 26 = X*/
				else if (str < 65)
					str = str + 26;
			}
		}
		/*writes the character stored in str to output. each iteration the written character is moved forward one place by the
		function, otherwise only one character would ever be written to the file*/ 
		fputc(str, output);
	}
	//input and output are closed to prevent any issues with opening and reading/writing from them when other functions are called
	fclose(input);
	fclose(output);
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*substitutionEncryption() is the function that performs the encryption of a piece of text read from input.txt using a key read from
key.txt and writes the result to output.txt. User's are able to write to key.txt and input.txt using functions that can be called
based on the argument that is given to substitutionEncryption() when it is called. The necessary files are only opened once user
input has been taken, if required.*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
void substitutionEncryption(int option)
{
	/*char array key is used to store the key that will be used when encrypting the string after being read from key.txt, while str
	stores a single character from input.txt at a time*/
	char key[27], str;// = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','\0'};
	/*declaration of the three files that are required for encryption. Input holds the text that will be encrypted, output is where
	the encrypted text will be written to and key holds the key used to encrypt the text from input*/
	FILE *input;
	FILE *output;
	FILE *keyText;
	/*end is stores the value that is used to determine whether or not the various loops will continue to run*/
	int end = 1;
	
	/*while loop will run until functions keyLengthCheck() and duplicateChecker() only return 0, which will result in end = 0, thus
	causing the loop to exit*/
	while (end != 0)
	{
		/*switch statement could have been used as well. Following if statements take the argument passed to the function when it
		was initially called, and performs an action based on that function*/
		/*option = 1 means the user opted to read text and key from a file, and therefore only keyCaseChange() is called*/
		if (option == 1)
		{
			//function reads the contents of key.txt and converts any lower case letters to upper case
			keyCaseChange();
		}
		/*option = 2 means the user opted to read text from file and key from stdin*/
		else if (option == 2)
		{
			/*writeKey() enables user to reads key from console and stores it in key.txt, where it can then be manipulated by other
			functions. Key caseChance() is not required as writeKey() checks user input to ensure it contains no capitals before
			writing it to key.txt*/
			writeKey();
		}
		/*option = 3 means the user opted to read key from key.txt and the text to be encrypted from console*/ 
		else if (option == 3)
		{
			/*calling plainTextWriter() prompts the user to enter the text that they would like to encrypt/decrypt. It then stores
			the result in input.txt which can then be read by substitutionEncryption() later in the function*/
			plainTextWriter();
			//function reads the contents of key.txt and converts any lower case letters to upper case
			keyCaseChange();
		}
		/*option 4 means the user opted to read key and text from console*/
		else if (option == 4)
		{
			/*calling plainTextWriter() prompts the user to enter the text that they would like to encrypt/decrypt. It then stores
			the result in input.txt which can then be read by substitutionEncryption() later in the function*/
			plainTextWriter();
			/*writeKey() enables user to reads key from console and stores it in key.txt, where it can then be manipulated by other
			functions. Key caseChance() is not required as writeKey() checks user input to ensure it contains no capitals before
			writing it to key.txt*/
			writeKey();
		}
		/*opens the file key.txt with read only privileges*/
		keyText = fopen("key.txt", "r");
		/*fscanf() reads from keyText and stores the string in key. %s was only used as there are no spaces in key that generally
		seem to cause havoc when reading strings*/
		fscanf(keyText, "%s", key);
		/*keyLengCheck takes the key as an argument and returns 0 if it has 26 characters, while duplicateChecker() takes key as 
		an argument and returns 0 if it only contains one of each character, else both functions will return 1*/
		end = keyLengthCheck(key) + duplicateChecker(key);
		fclose(keyText);
		/*if an issue was found with key, if statement will be triggered prompting the user to re-enter the key via the console.
		The writeKey() function won't exit until a valid key is entered, which will then be written to key.txt.*/
		if (end != 0)
		{
			printf("There is something wrong with the key, please enter a new key\n");
			writeKey();
		}
	}
	//prints the key being used to console
	printf("The key being used is %s\n", key);
	//opens input.txt with read only permissions and output.txt with write only permissions
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	//end is set back to 1 to ensure that the loop will initially run
	end = 1;
	while(end != 0)
	{
		//reads a character from input and stores it in str, each iteration of loop moves on to the next character input
		str = fgetc(input);
		//once fgetc reaches end of file, if statement will trigger and will break out of loop
		if (str == EOF)
		{
			end = 0;
			break;
		}
		//identifies if str is lower case, and subtracts 32 to set str to the same letter, but upper case as per assessment spec. 
		else if (str > 96 && str < 123)
		{
			str = str - 32;
		}
		/*this switch controls the encryption of each character. It takes str and looks at it's decimal value, then assigns str
		a value from the key array based on what the value is.
		Key memory location 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
		input value         a b c d e f g h i j k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
		In other words if str = a, it will be assigned the value of the char stored in key[0], k = key[10] and so on until the 
		end of the string is reached. Any value that is not a part of the alphabet is left unmodified*/
		switch (str)
		{
			case 65:
				str = key[0];
				break;
			case 66:
				str = key[1];
				break;
			case 67:
				str = key[2];
				break;
			case 68:
				str = key[3];
				break;
			case 69:
				str = key[4];
				break;
			case 70:
				str = key[5];
				break;
			case 71:
				str = key[6];
				break;
			case 72:
				str = key[7];
				break;
			case 73:
				str = key[8];
				break;
			case 74:
				str = key[9];
				break;
			case 75:
				str = key[10];
				break;
			case 76:
				str = key[11];
				break;
			case 77:
				str = key[12];
				break;
			case 78:
				str = key[13];
				break;
			case 79:
				str = key[14];
				break;
			case 80:
				str = key[15];
				break;
			case 81:
				str = key[16];
				break;
			case 82:
				str = key[17];
				break;
			case 83:
				str = key[18];
				break;
			case 84:
				str = key[19];
				break;
			case 85:
				str = key[20];
				break;
			case 86:
				str = key[21];
				break;
			case 87:
				str = key[22];
				break;
			case 88:
				str = key[23];
				break;
			case 89:
				str = key[24];
				break;
			case 90:
				str = key[25];
				break;
			case 91:
				str = key[26];
				break;
			default:
				break;
				str = str;
		}
		//stores the modified value of str in output (writes it to ouput.txt), moving forward after each iteration
		fputc(str, output);	
	}
	//close the files used to prevent any conflict if other functions need to manipulate them in any way
	fclose(input);
	fclose(output);
	fclose(keyText);
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*substitutionDecryption() is the function that performs the decryption of a piece of text, reading the text to be decrypted from
input.txt, the key to be used from key.txt and writing the resulting text from decryption to output.txt. An integer is taken as an
argument to control different variations of the function, such as allowing the user to enter the key via console, and a char array
can also be passed as an argument and decrypted based on which option is chosen. At the time of writing this a full char array is
only passed to the function during the proces of decrypting an unknown piece of text encrypted with a substitution cipher*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
void substitutionDecryption(int option, char str1[])
{
	//char arrays key and atr are used to store the key used to decrypt the text and the string being decrypted respectively
	char key[27], str[10000]; //= {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','\0'};
	//declaration of file pointers used, input will point to input.txt, output to output.txt and keyText to keyText.txt
	FILE *input;
	FILE *output;
	FILE *keyText;
	/*integers n and k are used incrementing values during for loops, while end holds the value that determines whether or not the
	while loop continues to run*/
	int n = 0, k = 0, end = 1;
	/*switch statement could have been used as well. Following if statements take the integer argument passed to the function when it
	was initially called, and performs an action based on that integer*/
	/*option = 1 means the user opted to read text and key from a file, and therefore only keyCaseChange() is called*/
	if (option == 1)
	{
		//function reads the contents of key.txt and converts any lower case letters to upper case		
		keyCaseChange();
	}
	/*option = 2 means the user opted to read text from file and key from stdin*/
	else if (option == 2)
	{
		/*writeKey() enables user to reads key from console and stores it in key.txt, where it can then be manipulated by other
		functions. Key caseChance() is not required as writeKey() checks user input to ensure it contains no capitals before
		writing it to key.txt*/
		writeKey();
	}
	/*option = 3 means the user opted to read key from key.txt and the text to be encrypted from console*/ 
	else if (option == 3)
	{
		/*calling plainTextWriter() prompts the user to enter the text that they would like to encrypt/decrypt. It then stores
		the result in input.txt which can then be read by substitutionEncryption() later in the function*/
		plainTextWriter();
		//function reads the contents of key.txt and converts any lower case letters to upper case
		keyCaseChange();
	}
	/*option 4 means the user opted to read key and text from console*/
	else if (option == 4)
	{
		/*calling plainTextWriter() prompts the user to enter the text that they would like to encrypt/decrypt. It then stores
		the result in input.txt which can then be read by substitutionEncryption() later in the function*/
		plainTextWriter();
		/*writeKey() enables user to reads key from console and stores it in key.txt, where it can then be manipulated by other
		functions. Key caseChance() is not required as writeKey() checks user input to ensure it contains no capitals before
		writing it to key.txt*/
		writeKey();
	}
	//should only occur when performing decryption of text with unknown key
	else
	{
		//for loop takes value stored in str1[n] and stores that value in key[n] until the end of str1[n] is reached
		//This was done to troubleshoot issues that were ocurring as a result of manipulating str1 during decryption
		for (n = 0; str1[n] != 0; n++)
		{
			key[n] = str1[n];
		}
	}
	/*Opens appropriate files with write, read and read privileges as required*/
	output = fopen("output.txt", "w");
	input = fopen("input.txt", "r");
	keyText = fopen("key.txt", "r");
	/*fscanf() reads from keyText and stores the string in key. %s was only used as there are no spaces in key that generally
	seem to cause havoc when reading strings*/
	fscanf(keyText, "%s", key);
	
	//sets n back to 0 so that assignment of str[n] begins at the first memory location
	n = 0;
	//char *u = "u2026";
	/*for loop would have been appropriate, but the code was already written with a while loop before it came to be like this
	so it was just left as is and n++ was added at the bottom to ensure values were stored in str correctly*/
	//will continue loop until the end of input is reached, end = 0 and break; ensure that one way or another the loop stops
	while(end != 0)
	{
		//reads a character from input and stores it in str, each iteration of loop moves on to the next character input
		str[n] = fgetc(input);
		//once fgetc reaches end of file, if statement will trigger and will break out of loop
		if (str[n] == EOF)
		{
			end = 0;
			break;
		}
		//identifies if str is lower case, and subtracts 32 to set str to the same letter, but upper case as per assessment spec.
		else if (str[n] > 96 && str[n] < 123)
			str[n] = str[n] - 32;
		//tyring to figure out how to work with ellipsis in the unknown key substitution string
		/*else if (str[n] == 85)
		{
			str[n] = 46;
			n++;
			str[n] = 46;
			n++;
			str[n] = 46;
		}*/	
		//n is incremented so that the next character read from input will be stored in the next location in str
		n++;
	}
	/* for loop controls the implementation of decryption one character at a time. Once one character is decrypted as outlined below,
	n is incremented and the next value stored in str is decrypted until the end of str is reached*/
	for (n = 0; str[n] != 0; n++)
	{
		/*for loop cycles through all of the characters in key until one matching the current character in str is found. Once a
		match is found, the if statement will assign the current value of str to k + 65, as this will match the decrypted value
		of the character.*/
		for (k=0; key[k] != 0; k++)
		{
			if (str[n] == key[k])
			{
				str[n] = k + 65;
				break;
			}		
		}
		/*once str[n] has been assigned it's decrypted value, it is written to output
		fputc(str[n], output);*/
	}
	//close the files used to prevent any conflict if other functions need to manipulate them in any way
	fclose(input);
	fclose(output);
	fclose(keyText);
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
int mostCommonLetter()
{
	FILE *input;
	char str[2000] = {'0'};
	int n = 0, a, count = 0, end = 1;
	int *strCount;
	
	input = fopen("input.txt", "r");
		
	while(end != 0)
	{
		str[n] = fgetc(input);
		if (str[n] == EOF)
		{
			end = 0;
			break;
		}
		else if (str[n] > 96 && str[n] < 123)
			str[n] = str[n] - 32;
		n++;
	}
	//printf("%s\n", str);
	strCount = stringCount(str);
	for (n = 0; n<27; n++)
	{
		if (strCount[n] > count)
		{
			count = strCount[n];
			a = n; //holds the value in the string that corresponds to the letter in the alpahbet
			//i.e. a=0, b=1,... z=26
	    }
	}
	//printf("a=%d\n", a);
	fclose(input);
	return a;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
int rotationCipherCalculator(int option, int a)
{
	int cipher;
	
	switch (option)
	{
		case 0:
			cipher = a + 97 - 101;
			break;
		case 1:
			cipher  = 26 + 97 - 101;
			break;
		case 2:
			cipher = a + 97 - 116;
			break;
		case 3:
			cipher = 26 + 97 -116;
			break;
		case 4:
			cipher = a + 97 -114;
			break;
		case 5:
			cipher = 26 + 97 -114;
			break;
		case 6:
			cipher = a + 97 - 105;
			break;
		case 7:
			cipher = 26 + 97 - 105;
			break;
		case 8:
			cipher = a + 97 - 111;
			break;
		case 9:
			cipher = 26 + 97 - 111;
			break;
		case 10:
			cipher = a + 97 - 110;
			break;
		case 11:
			cipher = 26 + 97 -110;
			break;
		case 12:
			cipher = a + 97 - 115;
			break;
		case 13:
			cipher = 26 + 97 - 115;
			break;
		case 14:
			cipher = a + 97 - 108;
			break;
		case 15:
			cipher = 26 + 97 - 115;
			break;
		case 16:
			cipher = a + 97 - 108;
			break;
		case 17:
			cipher = 26 + 97 - 108;
			break;
		case 18:
			cipher = a + 97 - 99;
			break;
		case 19:
			cipher = 26 + 97 - 99;
			break;
		case 20:
			cipher = a + 97 - 117;
			break;
		case 21:
			cipher = 26 + 97 - 117;
			break;
		case 22:
			cipher = a + 97 - 100;
			break;
		case 23:
			cipher = 26 + 97 - 100;
			break;
		case 24:
			cipher = a + 97 - 112;
			break;
		case 25:
			cipher = 26 + 97 - 112;
			break;
		case 26:
			cipher = a + 97 - 109;
			break;
		case 27:
			cipher = 26 + 97 - 109;
			break;
		case 28:
			cipher = a + 97 - 104;
			break;
		case 29:
			cipher = 26 + 97 - 104;
			break;
		case 30:
			cipher = a + 97 - 103;
			break;
		case 31:
			cipher = 26 + 97 - 103;
			break;
		case 32:
			cipher = a + 97 - 98;
			break;
		case 33:
			cipher = 26 + 97 - 98;
			break;
		case 34:
			cipher = a + 97 - 102;
			break;
		case 35:
			cipher = 26 + 97 - 102;
			break;
		case 36:
			cipher = a + 97 - 121;
			break;
		case 37:
			cipher = 26 + 97 - 121;
			break;
		case 38:
			cipher = a + 97 - 119;
			break;
		case 39:
			cipher = 26 + 97 - 119;
			break;
		case 40:
			cipher = a + 97 - 107;
			break;
		case 41:
			cipher = 26 + 97 - 107;
			break;
		case 42:
			cipher = a + 97 - 118;
			break;
		case 43:
			cipher = 26 + 97 - 118;
			break;
		case 44:
			cipher = a + 97 - 120;
			break;
		case 45:
			cipher = 26 + 97 - 120;
			break;
		case 46:
			cipher = a + 97 - 122;
			break;
		case 47:
			cipher = 26 + 97 - 122;
			break;
		case 48:
			cipher = a + 97 - 106;
			break;
		case 49:
			cipher = 26 + 97 - 106;
			break;
		case 50:
			cipher = a + 97 - 113;
			break;
		case 51:
			cipher = 26 + 97 - 113;
			break;
		default:
			break;
	}
	return cipher;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
char *stringMakerOutput()
{
	FILE *input;
	static char str[1000];
	int n;
	
	input = fopen("output.txt", "r");	
	
	for (n = 0; n < 999; n++)
	{
		str[n] = 0;
	}	
	for (n = 0; feof(input) == 0; n++)
	{
		fscanf(input, "%c", &str[n]);
		if (str[n] == EOF)
			break;
		//printf("String Tested is %s\n", str);
	}
	//printf("String Tested is %s\n", str);
	fclose(input);
	return str;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*Function returns score relating to the suitability of a decrypted piece of text by opening two files, one containing 10000 of the 
 most common words, the other cotaining text that has just been decrypted using the decryption function above, both as read only. 
 These pieces of text are then stored in char arrays words1[100000] and str[10000] respectively. The arrays are then compared in 
 sections of up to 4 characters, with values added to the score accordingly*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
int subWordComparison()
{
	//declaration and opening of the two files used
	FILE *wordsForComparison1 = fopen("wordlist10000.txt", "r");
	FILE *decryptedString = fopen("output.txt", "r");
	//declaration of the two char arrays used to store each string
	char words1[100000], str[10000];
	//declaration of n and k, used as counters later in function, and score which is returned at end of function
	int n, k, score = 0;

	
	for (n = 0; feof(decryptedString) == 0; n++)
	{
		fscanf(decryptedString, "%c", &str[n]);
		if (str[n] == EOF)
			break;
	}
	for (n = 0; n < 999998; n++)
	{
		fscanf(wordsForComparison1, "%c", &words1[n]);
		if (words1[n] == EOF)
		{
			break;
		}
		else if(words1[n] > 95 && words1[n] < 123)
			words1[n] = words1[n] - 32;
	}
	for (n = 0; str[n] != 0; n++)
	{
		for (k = 0; words1[k] != 0; k++)
		{
			if ((str[n] == words1[k]) && (str[n+1] == words1[k+1]) && (str[n+2] == words1[k+2]) && (str[n+3] == words1[k+3]))
			{
				score += 4;
			}
			else if (str[n] == words1[k] && str[n+1] == words1[k+1] && str[n+2] == words1[k+2])
			{
				score += 3;
			}
			else if (str[n] == words1[k] && str[n+1] == words1[k+1])
			{
				score += 2;
			}
		}
	}
	printf("%d\n", score);
	fclose(wordsForComparison1);
	fclose(decryptedString);
	return score;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/	

/*----------------------------------------------------------------------------------------------------------------------------------*/
int readCipher()
{
	FILE *input;
	int cipher;
	
	input = fopen("cipher.txt", "r");
	fscanf(input, "%d", &cipher);
	cipher = cipher;
	fclose(input);
	printf("Cipher used is %d\n", cipher);
	return cipher;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
int writeCipher(int option)
{
	int cipher;
	
	if (option == 1)
	{
		printf("Please enter the value for the cipher, between 1 and 26 (If you want to you can go between -26 and 26 and everything should still work)\n");
	}
	else
	{
		printf("Please enter the value of the cipher that was used to encrypt the text originally (between -26 and 26)\n");
	}
	scanf("%d", &cipher);
	
	while (cipher < -26 || cipher > 26)
	{
		printf("\nThe value that you've entered is invalid, please try again: ");
		scanf("%d", &cipher);
	}
	
	if (option != 1)
	{
		cipher = cipher * -1;
	}
	
	return cipher;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
void writeKey()
{
	char keyHolder[27];
	FILE *key = fopen("key.txt", "w");
	int n, end = 1, prelimEnd = 1;
	
	printf("Please enter the key to be used to encrypt decrypt the text in upper case with no space followed by pressing the enter key, for example: QWERTYUIOPASDFGHJKLZXCVBNM\n");
	scanf("%s", keyHolder);
	while (end != 0)
	{
		while (prelimEnd != 0)
		{
			prelimEnd = 0;
			for (n=0; keyHolder[n]!= 0; n++)
				;
			while (n < 25)
			{
				printf("The key doesn't contain enough characters, please try again\n");
				scanf("%s", keyHolder);
					for (n=0; keyHolder[n]!= 0; n++)
					;
				prelimEnd = 1;
			}
				
			for (n=26; keyHolder[26] != 0; n++)
			{
				keyHolder[n] = 0;
			}
			for (n=0; keyHolder[n] != 0; n++)
			{
				if (keyHolder[n] > 96 && keyHolder[n] < 123)
				{
					keyHolder[n] = keyHolder[n] - 32;
				}
				else if (keyHolder[n] < 65 || (keyHolder[n] > 90 && keyHolder[n] < 97) || keyHolder[n] > 122)
				{
					printf("The key entered contains an invalid character, please enter the full key again.\n");
					scanf("%s", keyHolder);
					n = 0;
					prelimEnd = 1;
				}
			}
			//printf("%d\n", duplicateChecker(keyHolder));
			if (duplicateChecker(keyHolder) == 1)
			{
				printf("The key entered contains a duplicate, please enter the full key again.\n");
				scanf("%s", keyHolder);
				prelimEnd = 1;
			}
		}
		end = 0;
	}
	printf("\n%s\n", keyHolder);
	for (n = 0; keyHolder[n] != 0; n++)
	{
		fputc(keyHolder[n], key);
	}
	fclose(key);
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
//10 Most common words - https://simple.wikipedia.org/wiki/Most_common_words_in_English
int wordChecker()
{
	char * stringToBeChecked;
	int complete = 0, n;
	stringToBeChecked = stringMakerOutput();
	
	for (n = 0; stringToBeChecked[n] != 0; n++)
	{
		if ((stringToBeChecked[n] == 'A' && stringToBeChecked[n+1] == 'N' && stringToBeChecked[n+2] == 'D') ||(stringToBeChecked[n] == 'T' && stringToBeChecked [n+1] == 'H' && stringToBeChecked[n+2] == 'E') || (stringToBeChecked[n] == ' ' && stringToBeChecked[n+1] == 'I' && stringToBeChecked[n+2] == 'T' && stringToBeChecked[n+3] == ' '))// && stringToBeChecked[n+1] == 'n' && stringToBeChecked[n+2] == 'd')
		{
			complete = 1;
			break;
		}
		else if ((stringToBeChecked[n] == '.' && stringToBeChecked[n+1] == '.'))
		{
			printf("String ends");
			stringToBeChecked[n+1] = 0;
		}
	}
	//printf("String checked %s", stringToBeChecked);
	if (complete == 1)
		return 1;
	else 
		return 0;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
int keyLengthCheck(char key[])
{
	int n;
	
	for (n = 0; key[n] != 0; n++)
	{
	}
	printf("n = %d\n", n);
	if (n<26)
	{
		printf("The key isn't long enough\n");
		return 1;
	}
	else if (n > 26)
	{
		printf("The key is too long\n");
		return 1;
	}
	else
		return 0;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
void plainTextWriter()
{
	FILE * plainText = fopen("input.txt", "w");
	char inputText[1000]; int n;
	
	printf("Please enter the plain text you would like to encrypt or decrypt: \n");
	scanf("\n");
	scanf("%[^\n]s", inputText);
	printf("The string you entered is %s\n", inputText);
	
	for (n = 0; inputText[n] != 0; n++)
	{
		fputc(inputText[n], plainText);
	}
	//fprintf(plainText, "%s", inputText);
	
	fclose(plainText);
	
	return;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
char * subAnalysis2()
{
	char encryptedString[10000], str[10000];
	FILE *theEncryptedString = fopen("input.txt", "r");
	FILE *theKey = fopen("key.txt", "r");
	static char key[26];
	int n, k;

	
	for (n = 0; feof(theEncryptedString) == 0; n++)
	{
		fscanf(theEncryptedString, "%c", &encryptedString[n]);
		if (encryptedString[n] == EOF)
			break;
	}
	for (n = 0; encryptedString[n] !=0; n++)
	{
		str[n] = encryptedString[n];
	}
	
	for (n = 0; feof(theKey) == 0; n++)
	{
		fscanf(theKey, "%c", &key[n]);
		if (key[n] == EOF)
			break;
	}
	//printf("String in subanalysis2 is %s\n", encryptedString);
	for (n=0; str[n] != 0; n++)
	{
		//printf("%c", encryptedString[n]);
		//printf("%d\n", (int)str[n]);
		if ((int)str[n] > 65 && str[n+1] > 65 && str[n+2] == str[n])// && (int)str[n+1] > 65 && str[n+2]== str[n])
		{
			char three = key[3];
			char eight = key[8];
			for (k = 0; key[k] != 0; k++)
			{
				if (key[k] == str[n])
					key[k] = three;
				else if (key[k] == str[n+1])
					key[k] = eight;
			}
			key[3] = str[n];
			key[8] = str[n+1];
			break;
		}
	}
	for (n=0; str[n] != 0; n++)
	{
		if(str[n] == 32 && str[n+1] >65 && str[n+2] > 65 && str[n+3] == 44 && str[n+4] > 65)
		{
			char eight = key[8];
			char nineteen = key[19];
			char eighteen = key[18];
			for (k = 0; key[k] != 0; k++)
			{
				if (key[k] == str[n+1])
					key[k] = eight;
				else if (key[k] == str[n+2])
					key[k] = nineteen;
				else if (key[k] == str[n+4])
					key[k] == eighteen;
			}
			key[8] = str[n+1];
			key[19] = str[n+2];
			key[18] = str[n+4];
			break;
		}
	}
	
	fclose(theEncryptedString);
	fclose(theKey);
	return key;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
int subAnalysis()
{
	char encryptedString[10000], key[26];
	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("key.txt", "w");
	int *strCount;
	int a, n, counter, count;
	
	for (n = 0; feof(input) == 0; n++)
	{
		fscanf(input, "%c", &encryptedString[n]);
		if (encryptedString[n] == EOF)
			break;
		//printf("String Tested is %s\n", str);
	}
	
	strCount = stringCount(encryptedString);
	for (counter = 0; counter <26; counter ++)
	{
		count = 0;
		for (n = 0; n<26; n++)
		{
			//static int count = 0;
			if (strCount[n] >= count)
			{
				count = strCount[n];
				a = n; 
				//holds the value in the string that corresponds to the letter in the alpahbet
				//i.e. a=0, b=1,... z=26
			}
		}
		strCount[a] = -1;
		switch (counter)
		{
			case 0:
				key[4] = a + 65;
				break;
			case 1:
				key[19] = a + 65;
				break;
			case 2:
				key[0] = a + 65;
				break;
			case 3:
				key[14] = a + 65;
				break;
			case 4:
				key[8] = a + 65;
				break;
			case 5:
				key[13] = a + 65;
				break;
			case 6:
				key[18] = a + 65;
				break;
			case 7:
				key[7] = a + 65;
				break;
			case 8:
				key[17] = a + 65;
				break;
			case 9:
				key[3] = a + 65;
				break;
			case 10:
				key[11] = a + 65;
				break;
			case 11:
				key[2] = a + 65;
				break;
			case 12:
				key[20] = a + 65;
				break;
			case 13:
				key[12] = a + 65;
				break;
			case 14:
				key[22] = a + 65;
				break;
			case 15:
				key[5] = a + 65;
				break;
			case 16:
				key[6] = a + 65;
				break;
			case 17:
				key[24] = a + 65;
				break;
			case 18:
				key[15] = a + 65;
				break;
			case 19:
				key[1] = a + 65;
				break;
			case 20:
				key[21] = a + 65;
				break;
			case 21:
				key[10] = a + 65;
				break;
			case 22:
				key[9] = a + 65;
				break;
			case 23:
				key[23] = a + 65;
				break;
			case 24:
				key[16] = a + 65;
				break;
			case 25:
				key[25] = a + 65;
				break;
			default:
				break;
		}
	}

	for (n = 0; n < 26; n++)
	{
		fputc(key[n], output);
	}
	fclose(input);
	fclose(output);
}	
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
//returns 0  if a letter in a string is found more than once, else returns 1
int duplicateChecker(char * someString)
{
	int n = 0;
	int *strCount;
	
	strCount = stringCount(someString);

	for (n = 0; n<=25; n++)
	{
		if (strCount[n] > 1)
			return 1;
	}
	return 0;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
int *stringCount(char str[])
{
	static int strCount[26];
	int n;
	
	for (n = 0; n < 26; n ++)
	{
		strCount[n] = 0;
	}
	for (n = 0; str[n] != 0; n++)
	{
		switch (str[n])
		{
			case 65:
				strCount[0]++;
				break;
			case 66:
				strCount[1]++;
				break;
			case 67:
				strCount[2]++;
				break;
			case 68:
				strCount[3]++;
				break;
			case 69:
				strCount[4]++;
				break;
			case 70:
				strCount[5]++;
				break;
			case 71:
				strCount[6]++;
				break;
			case 72:
				strCount[7]++;
				break;
			case 73:
				strCount[8]++;
				break;
			case 74:
				strCount[9]++;
				break;
			case 75:
				strCount[10]++;
				break;
			case 76:
				strCount[11]++;
				break;
			case 77:
				strCount[12]++;
				break;
			case 78:
				strCount[13]++;
				break;
			case 79:
				strCount[14]++;
				break;
			case 80:
				strCount[15]++;
				break;
			case 81:
				strCount[16]++;
				break;
			case 82:
				strCount[17]++;
				break;
			case 83:
				strCount[18]++;
				break;
			case 84:
				strCount[19]++;
				break;
			case 85:
				strCount[20]++;
				break;
			case 86:
				strCount[21]++;
				break;
			case 87:
				strCount[22]++;
				break;
			case 88:
				strCount[23]++;
				break;
			case 89:
				strCount[24]++;
				break;
			case 90:
				strCount[25]++;
				break;
			default:
				break;
		}
	}
	return strCount;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/	
int randomNumber(int min, int max)
{
	//https://www.google.com/search?q=randomly+generate+numbers+between+two+values+in+c&oq=randomly+generate+numbers+between+two+values+in+c&aqs=chrome..69i57j0l5.18546j0j4&sourceid=chrome&ie=UTF-8#kpvalbx=1
	int d, r, x;
	
	d = max - min;
	r = rand();
	x = r % d;
	return (x + min);
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
char * keyModifier(int option, char str[])
{
	int b = randomNumber(0, 25),n;
	printf("%d\n", b);
	int c = randomNumber(0, 25);
	printf("%d\n", c);
	static char keyHolder[26];
	FILE *key = fopen("key.txt", "r");
	char d;
	
	if (option == 1)
	{
		for (n = 0; n<27 ; n++)
		{
			//fscanf(key, "%c", &keyHolder[n]);
			keyHolder[n] = fgetc(key);
			if (keyHolder[n] == EOF)
			{
				keyHolder[n] = 0;
				break;
			}
			//printf("String Tested is %s\n", str);
		}
	}
	else 
	{
		for(n = 0; str[n] != 0; n++)
		{
			keyHolder[n] = str[n];
		}
	}
	//printf("original key %sis\n", keyHolder);
	
	d = keyHolder[b];
	keyHolder[b] = keyHolder[c];
	keyHolder[c] = d;
	fclose(key);
	//printf("%s\n", keyHolder);
	return keyHolder;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
void keyCaseChange()
{
	FILE *key = fopen("key.txt", "r");
	char keyHolder[27];
	int n;
	
	fscanf(key, "%s", keyHolder);
	for (n = 0; keyHolder[n] != 0; n++)
	{
		if (keyHolder[n] == EOF)
			break;
		else if (keyHolder[n] < 123 && keyHolder[n] > 96)
		{
			keyHolder[n] = keyHolder[n] - 32;
		}
	}
	fclose(key);
	//printf("Key was changed to \n%s\n",keyHolder);
	
	FILE *keyWrite = fopen("key.txt", "w");
	fprintf(keyWrite, "%s", keyHolder);
	fclose(keyWrite);
}
