#include <bits/stdc++.h>

using namespace std;

const int N = 10002;
const int M = 20002;

int n, m, cnt;
vector <int> adj[N];
int dfs_num[N], dfs_low[N], art[N];

void initialized() {
    memset(dfs_num, 0, sizeof dfs_num);
    memset(dfs_low, 0, sizeof dfs_low);
    memset(art, 0, sizeof art);
    for (int i = 0; i <= n; i++) adj[i].clear();
    cnt = 0;
}

void read() {
    scanf("%d %d\n", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d %d\n", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    scanf("\n");
}

void dfs(int u, int p) {
    int nChild = 0;
    dfs_num[u] = dfs_low[u] = ++cnt;

    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (v == p) continue;
        if (dfs_num[v]) dfs_low[u] = min(dfs_num[v], dfs_low[u]);
        else {
                dfs(v, u);
                nChild++;
                dfs_low[u] = min(dfs_low[u], dfs_low[v]);
                if (u == p) {
                    if (nChild > 1) art[u] = 1;
                } else if (dfs_low[v] >= dfs_num[u]) art[u] = 1;
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++)
        if (!dfs_num[i]) dfs(i, i);
}

void print(int t) {
    printf("Case %d: ", t);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += art[i];
    printf("%d\n", ans);
}

int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d\n", &T);
    for (int t = 1; t <= T; t++) {
        initialized();
        read();
        solve();
        print(t);
    }
}

