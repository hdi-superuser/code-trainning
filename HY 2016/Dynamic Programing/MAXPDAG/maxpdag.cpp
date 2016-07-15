#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int N = 100001;
const int M = 1000000007;

int n, m, f[N], deg[N];
vector< ii > adj[N];

int main() {
    ios_base::sync_with_stdio(0);   cin.tie(NULL);
    freopen("maxpdag.inp", "r", stdin);
    freopen("maxpdag.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;   cin >> u >> v >> w;
        adj[u].push_back(ii(v, w));
        deg[v]++;
    }

    queue <int> q;
    for (int i = 1; i <= n; i++)
        if (!deg[i]) q.push(i);


    while (!q.empty()) {
        int u = q.front();    q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            if (f[v] < f[u] + adj[u][i].second) {
                f[v] = f[u] + adj[u][i].second;
            }
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i]);

    cout << ans << endl;

    return 0;
}
