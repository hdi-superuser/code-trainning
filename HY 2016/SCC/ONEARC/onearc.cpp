#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const int N = 2001;

typedef pair<int, int> ii;
typedef vector<int> vi;

int n, m, Time, nscc;
int a[N], root[N], dfs_num[N], dfs_low[N];
vi adj[N], res[N];
int deg_in[N], deg_out[N];
ii e[30001];
stack <int> st;

void dfs(int u) {
    st.push(u);
    dfs_num[u] = dfs_low[u] = ++Time;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (dfs_num[v]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        else dfs(v), dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_low[u] == dfs_num[u]) {
        nscc++; root[nscc] = u;
        int v;
        do {
            v = st.top();   st.pop();
            a[v] = nscc;
            dfs_low[v] = dfs_num[v] = N;
        } while (v != u);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("onearc.inp", "r", stdin);
    freopen("onearc.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= m ; i++) {
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        e[i] = ii(u, v);
    }

    Time = 0;
    for (int i = 1; i <= n; i++)
        if (dfs_num[i] == 0) dfs(i);

    for (int i = 1; i <= m; i++)
        if (a[e[i].x] != a[e[i].y])
            deg_in[a[e[i].y]]++,
            deg_out[a[e[i].x]]++;

    int d1 = 0, d2 = 0;
    for (int i = 1; i <= nscc; i++)
        d1 += (deg_in[i] == 0 ? 1 : 0),
        d2 += (deg_out[i] == 0 ? 1 : 0);

    if (d1 == 1 && d2 == 1) {
        cout << "YES" << endl;
        for (int i = 1; i <= nscc; i++)
            if (deg_out[i] == 0) cout << root[i] << " ";
        for (int i = 1; i <= nscc; i++)
            if (deg_in[i] == 0) cout << root[i];
        return 0;
    }
    cout << "NO";
    return 0;
}
