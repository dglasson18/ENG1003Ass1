#include <stdio.h>

int main() 
{    
    char str[50]; 
	int cipher = -1;
    scanf("%[^'\n']s", str);
	
	for (int n = 0; str[n] != 0; n++)
		if (str[n] == 32)
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