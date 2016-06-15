#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int n,m,a[2000],res,ans,value,sum;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++){
        ans = 0;
        for(int j=1;j<=m;j++)
            ans += (a[j] >= a[i])*(a[i]);
        ans = min(ans,n*a[i]);
        if(ans >= res){
            res = ans;
            value = a[i];
        }
    }
    printf("%d %d",value,res);
    return 0;
}
