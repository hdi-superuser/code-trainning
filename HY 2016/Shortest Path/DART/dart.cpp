#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

const int N = 201;
const int W = 60001;
const int inf = 6000001;

int dist[N];
int n, pos[N][N], tr[N], adj[N][N];

void dijkstra() {
    priority_queue<ii, vii, greater<ii> > q;
    q.push(ii(0, n));   q.push(ii(0, n + 'M'));
    dist[n] = dist[n + 'M'] = 0;

    while (!q.empty()) {
        int u = q.top().y, w = q.top().x;
        q.pop();
        if (u == 1 || u == 1 + 'M') return;
        if (w > dist[u]) continue;
        for (int v = 1; v <= n + 'M'; v++) {
            if (dist[v] > dist[u] + adj[u][v]) {
                dist[v] = dist[u] + adj[u][v];
                tr[v] = u;
                q.push(ii(dist[v], v));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("dart.inp", "r", stdin);
    freopen("dart.out", "w", stdout);

    int u, v, wuv, wvu;
    char c;
    int i = 0;
    cin >> n;

    for (int i = 1; i <= n + 'M'; i++)
        for (int j = 1; j <= n + 'M'; j++)
            adj[i][j] = (i == j ? 0 : inf);

    while (cin >> u >> v >> wuv >> wvu >> c) {
        i++;
        if (c == 'M') {
            if (adj[u + 'M'][v] > wuv) {
                adj[u + 'M'][v] = wuv;
                pos[u + 'M'][v] = i;
            }
            if (adj[v][u + 'M'] > wvu) {
                adj[v][u + 'M'] = wvu;
                pos[v][u + 'M'] = i;
            }
        } else {
            if (adj[u][v + 'M'] > wuv) {
                adj[u][v + 'M'] = wuv;
                pos[u][v + 'M'] = i;
            }
            if (adj[v + 'M'][u] > wvu) {
                adj[v + 'M'][u] = wvu;
                pos[v + 'M'][u] = i;
            }
        }
    }

    for (int i = 0; i <= n + 'M'; i++) dist[i] = inf;
    for (int i = 0; i <= n + 'M'; i++) tr[i] = -1;
    dijkstra();

    vector<int> res;
    int ans = inf, f = 0;
    if (ans > dist[1]) ans = dist[1], f = 1;
    if (ans > dist[1 + 'M']) ans = dist[1 + 'M'], f = 1 + 'M';

    cout << ans << endl;
    while (tr[f] != -1) {
        res.push_back(f);
        f = tr[f];
    }
    res.push_back(f);

    for (int i = res.size() - 1; i >= 0; i--)
        cout << (res[i] > 'M' ? res[i] - 'M' : res[i]) << " ";
    cout << endl;
    for (int i = res.size() - 1; i; i--)
        cout << pos[res[i]][res[i-1]] << " ";

    return 0;
}
