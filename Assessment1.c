#include <stdio.h>
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
char encryptRotation();

int main()
{
	//User assigns value based on choice below.
	int choice = 0;
	
	/*Basic User Interface
	Available functions are displayed from the user.
	They enter a value corresponding to the function that they wish to use.
	e.g. entering 2 to decrypt a message using a rotation cipher.
	This will then assign 2 to the variable choice, which will then be used
	to call the function using a switch statement.*/
	printf("Available functions\n");
	printf("	(1) Encrypt message using Rotation Cipher\n");
	printf("	(2) Decrypt message using Rotation Cipher\n");
	printf("	(3) Enccypt message using Substitution Cipher\n");
	printf("	(4) Decrypt message using Substitution Cipher\n\n");
	
	
	while (choice < 1 || choice > 4)
	{
		printf("Please select the corresponding number for the function you wish to use: ");
		scanf("%d", &choice);
	}

	switch(choice) 
	{
	case 1:
		//This should call the function that will be used to encrypt rotation cipher
		printf("Encrypt Rotation Cipher");
		encryptRotation();
		break;
	case 2:
		//This should call the function that will be used to decrypt rotation cipher
		printf("Decrypt Rotation Cipher");
		break;
	case 3:
		//This should call the function that will be used to encrypt substitution cipher
		printf("Encrypt Substitution Cipher");
		break;
	case 4:
		//This should call the function that will be used to decrypt substitution cipher
		printf("Decrypt Substitution Cipher");
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
	
char encryptRotation()
{
	char str1[100];
	printf("Please enter the string you would like to encrypt");
	scanf("%s\n", str1);
	
	char str2[100];
	int f;
	f=0;
	while(str1[f] != 0)
	{
		str2[f]=str1[f]+1;
		printf("%c\n", str1[f]);
		printf("%d\n", f);
		printf("%s\n", str2);
		f++;
	}
	
	return str1;
}
/*Possible Functions
	- rotationEncrypt
    - rotationDecrypt
	- substitutionEncrypt
	- substitutionDecrypt
*/
