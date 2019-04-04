#include <stdio.h>

int main()
{
	char key[27] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','\0'};
	char str[50];
	scanf("%[^'\n']s", str);
	
	for (int n=0; str[n] != '\0'; n++)
	{
		for (int k=0; key[k] != '\0'; k++)
		{
			if (str[n] == 32)
			{
				str[n]=str[n];
			}
			else if (str[n] == key[k])
			{
				str[n] = k + 97;
				break;
			}

		}
	}
	printf("%s\n", str);
	return 0;
}