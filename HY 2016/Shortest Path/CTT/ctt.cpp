#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const int N = 1001;
const int inf = 2000000001;

typedef pair<int, int> ii;
typedef vector<ii> vi;

int n, m, dist[3][N], fr[N];
vi adj[N];
ii delta[N];

void dijkstra(int op) {
    priority_queue <ii, vi, greater<ii> > q;
    while (q.size()) q.pop();
    q.push(ii(0, op));
    memset(dist[op], inf, sizeof dist[op]);
    dist[op][op] = 0;

    while (!q.empty()) {
        int u = q.top().y, w = q.top().x; q.pop();
        if (w > dist[op][u]) continue;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].x;
            if (dist[op][v] > dist[op][u] + adj[u][i].y) {
                dist[op][v] = dist[op][u] + adj[u][i].y;
                q.push(ii(dist[op][v], v));
            }
        }
    }
}

int main() {
    freopen("ctt.inp", "r", stdin);
    freopen("ctt.out", "w", stdout);

    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, L;
        scanf("%d %d %d\n", &u, &v, &L);
        adj[u].push_back(ii(v, L));
        adj[v].push_back(ii(u, L));
    }

    dijkstra(1);    dijkstra(2);

    for (int i = 1; i <= n; i++)
        delta[i].x = dist[1][i] - dist[2][i],
        delta[i].y = i;

    sort(delta + 1, delta + n + 1);
    int sum = 0;
    for (int i = 1; i <= n/2; i++) sum += dist[1][delta[i].y];
    for (int i = n/2+1; i <= n; i++) sum += dist[2][delta[i].y];

    cout << sum;
    for (int i = 1; i <= n; i++) cerr << dist[1][i] << " ";
    cerr << endl;
    for (int i = 1; i <= n; i++) cerr << dist[2][i] << " ";
    return 0;
}
