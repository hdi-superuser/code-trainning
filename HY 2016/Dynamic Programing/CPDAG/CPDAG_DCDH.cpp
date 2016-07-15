//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "CPDAG"
#define maxn 100002
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

vector < int >  a[maxn];
int n, m;
int S[maxn], d[maxn];
int bac[maxn];

void nhap()
{
    cin >> n >> m;
    int u, v, w;
    memset(bac, 0, sizeof(bac));
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        a[u].PB(v);
        bac[v] ++;
    }
}

void QHD()
{
    int r = 0;

    for (int i = 1; i <= n; i++) d[i] = 1;
    for (int i = 1; i <= n; i++)
        if (bac[i] == 0) S[++r] = i;
    for (int l = 0; l <= r; l++)
    {
        int u = S[l];
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i];
            if (--bac[v] == 0) S[++r] = v;
            d[v] = (d[v] + d[u]) % MOD;
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    nhap();
    QHD();
    cout << (accumulate(d+1, d+n+1, 0ll) - n) % MOD;
    return 0;
}
