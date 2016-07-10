#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "cd"
#define maxn 205
#define maxm 6002
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

struct data
{
    int u, v, w;
};

int n, m, tplt;
long long ans;
data a[maxm];
int root[maxn];


bool comp(data p, data q)
{
    return p.w < q.w;
}

int Get_root(int u)
{
    return (root[u]) ? root[u] = Get_root(root[u]) : u;
}

void Kruskal()
{
    //sort(a+1, a+m+1, comp);	
	for (int x = m; x > 1 && a[x-1].w > a[x].w; x--) swap(a[x], a[x-1]);
    memset(root, 0, sizeof(root));
    ans = 0;
    tplt = n;
	int dem = 0;
    for (int i = 1; i <= m; i++)
    {
        int p = Get_root(a[i].u);
        int q = Get_root(a[i].v);
        if (p == q) continue;
		a[++dem] = a[i];
        root[p] = q;
        ans += a[i].w;
        tplt --;
    }
	m = dem;
}


int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    int sl;
    cin >> n >> sl;
    for (int i = 1; i <= sl; i++)
    {				
        cin >> a[++m].u;
		cin >> a[m].v >> a[m].w;			
        Kruskal();
        if (tplt > 1) ans = -1;
        cout << ans << endl;
    }
    return 0;
}
