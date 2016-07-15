#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

vector <int> adj[N];
int n, m, d[N], cnt[N];
bool fr[N];

bool dfs(int u) {
    if (!fr[u]) return false;
    fr[u] = false;
    for (int k = 0; k < adj[u].size(); k++) {
        int v = adj[u][k];
        if (!d[v] || dfs(d[v])) {
            d[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);   cin.tie(NULL);
    freopen("company.inp", "r", stdin);
    freopen("company.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        cnt[i] = true;
        for (int j = 1; j <= n; j++) fr[j] = true;
        if (dfs(i)) res++, cnt[i] = false;
    }

    cout << n - res << endl;
    for (int i = 1; i <= n; i++)
        if (cnt[i]) cout << i << " ";

    return 0;
}
