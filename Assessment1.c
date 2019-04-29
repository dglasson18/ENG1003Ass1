#include <stdio.h>
//required in order for random number generator function
#include <stdlib.h>
/*text to be encrypted can be entered into input.txt prior to selecting an option, or through the console as an option itself
The same goes for cipher in cipher.txt and key in key.txt. The options are explained in a menu that is displayed when the code
is run. The output will be written to output.txt, as well as displayed via console at the completion of task.
Limitations
 - any functions intended to use text from input.txt and output.txt will be able to handle a maximum of 100000
characers. Any more than this and it will die a horrible death.
 - any functions intended to use text from key.txt may behave in an unknown manner if a number of characters that is not 26 is
 passed to them
  - any functions intended to utilise the contents of cipher.txt may have unwanted behavious if the value held in cipher.text
	falls outside the range of -26 to 26

	Please be patient with unknown substitution decryption, as the method used can take quite a long time z*/

/*Function Headers*/
/*Encrypts text, writes result to output.txt, takes an integer for cipher as argument, no return value as work done
is written to output*/
void rotationEncryption(int cipher);
/*Decrypts text based on original key that was used for encryption, writes result to output.txt, takes an integer
for cipher as argument, no return value as work done is written to output*/
void rotationDecryption(int cipher);
/*Encrypts text, takes an integer to determine where and key and text are read from, no return value, work done
written to output*/
void substitutionEncryption(int option);
/*Decrypts text, takes int argument to determine where key and text are read from, no return value, work done is
written to output*/
void substitutionDecryption(int option, char str1[]);
/*scans input.txt to identify most common letter, returns an integer based on position of letter in alphabet
eg. a = 0, c = 2, z = 25*/
int mostCommonLetter();
/*calculates cipher based on how number of decryption attempts and the most common letter in encrypted text, passed
to the function as option and a respective, returns cipher as an integer*/
int rotationCipherCalculator(int option, int a);
/*creates string from contents of output.txt and returns pointer to result*/
char *stringMakerOutput();
/*checks output.txt for common words, e.g. and, and returns 1 if words are found*/
int wordChecker();
/*reads contents of cipher.txt and returns as an integer*/
int readCipher();
/*scans console for integer and, takes integer argument 1 for encryption, 2 for decryption, returns result as int*/
int writeCipher(int option);
/*takes user input (string) from console and writes result to input.txt*/
void plainTextWriter();
/*takes user input (string) from console and writes result to key.txt */
void writeKey();
/*string is passed as an argument to function and checked for duplicate characters, returns 1 if duplicate exists,*/
int duplicateChecker(char * someString);
/*analyses text stored in input.txt, writes characters to key.txt based on frequency, no return value*/
void subAnalysis();
/*compares 10 000 common words with contents of output.txt, returns integer value based on number of similarities*/
int subWordComparison();
/*generates random number and returns value as int, min and max values are passed to function as integers*/
int randomNumber(int min, int max);
/*swaps two characters in a string and returns result. option passed to function as int determines whether string
modified is the one passed to function as char argument, or one generated from contents of key.txt*/
char *keyModifier(int option, char str[]);
/*checks input.txt for certain character arrangement, then writes characters to string based on those arrangements
and returns that string at end of function*/
char *subAnalysis2();
/*checks the length of string passed as char key[] to function, returns 1 if length < 26 characters, 2 if more, else 0*/
int keyLengthCheck(char key[]);
/*converts the contents of key.txt to upper case, no return value*/
void keyCaseChange();
/*used to control the running of implementation of all other functions, returns int 0 when user is finished*/
int run();
/*contains switch which calls rot. enc. related functions based on char passed to function as argument*/
void rotEncChoice(char choice);
/*contains switch which calls rot. dec. related functions based on char passed to function as argument*/
void rotDecChoice(char choice);
/*contains switch which calls sub. enc. related functions based on char passed to function as argument*/
void subEncChoice(char choice);
/*contains switch which calls sub dec related functions based on char passed to function as argument*/
void subDecChoice(char choice);
/*function called when user opts to perform unknown rotation decryption*/
void unRotDecrypt();
/*function called when user opts to perform unknown substitution decryption*/
void unSubDecrypt();
/*counts and the number of times each character appears in a string passed to function as argument, returns pointer
to resulting integer array*/
int *stringCount(char str[]);
/*Contains statements printed to console ot give user direction, no return value, used to free up run()*/
void mainMenu();
/*Contains statements printed to console ot give user direction, no return value, used to free up run()*/
void menu1();
/*Contains statements printed to console ot give user direction, no return value, used to free up run()*/
void menu2();
/*Contains statements printed to console ot give user direction, no return value, used to free up run()*/
void menu3();
/*Contains statements printed to console ot give user direction, no return value, used to free up run()*/
void menu4();
/*takes input from console and returns value as char*/
char getChar();
/*takes input from console and returns value as int*/
int getNumber();
/*checks input.txt for existence, contents etc, returns 1 if issue with file was found*/
int inputCheck();

