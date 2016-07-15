#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const int N = 500005;
const int inf = 2000000001;

typedef vector<int> vi;
typedef pair<int, int> ii;

int n, m, nscc, pos;
long long dp[N];
int a[N], tplt[N], s, p;
bool mark[N];
ii e[N];
vi adj[N], adj_scc[N];

int Time, dfs_num[N], dfs_low[N];
struct scc {
    long long w;
    bool center, target;
};
int st[N], top;
vector <scc> T;

void dfs_tarjan(int u) {
    st[++top] = u;
    dfs_num[u] = dfs_low[u] = ++Time;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (dfs_num[v]) dfs_low[u] = min(dfs_num[v], dfs_low[u]);
        else dfs_tarjan(v), dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u]) {
        int v;  scc temp;   temp.w = 0;
        temp.center = temp.target = false;
        ++nscc;

        do {
            v = st[top--];
            tplt[v] = nscc;
            temp.w += a[v];
            if (!temp.center) temp.center = (v == s);
            if (!temp.target) temp.target = mark[v];
            dfs_low[v] = dfs_num[v] = N;
        } while (v != u);
        T.push_back(temp);
    }
}

void dfs_dp(int u) {
    for (int i = 0; i < adj_scc[u].size(); i++) {
        int v = adj_scc[u][i];
        dp[v] = max(dp[v], dp[u] + T[v].w);
        dfs_dp(v);
    }
}

int inqueue[N];
void spfa() {
    for (int i = 1; i <= n; i++) dp[i] = 0;
    dp[pos] = T[pos].w;
    queue <int> q;  q.push(pos);
    inqueue[pos] = 1;

    while (!q.empty()) {
        int u = q.front();  q.pop();    inqueue[u] = 1;
        for (int j = 0; j < adj_scc[u].size(); j++) {
            int v = adj_scc[u][j];
            if (dp[v] < dp[u] + T[v].w) {
                dp[v] = dp[u] + T[v].w;
                if (!inqueue[v]) {
                    q.push(v);
                    inqueue[v] = 1;
                }
            }
        }
    }
}

int main() {
    freopen("atm.inp", "r", stdin);
    freopen("atm.out", "w", stdout);

    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;   scanf("%d %d\n", &u, &v);
        e[i] = ii(u, v);
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) scanf("%d\n", &a[i]);
    scanf("%d %d\n", &s, &p);
    for (int i = 1; i <= p; i++) {
        int u;  scanf("%d ", &u);
        mark[u] = true;
    }

    scc temp;   temp.w = 0, temp.center = 0, temp.target = 0;
    T.push_back(temp);
    for (int i = 1; i <= n; i++)
        if (!dfs_num[i]) dfs_tarjan(i);

    for (int i = 1; i <= m; i++) {
        int u = e[i].x, v = e[i].y;
        if (tplt[u] == tplt[v]) continue;
        adj_scc[tplt[u]].push_back(tplt[v]);
    }
    pos = tplt[s];
    dp[pos] = T[pos].w;
    dfs_dp(pos);
    //spfa();
    long long ans = 0;
    for (int i = 1; i <= nscc; i++)
        if (T[i].target) ans = max(ans, dp[i]);

    printf("%lld", ans);

    return 0;
}
