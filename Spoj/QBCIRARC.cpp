#include <bits/stdc++.h>

using namespace std;

#define task "main"
#define N 1001
#define M 20001
#define MOD 1000000007
#define inf 0x7fffffff

#define WHITE 0  // UNVISITED
#define BLACK 1  // EXPLORED
#define GRAY 2   // VISITED BUT NOT EXPLORED

#define fst first
#define snd second
#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define ALL(x) (x).begin(), (x).end()
#define popcnt(x) __builtin_popcount(x)
#define remain(x) if (x > MOD) x -= MOD
#define rep(i, j, k) for (register int i = j; i <= k; i++)
#define dow(i, j, k) for (register int i = j; i >= k; i--)
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

template<typename T> void in(T& x) { cin >> x; }
template<typename T> void out(T x) { cout << x; }
template<typename T> void outln(T x) { cout << x << endl; }
template<typename T, typename X> void out(T x, X y) { cout << x << y; }
template<typename T, typename X> void outln(T x, X y) { cout << x << y << endl; }

struct _ { _() { ios_base::sync_with_stdio(0); cin.tie(NULL); } } _;
/*----------------------------- header -------------------------------*/

int m, n, target, cnt;
vi adj[N];
bool fr[N][N], vis[N][N];
int p[N], par[N], tr[N], dist[N], color[N], deg[N][N];

int bfs(int source, int x, int y) {
    queue <int> q;  q.push(source);
    p[source] = ++cnt;  dist[source] = 0;

    while (sz(q)) {
        int u = q.front();    q.pop();

        rep(i, 0, sz(adj[u]) - 1) {
            int v = adj[u][i];

            if (u == x && v == y) continue;
            if (v == source) { tr[source] = u; return dist[u];  }
            if (p[v] == cnt) continue;

            tr[v] = u;  dist[v] = dist[u] + 1;
            p[v] = cnt; q.push(v);
        }
    }

    return inf;
}

bool dfs(int u, int x, int y) {
    color[u] = GRAY;

    rep(j, 0, sz(adj[u]) - 1) {
        int v = adj[u][j];

        if (u == x && v == y) continue;

        if (color[v] == GRAY) return true;
        if (color[v] == WHITE && dfs(v, x, y))
            return true;
    }

    color[u] = BLACK;
    return false;
}

bool isCyclic(int x, int y) {
    fill(color + 1, color + n + 1, WHITE);

    rep(j, 1, n)
        if (color[j] == WHITE)
            if (dfs(j, x, y)) return true;

    return false;
}

main(void) {
    #ifndef ONLINE_JUDGE
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    #endif // ONLINE_JUDGE

    in(n);  in(m);
    rep(i, 1, m) {
        int u, v;   in(u);  in(v);  adj[u].pb(v);   deg[u][v]++;
    }

    rep(i, 1, n) rep(j, 1, n) fr[i][j] = false;
    fill(p + 1, p + n + 1, 0);  fill(dist + 1, dist + n + 1, 0);
    cnt = 1; target = 0;    int ret1 = inf, ret2;

    rep(i, 1, n) {
        ret2 = bfs(i, 0, 0);

        if (ret2 < ret1) {
            ret1 = ret2;
            target = i;
            rep(j, 1, n) par[j] = tr[j];
        }
    }

    if (target == 0) { out(-1); return 0; } int u = target;

    do {
        fr[par[u]][u] = !isCyclic(par[u], u);
        fr[par[u]][u] = deg[par[u]][u] > 1 || deg[par[u]][u] < 1 ? 0 : fr[par[u]][u];
        u = par[u];
    } while (u != target);

    vii ret;
    rep(i, 1, n) rep(j, 1, n)
        if (fr[i][j]) ret.pb(mp(i, j));

    if (sz(ret) == 0) { out(-1); return 0; }    outln(sz(ret));
    rep(i, 0, sz(ret) - 1) { out(ret[i].fst, " "); outln(ret[i].snd); }

    return 0;
}