/*----------------------------------------------------------------------------------------------------------------------------------*/
int main()
{
	//variable used to control the loop, as the run function returns 0 when the user opts to finish

	int end = 1;
	//while(run()) could also work
	/*run function is called repeatedly until user selects an option in the run() function that shows they wish to exit, in which
	instance int 0 is returned*/
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
  //end used to determine whether or not code will continue to run at end of loop
	int end;

	static int showMenu = 0;
	// secChoice stores users secondary choice will be tested against char a,b,c or d
  //choice stores users first choice, and tested against char 0 - 7
	char secChoice = 0, choice = 8;
	if (showMenu == 0)
	{
		//calls the function that displays the list of options available to the user
		mainMenu();
		showMenu = 1;
	}

	//ensures that the while loop will initially execute, do while could also have been used
	end = 1;
//	while (end != 0)
	//{
		printf("\nPlease select the corresponding number for the function you wish to use: \n");
		//calls the function getChar(), which will then store a char stdin in choice. No strictly necessary as
		//scanf("%d", &choice could also have been used, but I thought it was a good opportunity to play around with various functions
		//that serve a relatively simple purpose
		//mitigates issues that was causing execution to jump past choice = straight to while loop
		scanf("\n");
		choice = getChar();
		//If the number entered by the user doesn't correspond to an option, the while loop will kick in and prompt the user to enter
		//in their preference again. This will repeat until a valid option is selected.
		while (choice < '0' || choice > '7')
		{
			printf("\nThere was an issue with your choice, please select the corresponding number for the function you wish to use: ");
			choice = getChar();
		}
		//switch statement that will perform an action based on the preference the user entered earlier. For instance, selecting 1 will
		//run case 1, showing a submenu and then performing 1 of 4 variations to rotation encryption based on the users preference
		switch(choice)
		{
			case '0':
				//sets end = to 0, redundant however as the return 0 should cause execution to break out of function and return to main
				end = 0;
				//returning zero will break out of while loop in main, finishing execution
				return 0;
			case '1':
				//This should call the function that will be used to encrypt rotation cipher
				//calls function menu1 which displays the various options for rotation encryption
				menu1();
				//user enters a char a,b,c or d which is then stored in secChoice
				secChoice = getChar();
				//If the value entered by user doesn't correspond with one listed above, user will be prompted to re-enter char until
				//a valid value is entered
				while (secChoice < 97 || secChoice > 100)
				{
					printf("\nPlease enter a valid option\n");
					secChoice = getChar();
				}
				//calls another function containing a switch statement which calls functions relating specifically to rotation encryption
				//the variable secChoice is passed as an argument to the function and determines which case the function carries out
				rotEncChoice(secChoice);
				//stringMakerOutput() reads the contents of the encrypted file and stores it in char array, which is then returned at
				//the end of the function and can then be printed using statement below
				printf("\nThe resulting string is: '%s'", stringMakerOutput());
				//causes run() to exit and re-enter due to while loop in main
				return 1;
				break;
			case '2':
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
				//the variable secChoice is passed as an argument to the function and determines which option form menu the function carries out
				rotDecChoice(secChoice);
				//stringMakerOutput() reads the contents of the encrypted file and stores it in char array, which is then returned at
				//the end of the function and can then be printed using statement below
				printf("\nThe resulting string is: '%s'", stringMakerOutput());
				//causes run() to exit and re-enter due to while loop in main
				return 1;
				break;
			case '3':
				//This case will result in function relating to substitution encryption being called
				menu3();
				secChoice = getChar();
				while (secChoice < 97 || secChoice > 100)
				{
					printf("\nPlease enter a valid option:");
					scanf("\n%c", &secChoice);
				}
				//calls function subEncChoice, which will then call a variation of substitution encryption based on user input
				subEncChoice(secChoice);

				printf("\nThe resulting string is: '%s'", stringMakerOutput());
				//causes run() to exit and re-enter due to while loop in main
				return 1;
				break;
			case '4':
				//This should call the function that will be used to decrypt substitution cipher
				menu4();
				secChoice = getChar();
				while (secChoice < 97 || secChoice > 100)
				{
					printf("\nPlease enter a valid option:");
					scanf("\n%c", &secChoice);
				}
				//calls function subDecCho will then call a variation of substitution based on user input
				subDecChoice(secChoice);
				printf("\nThe resulting string is: '%s'", stringMakerOutput());
				//causes run() to exit and re-enter due to while loop in main
				return 1;
				break;
			case '5':
				//calls unRotDecrypt(), which in turn calls a number of other functions which work together to decrypted unknown rotation cipher
				unRotDecrypt();
				printf("\nThe resulting string is: '%s'\n", stringMakerOutput());
				//causes run() to exit and re-enter due to while loop in main
				return 1;
				break;
			case '6':
				//This should call the functions required to decrypt an unknown substitution cipher
				unSubDecrypt();
				printf("\nThe resulting string isL '%s'\n", stringMakerOutput());
				//causes run() to exit and re-enter due to while loop in main
				return 1;
				break;
			case '7':
				mainMenu();
				//causes run() to exit and re-enter due to while loop in main
				return 1;
				break;
			default:
				//This will happen if user doesn't select an option from 1 to 4 or something else goes wrong
				printf("Something went wrong. You entered %c. Please enter 1, 2, 3, 4, 5 or 6 or cry because something is broken\n", choice);
				choice = getChar();
				break;
				return 0;
		}
	//}
	return 1;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*mainMenu() function is used to send the main menu with user preferences to be displayed in the console. It takes no arguments and
doesn't return anything, as it's purpose is only to reduce the size of the run() function and increase the portability of the menu
throughout the code. This means that the menu can now be called anywhere with one line of code, rather than having to retype the whole
menu*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
void mainMenu()
{
	printf("\nAvailable functions\n");
	printf("	(1) Encrypt message using Rotation Cipher\n");
	printf("	(2) Decrypt message using Rotation Cipher\n");
	printf("	(3) Enccypt message using Substitution Cipher\n");
	printf("	(4) Decrypt message using Substitution Cipher\n");
	printf("	(5) Decrypt message using unknown rotation cipher\n");
	printf("	(6) Decrypt message using unknown substitution cipher\n");
	printf("		This may take some time, so please be patient\n");
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

/*getNumber() retrieves an int from stdin and stores it in the variable number, which is then returned at the end of the function
limited to 1 integer per function call*/
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

/*getChar() retrieves a char from stdin and stores it in the variable character, which is then returned at the end of the function
limited to one character per function call*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
char getChar()
{
	//contains the char entered by the user, which is then returned at the end of the function
	char character;
	//reads a char from console and stores it in character
	scanf("%c", &character);
	return character;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*returns 1 if there has been an issue with the file input,txt. For example the file doesn't exist, or doesn't contain any letters
that can be encrypted, such as '5' or '^', else returns 0. If an issue with the file is identified, users are given the
opportunity to rectify the issue*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
int inputCheck()
{
	//opens file input, with read only permissions
	FILE * input = fopen("input.txt", "r");
	//char test will be used to store characters which will be tested, explained below
	char test;
	//n is used as a counter, containsLetter is used like a flag to identify whether or not any letters from the alphabet were found
	int n, containsLetter = 0, end = 0;
	//tests whether the pointer points to a file, if null then the file input.txt wasn't present
	if (input == NULL)
	{
		//not sure whether or not this is necessary as input == null
		fclose(input);
		//opens the file input with write privileges. This creates the file, solving the problem of it not existing
		input = fopen("input.txt", "w");
		//file is closed so that plainTextWriter() can be used without experiencing any monumental hiccups
		fclose(input);
		//lets user know that the file didn't exist
		printf("\nThe file used to store the text to encrypt/decrypt does not exist\n");
		//allows user to enter text, which will then be stored in the newly created input.txt
		plainTextWriter();
		end =1;
	}
	if (end == 1)
		input = fopen("input.txt", "r");
	//for loop will run until the end of the file is reached
	for (n = 0; feof(input) == 0 && n < 10; n++)
	{
		//takes a character from input.txt which can then be tested.
		test = fgetc(input);
		//when the end of the file is reached, the for loop is broken
		if (test == EOF)
		{
			break;
		}
		//loop initiates if an upper or lower case letter is found, the loop then breaks, as encryption theoretically only requires
		//one letter - if the file only contains numbers or other such characters, contains letter will remain 0
		if ((test > 64 && test < 91) || (test > 96 && test < 123))
		{
			fclose(input);
			containsLetter = 1;
			return 0;
		}
	}
	//assumes that the file is either empty only contains letters - thus ensuring that encryption can actually be done
	if (containsLetter == 0)
	{
		printf("\nThe file is either empty, or doesn't contain any letters that can be encrypted\n");
		//takes a users input from console and stores it in 0
		plainTextWriter();
		//end = 0 will cause while loop to repeat, this will cause test to be repeated in case user didn't enter any valid characters
		//when prompted by plainTextWriter()
		end = 1;
	}
	fclose(input);
	return end;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/
/*rotEncChoice takes a char, intended to be a,b,c or d, as an argument and calls a function based on that char. This function
controls which variation of rotation encryption is completed. It does not have a return value, as any work done is stored in input,
output or cipher files
mesures are in place to prevent function being called with an argument that doesn't match any of the cases*/
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
			rotationDecryption(-readCipher());
			break;
		case 98:
			//case98 allows the user to specify the cipher that was used to encrypt the text, while the text is read from input.txt
			//2 is passed as an argument of writeCipher() to ensure that the correct string is printed to the console, and that the
			//cipher is set to have the opposite sign of the original sign, thus allowing decryption
			cipher = writeCipher(2);
			//cipher is passed as an argument to rotationEncryption, text is read from input.txt, cipher doesn't need to be modified
			//as sign has already been set
			rotationDecryption(cipher);
			break;
		case 99:
			//case99 allows the user to specify the text that is being decrypted through stdin
			//plainTextWriter takes user input and stores it in input.txt, where it can then be read by rotationEncryption()
			plainTextWriter();
			//negative sign placed in argument for same reason as case97
			rotationDecryption(-readCipher());
			break;
		case 100:
			//case100 allows the user to specify both the text and cipher that will be used via stdin using writeCipher() and
			//plainTextWriter() as explained above
			cipher = writeCipher(2);
			plainTextWriter();
			//rotationEncryption carries out 'encryption' using cipher of opposite sign specified with writeCipher(2) and passed
			//as an argument to the function, thus decrypting the text.
			rotationDecryption(cipher);
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
		rotationDecryption(cipher);
		/*the resulting string is tested. If it contains common english words, a value of 1 is returned which will end loop, otherwise
		0 is returned and loop will continue to run*/
		result = wordChecker();
		//counter is incremented to ensure that cipher value changes after each iteration of loop. Also assists with flow control
		counter++;
	}
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*Function called when user wishes to decrypt a string encrypted with an unknown substiution cipher. Analysis is performed on the
encrypted string and a key is generated on the frequency of letters when compared with general frequency of characters in the english
language, which is then written to key.txt. Decryption is then completed with this initial key and a baseline score is generated by,
identifying the suitability of decrypted string by comparing it with 10 000 common english words. Secondary analysis is then completed
to try and identify parts of the key using common words that are somewhat unique, such as 'DID' (this aspect wasn't overly successful)
and a modified key is generated and returned as a pointer, which can then be passed to the decryption function. If the decrypted text
is found to be more suitable then it will generate a higher score, and the new key will be written to key.txt. Random characters in the
key are then swapped in the key, and the resulting key is used to decrypt the string and test for suitability to the same effect.
This process then essentially repeats itself with some variation (explained below), until such point as 1000 modifications have
occurred and no increase in score has been experienced. At this point it is assumed that the encrypted string will not improve and so
the key with the highest score is written to key.txt and is used to perform a final decryption.
/*----------------------------------------------------------------------------------------------------------------------------------*/
void unSubDecrypt()
{
	int score;
	//calls function that analyses encrypted string and stores a key in key.txt based on letter frequency
	subAnalysis();
	//substitutuion decryption is completed, reading encrypted string from input.txt and key from key.txt (see function for more)
	substitutionDecryption(1, "");
	//a baseline score is generated using subWordComparison and stored in score/*
	score = subWordComparison();
	//a modified string is generated based on secondary analysis, with str1 used as a pointer

	char *str1 = subAnalysis2();
	/*substitution decryption is completed, reading ecrypted string from input.txt and the key as an argument passed to the function
	using the pointer str1*/
	substitutionDecryption(0, str1);
	//if the new key successfully generates more decrypted characters, the score should be greater, in which case it is written to key
	if (score < subWordComparison())
	{
		FILE *key = fopen("key.txt", "w");
		fprintf(key,"%s", str1);
		fclose(key);
	}
	//printf("str1 = %s\n", str1); //used for testing
	for (int n = 0; n < 1500; n++)
	{
		//two random values within key are swapped, with str used as a pointer to the result
		char * str = keyModifier(0, str1);
		//new string is printed to console to give visual indication of progress
		printf("str = %s\n", str);
		//decryption is attempted with new string
		substitutionDecryption(0, str);
		//suitability is tested and stored in newScore, which will then be used for comparsion
		int newScore = subWordComparison();
		//score of most recent string is compared with that of the most successful string, and if higher will enter loop
		if (newScore > score)
		{
			//newScore, being higher, replaces the old value of score as it is now obsolete
			score = newScore;
			//new string overwrites previous best string, this allows the new best string to be modified
			for (int k=0; str[k] != 0; k++)
			{
				str1[k] = str[k];
			}
			//indicates to user that a better string has been found, also useful during testing
			printf("str1 = %s\n", str1);
			/*n is reset to 0 as a new best string has been found, thus allowing the process of waiting for 1000 revisions without
			an increase in score to be carried out as intended*/
			n = 0;
		}
	}
	//once 1000 revisions have occurred without an increase in score, the best key is written to key.txt
	FILE *key = fopen("key.txt", "w");
	fprintf(key, "%s", str1);
	fclose(key);
	//a final decryption is then carried out using decrypted text stored in input.txt and key stored in key.txt
	substitutionDecryption(1,"");
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*rotationEncryption() is the function that performs the encryption of a piece of text. It reads the text to be
encrypted/decrypted from input.txt and writes it to output.txt, while the cipher is passed to the function as an argument.
/*----------------------------------------------------------------------------------------------------------------------------------*/
void rotationEncryption(int cipher)
{
	/*checks the contents of input.txt, if file doesn't exist or doesn't contain any letters than user is prompted to re-enter
	contents via console. This process repeats itself until no issues are found*/
	static int inputTest;
	inputTest = inputCheck();
	while (inputTest == 1)
	{
		inputTest = inputCheck();
	}
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
					str = (char)(str - 26);
				/*same principal as if statement above, but in reverse, so that if cipher causes a number to go below 65, 26 will
				be added to return it to the end of the alphabet. e.g. A - 3 = >, A - 3 + 26 = X*/
				else if (str < 65)
					str = (char)(str + 26);
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

/*RotationDecryption() is the function that performs the decryption of a piece of text. It reads the text to be
encrypted/decrypted from input.txt and writes it to output.txt, while the cipher is passed to the function as an argument. This will
only work if the user specifies the cipher that was originally used to encrypt the piece of text, as the function is not intended to
work with the key negative key required to decrypt a piece of test, instead it re-encrypts the text in the opposite direction to the
way that it was encrypted, thus returning it to it's unencrypted state, decrypting it. The cipher passed to the function is modified
prior to it being passed to the function to meet this condition. This function as only been included to meet the specification
requireing each task be completed by a different function*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
void rotationDecryption(int cipher)
{
	/*checks the contents of input.txt, if file doesn't exist or doesn't contain any letters than user is prompted to re-enter
	contents via console. This process repeats itself until no issues are found*/
	static int inputTest;
	inputTest = inputCheck();
	while (inputTest == 1)
	{
		inputTest = inputCheck();
	}
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
					str = (char)(str - 26);
				/*same principal as if statement above, but in reverse, so that if cipher causes a number to go below 65, 26 will
				be added to return it to the end of the alphabet. e.g. A - 3 = >, A - 3 + 26 = X*/
				else if (str < 65)
					str = (char)(str + 26);
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
		/*checks the contents of input.txt, if file doesn't exist or doesn't contain any letters than user is prompted to re-enter
		contents via console. This process repeats itself until no issues are found*/
		static int inputTest;
		inputTest = inputCheck();
		while (inputTest == 1)
		{
			inputTest = inputCheck();
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
	char key[27], str[100000]; //= {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','\0'};
	//declaration of file pointers used, input will point to input.txt, output to output.txt and keyText to keyText.txt
	FILE *input;
	FILE *output;
	FILE *keyText;
	/*integers n and k are used incrementing values during for loops, while end holds the value that determines whether or not the
	while loop continues to run*/
	int n = 0, k = 0, end = 1;
	/*while loop will run until functions keyLengthCheck() and duplicateChecker() only return 0, which will result in end = 0, thus
	causing the loop to exit*/
	while (end != 0)
	{
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
			FILE *key2 = fopen("key.txt", "w");
			for (n = 0; str1[n] != 0; n++)
			{
				key[n] = str1[n];
				fputc(key[n], key2);
			}
			fclose(key2);

		}
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
	if (option > 0)
	{
		int inputTest = 1;
		while (inputTest == 1)
		{
			inputTest = inputCheck();
		}
	}
	for (n = 0; n < 99999; n++)
	{
		str[n] = 0;
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
	end = 1;
	//while(end != 0)
	//{
		//for loop intended to scan a character at a time from input and store it in str[n].
		for (n = 0; feof(input) == 0; n++)
		{
			//fscanf was used instead of fgetc to experiment and see whether there are any functional differences. fgetc could also be used
			fscanf(input, "%c", &str[n]);
			//if fscanf reaches the end of input, then if statement will be triggered and will break out of for loop
			if (str[n] == EOF)
			{
				str[n] = 0;
				break;
			}
			//identifies if str is lower case, and subtracts 32 to set str to the same letter, but upper case as per assessment spec.
			else if (str[n] > 96 && str[n] < 123)
				str[n] = str[n] - 32;
			//tyring to figure out how to work with ellipsis in the unknown key substitution string
			else if (str[n] > 123)
			{
				printf("That character is %d\n", str[n]);
			}
			//printf("String Tested is %s\n", str);
		}

		/*//identifies if str is lower case, and subtracts 32 to set str to the same letter, but upper case as per assessment spec.
		else if (str[n] > 96 && str[n] < 123)
			str[n] = str[n] - 32;
		//tyring to figure out how to work with ellipsis in the unknown key substitution string
		else if (str[n] > 123)
		{
			printf("That character is %d\n", str[n]);
		}
		//n is incremented so that the next character read from input will be stored in the next location in str
		n++;*/
	//}
	//printf("%s\n", str);
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
		/*once str[n] has been assigned it's decrypted value, it is written to output*/
		fputc(str[n], output);
	}
	n++;
	str[n] = 0;
	fprintf(output,"%c", str[n]);
	printf("String is %s\n", str);
	//close the files used to prevent any conflict if other functions need to manipulate them in any way
	fclose(input);
	fclose(output);
	fclose(keyText);
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*reads text from file input.txt and returns an integer value for the most common letter based on table below:
return value       0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
most common letter a b c d e f g h i j k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
the return value is then used in other functions, such as rotationCipherCalculator() to help generate ciphers, keys etc.
/*----------------------------------------------------------------------------------------------------------------------------------*/
int mostCommonLetter()
{
	/*checks the contents of input.txt, if file doesn't exist or doesn't contain any letters than user is prompted to re-enter
	contents via console. This process repeats itself until no issues are found*/
	static int inputTest;
	inputTest = inputCheck();
	while (inputTest == 1)
	{
		inputTest = inputCheck();
	}
	//declaration of pointer to file that text will be read from
	FILE *input;
	/*str stores the text as a string to be analysed. Initialised in as issues were occuring when the function was re-used with text
	different lengths and array was only declared as char str[2000]*/
	char str[10000] = {'0'};
	/*n is used as a counter and condition in for loop at end of function, a holds the integer that is returned at the end of the
	function, count is used to store the highest letter count and end is used in the while loop rather than while(1) to stope Brentons
	script from killing the code during execution*/
	int n = 0, a, count = 0, end = 1;
	//pointer to a value returned by stringCount() function, holds the number of letters each char is found in str.
	int *strCount;
	//opens the file input.txt with read only privileges
	input = fopen("input.txt", "r");
	//while loop repeats until the entire contents of input.txt are stored in str
	while(end != 0)
	{
		//takes a char from input and stores it in str[n], char read automatically increments after each iteration
		str[n] = fgetc(input);
		//when fgetc reaches end of input, if statement will be triggered, breaking out of the loop
		if (str[n] == EOF)
		{
			end = 0;
			break;
		}
		//triggers if a character is lower case, modifying it to it's upper case equivalent
		else if (str[n] > 96 && str[n] < 123)
			str[n] = str[n] - 32;
		//increments n so that fgetc doesn't just store a char in the same memory location over and over
		n++;
	}
	//printf("%s\n", str);
	/*stringCount() counts the number of times each letter is found in the argument passed to it (see function for more) in this case
	str and stores the location of those values in strCount*/
	strCount = stringCount(str);
	//moves through each value stored in strCount until the highest is found, which is then stored in a
	for (n = 0; n<27; n++)
	{
		/*count holds the current highest number, if strCount[n] is greater than the if statement is triggered, causing count to take
		on the value of strCount[n] and for a to take on the value of n (see table and accompanying information above for info)*/
		if (strCount[n] > count)
		{

			count = strCount[n];
			a = n; //holds the value in the string that corresponds to the letter in the alpahbet
			//i.e. a=0, b=1,... z=26
	    }
	}
	//printf("a=%d\n", a);
	//closes input.txt so that other functions trying to manipulate the files later don't run into issues
	fclose(input);
	/*returns the n value relating to highest location, e.g. if the most common letter was e, then a would equal 4. It was just as
	simple to return this value as it was to return the actual ASCII char value, as functions can manipulate it later.*/
	return a;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/


/*rotationCipherCalculator() returns takes an argument option, which determines which fomula is used for cipher calculation, and a
which holds the integer returned from mostCommonLetter(). rotationCipherCalculator is intended for use in a loop that allows it to
iterate through all 52 keys, however, the likelihood of it needing to do so is limited, as this would only need to ocurr if the most
common letter in a piece of text was z.
each case works for a different plainText letter, and it is a little difficult to explain my logic. Case0 assumes that the most
most common letter in an encrypted piece of text will return an e when decrypted, and thus calculates the key accordingly. Case1
then calculates a secondary version of this for when the most common letter in an encrypted piece of text is a, as the calculation
doesn't work when this scenario occurs. Each set of two cases repeats the same concept, assuming that the most common letter once
decrypted will be e, followed by t, then r and so on and so forth, accounting for all possibilties. As mentioned above however this
will only work if the first argument passed to the function is able to increment from 0 to 52 or until the loop breaks due to the
appropriate cipher being found, as exemplified in it's implementation in unRotDecrypt().
If the second argument passed to the function isn't within the range of 0 to 25, the cipher generated will not be accurate
/*----------------------------------------------------------------------------------------------------------------------------------*/
int rotationCipherCalculator(int option, int a)
{
	//stores the value that will be returned at the end of the function and used as a cipher in functions like rotationEncryption()
	int cipher;

	switch (option)
	{
		//assumes most common decrypted letter will be e
		case 0:
			cipher = a + 97 - 101;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 1:
			cipher  = 26 + 97 - 101;
			break;
		//assumes most common decrypted letter will be t
		case 2:
			cipher = a + 97 - 116;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 3:
			cipher = 26 + 97 -116;
			break;
		//assumes most common decrypted letter will be r
		case 4:
			cipher = a + 97 -114;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 5:
			cipher = 26 + 97 -114;
			break;
		//assumes most common decrypted letter will be I
		case 6:
			cipher = a + 97 - 105;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 7:
			cipher = 26 + 97 - 105;
			break;
		//assumes most common decrypted letter will be o
		case 8:
			cipher = a + 97 - 111;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 9:
			cipher = 26 + 97 - 111;
			break;
		//assumes most common decrypted letter will be n
		case 10:
			cipher = a + 97 - 110;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 11:
			cipher = 26 + 97 -110;
			break;
		//assumes most common decrypted letter will be s
		case 12:
			cipher = a + 97 - 115;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 13:
			cipher = 26 + 97 - 115;
			break;
		//assumes most common decrypted letter will be L
		case 14:
			cipher = a + 97 - 108;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 15:
			cipher = 26 + 97 - 108;
			break;
		//assumes most common decrypted letter will be a
		case 16:
			cipher = a;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 17:
			cipher = 26;
			break;
		//assumes most common decrypted letter will be c
		case 18:
			cipher = a + 97 - 99;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 19:
			cipher = 26 + 97 - 99;
			break;
			//assumes most common decrypted letter will be u
		case 20:
			cipher = a + 97 - 117;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 21:
			cipher = 26 + 97 - 117;
			break;
		//assumes most common decrypted letter will be d
		case 22:
			cipher = a + 97 - 100;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 23:
			cipher = 26 + 97 - 100;
			break;
		//assumes most common decrypted letter will be p
		case 24:
			cipher = a + 97 - 112;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 25:
			cipher = 26 + 97 - 112;
			break;
		//assumes most common decrypted letter will be m
		case 26:
			cipher = a + 97 - 109;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 27:
			cipher = 26 + 97 - 109;
			break;
		//assumes most common decrypted letter will be h
		case 28:
			cipher = a + 97 - 104;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 29:
			cipher = 26 + 97 - 104;
			break;
		//assumes most common decrypted letter will be g
		case 30:
			cipher = a + 97 - 103;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 31:
			cipher = 26 + 97 - 103;
			break;
		////assumes most common decrypted letter will be b
		case 32:
			cipher = a + 97 - 98;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 33:
			cipher = 26 + 97 - 98;
			break;
		//assumes most common decrypted letter will be f
		case 34:
			cipher = a + 97 - 102;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 35:
			cipher = 26 + 97 - 102;
			break;
		//assumes most common decrypted letter will be y
		case 36:
			cipher = a + 97 - 121;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 37:
			cipher = 26 + 97 - 121;
			break;
		//assumes most common decrypted letter will be w
		case 38:
			cipher = a + 97 - 119;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 39:
			cipher = 26 + 97 - 119;
			break;
		//assumes most common decrypted letter will be k
		case 40:
			cipher = a + 97 - 107;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 41:
			cipher = 26 + 97 - 107;
			break;
		//assumes most common decrypted letter will be v
		case 42:
			cipher = a + 97 - 118;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 43:
			cipher = 26 + 97 - 118;
			break;
		//assumes most common decrypted letter will be x
		case 44:
			cipher = a + 97 - 120;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 45:
			cipher = 26 + 97 - 120;
			break;
		//assumes most common decrypted letter will be z
		case 46:
			cipher = a + 97 - 122;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 47:
			cipher = 26 + 97 - 122;
			break;
		//assumes most common decrypted letter will be j
		case 48:
			cipher = a + 97 - 106;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 49:
			cipher = 26 + 97 - 106;
			break;
		//assumes most common decrypted letter will be q
		case 50:
			cipher = a + 97 - 113;
			break;
		//same as above, but also assumes that most common encrypted letter will have a decimal value less than decrypted letter
		case 51:
			cipher = 26 + 97 - 113;
			break;
		default:
			break;
	}
	//returns the integer cipher so that it may be used in other functions or stored in other variables
	return cipher;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*function reads the contents out output.txt and returns it as a string. Helpful for printing the result of encryption/decryption
at the end of a function*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
char *stringMakerOutput()
{
	//decaration of pointer to file that will be used as input, in this instance output.txt will be used
	FILE *input;
	//static char stores the string that is being read to the file
	static char str[100000];
	//n is used as a counter for control of for loops and assisting in ensuring that str is written to properly
	int n;
	//opens the file being used for input with read only permissions
	input = fopen("output.txt", "r");
	//for loop that zeros every value in str, as it is static and would retain values from the previous time it was recalled otherwise
	for (n = 0; n < 99999; n++)
	{
		str[n] = 0;
	}
	//for loop intended to scan a character at a time from input and store it in str[n].
	for (n = 0; feof(input) == 0; n++)
	{
		//fscanf was used instead of fgetc to experiment and see whether there are any functional differences. fgetc could also be used
		fscanf(input, "%c", &str[n]);
		//if fscanf reaches the end of input, then if statement will be triggered and will break out of for loop
		if (str[n] == EOF)
		{
			str[n] = 0;
			break;
		}
		//printf("String Tested is %s\n", str);
	}
	//printf("String Tested is %s\n", str);
	//closes the file so that other functions can manipulate it without experiencing any issues
	fclose(input);
	//returns the string created from reading the file
	return str;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*Function returns score relating to the suitability of a decrypted piece of text by opening two files, one containing 10000 of the
 most common words, the other cotaining text that has just been decrypted using the decryption function above, both as read only.
 These pieces of text are then stored in char arrays words1[100000] and str[10000] respectively. The arrays are then compared in
 sections of up to 4 characters, with values added to the score accordingly
 This is used in the decryption of unknown substitution decryption, as multiple keys are generated. Each key is used to decrypt the
 text and subWordComparison is then used to determine the 'suitability' or the likelihood that the text has been decrypted properly.
 The higher the score the closer the text should be to decryption, so the score of 1 key is compared with the score of another and
 the key that produced the highest score will ultimately be kept*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
int subWordComparison()
{
	//declaration and opening of the two files used

	FILE *decryptedString = fopen("output.txt", "r");
	//declaration of the two char arrays used to store each string
	static char words1[1000000];
	char str[10000];
	//declaration of n and k, used as counters later in function, and score which is returned at end of function
	int n, k, score = 0;
	static int done = 0;

	//for loop runs until the end of the file decryptedString (output.txt) is reached, storing a character in str on each iteration
	for (n = 0; feof(decryptedString) == 0; n++)
	{
		str[n] = fgetc(decryptedString);
		if (str[n] == EOF)
			break;
	}
	//for loop runs until the end of the file wordlist10000.txt is reached, after which the loop breaks
	if (done == 0)
	{FILE *wordsForComparison1 = fopen("wordlist10000.txt", "r");
		for (n = 0; n < 999998; n++)
		{
			//reads a characeter from output.txt and stroes it in words1[n]
			fscanf(wordsForComparison1, "%c", &words1[n]);
			//when the end of the file is reached, if statement initiates and breaks out of loop
			if (words1[n] == EOF)
			{
				break;
			}
			/*identifies if a character is lowercase and converts it to it's uppecase equivalent, if this loop was not put in place
			then the final score returned at the end of the function would have a higher possibility of being inaccurate*/
			else if(words1[n] > 95 && words1[n] < 123)
				words1[n] = words1[n] - 32;
		}
		done = 1;fclose(wordsForComparison1);
	}
	//multi layer for loop that moves through str character by character
	for (n = 0; str[n] != 0; n++)
	{
		/*for loop checks whether a combination of four, three or two characters from str match any four, three or two characters from
		words1, then adds to score based on how many character match. Once the entirety of words1 is tested, this for loop exits, n is
		incremented and the process repeats itself until the end of str is reached.
		I don't think this is a very good way of implementing this, but I couldn't think of a better one.*/
		for (k = 0; words1[k] != 0; k++)
		{
			//4 is added to score if 4 characters from str match four characters from words1
			if (/*str[n] != ' '&& */(str[n] == words1[k]) && (str[n+1] == words1[k+1]) && (str[n+2] == words1[k+2]) && (str[n+3] == words1[k+3]))
			{
				score += 4;
				break;
			}/*
			//3 is added to score if 3 characters from str match three characters from wrods1
			else if (str[n] == words1[k] && str[n+1] == words1[k+1] && str[n+2] == words1[k+2])
			{
				score += 3;
				break;
			}

			//2 is added to score if 2 characters from str match two characters from words1
			else if (str[n] == words1[k] && str[n+1] == words1[k+1])
			{
				score += 2;
				break;
			}
			*/
		}
	}
	printf("%d\n", score);
	//files used are closed so that they may be manipulated by other functions without experiencing any issues

	fclose(decryptedString);
	//the final score is returned
	return score;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/
/*function reads an integer from the file cipher.txt and returns it as an integer. This can then be passed as an argument to the
rotation and decryption functions*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
int readCipher()
{
	//Pointer to file used for input declared
	FILE *input;
	//int cipher declared, will store the value of the integer read from cipher.txt
	int cipher;
	//opens the file cipher.txt with read only permissions
	input = fopen("cipher.txt", "r");
	//reads an integer from the file and stores it in variable cipher
	fscanf(input, "%d", &cipher);
	cipher = cipher;
	//close file so that other functions can access it without experiencing any issues
	fclose(input);
	//printf("Cipher used is %d\n", cipher);//used for testing purposes to ensure that the function is reading the write value
	//returns the variable cipher as an integer so that it may then be passed to other functions as an argument
	return cipher;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/
/*allows the user to enter a cipher into the console. This cipher is then returned as an int which can be passed to other functions
like rotationEncryption(). It can also be used to create a new cipher in the event that a cipher check identifies that the cipher
being used in a function has an invalid value, such as 'a' or '-50000546540316'. Takes an argument option that determines what is
printed to the console and whether the cipher is modified before being returned at end of function.*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
int writeCipher(int option)
{
	//declaration of integer variable used to store the cipher entered by user from console and returned at end of function
	int cipher;
	//option==1 ocurrs when user is entering a cipher for encryption. The printf() statement reflects this
	if (option == 1)
	{
		printf("Please enter the value for the cipher, between 1 and 26 (If you want to you can go between -26 and 26 and everything should still work)\n");
	}
	//occurs when user is entering a cipher for decryption. The printf statement reflects this as well
	else
	{
		printf("Please enter the value of the cipher that was used to encrypt the text originally (between -26 and 26)\n");
	}
	//irrespective of argument, cipher is taken using scanf(), modification may be done later based on value stored in option
	scanf("%d", &cipher);
	/*while loop tests whether or not the cipher falls within the valid range of -26 to 26, and asks the user to input the value again
	if it does not fall within that range. It will then repeat itself until the user enters a value that is valid*/
	while (cipher < -26 || cipher > 26)
	{
		printf("\nThe value that you've entered is invalid, please try again: ");
		scanf("%d", &cipher);
	}
	//when the cipher is entered for decryption, it's sign is reversed so that rotationEncryption() applies the opposite to what the
	//text was originally encrypted with
	if (option != 1)
	{
		cipher = cipher * -1;
	}
	FILE * ciphertxt = fopen("cipher.txt", "w");
	fprintf(ciphertxt, "%d", cipher);
	fclose(ciphertxt);
	//returns the final value stored in cipher as an integer
	return cipher;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*function allows a usr to enter a key into the console, after which it will then be written to key.txt rather than being returned as
an array. I took a different approach to writeKey then I did to writeCipher as I wanted to experiment with different ways of
completing a similar objective. I also found that reading a string from a file was simpler then working with pointers and such as
would have to be done if this function was to return keyHolder rather than write it to key.txt*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
void writeKey()
{
	/*char array used to hold the values for the key that will be entered via the console. Only contains alphabet so doesn't need to
	be large.*/
	char keyHolder[27];
	/*declation and opening of file key.txt with write permissions. This will overwite the file so be careful a key that needs to be
	used again is stored in the file prior to calling this function*/
	FILE *key = fopen("key.txt", "w");
	/*n is used as a counter, while end is used in the while statement so that Brentons script won't kill the code while executing as
	it did with while(1), prelimEnd is used for control of the secondary while statement*/
	int n, end = 1, prelimEnd = 1;
	//printf prints directions for user to the screen
	printf("Please enter the key to be used to encrypt decrypt the text in upper case with no space followed by pressing the enter key, for example: QWERTYUIOPASDFGHJKLZXCVBNM\n");
	/*scanf takes user input from console and stores it in keyHolder. it is fine to user to take input in this instance as the key
	string should not contain any spaces*/
	scanf("%s", keyHolder);

	while (end != 0)
	{
		//loop will continue until key entered contains 26 characters, no duplicates and no invalid characters.
		while (prelimEnd != 0)
		{
			//unless an error is found, loop will now break once it reaches the end.
			prelimEnd = 0;
			//for loop does nothing except count the number of values contained in keyHolder
			for (n=0; keyHolder[n]!= 0; n++)
				;
			/*if the number of values counted above is less than 25(total of 26 values as n starts at 0), while loop will execute,
			prompting the user to enter a new key until they enter more than 25 characters*/
			while (n < 25)
			{
				printf("The key doesn't contain enough characters, please try again\n");
				scanf("%s", keyHolder);
					//counts characters as seen earlier in function
					for (n=0; keyHolder[n]!= 0; n++)
					;
				//an error was found, so prelimEnd is set to 1 to repeat the testing process and ensure the key is correct
				prelimEnd = 1;
			}
			//sets the 27th value and beyond to NULL, anything written beyond this point will now be ignored
			for (n=26; keyHolder[26] != 0; n++)
			{
				keyHolder[n] = 0;
			}
			//for loop moves through each value of keyHolder as n is incremented
			for (n=0; keyHolder[n] != 0; n++)
			{
				//if character is identified as lower case, 32 is subtracted to convert it to equivalent letter in upper case
				if (keyHolder[n] > 96 && keyHolder[n] < 123)
				{
					keyHolder[n] = keyHolder[n] - 32;
				}
				/*if a character is found to fall outside the decimal range for the upper case and lower case alphabet, the user
				is notified and prompted to enter in the full key again. This process will repeat until their input doesn't contain
				any invalid values, such as  '+' or '...'*/
				else if (keyHolder[n] < 65 || (keyHolder[n] > 90 && keyHolder[n] < 97) || keyHolder[n] > 122)
				{
					printf("The key entered contains an invalid character, please enter the full key again.\n");
					scanf("%s", keyHolder);
					/*for loop will start again, as n = 0, this will allow for conversion of lower case to upper case and testing
					of all characters to ocurr again*/
					n = 0;
					//prelim end is set to 1 to ensure that the entire loop is repeated again, ensuring the validity fo final key
					prelimEnd = 1;
				}
			}
			//printf("%d\n", duplicateChecker(keyHolder));
			/*duplicateChecker() is called with the string keyHolder passed as an argument. This will check the string for any
			duplicate values, such as two 'a' characters. If none are found then duplicateChecker() will return a value of 0*/
			if (duplicateChecker(keyHolder) == 1)
			{
				//asks users to input full key again
				printf("The key entered contains a duplicate, please enter the full key again.\n");
				//users enter key via console
				scanf("%s", keyHolder);
				//prelimEnd = 1 will cause the while loop to repeat, ensuring the validity of the final key
				prelimEnd = 1;
			}
		}
		end = 0;
	}
	//printf("\n%s\n", keyHolder); // used for testing
	//for loop runs until the end of keyHolder is reached, writing each character in keyHolder to key (key.txt)
	for (n = 0; keyHolder[n] != 0; n++)
	{
		fputc(keyHolder[n], key);
	}
	//closes file so that other functions don't experience issues trying to access it after this function is called
	fclose(key);
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*function that checks a string against a select group of words, and if any of those words are found in the string returns an integer
value of 1, else 0 is returned. Used during unknown rotation decryption, as it requires less words to be checked in order to identify
whether or not a piece of text has been decrypted than substituion decryption.*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
//10 Most common words - https://simple.wikipedia.org/wiki/Most_common_words_in_English
int wordChecker()
{
	//declaration of a pointer to the string returned by stringMakerOutput();
	char * stringToBeChecked;
	//int complete is used to identify whether or not a word has been found, n is used as a counter to cycle through all values in
	//stringToBeChecked
	int complete = 0, n;
	//pointer allocated to the string returned by stringMakerOutput(), which is simply a string matching the text in output.txt
	stringToBeChecked = stringMakerOutput();
	//for loop that progresses through stringToBeChecked 1 character at a time until the end of the string is reached
	for (n = 0; stringToBeChecked[n] != 0; n++)
	{
		//compares characters of stringToBeChecked with characters making up common words. If they are found to match then complete
		//is set to equal 1
		if ((stringToBeChecked[n] == 'A' && stringToBeChecked[n+1] == 'N' && stringToBeChecked[n+2] == 'D') || (stringToBeChecked[n] == 'T' && stringToBeChecked [n+1] == 'H' && stringToBeChecked[n+2] == 'E') || (stringToBeChecked[n] == 32 && stringToBeChecked[n+1] == 'I' && stringToBeChecked[n+2] == 'T' && stringToBeChecked[n+3] == ' '))// && stringToBeChecked[n+1] == 'n' && stringToBeChecked[n+2] == 'd')
		{
			complete = 1;
			break;
		}
		else if (stringToBeChecked[n] == ' ' && stringToBeChecked[n+1] == 'B' && stringToBeChecked[n+2] == 'E' && stringToBeChecked[n+3] == ' ')
		{
			complete = 1;
			break;
		}
		else if (stringToBeChecked[n] == ' ' && stringToBeChecked[n+1] == 'T' && stringToBeChecked[n+2] == 'O' && stringToBeChecked[n+3] < 'A')
		{
			complete = 1;
			break;
		}
		else if (stringToBeChecked[n] == ' ' && stringToBeChecked[n+1] == 'O' && stringToBeChecked[n+2] == 'F' && stringToBeChecked[n+3] < 'A')
		{
			complete = 1;
			break;
		}
		else if (stringToBeChecked[n] == ' ' && stringToBeChecked[n+1] == 'I' && stringToBeChecked[n+2] == 'N' && stringToBeChecked[n+3] < 'A')
		{
			complete = 1;
			break;
		}
		else if (stringToBeChecked[n] == ' ' && stringToBeChecked[n+1] == 'O' && stringToBeChecked[n+2] == 'N' && stringToBeChecked[n+3] < 'A')
		{
			complete = 1;
			break;
		}
		else if (stringToBeChecked[n] == ' ' && stringToBeChecked[n+1] == 'A'  && stringToBeChecked[n+2] == 'N' && stringToBeChecked[n+3] < 'A')
		{
			complete = 1;
			break;
		}
		else if (stringToBeChecked[n] == ' ' && stringToBeChecked[n+1] == 'D'  && stringToBeChecked[n+2] == 'O' && stringToBeChecked[n+3] < 'A')
		{
			complete = 1;
			break;
		}
		else if (stringToBeChecked[n] == ' ' && stringToBeChecked[n+1] == 'A'  && stringToBeChecked[n+2] == 'T' && stringToBeChecked[n+3] < 'A')
		{
			complete = 1;
			break;
		}
		else if (stringToBeChecked[n] == ' ' && stringToBeChecked[n+1] == 'T'  && stringToBeChecked[n+2] == 'N' && stringToBeChecked[n+3] < 'A')
		{
			complete = 1;
			break;
		}
		//used during the early stages of testing code, had an issue where extra full stops were being appended to the end of strings*/
		//possibly redundant now but left in just in case
		else if ((stringToBeChecked[n] == '.' && stringToBeChecked[n+1] == '.'))
		{
			printf("String ends");
			stringToBeChecked[n+1] = 0;
		}
	}
	//printf("String checked %s", stringToBeChecked);
	//returns 1 if a matching word was found, else returns 0. Return value then used to identify whether or not decryption was successful
	if (complete == 1)
		return 1;
	else
		return 0;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*function returns an integer if the the array passed to the function doesn't contain 26 characters. Message is also printed to the
console identifying whether or not the issues is too many or too few characters. This function is used to determine whether a key read
from a file is valid or not*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
int keyLengthCheck(char key[])
{
	//declaration of variable used to store the number of characters stored in the array that is passed to the function as an argument
	int n;
	//for loop starts at the beginning of an array and keeps incrementing n until the end of the array is reached, thus counting the
	//number of characters in the array
	for (n = 0; key[n] != 0; n++)
	{
	}
	//printf("n = %d\n", n); //used for testing
	//if key contains less than 26 characters, the function will return 1 and corresponding message will be printed
	if (n<26)
	{
		printf("The key isn't long enough\n");
		return 1;
	}
	//if key contains more than 26 characters, the function will return 2 and corresponding message will be printed
	else if (n > 26)
	{
		printf("The key is too long\n");
		return 2;
	}
	//if the key contains 26 characters, the function will return 0 and nothing will be printed
	else
		return 0;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*function used when text needs to be specified by user and written to input, such as when the user opts to enter text to encrypt or
decrypt via the console. Function takes user input from the console and writes it to input.txt, where the text can then be read by
other function*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
void plainTextWriter()
{
	//declaration and opening of file with write only privileges, into which the text will be written
	FILE * plainText = fopen("input.txt", "w");
	//declaration of inputText, which will store the string input by the user, and n which will act as a counter for for loop control
	char inputText[10000]; int n;
	//user is given instructions
	printf("Please enter the plain text you would like to encrypt or decrypt: \n");
	//reads a new line character, not strictly necessary in this instance but the scanf() below it has some interesting behaviours
	//which can be mitigated by having scanf("\n") before it
	scanf("\n");
	//takes a string, including spaces, and stores it in inputText
	scanf("%[^\n]s", inputText);
	//printf("The string you entered is %s\n", inputText); //used for testing that the string entered by user match what is stored
	/*for loop that steps through each character in array inputText, serving the dual purpose of converting any lower case characters
	to upper case, then writing all characters to file input.txt*/
	for (n = 0; inputText[n] != 0; n++)
	{
		//identifies if character is lower case, then substracts 32 to convert to equivalent upper case if required
		if (inputText[n] > 96 && inputText[n] < 123)
		{
			inputText[n] = inputText[n] - 32;
		}
		//writes each character in inputText to input.txt one character at a time.
		fputc(inputText[n], plainText);
	}
	//fprintf(plainText, "%s", inputText);
	//closes file so that other functions trying to access it won't experience any issues
	fclose(plainText);

	return;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/
/*experimental function, checks the encrypted string for words that could possibly be identified without a key, and assigns the
appropriate character to that value in the key. The result is then returned and used during unSubDecryption*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
char * subAnalysis2()
{
	//checks the file input.txt to ensure that it exists and has content that can be encrypted, if not user is prompted to enter
	static int inputTest = 1;
	inputTest = inputCheck();
	while (inputTest == 1)
	{
		inputTest = inputCheck();
	}
	//char arrays that store
	char str[10000];
	FILE *theEncryptedString = fopen("input.txt", "r");
	//array that stores the key and is returned at the end of the function
	static char key[26];
	//int n and k are used as counters later in function
	int n, k;
	/*found array helps identify whether or not a characters key has been found, and thus whether other words can be identified, may
	not	be properly implemented in final code, option is used to control switch, see switch for details*/
	int found[27], option;
	//declaration and opening of file that stores the key, which should be modified and returned as a char array at end of function
	FILE *theKey = fopen("key.txt", "r");

	//for loop 0's out all values in found array
	for (n = 0; n < 27; n++)
	{
		found[n] = 0;
	}
	//for loop reads single character from key.txt, storing in key[n], then moving on to next character until end of file is reached
	for (n = 0; feof(theKey) == 0; n++)
	{
		fscanf(theKey, "%c", &key[n]);
		if (key[n] == EOF)
			break;
	}
	//file is closed to minimise the risk of issues ocurring when other functions try to access it
	fclose(theKey);
	/*for loop read single character from input.txt at a time, storing in str[n] then moving on until end of file is
	reached*/
	for (n = 0; feof(theEncryptedString) == 0; n++)
	{
		fscanf(theEncryptedString, "%c", &str[n]);
		if (str[n] == EOF)
			break;
	}

	//printf("String in subanalysis2 is %s\n", encryptedString);
	/*template
	for (n=0; str[n] != 0; n++)
	{
		if (test the values)
		{
			char keyLocation = key[keyLocation];
			for (k = 0; key[k] != 0; k++)
			{
				switch(option)
				{
					case 1:
						if (key[k] == str[n])
						{
							key[keyLocation] = str[n];
							key[k] = keyLocation;
							k = 0;
							option = 2;
						}
						break;
					case 2:
						if (key[k] == str[n+1])
						{
							key[keyLocation] = str[n+1];
							key[k] = keyLocation;
							k = 0;
						}
						break;
				}
			}
			found[keyLocation] = 1;
			found[keyLocation] = 1;
			break;
		}
	}*/
	/*for loop steps trough every value of the encrypted string until a section that could match the decrypted word 'DID'
	after which, appropriate values are assigned to key array and  the loop breaks*/
	for (n=0; str[n] != 0; n++)
	{
		//printf("%d\n", (int)str[n]); //used for testing
		/*if statement checks for four conscutive characters, including three letters and a space, with the first letter
		matching the third letter*/
		if ((int)str[n] > 65 && str[n+1] > 65 && str[n+2] == str[n] && str[n+3] == ' ')// && (int)str[n+1] > 65 && str[n+2]== str[n])
		{
			//variables are used to hold the values of keys so that they aren't lost when swapping values
			char three = key[3];
			char eight = key[8];
			//for loop moves through key array until end of array is rached
			for (k = 0; key[k] != 0; k++)
			{
				/*if statements check to see whether or not values in key matches the letter's suspected of making up
				the decrypted word 'DID', when a match is found, the key is overwritten with the value that was stored
				in key location where the proper key needs to be stored*/
				if (key[k] == str[n])
					key[k] = three;
				else if (key[k] == str[n+1])
					key[k] = eight;
			}
			//stores the proper key in the appropriate location
			key[3] = str[n];
			key[8] = str[n+1];
			//printf("%c%c%c\n", str[n], str[n+1], str[n+2]); // used for testing
			/*setting values to 1 identifies that the appropriate character fro key[3] and key[8] have been found, and that
			identification of other words relying on these characters can be undertaken*/
			found[3] = 1;
			found[8] = 1;
			//breaks out of the for loop, as a word has already been found and no purpose is served by repeating process
			break;
		}
	}
	/*for loop steps trough every value of the encrypted string until a section that could match the decrypted word 'DID'
	after which, appropriate values are assigned to key array and  the loop breaks*/
	for (n=0; str[n] != 0; n++)
	{
		//if statement checks for consecutive characters that may make up decrypted word 'THAT'
		if (str[n] == ' ' && str[n+1] > 64 && str[n+2] > 64 && str[n+3] > 64 && str[n+4] == str[n+1] && str[n+5] == ' ')
		{
			//variables are used to hold the values of keys so that they aren't lost when swapping values
			char nineteen = key[19];
			char seven = key[7];
			//printf("This is seven%c\n", seven); // used for testing
			char zero = key[0];
			//option controls switch statement below
			option = 1;
			//for loop moves through key array until end of array is rached
			for (k = 0; key[k] != 0; k++)
			{
				/*switch statement is used as using only if statements caused two H's to be written to key, controlling
				the order in which the key values are swapped from first to last in alphabet prevents this from happening
				and this control is achieved through the if statement*/
				switch(option)
				{
					case 1:
						if (key[k] == str[n+3])
						{
							//printf("K for a is %d\n", k); //used for testing
							/*character suspected of being appropriate key is swapped with character currently in the
							location that suspected character would be required to be in in order for key to be accurate*/
							key[0] = str[n+3];
							key[k] = zero;
							//k is reset to 0 so that all values of key are tested in next case
							k = 0;
							//moves execution to next loop once keys have been swapped and if statement exits
							option = 2;
						}
						break;
					case 2:
						if (key[k] == str[n+2])
						{
							//printf("K for h is %d\n", k); //used for testing
							//see case 1 for info
							key[7] = str[n+2];
							key[k] = seven;
							k = 0;
							option = 3;
						}
						break;
					case 3:
						if (key[k] == str[n+1])
						{
							//printf("K for t is %d\n", k); //used for testing
							//see case 1 for info
							key[19] = str[n+1];
							key[k] = nineteen;
							option = 4;
							break;
							//k is not required to be reset or option changed, as all values have been set
						}
						break;
				}
			}
			//printf("here is %c%c%c%c\n", str[n+1], str[n+2], str[n+3], seven); //used for testing
			/*setting values to 1 identifies that the appropriate character fro key[3] and key[8] have been found, and that
			identification of other words relying on these characters can be undertaken*/
			found[19] = 1;
			found[7] = 1;
			found [0] = 1;
			break;
		}
	}

	if (found[3] == 1 && found[0] == 1)
	{
		for (n=0; str[n] != 0; n++)
		{
			if (str[n] == ' ' && str[n+1] == key[0] && str[n+2] > 64 && str[n+3] == key[3] && str[n+4] < 64)
			{
				char fourteen = key[14];
				for (k = 0; key[k] != 0; k++)
				{
					if (key[k] == str[n+2])
					{
						key[14] = str[n+2];
						key[k] = fourteen;
					}
				}
				found[14] = 1;
				break;
			}
			break;
		}
	}

	if (found[3] == 1)
	{
		for (n=0; str[n] !=0; n++)
		{
			if (str[n] == ' ' && str[n+1] == key[3] && str[n+2] > 64 && str[n+3] < 64)
			{
				char fourteen = key[14];
				for (k = 0; key[k] != 0; k++)
				{
					if (key[k] == str[n+2])
					{
						key[k] == fourteen;
					}
				}
				key[14] = str[n+2];
				found[14] = 1;
				break;
			}
		}
	}
	if (found[19] == 1 && found [7] == 1 && found [0] == 1)
	{
		for (n=0; str[n] !=0; n++)
		{
			if (str[n] == ' ' && str[n+1] == key[19] && str[n+2] == key[7] && str[n+3] == key[0] && (str[n+4] > 64 &&str[n+4] != key[19]) && str[n+5] < 64)
			{
				char thirteen = key[13];
				for (k = 0; key[k] != 0; k++)
				{
					if (key[k] == str[n+4])
					{
						key[k] == thirteen;
					}
				}
				key[13] = str[n+4];
				break;
			}
		}
	}


	for (n=0; str[n] != 0; n++)
	{
		if (str[n] == key[19] && str[n+1] == key[7] && str[n+2] > 64 && str[n+3] == ' ')
		{
			char four = key[4];
			for (k = 0; key[k] !=0; k++)
			{
				if (key[k] == str[n+2])
					key[k] = four;
			}
			key[4] = str[n+2];
		break;
		}
	}
	for (n = 0; str[n] != 0; n++)
	{
		if (str[n] == key[19] && str[n+1] ==key[7] && str[n+2] == key[4] && str[n+3] > 64 && str[n+4] == ' ')
		{
			char thirteen = key[13];
			for (k = 0; key[k] != 0; k++)
			{
				if (key[k] == str[n+3])
					key[k] = thirteen;
			}
			key[13] = str[n+3];
		}
		if (str[n] == key[8] && str[n+1] == key[19] && str[n+2] == '\'' && str[n+3] > 64)
		{
			char eighteen = key[18];
			for (k = 0; key[k] != 0; k++)
			{
				if (key[k] == str[n+3])
					key[k] = eighteen;
			}
			key[18] = str[n+3];
		}
		if (str[n] == ' ' && str[n+1] == key[4] && str[n+2] > 64 && str[n+3] == key[4] && str[n+4] > 64 && str[n+5]  == ' ')
		{
			char twentyOne = key[21];
			char seventeen = key[17];
			for (k=0;key[k] != 0; k++)
			{
				if (key[k] == str[n+2])
					key[k] = twentyOne;
				else if (key[k] == str[n+4])
					key[k] = seventeen;
			}
			key[21] = str[n+2];
			key[17] = str[n+4];
		}
		if(str[n] == ' ' && str[n+1] == key[13] && str[n+2] > 64 && str[n+3] == key[19] && str[n+4] == ' ')
		{
			char fourteen = key[14];
			for (k = 0; key[k] !=0; k++)
			{
				if (key[k] == str[n+2])
					key[k] = fourteen;
			}
			key[14] = str[n+2];
		}
		int end = 1;
		if (end == 1 && str[n] == ' ' && str[n+1] == key[14] && str[n+2] > 64 && str[n+2] != key[17] &&  str[n+3] ==' ')
		{
			char five = key[5];
			for (k = 0; key[k] != 0; k++)
			{
				if (key[k] == str[n+2])
					key[k] = five;
			}
			key[14] = str[n+1];
			key[5] = str[n+2];
			end = 0;
			break;
		}
	}
	for (n = 0; str[n] != 0; n++)
	{
	}
	for (n=0; str[n] != 0; n ++)
	{

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
	printf("%s\n", key);
	//closes the file input.txt to reduce the risk of issues when other functions try to access it
	fclose(theEncryptedString);
	//fclose(theKey);
	return key;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*function analyses a piece of encrypted text read from input.txt, then generates a key based on the frequency of decrypted letters
occuring compared to the frequency of unencrypted letters.
Unencrypted letters from most to least common are ordered : e t a o i u s h r d l c u m w f g y p b v k j x q z
It is thus assumed that the most common letter in the encrypted text is e when decrypted, second most common is t when decrypted...
through to z being the least common when decrypted. The key produced is then written to key.txt, after which it can be used by
substitutionDecryption() function, or manipulated by other functions, such as keyModifier().
/*----------------------------------------------------------------------------------------------------------------------------------*/
void subAnalysis()
{
	//encryptedString will store the string being analysed, while key will store the key that is being produced
	char encryptedString[10000], key[26];
	/*checks the contents of input.txt, if file doesn't exist or doesn't contain any letters than user is prompted to re-enter
	contents via console. This process repeats itself until no issues are found*/
	static int inputTest = 1;
	inputTest = inputCheck();
	while (inputTest == 1)
	{
		inputTest = inputCheck();
	}
	//declaration and opening of files being used during function, input with read only permissions and output with write only
	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("key.txt", "w");
	//pointer to integer, will be used to point to return value of stringCount()
	int *strCount;
	//a stores the value of n for which strCount > count (see below), n and counter are both used to help control for loops and count
	//holds the value for the highest number of times a character occurs in a string as returned by stringCount()
	int a, n, counter, count;

	//for loop intended to run until the end of input is reached, allowing each character of input.txt to be stored in encryptedString
	for (n = 0; feof(input) == 0; n++)
	{
		//reads each character in input.txt, storing it in encryptedString[n] then moving forward after each iteration
		fscanf(input, "%c", &encryptedString[n]);
		//triggered when input reaches end of file, resulting in execution breaking out of for loop and moving on
		if (encryptedString[n] == EOF)
			break;
		//printf("String Tested is %s\n", str);
	}
	//stringCount(encryptedString) returns a pointer to an array containing a count for the number of time each character
	//is found in encryptedString. strCount is then used as a pointer to these values.
	strCount = stringCount(encryptedString);

	//for loop that repeats 26 times, each time finding the most frequent letter, storing it in key in order outlined above fuction
	//that letter is then set to a frequency of -1 and the process repeats itself, finding the next most common letter until all
	//letters have been assigned a place in c.
	for (counter = 0; counter <26; counter ++)
	{
		//count is zeroed out so that it doesn't carry it's value over from the last loop iteration
		count = 0;
		//for loop that compares the value stored in strCount[n] with the current highest value, stored in count. If strCount
		//is greater it replaces the value in count, and a takes the value of n (which helps identify the letter later). This
		//process then repeats itself until frequency of all 26 letters have been compared
		for (n = 0; n<26; n++)
		{
			//printf("stringCounttext %d\n", strCount[n]); //used for testing
			//static int count = 0;
			if (strCount[n] >= count)
			{
				count = strCount[n];
				a = n;
				//holds the value in the string that corresponds to the letter in the alpahbet
				//i.e. a=0, b=1,... z=26
		 	}

		}
		//Most frequent value is set to -1 so that it is essentially ignored during following iterations
		strCount[a] = -5;
		//switch based on counter allows key to be filled sequentially based on letter frequency outlined above
		switch (counter)
		{
			//assuming the first most frequent letter in the encrypted text was 'R', a would have a value of 17. To create R
			//from 17, 65 is added to a, which equals 82, the ASCII decimal value for R, which would then be assigned to key[4]
			//counter would then be incremented in the for loop, the second most common encrypted letter would then be assigned
			//to key[19], counter incremented, third most common letter to key[0] etc. until all characters have been assigned.
			//for full order see description above function
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
	//loop that writes each character in key to the file output points to, one at a time until all 26 characters are written
	for (n = 0; n < 26; n++)
	{
		fputc(key[n], output);
	}
	//close the files used so that other functions that try to access them don't experience any issues
	fclose(input);
	fclose(output);
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*returns 1 if a letter in a string is found more than once, else returns 0. the string being checked is passed as an argument of
function*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
int duplicateChecker(char * someString)
{
	//declaration of n used as a varialbe to assist in for loop control
	int n = 0;
	//declaration of pointer used when referencing a value required to be accessed from the return of stringCount()
	int *strCount;
	/*stringCount(someString) returns the frequency of letters in an char array passed to the function as an argument, in this instance
	someString. The return takes the form of an array of integers. These individual values are accessed using strCount*/
	strCount = stringCount(someString);

	//for loop cycles through all of the values returned by stringCount(someString).
	for (n = 0; n<=25; n++){
		//printf("stringCount key%d\n", strCount[n]); used for testing
		//If any value strCount[n] is greater than 1, it means that a character appeared more than once. This triggers
		//the if statement causing the function to return a value of 1.
		if (strCount[n] > 1)
			return 1;
	}
	//for all 26 values that can be accessed with strCount, if none are greater than 1 then the function returns 0, thus communicating
	//that the string tested doesn't contain any duplicate alphabetical values
	return 0;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*function that passes a char array as an argument, counts the number of times each value appears within that array and then returns
those values as a pointer to an integer array.
/*----------------------------------------------------------------------------------------------------------------------------------*/
int *stringCount(char str[])
{
	//declaration of array used to store how many times each value appears within the char array.
	//result will be formatted such that the number of A ocurrences will be stored in strCount[0], number of B ocurrences will be
	//stored in strCount[1], ..., number of Z ocurrences will be stored in strCount[25]
	static int strCount[26];
	//declaration of integer variable used to assist with for loop control.
	int n;

	//for loop zeros out each value in the array, just in case the memory locations were previously occupied by non-zero stuff
	for (n = 0; n < 26; n ++)
	{
		strCount[n] = 0;
	}
	//for loop steps through each character in the array until the end of the array is reached.
	for (n = 0; str[n] != 0; n++)
	{
		//switch statement determines which location in strCount is incremented based on str[n]. e.g. if str[n] == 'D' then
		//strCount[3]++
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
	//once for loop ends, the final count is returned from the function.
	return strCount;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/
/*generates a semi random number and returns it as an integer. min and max are passed to the function as integers and determine the
minimum and maximum values that the function will be able to return*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
int randomNumber(int min, int max)
{
	//https://www.google.com/search?q=randomly+generate+numbers+between+two+values+in+c&oq=randomly+generate+numbers+between+two+values+in+c&aqs=chrome..69i57j0l5.18546j0j4&sourceid=chrome&ie=UTF-8#kpvalbx=1
	/*declaration of integers used in function - d will store the range between the maximum and the minimum values that are to be
	produced, x stores the result of rand()%d which is then used to calculate the
	final value that is returned (x + min)*/
	//srand(time(NULL));
	int d, x , r = rand();


	//calculates range between arguments passed to function and stores them in d
	d = max - min;
	//calculates a 'psuedo random' number with a maximum value equivalent to the range calculated above and stores it in x
	x = r % d;
	/*returns the result of adding x and the minimum value passed to the function, thus producing a random number that will always
	between the max and min arguments passed to the function*/
	return (x + min);
}
/*----------------------------------------------------------------------------------------------------------------------------------*/
/*function returns a string that randomly swaps two letters in that string. Used to generate variations of a key for unknown
subsitution decryption. The int option passed to the function determines whether or not the string modifed is read from the file
key.txt, or from the string that is passed to the function as an argument. If a string is passed to the function as an argument, only
the first 26 characters will be modified.*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
char * keyModifier(int option, char str[])
{
	/*declaration of integer varialbe used in function - b and c store random numbers between 0 and 25 which reference the two
	positions in keyHolder[] that will be swapped. n is used as a counter to help control for loop*/
	int b = randomNumber(0, 26), c = randomNumber(0, 26), n;
	//printf("%d\n", b); // used for testing
	//printf("%d\n", c); //used for testing
	/*declaration of static char array that will hold the key to be modified - declared static so that it can be returned at end of
	function*/
	static char keyHolder[26];
	//declaration of char variable d used to hold one of the char's as the values are swapped
	char d;

	/*if statement that takes the argument option and uses it to determine whether or not keyHolder will be read from file or function
	argument*/
	if (option == 1)
	{
		//declaration of file pointer and opening of file key.txt with read only privileges
		FILE *key = fopen("key.txt", "r");
		//for loop assists in storing the contents of key.txt, incrementing n after each iteration
		for (n = 0; n<27 ; n++)
		{
			//fscanf(key, "%c", &keyHolder[n]); //alternative option
			//fgetc() reads char from file and stores it in keyHolder[n], then moves on to next char with each iteration
			keyHolder[n] = fgetc(key);
			//when fgetc() reaches end of file, if statement is triggered, breaking out of the for loop.
			if (keyHolder[n] == EOF)
			{
				keyHolder[n] = 0;
				break;
			}
			//printf("String Tested is %s\n", str);
		}
		//closes the file so that other functions are able to access it without experiencing any issues
		fclose(key);
	}
	/*initiates a for loop that stores the contents of array passed to the function as an argument in the equivalent position in
	keyHolder, making the manipulation and return of the values somewhat simpler*/
	else
	{
		//for loop runs until the end of str is reached, with the value from str[n] stored in keyHolder[n]
		for(n = 0; str[n] != 0; n++)
		{
			keyHolder[n] = str[n];
		}
	}
	//printf("original key %sis\n", keyHolder);
	//stores the value of keyHolder[b] so that it isn't lost when that location is overwritten
	d = keyHolder[b];
	//overwrites the value in keyHolder[b] with the value in keyHolder[c]
	keyHolder[b] = keyHolder[c];
	//overWrites the value in keyHolder[c] with the value stored in d, which was originally stored in keyHolder[b]
	keyHolder[c] = d;

	//printf("%s\n", keyHolder); //used for testing
	//returns the modified key as a pointer to the array keyHolder
	return keyHolder;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/
/*function reads the contents of key.txt. If any lower case letters are present, they are converted to upper case and the key is
rewritten to key.txt*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
void keyCaseChange()
{
	//declaration or pointer and opening of file with read only privileges
	FILE *key = fopen("key.txt", "r");
	//declaration of char array that will be used to store the key read from key.txt
	char keyHolder[27];
	/*declration of n used to control for statement and lowerPresent, which is used to identify whether or not any lower case letters
	were found and thus whether or not key.txt needs to be rewritten*/
	int n, lowerPresent = 0;
	//reads key from key.txt and stores it in keyHolder. Can be done in this manner as there should be no spaces in key.txt
	fscanf(key, "%s", keyHolder);
	//for loop will run until the end of keyHolder string is reached
	for (n = 0; keyHolder[n] != 0; n++)
	{
		//if iteration of loop is found to have reached end of file, if statement will trigger and loop will exit
		if (keyHolder[n] == EOF)
			break;
		//identifies whether or not current char is lowercase and converts it to upper case if it is.
		else if (keyHolder[n] < 123 && keyHolder[n] > 96)
		{
			keyHolder[n] = keyHolder[n] - 32;
			//value is changed to 1, which will trigger if statement later in the function forcing key.txt to be re-written
			lowerPresent = 1;
		}
	}
	//closes files so that it can be re-opened with different privileges and not cause any conflicts
	fclose(key);
	//printf("Key was changed to \n%s\n",keyHolder); //used for testing
	//triggered if a lower case character was found in the previous for loop,
	if (lowerPresent == 1)
	{
		//opens files with appropriate permissions to rewrite the key stored in key.txt. Old key will be overwritten
		FILE *keyWrite = fopen("key.txt", "w");
		//writes the contents to key.txt as a string (only works as there are no spaces in keyHolder)
		fprintf(keyWrite, "%s", keyHolder);
		//closes file to prevent any issues when other functions try to access it later
		fclose(keyWrite);
	}
}
