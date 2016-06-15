#include <stdio.h>
#include <math.h>
int main()
{
    long n, i = 2;
    double x = 0;
    scanf("%ld", &n);
    if(n==1)
        printf("3\n1\n2\n6\n");
    else if(n==3)
        printf("2\n5\n6\n");
    else
    {
        n--;
        while(1)
        {
            x += log10(i);
            if(n==(int)x)
            {
                printf("1\n%ld\n", i);
                break;
            }
            if(n<(int)x)
            {
                printf("NO");
                break;
            }
            i++;
        }
    }
    return 0;
}