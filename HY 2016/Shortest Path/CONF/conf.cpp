#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair <int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int N = 101;
const int M = 5001;
const int inf = 2000000001;

int n, m;
int C[N][N], dist[4][N], tr[N][4][N], inRes[N][N];
vii adj[N], res;

void dijkstra(int s, int f, int op)
{
    priority_queue <ii, vii, greater<ii> > q;
    q.push(ii(0, s));
    memset(dist[op], inf, sizeof dist[op]);
    dist[op][s] = 0;

    while (!q.empty())
    {
        int u = q.top().y, w = q.top().x;
        q.pop();
        if (w > dist[op][u]) continue;
        if (u == f) return;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].x;
            if (dist[op][v] > dist[op][u] + adj[u][i].y)
            {
                dist[op][v] = dist[op][u] + adj[u][i].y;
                tr[f][op][v] = u;
                q.push(ii(dist[op][v], v));
            }
        }
    }
}

void trace(int u, int target, int op)
{
    while (tr[target][op][u])
    {
        int v = tr[target][op][u];
        if (!inRes[u][v]) res.push_back(ii(v, u));
        inRes[u][v] = inRes[v][u] = 1;
        u = v;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("conf.inp", "r", stdin);
    freopen("conf.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, k;
        cin >> u >> v >> k;
        adj[u].push_back(ii(v, k));
        adj[v].push_back(ii(u, k));
        C[u][v] = C[v][u] = k;
    }

    int a, b, c;
    cin >> a >> b >> c;

    int ans = inf, pos = 0;
    memset(tr, 0, sizeof tr);

    for (int i = 1; i <= n; i++)
    {
        dijkstra(a, i, 1);  dijkstra(b, i, 2);  dijkstra(c, i, 3);

        if (ans > dist[1][i] + dist[2][i] + dist[3][i])
            ans = dist[1][i] + dist[2][i] + dist[3][i],
            pos = i;
    }

    trace(pos, pos, 1); trace(pos, pos, 2); trace(pos, pos, 3);

    ans = 0;
    for (int i = 0; i < res.size(); i++)
        ans += C[res[i].x][res[i].y];

    cout << ans << " " << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i].x << " " << res[i].y << endl;

    return 0;
}
