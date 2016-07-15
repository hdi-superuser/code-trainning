#include <bits/stdc++.h>
#define filein(t) freopen(t, "r", stdin)
#define fileout(t) freopen(t, "w", stdout)
#define f first
#define s second
#define cs 137
#define ll long long
#define mp make_pair
#define BIT(i, j) ((j >> i) & 1)
#define N 300005
#define ln 1e9+1
#define oo 10007
#define Pa pair < int, int >
#define Pi pair < int, Pa >

using namespace std;

int n, P[N][20], H[N], Val[4*N];
int In[N], Out[N], num;
Pa que[N];
vector < int > a[N];

void DFS(int u)
{
    In[u] = ++num;
    for(int i=0; i<a[u].size(); i++)
    {
        int v = a[u][i];
        H[v] = H[u] + 1;
        P[v][0] = u;
        DFS(v);
    }
    Out[u] = num;
}

int Get_Val(int node, int l, int r, int d, int c)
{
    if(l > c || r < d)  return 0;
    if(d <= l && r <= c)    return Val[node];
    int g = (l + r) / 2;
    int V1 = Get_Val(2*node, l, g, d, c);
    int V2 = Get_Val(2*node+1, g+1, r, d, c);
    return max(V1, V2);
}

void Update(int node, int l, int r, int pos, int V)
{
    if(l > pos || r < pos)  return;
    if(l == r)
    {
        Val[node] = max(Val[node], V);
        return;
    }
    int g = (l + r) / 2;
    Update(2*node, l, g, pos, V);
    Update(2*node+1, g+1, r, pos, V);
    Val[node] = max(Val[2*node], Val[2*node+1]);
}

int Get_Par(int u, int h)
{
    int hi = H[u] - h;
    for(int i=0; i<20; i++)
        if(BIT(i, hi))
            u = P[u][i];
    return u;
}

int main()
{
    filein("SALARY.inp");   fileout("SALARY.out");
    int par, X, V;
    cin >> n;
    cin >> X;
    H[2] = 1;
    for(int i=3; i<=n+2; i++)
    {
        scanf("%d%d", &V, &par);    par+=2;
        a[par].push_back(i);
        que[i] = mp(V, par);
    }
    DFS(2);
    P[2][0] = 1;
    Update(1, 1, n+1, In[2], X);
    for(int j=1; j<20; j++)
        for(int i=1; i<=n+2; i++)
            P[i][j] = P[P[i][j-1]][j-1];
    for(int i=3; i<=n+2; i++)
    {
        int V = que[i].f;
        int par = que[i].s;
        for(int j=19; j>=0; j--)
        {
            int Np = P[par][j];
            if(Np == 0)    continue;
            int u = Get_Par(i, H[Np]+1);
            int Maxv = Get_Val(1, 1, n+1, In[u], Out[u]);
            if(Maxv < V && Maxv)
                par = Np;
        }
        //cout << H[i] - H[par] - 1 << endl;
        printf("%d\n", H[i] - H[par] - 1);
        Update(1, 1, n+1, In[i], V);
    }
}
