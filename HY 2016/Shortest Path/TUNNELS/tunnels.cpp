#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<pii> vii;
typedef vector<ii> vi;

const int N = 101;
const int inf = 1000000;

int dist[N], tr[N], bk_d[N], bk_tr[N];
int n, m, X, Y;
vii adj[N];

bool dijkstra(int H)
{
    priority_queue<ii, vi, greater<ii> > q;
    q.push(ii(0, X));
    memset(dist, inf, sizeof dist);
    memset(tr, 0, sizeof tr);
    dist[X] = 0;
    while (!q.empty())
    {
        int u = q.top().y, w = q.top().x;
        q.pop();
        if (u == Y) return true;
        if (w > dist[u]) continue;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].x;
            if (dist[v] > w + adj[u][i].y.x && H <= adj[u][i].y.y)
            {
                dist[v] = w + adj[u][i].y.x;
                tr[v] = u;
                q.push(ii(dist[v], v));
            }
        }
    }
    return false;
}

void backup()
{
    for (int j = 1; j <= n; j++)
        bk_d[j] = dist[j], bk_tr[j] = tr[j];
}

int main()
{
    freopen("tunnels.inp", "r", stdin);
    freopen("tunnels.out", "w", stdout);

    vector<int> p;
    cin >> n >> X >> Y >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, k, h;
        cin >> u >> v >> h >> k;
        p.push_back(h);
        adj[u].push_back(pii(v, ii(k, h)));
        adj[v].push_back(pii(u, ii(k, h)));
    }

    sort(p.begin(), p.end());
    int i;
    for (i = 0; i < p.size(); i++)
    {
        if (dijkstra(p[i])) backup();
        else break;
    }

    vector<int> res;
    cout << p[i-1] << " " << bk_d[Y] << endl;
    while (bk_tr[Y])
    {
        res.push_back(Y);
        Y = bk_tr[Y];
    }

    res.push_back(X);
    cout << res.size() << endl;
    for (int i = res.size() - 1; i >= 0; i--) printf("%d ", res[i]);

    return 0;
}
