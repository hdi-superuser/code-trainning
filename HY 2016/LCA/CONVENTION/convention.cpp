#include <bits/stdc++.h>

#define mp make_pair
#define x first
#define y second

using namespace std;

const int inf = 1000000001;
const int N = 200001;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;

int n;
int par[N][21], f[N], d[N][21], H[N];
pii a[N];

int LCA(int u, int v) {
    if (H[u] < H[v]) swap(u, v);
    int delta = H[u] - H[v];
    for (int i = 0; i < 20; i++)
        if ((delta >> i) & 1) u = par[u][i];
    if (u == v) return u;
    for (int i = 19; i >= 0; i--)
        if (par[u][i] != par[v][i])
            u = par[u][i], v = par[v][i];
    return par[u][0];
}

int query(int u, int v) {
    int res = inf;
    int delta = H[u] - H[v];
    for (int i = 0; i < 20; i++)
        if ((delta >> i) & 1)
            res = min(res, d[u][i]),
            u = par[u][i];
    return res;
}

int minimize(int u, int v) {
    int dad = LCA(u, v);
    int M1 = query(u, dad);
    int M2 = query(v, dad);
    if(H[u] == H[v]) return (M1 < M2) ? u : v;
    return (H[u] > H[v]) ? u : v;
}

void Merge(int u, int pos) {
    par[u][0] = f[pos];
    d[u][0] = a[u].y;
    H[u] = H[f[pos]] + 1;
    for (int j = 1; j < 20; j++) {
        par[u][j] = par[par[u][j-1]][j-1];
        d[u][j] = min(d[u][j-1], d[par[u][j-1]][j-1]);
    }
    f[u] = minimize(u, f[u-1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("convention.inp", "r", stdin);
    freopen("convention.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].x.y >> a[i].x.x, a[i].y = i;

    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        int pos = lower_bound(a + 1, a + n + 1, mp(mp(a[i].x.y, 0), 0)) - a - 1;
        Merge(i, pos);
    }

    vi ans; int res = f[n];
    while(res) {
        ans.push_back(a[res].y);
        res = par[res][0];
    }

    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

    return 0;
}
