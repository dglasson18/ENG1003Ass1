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

/*----------------------------------------------------------------------------------------------------------------------------------*/
void rotDecChoice(char choice)
{
	int cipher;
	switch(choice)
	{
		case 97:
			rotationEncryption(readCipher());
			break;
		case 98:
			cipher = writeCipher(2);
			rotationEncryption(cipher);
			break;
		case 99:
			plainTextWriter();
			rotationEncryption(readCipher());
			break;
		case 100:
			cipher = writeCipher(2);
			plainTextWriter();
			//cipher = writeCipher(2);
			rotationEncryption(cipher);
			break;
	}
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
void subEncChoice(char choice)
{
	switch(choice)
	{
		case 97:
			substitutionEncryption(1);
			break;
		case 98:
			substitutionEncryption(2);
			break;
		case 99:
			substitutionEncryption(3);
			break;
		case 100:
			substitutionEncryption(4);
			break;
	}
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
void subDecChoice(char choice)
{
	switch(choice)
	{
		case 97:
			substitutionDecryption(1, "");
			break;
		case 98:
			substitutionDecryption(2,"");
			break;
		case 99:
			substitutionDecryption(3,"");
			break;
		case 100:
			substitutionDecryption(4,"");
			break;
	}
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
void unRotDecrypt()
{
	int m, cipher, result = 0, counter = 0;
	m = mostCommonLetter();
	while (result != 1 && counter < 50)
	{
		cipher = (-1) * rotationCipherCalculator(counter, m);
		rotationEncryption(cipher);
		result = wordChecker();
		counter = counter + 1;
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

/*----------------------------------------------------------------------------------------------------------------------------------*/
void rotationEncryption(int cipher)
{
	FILE *input;
	FILE *output;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	int end = 0;
	char str;
	//printf("%d\n", cipher);
	while (end != 1)
	{
		str = fgetc(input);
		
		if(str == EOF)
		{
			end = 1;
			break;
		}
		else
		{
			if (str > 96 && str < 123)
			{
				str = str - 32;
			}
			if (str > 64 && str  < 91)
			{
				str = str + cipher;
				if (str > 90)
					str = str - 26;
				else if (str < 65)
					str = str + 26;
			}
		}
		fputc(str, output);
	}
	fclose(input);
	fclose(output);
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
void substitutionEncryption(int option)
{
	char key[27], str;// = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','\0'};
	FILE *input;
	FILE *output;
	FILE *keyText;
	int end = 1;
	
	while (end != 0)
	{
		if (option == 1)
		{
			keyCaseChange();
		}
		else if (option == 2)
		{
			writeKey();
		}
		else if (option == 3)
		{
			plainTextWriter();
			keyCaseChange();
		}
		else if (option == 4)
		{
			plainTextWriter();
			writeKey();
		}
		
		keyText = fopen("key.txt", "r");
		fscanf(keyText, "%s", key);
		end = keyLengthCheck(key) + duplicateChecker(key);

		if (end != 0)
		{
			printf("There is something wrong with the key, please enter a new key\n");
			writeKey();
		}
	}
	printf("The key being used is %s\n", key);
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	
	while(end != 0)
	{
		str = fgetc(input);
		
		if (str == EOF)
		{
			end = 0;
			break;
		}
		else if (str > 65 && str < 123)
		{
			str = str - 32;
		}
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
		fputc(str, output);	
	}
	fclose(input);
	fclose(output);
	fclose(keyText);
}
/*----------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------*/
void substitutionDecryption(int option, char str1[])
{
	char key[27], str[10000]; //= {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','\0'};
	FILE *input;
	FILE *output;
	FILE *keyText;
	int n = 0, k = 0, end = 1;
	
	if (option == 1)
	{
		keyCaseChange();
	}
	else if (option == 2)
	{
		writeKey();
	}
	else if (option == 3)
	{
		plainTextWriter();
	}
	else if (option == 4)
	{
		plainTextWriter();
		writeKey();
	}		
	else
	{
		for (n = 0; str1[n] != 0; n++)
		{
			key[n] = str1[n];
		}
	}
	input = fopen("input.txt", "r");
	keyText = fopen("key.txt", "r");
	fscanf(keyText, "%s", key);
	output = fopen("output.txt", "w");
	n = 0;
	//char *u = "u2026";
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
		/*else if (str[n] == 85)
		{
			str[n] = 46;
			n++;
			str[n] = 46;
			n++;
			str[n] = 46;
		}*/			
		n++;
	}
	for (n = 0; str[n] != 0; n++)
	{
		for (k=0; key[k] != 0; k++)
		{
			if (str[n] == key[k])
			{
				str[n] = k + 65;
				break;
			}		
		}
		fputc(str[n], output);
	}
	
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
