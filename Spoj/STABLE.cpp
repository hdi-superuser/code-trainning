#include <bits/stdc++.h>
#define fs first
#define sc second
#define maxn 10001
using namespace std;
typedef pair<int,int> II;
    int n,m,s;
    II a[50001];
    vector<int> g[maxn];
    int cl[maxn], kc[maxn], q[maxn], x[maxn], slx=0, deg[maxn], f[maxn];
void bfs(int xp)
{
    int l=1, r=0;
    q[++r]=xp; cl[xp]=1; kc[xp]=0;
    while(l<=r)
    {
        int u=q[l++];
        x[++slx]=u;
        for(int i=0; i<deg[u]; i++)
        {
            int v=g[u][i];
            if(cl[v]==0)
                {q[++r]=v;
            cl[v]=1; kc[v]=kc[u]+1;}
        }
    }
}
void in()
{
    int ds=0;
    for(int i=1; i<=n; i++)
        if(f[i]>1) ds++;
    cout<<ds;
}
void tinh()
{
    bfs(s);
    for(int i=1; i<=n; i++) f[i]=0;
    f[s]=1;
    for(int i=1; i<=slx; i++)
    {
        int u=x[i];
        for(int j=0; j<deg[u]; j++)
        {
            int v=g[u][j];
            if(cl[v]==1&&kc[v]==kc[u]+1)
                f[v]+=f[u];
            if(f[u]>1) f[u]=2;
        }
    }
    in();
}
int main()
{
    cin>>n>>m>>s;
    for(int i=1; i<=m; i++)
        cin>>a[i].fs>>a[i].sc;
    sort(a+1,a+m+1);
    g[a[1].fs].push_back(a[1].sc);
    deg[a[1].fs]++;
    for(int i=2; i<=m; i++)
        if(a[i]!=a[i-1])
        {
            g[a[i].fs].push_back(a[i].sc);
            deg[a[i].fs]++;
        }
    tinh();
}