#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 10001;

struct Edge {
    int u, v, cost;
    Edge() {};
    Edge(int _u, int _v, int _cost) : u(_u), v(_v), cost(_cost) {};
    int getNb(int V) {  return V == v ? u : v;  }
};

vector <int> nb[N];
Edge edges[N];
int n, LOG, numChains, generateArrayIdx;
int childSz[N], parent[N][32], depth[N], isSpecial[N];
int generateArray[N], chainHead[N], chainSize[N], vertexChain[N], vertexPos[N], tree[8*N];

int slow(int u, int c, int p, int r) {
    if (u == r) return c;
    int res = 0;

    for (int i = 0; i < nb[u].size(); i++) {
        int v = edges[nb[u][i]].getNb(u);
        if (p == v) continue;
        int q = slow(v, edges[nb[u][i]].cost, u, r);
        if (q) q = max(q, edges[nb[u][i]].cost);
        res = max(res, q);
    }

    return res;
}

void reset() {
    numChains = 0;  generateArrayIdx = 0;
    for (int i = 0; i <= n; i++) {
        nb[i].clear();
        childSz[i] = parent[i][0] = depth[i] = 0;
        isSpecial[i] = chainHead[i] = generateArray[i] = 0;
        chainSize[i] = vertexChain[i] = vertexPos[i] = 0;
    }
}

void dfs(int u, int p) {
    childSz[u] = 1; parent[u][0] = p;   depth[u] = depth[p] + 1;
    for (int i = 0; i < nb[u].size(); i++) {
        int v = edges[nb[u][i]].getNb(u);
        if (v == p) continue;
        dfs(v, u);
        childSz[u] += childSz[v];
    }
}

void HLD(int u, int e) {
    if (chainHead[numChains] == 0) chainHead[numChains] = u;
    vertexChain[u] = numChains;
    vertexPos[u] = generateArrayIdx;
    chainSize[numChains]++;
    if (u) generateArray[generateArrayIdx++] = e;

    int special = 0, edge;
    for (int i = 0; i < nb[u].size(); i++) {
        int v = edges[nb[u][i]].getNb(u);
        if (v == parent[u][0]) continue;

        if (childSz[v] > childSz[special])
            special = v,
            edge = edges[nb[u][i]].cost;
    }

    if (special == 0) return;
    isSpecial[special] = 1;
    HLD(special, edge);

    for (int i = 0; i < nb[u].size(); i++) {
        int v = edges[nb[u][i]].getNb(u);
        if (v == parent[u][0] || v == special) continue;
        ++numChains;
        HLD(v, edges[nb[u][i]].cost);
    }
}

void build(int idx, int sfrom, int sto) {
    if (sfrom == sto) {
        tree[idx] = generateArray[sfrom];
        return;
    }

    int mid = (sfrom + sto) >> 1;
    build(idx << 1, sfrom, mid);
    build(idx << 1 | 1, mid + 1, sto);
    tree[idx] = max(tree[idx << 1], tree[idx << 1 | 1]);
}

void init() {
    dfs(1, 0);  LOG = trunc(log(n)/log(2)) + 1;
    for (int i = 1; i <= LOG; i++)
        for (int u = 1; u <= n; u++)
            parent[u][i] = parent[parent[u][i-1]][i-1];

    HLD(1, 0);
    build(1, 0, generateArrayIdx - 1);
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int delta = depth[u] - depth[v];

    for (int i = LOG; i >= 0; i--)
        if ((delta >> i) & 1) u = parent[u][i];

    if (u == v) return u;

    for (int i = LOG; i >= 0; i--)
        if (parent[u][i] != parent[v][i])
            u = parent[u][i],
            v = parent[v][i];

    return parent[u][0];
}

int query(int idx, int sfrom, int sto, int qfrom, int qto) {
    if (sfrom == qfrom && sto == qto) return tree[idx];

    int mid = (sfrom + sto) >> 1;

    if (qto <= mid) {
        return query(idx << 1, sfrom, mid, qfrom, qto);
    } else if (qfrom > mid) {
        return query(idx << 1 | 1, mid + 1, sto, qfrom, qto);
    } else {
        return max(query(idx << 1, sfrom, mid, qfrom, mid),
                   query(idx << 1 | 1, mid + 1, sto, mid + 1, qto));
    }
}

