#include <cstdio>
#include <cstring>
using namespace std;

#define MAXFIB 5001
#define MAXLENGTH 1050

char fib[MAXFIB][MAXLENGTH];

void generateFib();

int main()
{
	int n, len, i;
	generateFib();
	while(scanf("%d",&n)==1)
	{
		len = strlen(fib[n]);
		for(i = len-1; i >= 0; i--)
			 printf("%c",fib[n][i]);
		printf("\n");
	}
	return 0;
}

void generateFib()
{
	int i, j, a, b, carry, max, len1, len2;
	fib[0][0] = '0';
	fib[1][0] = '1';
	for(i = 2; i < MAXFIB; i++)
	{
		len1 = strlen(fib[i-2]);
		len2 = strlen(fib[i-1]);
		if(len1 > len2)
			max = len1;
		else
			max = len2;
		carry = 0;
		for(j = 0; j < max || carry; j++)
		{
			if(j < len1)
				a = fib[i-2][j] - '0';
			else
				a = 0;
			if(j < len2)
				b = fib[i-1][j] - '0';
			else
				b = 0;
			fib[i][j] = (a+b+carry)%10 + '0';
			carry = (int)((a+b+carry)/10);
		}
	}
}
