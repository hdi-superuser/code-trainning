#include <bits/stdc++.h>

using namespace std;

const int N = 10001;
const int M = 100001;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, cnt, dfs_num[N], dfs_low[N];
vi adj[N];
vii res;

void initialized() {
    memset(dfs_num, 0, sizeof dfs_num);
    memset(dfs_low, 0, sizeof dfs_low);
    cnt = 0;
    for (int i = 0; i < N; i++) adj[i].clear();
    res.clear();
}

void read() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        int u, k, v;
        scanf("%d (%d) ", &u, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d ", &v);
            adj[u].push_back(v);
        }
    }
    scanf("\n");
}

void dfs(int u, int p) {
    dfs_num[u] = dfs_low[u] = ++cnt;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (v == p) continue;
        if (dfs_num[v]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        else {
            dfs(v, u);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            if (dfs_low[v] >= dfs_num[v]) {
                if (u > v) res.push_back(ii(v, u));
                else res.push_back(ii(u, v));
            }
        }
    }
}

void solve() {
    for (int i = 0; i < n; i++)
        if (!dfs_num[i]) dfs(i, i);
}

void print(int t) {
    sort(res.begin(), res.end());
    printf("Case %d:\n", t);
    printf("%d critical links\n", res.size());
    for (int i = 0; i < res.size(); i++)
        printf("%d - %d\n", res[i].first, res[i].second);
}

int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d\n\n", &T);
    for (int t = 1; t <= T; t++) {
        initialized();
        read();
        solve();
        print(t);
    }
    return 0;
}