void update(int idx, int sfrom, int sto, int pos) {
    if (sfrom == sto) {
        tree[idx] = generateArray[pos];
        return;
    }

    int mid = (sfrom + sto) >> 1;

    if (pos <= mid) {
        update(idx << 1, sfrom, mid, pos);
    } else {
        update(idx << 1 | 1, mid + 1, sto, pos);
    }

    tree[idx] = max(tree[idx << 1], tree[idx << 1 | 1]);
}

int subquery(int TOP, int BOTTOM) {
    int ans = -1;
    if (TOP == BOTTOM) return 0;

    while (true) {
        if (vertexChain[TOP] == vertexChain[BOTTOM]) {
            int topPos = vertexPos[TOP];
            int botPos = vertexPos[BOTTOM];

            if (topPos == botPos) return ans;

            topPos++;
            return max(ans, query(1, 0, generateArrayIdx - 1, topPos, botPos));
        } else {
            int botPos = vertexPos[BOTTOM];
            int topPos = vertexPos[chainHead[vertexChain[BOTTOM]]];

            ans = max(ans, query(1, 0, generateArrayIdx - 1, topPos, botPos));
            BOTTOM = parent[chainHead[vertexChain[BOTTOM]]][0];
        }
    }
}

int query(int u, int v) {
    int w = lca(u, v);
    return max(subquery(w, u), subquery(w, v));
}

int update(int u, int c) {
    Edge &e = edges[u-1];
    e.cost = c;
    int CHILD;
    if (e.u == parent[e.v][0]) CHILD = e.v;
    else CHILD = e.u;
    generateArray[vertexPos[CHILD]] = c;
    update(1, 0, generateArrayIdx - 1, vertexPos[CHILD]);
}

void genRandom() {
    int t = 1;
    ofstream out("main.inp");
    out << t << endl;
    srand(time(NULL));
    int FROM = 4000, TO = 4001;
    for (int i = 0; i < t; i++) {
        int v = rand() % (TO - FROM) + FROM;
        out << v << endl;
        vector <int> used;
        used.reserve(v);    used.push_back(1);
        for (int j = 2; j <= v; j++) {
            int cost = rand() % 100 + 5;
            int u = used[rand() % used.size()];
            used.push_back(j);
            out << u << " " << j << " " << cost << endl;
        }
        int op = 2000;
        for (int j = 0; j < op; j++) {
            int M = rand() % 2;
            if (M == 0) {
                int A = rand() % v + 1;
                int B = rand() % v + 1;
                out << "QUERY " << A << " " << B << endl;
            } else {
                int A = rand() % v + 1;
                int B = rand() % 1000 + 5;
                out << "CHANGE " << A << " " << B << endl;
            }
        }
        out << "DONE";
    }
    out.close();
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("main.inp", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif // ONLINE_JUDGE

    #ifdef DEBUG
        genRandom();
    #endif // DEBUG

    int t;  scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i < n; i++) {
            int a, b;    long long c;
            scanf("%d %d %lld", &a, &b, &c);
            edges[i-1] = Edge(a, b, c);
            nb[a].push_back(i-1);
            nb[b].push_back(i-1);
        }
        init();
        int a, b, c, cnt = 0;    char buf[7];
        while (true) {
            scanf("%s", buf);
            if (buf[0] == 'D') break;
            if (buf[0] == 'Q') {
                scanf("%d %d", &a, &b);
                printf("%d\n", query(a, b));

				#ifdef DEBUG
                    assert(query(a, b) == slow(a, 0, 0, b));
                #endif //DEBUG

            } else if (buf[0] == 'C') {
                scanf("%d %d", &a, &c);
                update(a, c);
            }
        }
        reset();
    }

    return 0;
}
