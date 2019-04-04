#include<stdio.h> 
  
int main() 
{    
    char str[50]; 
    scanf("%[^'\n']s", str);
	
	for (int n = 0; str[n] != 0; n++)
	{
		if (str[n] == 32)
		{
			str[n] = str[n];
		}
		else if (str[n] >= 65 && str[n] <= 90)
		{
			str[n] = str[n] + 32;
		}
	}
	printf("%s\n", str);
	return 0;
}