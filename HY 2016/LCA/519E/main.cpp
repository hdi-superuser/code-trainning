#include <bits/stdc++.h>

using namespace std;

const int N = 100001;

vector <int> adj[N];
int n, m, k, H[N], d[N], par[N][20];

int lca(int u, int v) {
    if (H[v] > H[u]) swap(u, v);
    int delta = H[u] - H[v];
    for (int i = k; i >= 0; i--)
        if ((delta >> i) & 1) u = par[u][i];
    if (v == u) return u;
    for (int i = k; i >= 0; i--)
        if (par[u][i] != par[v][i])
            u = par[u][i], v = par[v][i];
    return par[u][0];
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;   q.push(1);  H[1] = 1;
    while (!q.empty()) {
        int u = q.front();  q.pop();
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            if (H[v]) continue;
            H[v] = H[u] + 1;
            par[v][0] = u;
            q.push(v);
        }
    }

    k = trunc(log(N)/log(2));
    for (int j = 1; j <= k; j++)
        for (int i = 1; i <= n; i++)
            par[i][j] = par[par[i][j-1]][j-1];

    cin >> m;
    while (m--) {
        int u, v;   cin >> u >> v;
        if (u == v) { cout << n << endl; return 0; }
        int _lca = lca(u, v);
        int w = d[u] + d[v] - 2*d[_lca];
        if (w & 1) { cout << "0" << endl; return 0; }
        else {
            w /= 2;
        }
    }

    return 0;
}
