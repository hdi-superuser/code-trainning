#include <stdio.h>
#include <string.h>
int main()
{
    //freopen("ltpmseq.in", "r", stdin);
    //freopen("ltpmseq.out", "w", stdout);
    char st[16];
    int r[15] = {0};
    int n, i;
    scanf("%d\n", &n);
    while(n--)
    {
        gets(st);
        i = strlen(st)-1;
        for(;i>=0; i--)
        {
            r[i] = r[i]^(st[i]-'0');
        }
    }
    for(i=0; i<15; i++)
    {
        if(r[i]==0) break;
        st[i] = r[i]+'0';
    }
    st[i] = '\0';
    puts(st);
    return 0;
}