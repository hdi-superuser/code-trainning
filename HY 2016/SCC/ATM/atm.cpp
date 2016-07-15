#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 500001;

vector<int> inc[N], out[N], adj[N];

int n, m;
int cost[N], stop[N], can_stop[N], scc[N];
ll tot[N], f[N];
int visited[N], st[N], S, C;


void dfs(int v) {
    if(visited[v]) return;
    visited[v] = 1;
    for(int i = 0 ; i < out[v].size(); i++)
        dfs(out[v][i]);
    st[S++] = v;
}

void dfs_scc(int v) {
    if(visited[v]) return;
    visited[v] = 1;
    for(int i = 0; i < inc[v].size(); i++)
        dfs_scc(inc[v][i]);

    scc[v] = C;
    tot[C] += cost[v];
    can_stop[C] |= stop[v];
}

ll dp(int v) {
    if(f[v] >= 0) return f[v];
    f[v] = can_stop[v] ? tot[v] : -(1e15);
    for(int i = 0; i < adj[v].size(); i++)
        f[v] = max(f[v], dp(adj[v][i]) + tot[v]);
    return f[v];
}

int main() {
    ios_base::sync_with_stdio(0);   cin.tie(NULL);
    freopen("atm.inp", "r", stdin);
    freopen("atm.out", "w", stdout);

    scanf("%d%d",&n,&m);
    while(m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u,--v;
        out[u].push_back(v);
        inc[v].push_back(u);
    }

    for(int i = 0; i < n ; i++)
        scanf("%d", &cost[i]);

    int u;
    scanf("%d%d", &u, &m);
    --u;
    while(m--) {
        int i;
        scanf("%d", &i);
        stop[--i] = 1;
    }

    for(int i = 0; i < n; i++) dfs(i);

    memset(visited,0,sizeof(visited));
    while(S--) {
        if(visited[st[S]]) continue;
        dfs_scc(st[S]);
        ++C;
    }

    memset(f, -1, sizeof(f));
    for(int v = 0; v < N; v++) {
        for(int i = 0; i < out[v].size(); ++i) {
            if(scc[v] == scc[out[v][i]]) continue;
            adj[scc[v]].push_back(scc[out[v][i]]);
        }
    }

    printf("%lld\n",dp(scc[u]));

    return 0;
}
