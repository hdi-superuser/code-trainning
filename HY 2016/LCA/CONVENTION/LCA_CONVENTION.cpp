#include <bits/stdc++.h>
#define N 200005
#define filein(t) freopen(t, "r", stdin)
#define fileout(t) freopen(t, "w", stdout)
#define ll long long
#define ln 1e9 + 5
#define f first
#define BIT(i,x) ((x >> i) & 1)
#define s second
#define mp make_pair
#define oo 1000000007

using namespace std;

int P[N][21], Best[N], Mi[N][21], T[N];
int n;
pair < pair <int, int>, int > a[N];
vector <int> ans;

int LCA(int u, int v)
{
    if(T[u] < T[v]) swap(u, v);
    int hi = T[u] - T[v];
    for(int i=0; i<20; i++)
        if(BIT(i, hi))
            u = P[u][i];
    if(u == v) return u;
    for(int i=19; i >= 0; i--)
        if(P[u][i] != P[v][i])
        {
            u = P[u][i];
            v = P[v][i];
        }
    return P[u][0];
}

int Get_min(int u, int v)
{
    int r = ln;
    int hi = T[u] - T[v];
    for(int i=0; i<20; i++)
        if(BIT(i, hi))
        {
            r = min(r, Mi[u][i]);
            u = P[u][i];
        }
    return r;
}

int Min(int u, int v)
{
    int dad = LCA(u, v);
    int Mi1 = Get_min(u, dad);
    int Mi2 = Get_min(v, dad);
    if(T[u] == T[v])
    {
        if(Mi1 < Mi2) return u;
        return v;
    }
    if(T[u] > T[v]) return u;
    return v;
}

void Merge(int u, int pos)
{
    P[u][0] = Best[pos];
    Mi[u][0] = a[u].s;
    T[u] = T[Best[pos]] + 1;
    for(int j=1; j<20; j++)
    {
        P[u][j] = P[P[u][j-1]][j-1];
        Mi[u][j] = min(Mi[u][j-1], Mi[P[u][j-1]][j-1]);
    }
    Best[u] = Min(u, Best[u-1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    filein("CONVENTION.inp");   fileout("CONVENTION.out");
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i].f.s >> a[i].f.f, a[i].s = i;
    sort(a+1, a+n+1);
   // a[n+1] = mp(mp(ln, 0), 0);
    for(int i=1; i<=n; i++)
    {
        int pos = lower_bound(a+1, a+n+1, mp(mp(a[i].f.s, 0), 0)) - a - 1;
        Merge(i, pos);
    }
    int Ma = Best[n];
    while(Ma)
    {
        ans.push_back(a[Ma].s);
        Ma = P[Ma][0];
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
}
