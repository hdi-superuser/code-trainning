 #include <bits/stdc++.h>

#define ver first
#define len second

using namespace std;

const int N = 100001;

typedef long long ll;
typedef pair<int, ll> ii;
typedef vector<ii> vi;

vi adj[N];
ll d[N];
int n, k, H[N], fr[N], par[N][20];

void init() {
    k = trunc(log(n)/log(2));
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        d[i] = 0;   fr[i] = 0;  H[i] = 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++) par[i][j] = 0;
}

void read() {
	for (int i = 1; i < n; i++) {
		int x; ll y;   cin >> x >> y;
		adj[i].push_back(make_pair(x, y));
		adj[x].push_back(make_pair(i, y));
	}
}

void bfs() {
    queue<int> q;   q.push(0);
    H[0] = 1;   fr[0] = 1;
    while (!q.empty()) {
        int u = q.front();  q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].ver;
            if (fr[v]) continue;
            d[v] = d[u] + adj[u][i].len;
            H[v] = H[u] + 1;
            par[v][0] = u;
            fr[v] = 1;
            q.push(v);
        }
    }
}

void rmq() {
    for (int j = 1; j <= k; j++)
        for (int i = 1; i <= n; i++)
            par[i][j] = par[par[i][j-1]][j-1];
}

int lca(int u, int v) {
    if (H[v] > H[u]) return lca(v, u);
    int delta = H[u] - H[v];
    for (int i = k; i >= 0; i--)
        if ((delta >> i) & 1) u = par[u][i];
    if (u == v) return u;
    for (int i = k; i >= 0; i--)
        if (par[u][i] != par[v][i])
            u = par[u][i], v = par[v][i];
    return par[u][0];
}

void solve() {
    bfs();
    rmq();

    int Q;  cin >> Q;
    while (Q--) {
        int u, v;   cin >> u >> v;
        int _lca = lca(u, v);
        cout << d[u] + d[v] - 2*d[_lca];
        if (Q >= 1) cout << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("ants.inp", "r", stdin);
    freopen("ants.out", "w", stdout);

	while (1) {
		cin >> n;
		if (n == 0) return 0;
        init();
        read();
        solve();
	}
}
