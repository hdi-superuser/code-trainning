
#include <bits/stdc++.h>
#define fs first
#define sc second
using namespace std;
typedef pair<int,int> II;
    int n,x[10001],y[10001],f[10001][10001];
int main()
{
    //freopen("mpilot.inp","r",stdin);
    //freopen("mpilot.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d%d",&x[i],&y[i]);
    f[1][1]=y[1];
    for(int i=2; i<=n; i++)
    {
        f[i][0]=f[i-1][1]+x[i];
        f[i][i]=f[i-1][i-1]+y[i];
        for(int j=1; j<=i-1; j++)
            f[i][j]=min(f[i-1][j-1]+y[i],f[i-1][j+1]+x[i]);
    }
    printf("%d",f[n][0]);
}
