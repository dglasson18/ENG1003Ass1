#include <stdio.h>

int main()
{
	char str[] = "jvtwsle zlualujl nlulyhavy pz h myll jvualua yldypaly aoha jhu wvaluaphssf ylwoyhzl, yldvyk, whyhwoyhzl huk/vy yldypal zlualujlz, whyhnyhwoz, hyapjslz, jvualua, dvykz huk/vy woyhzlz puav h tvyl jvtwsle, buvyaovkve vy jvucvsbalk hsalyuhapcl dopsl klspclypun aol zhtl tlhupun. aol cvjhibshyf vm aopz zlualujl whyhwoyhzly jvuahpuz hu hibukhujl vm yhylsf bzlk dvykz/woyhzlz huk jhu whyhwoyhzl zlualujlz pu h chyplaf vm dhfz aoha hyl jovzlu yhukvtsf. hzpkl myvt aopz dli ihzlk zvmadhyl ilpun bzlk hz h whyhwoyhzpun avvs vy h alea zwpuuly, pa jhu hszv il bzlk hz h cvjhibshyf ptwyvcltlua avvs. aol hyapmpjphs pualsspnlujl vm aopz whyhwoyhzl nlulyhavy pz zv zvwopzapjhalk aoha pa pz jhwhisl vm buklyzahukpun jvualea. bzl aol kpjapvuhyf vy aolzhbybz av slhyu klmpupapvuz mvy dvykz vy kpzjvcly tvyl zfuvuftz.";
	int strCount[27];
	int a, end = 10;
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
			printf("Count = %d and strCount = %d\n", count, strCount[n]);
			count = strCount[n];
			a = n; //holds the value in the string that corresponds to the letter in the alpahbet
			//i.e. a=0, b=1 etc.
	    }
	}
	
	int cipher = ((a +97) - 101);
	printf("a = %d\n", a);
	printf("Common %c\n", a+97);
	printf("%d\n", strCount[0]);
	printf("%d\n", strCount[1]);
	printf("%d\n", cipher);
	
	for (;end !=0;)
	{
		for (int n = 0; str[n] != 0; n++)
		{
			if (str[n] >= 97 && str[n] <= 122)
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
			else
			{	
				str[n] = str[n];
			}
		}
		printf("Does %s make sense?\n", str);
		scanf("%d", &end);
	}
    printf("%s", str); 
}