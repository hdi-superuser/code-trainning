//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "minpath"
#define maxn 100000
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

vector<pii> a[maxn];
int n, s, t, m;
int d[maxn], tr[maxn];
bool kt[maxn];


void nhap()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].PB(mp(v,w));
        a[v].PB(mp(u,w));
    }

}

void IJK()
{
    memset(kt, 0, sizeof(kt));
    memset(d, 60, sizeof(d));

    priority_queue < pair<int, int> > P;
    P.push(mp(0, s));
    d[s] = 0;
    while (!P.empty())
    {
        // Tim dinh toi uu
        int u = P.top().S;
        int l = -P.top().F; // == d[u]
        P.pop();
        if (l > d[u]) continue;
        // Dung dinh u di toi uu
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i].F;
            int w = a[u][i].S;
            if (d[v] > l + w)
            {
                d[v] = l + w;
                tr[v] = u;
                P.push(mp(-d[v],v ));
            }
        }
    }
}

void Ghikq()
{
    cout << d[t] << endl;
  /*  int x = t;
    vector<int> kq;
    //kq.PB(t);
    while (x != s)
    {
        kq.PB(x);
        x = tr[x];
    }
    kq.PB(s);
    cout << kq.size() << endl;
    for (int i = kq.size() -1; i >=0; i--)
            cout << kq[i] << " ";*/
}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    nhap();
    IJK();
    Ghikq();
    return 0;
}
