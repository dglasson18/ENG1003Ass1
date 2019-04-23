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
char * statRotDecryption(int option);
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
char *keyModifier();

int main()
{
	//User assigns value based on choice below.
	int choice = 0, score;
	char toDecrypt[50], finalString[1000], secChoice = 0;
	int cipher, counter = 0;
	int end = 1;
	int m;
	char *string;
	//subWordComparison();
	//printf("Score: %d\n", subWordComparison());
	/*Basic User Interface
	Available functions are displayed from the user.
	They enter a value corresponding to the function that they wish to use.
	e.g. entering 2 to decrypt a message using a rotation cipher.
	This will then assign 2 to the variable choice, which will then be used
	to call the function using a switch statement.*/
	//string = stringMaker();
	//printf("%s", string);
	//printf("%c", string[0]);
	//printf("%d", wordChecker());
	printf("Available functions\n");
	printf("	(1) Encrypt message using Rotation Cipher\n");
	printf("	(2) Decrypt message using Rotation Cipher\n");
	printf("	(3) Enccypt message using Substitution Cipher\n");
	printf("	(4) Decrypt message using Substitution Cipher\n");
	printf("	(5) Decrypt message using unknown rotation cipher\n");
	printf("	(6) Decrypt message using unknown substitution cipher\n");
	
	
	while (choice < 1 || choice > 6)
	{
		printf("Please select the corresponding number for the function you wish to use: ");
		scanf("%d", &choice);
	}

	switch(choice) 
	{
	case 1:
		//This should call the function that will be used to encrypt rotation cipher
		printf("\nYou selected 'Encrypt Rotation Cipher' You can choose from the following options:\n");
		printf("	(a) Read plain text from 'input.txt' and cipher key from 'cipher.txt'\n");
		printf("	(b) Read plain text from 'input.txt' and cipher key from stdin\n");
		printf("	(c) Read plain text from stdin and cipher key from 'cipher.txt'\n");
		printf("	(d) Read plain text and cipher key from stdin\n");
		printf("\nPlease enter a letter corresponding to your preference: ");
		scanf("%c", &secChoice);
		while (secChoice < 97 || secChoice > 100)
		{
			printf("Please enter a valid option\n");
			scanf("%c", &secChoice);
		}
		switch(secChoice)
		{
			case 97:
				rotationEncryption(readCipher());
				break;
			case 98:
				cipher = writeCipher(1);
				rotationEncryption(cipher);
				break;
			case 99:
				plainTextWriter();
				rotationEncryption(readCipher());
				break;
			case 100:
				plainTextWriter();
				cipher = writeCipher(1);
				rotationEncryption(cipher);
				break;
		}
		printf("\nThe resulting string is: '%s'", stringMakerOutput());
		break;
	case 2:
		//This should call the function that will be used to decrypt rotation cipher
		printf("\nYou selected 'Decrypt Rotation Cipher' You can choose from the following options:\n");
		printf("	(a) Read plain text from 'input.txt' and cipher key from 'cipher.txt'\n");
		printf("	(b) Read plain text from 'input.txt' and cipher key from stdin\n");
		printf("	(c) Read plain text from stdin and cipher key from 'cipher.txt'\n");
		printf("	(d) Read plain text and cipher key from stdin\n");
		printf("Please enter a letter corresponding to your preference:");
		scanf("\n%c", &secChoice);
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
		switch(secChoice)
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
		/*
		scanf("%d", &cipher);
		cipher = cipher * -1;
		rotationEncryption(cipher);*/
		printf("\nThe resulting string is: '%s'", stringMakerOutput());
		break;
	case 3:
		//This should call the function that will be used to encrypt substitution cipher
		printf("Encrypt Substitution Cipher");
		printf("\nYou selected 'Decrypt Rotation Cipher' You can choose from the following options:\n");
		printf("	(a) Read plain text from 'input.txt' and cipher key from 'key.txt'\n");
		printf("	(b) Read plain text from 'input.txt' and cipher key from stdin\n");
		printf("	(c) Read plain text from stdin and cipher key from 'cipher.txt'\n");
		printf("	(d) Read plain text and cipher key from stdin\n");
		printf("Please enter a letter corresponding to your preference:");
		scanf("\n%c", &secChoice);
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
		switch(secChoice)
		{
			case 97:
				//substitutionEncryption();
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
		substitutionEncryption();
		printf("\nThe resulting string is: '%s'", stringMakerOutput());
		break;
	case 4:
		//This should call the function that will be used to decrypt substitution cipher
		printf("Decrypt Substitution Cipher");
		substitutionDecryption(1, "");
		printf("\nThe resulting string is: '%s'", stringMakerOutput());
		break;
	case 5:
		m = mostCommonLetter();
		//printf("%d\n", m);
		//cipher = (-1) * rotationCipherCalculator(0, m);
		//printf("%d\n", cipher);
		//rotationEncryption(cipher);
		//int result = wordChecker();
		//printf("%d\n", result);
		int result = 0;
		while (result != 1 && counter < 25)
		{
			cipher = (-1) * rotationCipherCalculator(counter, m);
			//printf("Testing key %d\n", cipher * -1);
			rotationEncryption(cipher);
			result = wordChecker();
			counter = counter + 1;
		}
		//finalString = stringMakerOutput();
		printf("\nThe resulting string is: '%s'", stringMakerOutput());
		break;
	case 6:
		//This should call the functions required to decrypt an unknown substitution cipher
		subAnalysis();
		substitutionDecryption(1, "");
		score = subWordComparison();
		for (int n = 0; n < 10000; n++)
		{
			char *str = keyModifier();
			substitutionDecryption(0, str);
			if (score < subWordComparison())
			{
				score = subWordComparison();
				FILE *key = fopen("keytext.txt", "w");
				fprintf(key, "%s", str);
				fclose(key);
			}
		}
		printf("\nThe resulting string isL '%s'", stringMakerOutput());
		break;
	default:
		//This will happen if user doesn't select an option from 1 to 4 or something else goes wrong
		printf("Something went wrong. You entered %d. Please enter 1, 2, 3, 4, 5 or 6 or cry because something is broken\n");
		scanf("%d", &choice);
	}
}
/*Doesn't work
const char encryptRotation(char *input[])
{
	char textToEncrypt[] = input[];
	printf("%c", textToEncrypt);
	return "fish"; //should return encrypted string when complete
}
*/
	
void rotationEncryption(int cipher)
{

	FILE *input;
	FILE *output;
	
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");

	int c, end = 0;
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

void substitutionEncryption()
{
	char key[27];// = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','\0'};
	FILE *input;
	FILE *output;
	FILE *keyText;
	
	input = fopen("test.txt", "r");
	keyText = fopen("key.txt", "r");
	output = fopen("output.txt", "w");
	fscanf(keyText, "%s", key);
	char str;
	while(1)
	{
		str = fgetc(input);
		
		if (str == EOF)
			break;
		else
		{
			switch (str)
			{
				case 97:
					str = key[0];
					break;
				case 98:
					str = key[1];
					break;
				case 99:
					str = key[2];
					break;
				case 100:
					str = key[3];
					break;
				case 101:
					str = key[4];
					break;
				case 102:
					str = key[5];
					break;
				case 103:
					str = key[6];
					break;
				case 104:
					str = key[7];
					break;
				case 105:
					str = key[8];
					break;
				case 106:
					str = key[9];
					break;
				case 107:
					str = key[10];
					break;
				case 108:
					str = key[11];
					break;
				case 109:
					str = key[12];
					break;
				case 110:
					str = key[13];
					break;
				case 111:
					str = key[14];
					break;
				case 112:
					str = key[15];
					break;
				case 113:
					str = key[16];
					break;
				case 114:
					str = key[17];
					break;
				case 115:
					str = key[18];
					break;
				case 116:
					str = key[19];
					break;
				case 117:
					str = key[20];
					break;
				case 118:
					str = key[21];
					break;
				case 119:
					str = key[22];
					break;
				case 120:
					str = key[23];
					break;
				case 121:
					str = key[24];
					break;
				case 122:
					str = key[25];
					break;
				case 123:
					str = key[26];
					break;
				default:
					break;
					str = str;
			}
			fputc(str, output);
		}
	}
	fclose(input);
	fclose(output);
	fclose(keyText);
}

void substitutionDecryption(int option, char str1[])
{
	char key[100]; //= {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','\0'};
	FILE *input;
	FILE *output;
	FILE *keyText;
	int n = 0;
	char str;
	
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	keyText = fopen("key.txt", "r");
	if (option == 1)
	{
		while(feof(keyText) == 0)
		{
			fscanf(keyText, "%c", &key[n]);
			n++;
			
		}
	}
	else
	{
		for (n = 0; str1[n] != 0; n++)
		{
			key[n] = str1[n];
		}
	}
	
	while(1)
	{
		str = fgetc(input);
		if (str == EOF)
			break;
		else
		{
			for (int k=0; key[k] != 0; k++)
			{
				if (str == 32 || str == '.' || str == '?')
				{
					str = str;
				}
				else if (str == key[k])
				{
					str = k + 65;
					break;
				}
			}
			fputc(str, output);
		}
	}
	fclose(input);
	fclose(output);
	fclose(keyText);
}

int mostCommonLetter()
{
	FILE *input;
	char str[10000];
	int n = 0, a;
	
	input = fopen("input.txt", "r");
		
	int strCount[27];
	
	while(1)
	{
		str[n] = fgetc(input);
		if (str[n] == EOF)
			break;
		else if (str[n] > 96 && str[n] < 123)
			str[n] = str[n] - 32;
		n++;
	}
	//printf("%s\n", str);
	for (n = 0; n<27; n++)
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
	
	for (n = 0; n<27; n++)
	{
		static int count = 0;
		if (strCount[n] > count)
		{
			count = strCount[n];
			a = n; //holds the value in the string that corresponds to the letter in the alpahbet
			//i.e. a=0, b=1,... z=26
	    }
	}
	printf("%d\n", a);
	return a;
}

int rotationCipherCalculator(int option, int a)
{
	int static cipher = 0;
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
char *stringMakerOutput()
{
	FILE *input;
	char fileName[100];
	static char str[1000];
	int option = 1;
	
	if (option ==0)
	{
		printf("Please enter the name of file from which to create string");
		scanf("%[^'\n']s", fileName);
		input = fopen(fileName, "r");
	}
	else
		input = fopen("output.txt", "r+");
	
	for (int n = 0; feof(input) == 0; n++)
	{
		fscanf(input, "%c", &str[n]);
		if (str[n] == EOF)
			break;
		//printf("String Tested is %s\n", str);
	}
	//printf("String Tested is %s\n", str);
	return str;
}

int subWordComparison()
{
	FILE *wordsForComparison1 = fopen("wordlist10000.txt", "r");
	//FILE *wordsForComparison2 = fopen("words2.txt", "r");
	//FILE *wordsForComparison3 = fopen("words3.txt", "r");
	char words1[100000];//, words2[1000000];
	//char words3[999999];
	int n, k = 0, score = 0,end = 1;
	FILE *decryptedString = fopen("output.txt", "r");
	char str[10000];
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
		/*
		for (k = 0; words2[k] != 0; k++)
		{
			if (str[n] == words2[k] && str[n+1] == words2[k+1] && str[n+2] == words2[k+2] && str[n+3] == words2[k+3])
			{
				score++;
			}
		}
	}
	while (end == 1)
	{
		for (n = 0; n < 5 ;n++)
		{
			fscanf(wordsForComparison1,"%c", &words1[n]);
			if (words1[n] = EOF)
			{
				printf("It Broke");
				end = 0;
				break;
			}
			else if(words1[n] > 95 && words1[n] < 123)
			{
				words1[n] = words1[n] - 32;
			}
			printf("%s\n", words1);
		}
		for (k = 0; str[k] != 0; k++)
		{
			if (str[k] == words1[0] && str[k+1] == words1[1] && str[k+2] == words1[2] && str[k+3] == words1[3])
				score++;
		}
		printf("%s\n", words1);
		score = score + 10;
	}
	printf("%d\n", score);
		
	*/
	//printf("%s\n", words1);
	//printf("%s\n", words1);
	/*
	for (n = 0; n < 999999; n++)
	{
		fscanf(wordsForComparison2, "%c", &words2[n]);
		if (words2[n] == EOF)
		{
			printf("Endofstring");
			break;
		}
		else if(words2[n] > 95 && words2[n] < 123)
		{
			words2[n] = words2[n] - 32;
		}
	}
	//printf("%s\n", words2);
			
	for (n = 0; n < 900000; n++)
	{
		//words3[n] = fgetc(wordsForComparison3);
		fscanf(wordsForComparison3, "%c", &words3[n]);
		if (words3[n] == EOF)
		{
			printf("EndofString");
			break;
		}
		else if(words3[n] > 95 && words3[n] < 123)
		{
			words3[n] = words3[n] - 32;
		}
	}
	//printf("%s\n", words3);
	*/

	
	printf("%d\n", score);
	fclose(wordsForComparison1);
	fclose(decryptedString);
	return score;
}
	

int readCipher()
{
	FILE *input;
	char c;
	int cipher;
	input = fopen("cipher.txt", "r");
	c = fgetc(input);
	cipher = c - '0';
	fclose(input);
	return cipher;
}

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
			if (duplicateChecker(keyHolder) == 0)
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
//10 Most common words - https://simple.wikipedia.org/wiki/Most_common_words_in_English
int wordChecker()
{
	char * stringToBeChecked;
	int complete = 0;
	stringToBeChecked = stringMakerOutput();
	for (int n = 0; stringToBeChecked[n] != 0; n++)
	{
		if ((stringToBeChecked[n] == 'A' && stringToBeChecked[n+1] == 'N' && stringToBeChecked[n+2] == 'D') ||(stringToBeChecked[n] == 'T' && stringToBeChecked [n+1] == 'H' && stringToBeChecked[n+2] == 'E') || (stringToBeChecked[n] == ' ' && stringToBeChecked[n+1] == 'I' && stringToBeChecked[n+2] == 'T' && stringToBeChecked[n+3] == ' '))// && stringToBeChecked[n+1] == 'n' && stringToBeChecked[n+2] == 'd')
		{
			complete = 1;
			break;
		}
		else if ((stringToBeChecked[n] == '.' && stringToBeChecked[n+1] == '.'))
		{
			printf("String ends");
			stringToBeChecked[n+1] = NULL;
		}
	}
	//printf("String checked %s", stringToBeChecked);
	if (complete == 1)
		return 1;
	else 
		return 0;
}

void plainTextWriter()
{
	FILE * plainText = fopen("input.txt", "w");
	char inputText[1000];
	
	printf("Please enter the plain text you would like to encrypt\n");
	scanf("\n");
	scanf("%[^\n]s", inputText);
	printf("The string you entered is %s\n", inputText);
	
	for (int n = 0; inputText[n] != 0; n++)
	{
		fputc(inputText[n], plainText);
	}
	//fprintf(plainText, "%s", inputText);
	
	fclose(plainText);
	
	return;
}
	

int subAnalysis()
{
	char encryptedString[10000];
	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("key.txt", "w");
	char key[26];
	int strCount[26];
	int a, n, counter;
	
	for (n = 0; feof(input) == 0; n++)
	{
		fscanf(input, "%c", &encryptedString[n]);
		if (encryptedString[n] == EOF)
			break;
		//printf("String Tested is %s\n", str);
	}
	
	/*for (n = 0; encryptedString[n] != EOF; n++)
	{
		encryptedString[n] = fgetc(input);
		if (encryptedString[n] == EOF)
		{
			printf("The end of file has been reached\n");
			break;
		}
	}
	*/
	for (n = 0; n <= 25; n++);
	{
		strCount[n] = 0;
	}

	for (n = 0; encryptedString[n] != 0; n++)
	{
		switch (encryptedString[n])
		{
			case 65:
				strCount[0]++;
				break;
			case 66:
				strCount[1] = strCount[1] + 1;
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
	for (counter = 0; counter <26; counter ++)
	{
		int count = 0;
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
		strCount[a] = 0;
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
	/*
	for (n = 0; encryptedString[n] != 0; n++)
	{
		if (encryptedString[n] == " " && (encryptedString[n+1] < 91 && encryptedString[n+1] > 64) && (encryptedString[n+2] < 91 && encryptedString[n+2] > 64) && (encryptedString[n+3] < 91 && encryptedString[n+3] > 64) && encryptedString[n+4] == " ")
		{
			key[19] = encryptedString[n+1];
			key[7] = encryptedString[n+2];
			key[4] = encryptedString[n+3];
		}
		else if (encryptedString[n] == " " && encryptedString[n+1] > 64 && encryptedString[n+2] == " ")
			key[0] = encryptedString[n+1];
	}*/
	for (n = 0; n < 26; n++)
	{
		fputc(key[n], output);
	}
	fclose(input);
	fclose(output);
	
}	

//returns 0  if a letter in a string is found more than once, else returns 1
int duplicateChecker(char * someString)
{
	int n = 0;
	int strCount[26];
	
	for (n = 0; n <= 25; n++)
	{
		strCount[n] = 0;
	}
	for (n = 0; someString[n] != 0; n++)
	{
		switch (someString[n])
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

	for (n = 0; n<=25; n++)
	{
		if (strCount[n] > 1)
			return 0;
	}
	return 1;
}
int randomNumber(int min, int max)
{
	//https://www.google.com/search?q=randomly+generate+numbers+between+two+values+in+c&oq=randomly+generate+numbers+between+two+values+in+c&aqs=chrome..69i57j0l5.18546j0j4&sourceid=chrome&ie=UTF-8#kpvalbx=1
	int d, r, x;
	d = max - min;
	r = rand();
	
	x = r % d;
	return (x + min);
}

char * keyModifier()
{
	int b = randomNumber(0, 25),n, d;
	printf("%d\n", b);
	char c = (char)randomNumber(65, 90);
	printf("%c\n", c);
	static char keyHolder[27];
	FILE *key = fopen("key.txt", "r");
	int end = 1, prelimEnd = 1;
	
	for (n = 0; feof(key) == 0; n++)
	{
		fscanf(key, "%c", &keyHolder[n]);
		if (keyHolder[n] == EOF)
			break;
		//printf("String Tested is %s\n", str);
	}
	fclose(key);
	for (n = 0; keyHolder[n] != c; n++)
	{
		if (keyHolder[n] == c)
		{
			keyHolder[n] = keyHolder[b];
			break;
		}
	}
	keyHolder[b] = c;
	/*
	FILE *key = fopen("key.txt", "w");
	for (n = 0; keyHolder[n] != 0; n++)
	{
		fputc(keyHolder[n], key);
	}
	fclose(key);*/
	printf("%s\n", keyHolder);
	return keyHolder;
}
