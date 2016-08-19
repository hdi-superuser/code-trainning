#include <bits/stdc++.h>

#define task "main"
//#define DEBUG

using namespace std;

const int N = 10001;

struct Edge {
    int u, v, cost;
    Edge() {}
    Edge(int _u, int _v, int _cost) : u(_u), v(_v), cost(_cost) {}
    int getNb(int V) { return V == v ? u : v; }
} ed[N];

vector <int> adj[N];
int nChains, nBase, LN, n;
int ChainHead[N], ChainInd[N], d[N], depth[N];
int posInBase[N], Base[N], it[4*N], par[N][32];
int ChildSz[N];

void enter() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, c;    scanf("%d %d %d\n", &u, &v, &c);
        adj[u].push_back(i);    adj[v].push_back(i);
        ed[i] = Edge(u, v, c);
    }
}

void dfs(int u, int p, int w) {
    par[u][0] = p;  depth[u] = depth[p] + 1;
    ChildSz[u] = 1; d[u] = d[p] + w;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = ed[adj[u][i]].getNb(u);

        if (v == p) continue;
        dfs(v, u, ed[adj[u][i]].cost);
        ChildSz[u] += ChildSz[v];
    }
}

void HLD(int u, int w) {
    if (ChainHead[nChains] == 0) ChainHead[nChains] = u;
    ChainInd[u] = nChains;
    posInBase[u] = nBase;
    if (u) Base[nBase++] = w;

    int heavy = 0, _w;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = ed[adj[u][i]].getNb(u);
        if (v == par[u][0]) continue;

        if (ChildSz[v] > ChildSz[heavy])
            heavy = v, _w = ed[adj[u][i]].cost;
    }

    if (!heavy) return;
    HLD(heavy, _w);

    for (int i = 0; i < adj[u].size(); i++) {
        int v = ed[adj[u][i]].getNb(u);
        if (v == par[u][0] || v == heavy) continue;

        ++nChains;
        HLD(v, ed[adj[u][i]].cost);
    }
}

void RMQ() {
    LN = trunc(log(n)/log(2)) + 1;
    for (int j = 1; j <= LN; j++)
        for (int i = 1; i <= n; i++)
            par[i][j] = par[par[i][j-1]][j-1];
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int delta = depth[u] - depth[v];
    for (int i = LN; i >= 0; i--)
        if ((delta >> i) & 1) u = par[u][i];

    if (u == v) return u;

    for (int i = LN; i >= 0; i--)
        if (par[u][i] != par[v][i])
            u = par[u][i], v = par[v][i];

    return par[u][0];
}

void build(int id, int l, int r) {
    if (l == r) {
        it[id] = Base[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    it[id] = it[id << 1] + it[id << 1 | 1];
}

int query(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return it[id];

    int mid = (l + r) >> 1;
    return query(id << 1, l, mid, u, v) + query(id << 1 | 1, mid + 1, r, u, v);
}

int hld_query(int u, int v) {
    if (u == v) return 0;

    int ans = 0;
    while (true) {
        if (ChainInd[u] == ChainInd[v]) {
            if (posInBase[u] == posInBase[v]) return ans;
            return ans + query(1, 0, nBase - 1, posInBase[v] + 1, posInBase[u]);
        } else {
            ans += query(1, 0, nBase - 1, posInBase[ChainHead[ChainInd[u]]], posInBase[u]);
            u = par[ChainHead[ChainInd[u]]][0];
        }
    }
}

int dist(int u, int v) {
    int _lca = LCA(u, v);
    return hld_query(u, _lca) + hld_query(v, _lca);
}

int jump(int u, int delta) {
    if (delta <= 0) return u;
    for (int i = 0; i <= LN; i++)
        if ((delta >> i) & 1) u = par[u][i];
    return u;
}

int kth(int u, int v, int k) {
    int _lca = LCA(u, v);
    if (depth[u] - depth[_lca] + 1 >= k) return jump(u, k - 1);
    else jump(v, depth[u] + depth[v] - 2*depth[_lca] - k + 1);
}

void init() {
    dfs(1, 0, 9);
    HLD(1, 0);
    build(1, 0, nBase - 1);
    RMQ();
}

void reset() {
    nChains = nBase = 0;
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        ChainHead[i] = 0;
        ChainInd[i] = 0;
        posInBase[i] = 0;
        Base[i] = 0;
        par[i][0] = 0;
        depth[i] = 0;
        d[i] = 0;
        ChildSz[i] = 0;
    }
}

#ifdef DEBUG
    void generate_graph_random(int _t, int _v, int _op) {
        ofstream out("main.inp");
        int t = rand() % _t + 1;
        out << t << endl;
        srand(time(NULL));
        int L = 4000, R = 4001;

        for (int i = 0; i < t; i++) {
            int v = rand() % _v + 1;
            out << v << endl;
            n = v;
            vector <int> used;
            used.reserve(v);
            used.push_back(1);

            for (int j = 2; j <= v; j++) {
                int cost = rand() % 100 + 5;
                int u = used[rand() % used.size()];
                used.push_back(j);
                out << u << " " << j << " " << cost << endl;
                adj[u].push_back(j-1);    adj[j].push_back(j-1);
                ed[j-1] = Edge(u, j, cost);
            }

            dfs(1, 0, 0);
            RMQ();

            int op = rand() % _op + 1;
            for (int i = 0; i < op; i++) {
                int M = rand() % 2;
                if (M == 0) {
                    // dist
                    int A = rand() % v + 1;
                    int B = rand() % v + 1;
                    out << "DIST " << A <<  " " << B << endl;
                } else {
                    // kth
                    int A = rand() % v + 1;
                    int B = rand() % v + 1;
                    if (A == B) continue;
                    int C = rand() % (depth[A] + depth[B] - 2*depth[LCA(A, B)]) + 1;
                    out << "KTH " << A << " " << B << " " << C << endl;
                }
            }
            out << "DONE" << endl;
        }
        out.close();
    }

    int LCA_query(int u, int v) {
        int _lca = LCA(u, v);
        return d[u] + d[v] - 2*d[_lca];
    }
#endif // DEBUG

void process() {
    reset();
    enter();
    init();

    while (true) {
        char buff[10];  scanf("%s", buff);
        if (*buff == 'D' && buff[3] == 'E') break;
        int u, v;   scanf("%d %d", &u, &v);
        if (*buff == 'D') {
            printf("%d\n", dist(u, v));

            #ifdef DEBUG
                assert(LCA_query(u, v) == dist(u, v));
            #endif // DEBUG
        }
        else {
            int k;  scanf("%d\n", &k);
            printf("%d\n", kth(u, v, k));
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        assert(freopen(task".inp", "r", stdin));
        assert(freopen(task".out", "w", stdout));
    #endif // ONLINE_JUDGE

    #ifdef DEBUG
        generate_graph_random(1, 10, 10);
    #endif // DEBUG

    int Case;   scanf("%d", &Case);
    while (Case--) process();

    return 0;
}
