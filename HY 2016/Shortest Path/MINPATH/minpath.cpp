#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const int N = 10001;
const int M = 100001;

typedef pair <int, long long> ii;
typedef vector < ii > vi;

int n, m, s, t, tr[N];
long long dist[N];
vi adj[N];

struct comp {
    bool operator()(ii a, ii b) {
        return a.y < b.y;
    }
};

int main() {
    freopen("minpath.inp", "r", stdin);
    freopen("minpath.out", "w", stdout);

    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v;
        long long k;
        cin >> u >> v >> k;
        adj[u].push_back(make_pair(v, k));
        adj[v].push_back(make_pair(u, k));
    }

    priority_queue < ii, vi, comp > q;
    q.push(ii(s, 0)); tr[s] = -1;
    return 0;
}
