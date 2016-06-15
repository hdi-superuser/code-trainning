#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> ii;
 
int main()
{
    //freopen("test.inp.c","r",stdin);
    int n,i,j,k,a,b,s[2]={0};
    vector<ii> v;
    scanf("%d%d%d",&n,&a,&b);
    for(i=0;i<n;++i)
    {
        scanf("%d%d",&j,&k);
        v.push_back(ii(j,k));
    }
    sort(v.begin(),v.end());
    j=-1;k=1e9;
    for(i=0;i<n;++i)
    {
        if(i) --s[(v[i-1].second)&1];
        while((s[1]<a || s[0]<b) && j<n) ++s[(v[++j].second)&1];
        if(j==n) break;
        k=min(k,v[j].first-v[i].first);
    }
    if(k==1e9) printf("-1");
    else printf("%d",k);
}