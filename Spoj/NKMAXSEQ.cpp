#include <bits/stdc++.h>
using namespace std;
 
int n,p;
vector<int> s;
vector<bool> d;
 
void Init()
{
    cin>>n>>p;
    s.resize(n+2);    d.resize(n+2);
    d[0]=true;
    int min=0, tg;
    for (int i=1;i<=n;i++)
    {
        cin>>tg;
        s[i]=s[i-1]+tg;
        if(s[i]<min)
        {
            d[i]=true;
            min=s[i];
        }
    }
}
 
void Solve()
{
    int res=-1, pos=n;
    for(int i=n;i>=0;i--)
        if(d[i])
            while(pos>i)
            {
                if(s[pos]-s[i]>=p)
                {
                    res=max(res,pos-i);
                    break;
                }
                pos--;
            }
            cout<<res;
}
 
int main()
{
    Init();
    Solve();
}