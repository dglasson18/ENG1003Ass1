#include <stdio.h>
/*Program should be able to do the following to achieve full marks:
	- Encrypt a message using a rotation cipher given the message text and rotation amount
	- Decrypt a message using a rotation cipher given cipher text and rotation amount
	- Encrypt a message using a substitution cipher given message text and alphabet substitution
	- Decrypt a message encrypted using a substitution cipher given cipher text and substitutions
	- Decrypt a message encrypted using a rotation cipher given cipher text only
	- Decrypt a message encrypted with a subtitution cipher given cipher text only
*/
char str12[1000];

char completeString[1000];
/*Function Headers
const char encryptRotation(char *input[]);
*/
char * rotationEncryption(int cipher);
char * substitutionEncryption();
char * substitutionDecryption();
char * rotationDecryption();
char * statRotDecryption(int option);
int mostCommonLetter();
int rotationCipherCalculator(int option, int a);
char *stringMaker();
int wordChecker(); //returns 1 if the decrypted cipher creates a common word such as 'and' or 'the'

int main()
{
	//User assigns value based on choice below.
	int choice = 0;
	char toDecrypt[50];
	int cipher, counter = 0;
	int end = 1;
	int m;
	char *string;
	int c = mostCommonLetter();
	printf("%d\n", c);
	
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
	
	
	while (choice < 1 || choice > 5)
	{
		printf("Please select the corresponding number for the function you wish to use: ");
		scanf("%d", &choice);
	}

	switch(choice) 
	{
	case 1:
		//This should call the function that will be used to encrypt rotation cipher
		printf("You selected 'Encrypt Rotation Cipher' Please enter the key: ");
		scanf("%d", &cipher);
		rotationEncryption(cipher);
		break;
	case 2:
		//This should call the function that will be used to decrypt rotation cipher
		printf("You selected 'Decrypt Rotation Cipher' Please enter the key that was used: ");
		scanf("%d", &cipher);
		cipher = cipher * -1;
		rotationEncryption(cipher);
		break;
	case 3:
		//This should call the function that will be used to encrypt substitution cipher
		printf("Encrypt Substitution Cipher");
		substitutionEncryption();
		break;
	case 4:
		//This should call the function that will be used to decrypt substitution cipher
		printf("Decrypt Substitution Cipher");
		substitutionDecryption();
		break;
	case 5:
		m = mostCommonLetter();
		printf("%d\n", m);
		//cipher = (-1) * rotationCipherCalculator(0, m);
		//printf("%d\n", cipher);
		//rotationEncryption(cipher);
		//int result = wordChecker();
		//printf("%d\n", result);
		int result = 0;
		while (result != 1 && counter < 25)
		{
			cipher = (-1) * rotationCipherCalculator(counter, m);
			printf("Testing key %d\n", cipher * -1);
			rotationEncryption(cipher);
			result = wordChecker();
			counter = counter + 1;
		}
		printf("%s", str12);
		break;
	default:
		//This will happen if user doesn't select an option from 1 to 4 or something else goes wrong
		printf("Something went wrong. You entered %d. Please enter 1, 2, 3, 4 or cry because something is broken\n");
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
	
char * rotationEncryption(int cipher)
{
    /*char str[50]; 
	int cipher;
	printf("Please enter text to be encrypted:");
    scanf("%s[^\n]", str);
	printf("Please enter the cipher key:\n");
	scanf("%d\n", &cipher);
	*/
	FILE *input;
	FILE *output;
	
	input = fopen("test.txt", "r");
	output = fopen("output.txt", "w");
	
	/*char str[1000];
	
	fscanf(input, "%s", &str);
	int n;
	for (n = 0; str[n] != 0; n++);
	{
		if (str[n] > 96 && str[n] < 123)
		{
			str[n] = str[n] - 32;
		}
		if (str[n] > 64 && str [n] < 91)
		{
			str[n] = str[n] + cipher;
			if (str[n] > 90)
				str[n] = str[n] - 26;
			else if (str[n] < 65)
				str[n] = str[n] + 26;
		}
		printf("%s", str);
		//fprintf(output, "%", str[n]);
	}
	fprintf(output, "%s", str[n]);
	fclose(output);
	fclose(input);
}
*/
	int c;
	char str;
	
	while (1)
	{
		str = fgetc(input);
		
		if(str == EOF)
			break;
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
/*				
		//if (feof(input) != 0)
			//break;
		
		fscanf(input, "%c", &str);

		if (str == 32 || str == '?' || str == '.' || str == ':' || str == '\'')
		{	
			;
		}			

		else
		{
			if (str>64 && str <91)
				str = str + 32;
			str = str + cipher;
			if (str >= 123 || str < 0)
			{
				if (str >= 123)
				{
					str = str-26;
				}
				else if (str < 0)
				{
					str = -1 * str -18;
				}
			}
			else if (str <= 96)
			{
				str = str + 26;
			}
		}
		fprintf(output, "%c", str);
	}
	fclose(output);
}
*/

char * substitutionEncryption()
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

char * rotationDecyption()
{    
    char str[50]; 
	int cipher = -1;
    scanf("%[^'\n']s", str);
	
	for (int n = 0; str[n] != 0; n++)
		if (str[n] == 32 || str[n] == 58 || str[n] == 46 || str[n] == 44)
		{	
			str[n] = str[n];
		}
		else
		{
			str[n] = str[n] - cipher;
			if (str[n] >= 123 || str[n] < 0)
			{
				if (str[n] >= 123)
				{
					str[n] = str[n]-26;
				}
				else if (str[n] < 0)
				{
					str[n] = -1 * str[n] -18;
				}
			}
			else if (str[n] <= 96)
			{
				str[n] = str[n] + 26;
			}
		}
    printf("%s", str); 
  
    return 0; 
}

char * substitutionDecryption()
{
	char key[100]; //= {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','\0'};
	FILE *input;
	FILE *output;
	FILE *keyText;
	int n = 0;
	char str;
	
	input = fopen("test.txt", "r");
	output = fopen("output.txt", "w");
	keyText = fopen("key.txt", "r");
	
	while(feof(keyText) == 0)
	{
		fscanf(keyText, "%c", &key[n]);
		n++;
		
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
					str = k + 97;
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

char * statRotDecryption(int option)
{
	FILE *input;
	FILE *output;
	char str[1000];
	int n = 0, cipher;
	
	input = fopen("test.txt", "r");
	output = fopen("output.txt", "r+");
	
	int strCount[27];
	int a, fish = 10;
	
	while(feof(input) == 0)
	{
		fscanf(input, "%c", &str[n]);
		if (str[n] > 64 && str[n] < 91)
			str[n] = str[n] + 32;
		n++;
		
	}
	for (int n = 0; n<27; n++)
		strCount[n] = 0;
	for (int n = 0; str[n] !=0; n++)
	{
		switch (str[n])
		{
			case 97:
				strCount[0]++;
				break;
			case 98:
				strCount[1]++;
				break;
			case 99:
				strCount[2]++;
				break;
			case 100:
				strCount[3]++;
				break;
			case 101:
				strCount[4]++;
				break;
			case 102:
				strCount[5]++;
				break;
			case 103:
				strCount[6]++;
				break;
			case 104:
				strCount[7]++;
				break;
			case 105:
				strCount[8]++;
				break;
			case 106:
				strCount[9]++;
				break;
			case 107:
				strCount[10]++;
				break;
			case 108:
				strCount[11]++;
				break;
			case 109:
				strCount[12]++;
				break;
			case 110:
				strCount[13]++;
				break;
			case 111:
				strCount[14]++;
				break;
			case 112:
				strCount[15]++;
				break;
			case 113:
				strCount[16]++;
				break;
			case 114:
				strCount[17]++;
				break;
			case 115:
				strCount[18]++;
				break;
			case 116:
				strCount[19]++;
				break;
			case 117:
				strCount[20]++;
				break;
			case 118:
				strCount[21]++;
				break;
			case 119:
				strCount[22]++;
				break;
			case 120:
				strCount[23]++;
				break;
			case 121:
				strCount[24]++;
				break;
			case 122:
				strCount[25]++;
				break;
			default:
				break;
		}
	}
	for (int n = 0; n<27; n++)
	{
		static int count = 0;
		if ((int)strCount[n] > count)
		{
			count = strCount[n];
			a = n; //holds the value in the string that corresponds to the letter in the alpahbet
			//i.e. a=0, b=1 etc.
	    }
	}
	if (option == 0)
	{
		cipher = a + 97 - 101;
		printf("Cipher 0 Working");
	}
	else if (option ==1)
	{
		cipher = a + 97 - 116;
		printf("Cipher 1 Working");
	}
	else if (option == 2)
	{
		cipher = a;
		printf("Cipher 2 Working");
	}
	else if (option == 3)
	{
		cipher = a + 97 - 111;
		printf("Cipher 3 Working");
	}
	
		
	if (cipher <= 0 )
	{
		cipher = cipher + 26;
		printf("Cipher adjusted");
	}	
	
	char strCopy[1000];
	for (int n = 0; str[n] != 0; n++)
	{
		strCopy[n] = str[n];
}		
	for (;fish !=0;)
	{
		printf("Entered initial for loop");
		for (int n = 0; str[n] != 0; n++)
		{
			
			
			if (strCopy[n] == 32 || strCopy[n] == 58 || strCopy[n] == 46 || strCopy[n] == 44 || strCopy[n] == 47)
			{	
				strCopy[n] = strCopy[n];
			}
			else
			{
				strCopy[n] = strCopy[n] - cipher;
				if (strCopy[n] >= 123 || strCopy[n] < 0)
				{
					if (strCopy[n] >= 123)
					{
						strCopy[n] = str[n]-26;
					}
					else if (strCopy[n] < 0)
					{
						strCopy[n] = -1 * str[n] -18;
					}
				}
				else if (strCopy[n] <= 96)
				{
					strCopy[n] = strCopy[n] + 26;
				}
			}
		}
		fish = 0;
		printf("%s", strCopy);
	}
	fprintf(output, "%s", strCopy);
    return str; 
}

int mostCommonLetter()
{
	FILE *input;
	char str[1000];
	int n = 0, a;
	
	input = fopen("test.txt", "r");
		
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
	for (int n = 0; n<27; n++)
	{
		strCount[n] = 0;
	}
	for (int n = 0; str[n] !=0; n++)
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
	
	for (int n = 0; n<27; n++)
	{
		static int count = 0;
		if (strCount[n] > count)
		{
			count = strCount[n];
			a = n; //holds the value in the string that corresponds to the letter in the alpahbet
			//i.e. a=0, b=1,... z=26
	    }
		printf("a = %d\n", a);
	}
	return a;
}

int rotationCipherCalculator(int option, int a)
{
	int static cipher;
	switch (option)
	{
		case 0:
			cipher = a + 97 - 101;
			printf("Cipher 0 Working");
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
		default:
			cipher++;
	}
	return cipher;
}
char *stringMaker()
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
	
//10 Most common words - https://simple.wikipedia.org/wiki/Most_common_words_in_English
int wordChecker()
{
	char * stringToBeChecked;
	int complete = 0;
	stringToBeChecked = stringMaker();
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
	printf("String checked %s", stringToBeChecked);
	if (complete == 1)
		return 1;
	else 
		return 0;
}

int subAnalysis()
{
	char encryptedString[1000];
	file *input = fopen("test.txt", "r");
	
	for (int n = 0; encryptedString[n] != FEOF; n++)
		encryptedString[n] = fgetc(input)
		if (encryptedString == FEOF)
			break;
		else
			

