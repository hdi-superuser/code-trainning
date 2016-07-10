#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const int N = 101;

typedef long long ll;
typedef pair<int, ll> il;

vector <il> adj[N];
int n, s, f;
bool fr[N];
int tr[N];

bool bfs(ll x) {
    queue <int> q;
    memset(fr, 0, sizeof fr);
    memset(tr, 0, sizeof tr);
    fr[s] = 1;  q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == f) return true;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].x;
            if (fr[v] || adj[u][i].y < x) continue;
            tr[v] = u;  q.push(v); fr[v] = 1;
        }
    }
    return false;
}

int main() {
    freopen("hight.inp", "r", stdin);
    freopen("hight.out", "w", stdout);

    cin >> n >> s >> f;
    int u, v;
    ll k;
    while (cin >> u >> v >> k) {
        adj[u].push_back(il(v, k));
        adj[v].push_back(il(u, k));
    }

    ll L = 0, R = (ll) 2e9;
    while (L < R - 1) {
        ll mid = L + (R - L)/2;
        if (bfs(mid)) L = mid; else R = mid;
    }

    cout << R - 1 << endl;
    bfs(R - 1);
    vector<int> res;
    while (tr[f]) {
        res.push_back(f);
        f = tr[f];
    }
    res.push_back(f);

    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";

    return 0;
}
