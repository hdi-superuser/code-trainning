#include <bits/stdc++.h>

#define task "main"
#define DEBUG(z, x) { cerr << setw(z) << "" << (#x) << " = " << (x) << '\n'; }
using namespace std;

const int N = 10010;
const int inf = 0x3f3f3f;

struct edge {
    int u, v, c;
    edge(int u = 0, int v = 0, int c = 0) : u(u), v(v), c(c) {}
    inline int get(int x) const {
        return u == x ? v : u;
    }
} e[N];

struct node {
    int lazy, neg_min, neg_max, pos_min, pos_max;
    node() : lazy(0), neg_max(-inf), neg_min(inf), pos_max(-inf), pos_min(inf) {}
    inline friend node merge(const node& x, const node& y) {
        node r;
        r.lazy = 0;
        r.neg_max = max(x.neg_max, y.neg_max);
        r.neg_min = min(x.neg_min, y.neg_min);
        r.pos_max = max(x.pos_max, y.pos_max);
        r.pos_min = max(x.pos_min, y.pos_min);
        return r;
    }
};

vector <node> tree[N];
vector <int> ed[N], chain[N];
int eid[N], eps[N], vid[N], vps[N], top[N];
int sub_sz[N], depth[N], ancestor[15][N], heavy[N];

inline void push(int id, int i) {
    node& x = tree[id][i];
    swap(x.neg_max, x.pos_min);
    swap(x.neg_min, x.pos_max);

    x.neg_max = -x.neg_max;     x.neg_min = -x.neg_min;
    x.pos_max = -x.pos_max;    x.pos_min = -x.pos_min;

    tree[id][i].lazy ^= 1;
}

inline void push(int id, int i, int f, int t) {
    if (f < t && tree[id][i].lazy > 0) {
        push(id, i << 1);
        push(id, i << 1 | 1);
        tree[id][i].lazy = 0;
    }
}

void change(int id, int i, int f, int t, int p, int v) {
    push(id, i, f, t);
    if (f == t) {
        tree[id][i] = node();
        if (v <= 0) tree[id][i].neg_min = tree[id][i].neg_max = v;
        if (v >= 0) tree[id][i].pos_min = tree[id][i].pos_max = v;
    } else {
        int mid = (f + t) >> 1;
        if (p < mid + 1) change(id, i << 1, f, mid, p, v);
        else change(id, i << 1 | 1, mid + 1, t, p, v);
        tree[id][i] = merge(tree[id][i << 1], tree[id][i << 1 | 1]);
    }
}

void _negate(int id, int i, int f, int t, int qf, int qt) {
    push(id, i, f, t);
    if (qf <= f && t <= qt) push(id, i);
    else {
        int mid = (f + t) >> 1;
        if (qf < mid + 1) _negate(id, i << 1, f, mid, qf, qt);
        if (qt > mid) _negate(id, i << 1 | 1, mid + 1, t, qf, qt);
        tree[id][i] = merge(tree[id][i << 1], tree[id][i << 1 | 1]);
    }
}

int query(int id, int i, int f, int t, int qf, int qt) {
    push(id, i, f, t);
    if (qf <= f && t <= qt) return max(tree[id][i].pos_max, tree[id][i].neg_max);
    int mid = (f + t) >> 1;
    if (qt < mid + 1) return query(id, i << 1, f, mid, qf, qt);
    if (qf > mid) return query(id, i << 1 | 1, mid + 1, t, qf, qt);
    return max(query(id, i << 1, f, mid, qf, qt), query(id, i << 1 | 1, mid + 1, t, qf, qt));
}

void dfs_size(int u, int p) {
    ancestor[0][u] = p;
    depth[u] = depth[p] + 1;
    sub_sz[u] = 1;
    for (int i = 0; i < (int) ed[u].size(); i++) {
        int id = ed[u][i];
        int v = e[id].get(u);
        if (v == p) continue;
        dfs_size(v, u);
        sub_sz[u] += sub_sz[v];
        if (sub_sz[heavy[u]] < sub_sz[v]) heavy[u] = v;
    }
}

void dfs_heavy(int u, int p, int tp, int cid, int cps, int& cnt) {
    vid[u] = cid;
    vps[u] = cps;
    top[u] = tp;
    for (int i = 0; i < (int) ed[u].size(); i++) {
        int id = ed[u][i];
        int v = e[id].get(u);
        if (v == p) continue;
        if (v == heavy[u]) {
            chain[cid].push_back(id);
            eid[id] = cid;
            eps[id] = cps + 1;
            dfs_heavy(v, u, tp, cid, cps + 1, cnt);
        } else {
            cnt++;
            chain[cnt].push_back(id);
            eid[id] = cnt;
            eps[id] = 1;
            dfs_heavy(v, u, u, cnt, 1, cnt);
        }
    }
}
/*
inline int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int delta = depth[u] - depth[v];
    for (int i = 14; i >= 0; i--)
        if ((delta >> i) & 1) u = ancestor[u][i];
    if (u == v) return u;
    for (int i = 14; i >= 0; i--)
        if (ancestor[u][i] != ancestor[v][i])
            u = ancestor[u][i], v = ancestor[v][i];
    return ancestor[u][0];
}
*/
inline int jump(int u, int v, int d) {
  for (int i = 14; i >= 0; --i)
    if (depth[u] - (1 << i) >= depth[v] + d)
      u = ancestor[i][u];
  return u;
}

inline int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  u = jump(u, v, 0);
  if (u == v) return u;
  for (int i = 14; i >= 0; --i)
    if (ancestor[i][u] != ancestor[i][v]) {
      u = ancestor[i][u];
      v = ancestor[i][v];
    }
  return ancestor[0][u];
}

inline void change(int p, int v) {
    int id = eid[p];
    int sz = (int) chain[id].size();
    change(id, 1, 1, sz, eps[p], v);
}

inline int query(int u, int v) {
    int res = -inf;
    for ( ;; ) {
        int id = vid[u];
        int sz = (int) chain[id].size();
        if (id == vid[v]) {
            if (vps[u] > vps[v]) {
                int val = query(id, 1, 1, sz, vps[v] + 1, vps[u]);
                res = max(res, val);
            }
            break;
        }
        int val = query(id, 1, 1, sz, 1, vps[u]);
        res = max(res, val);
        u = top[u];
    }
    return res;
}

inline void _negate(int u, int v) {
    for ( ;; ) {
        int id = vid[u];
        int sz = (int) chain[id].size();
        if (id == vid[v]) {
            if (vps[u] > vps[v]) _negate(id, 1, 1, sz, vps[v] + 1, vps[u]);
            break;
        }
        _negate(id, 1, 1, sz, 1, vps[u]);
        u = top[u];
    }
}

void process() {
    int n;  scanf("%d", &n);
    for (int i = 1; i <= n; i++) ed[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        e[i] = edge(u, v, c);
        ed[u].push_back(i);
        ed[v].push_back(i);
    }

    dfs_size(1, 0);
    int cnt = 1;
    chain[1].push_back(0);
    e[0].c = -inf;
    dfs_heavy(1, 0, 0, 1, 1, cnt);
    for (int i = 1; i <= cnt; i++) {
        int sz = (int) chain[i].size();
        if (tree[i].size() < (sz << 2 | 1)) tree[i].resize(sz << 2 | 1);
        for  (int j = 0; j < sz; j++) change(i, 1, 1, sz, j + 1, e[chain[i][j]].c);
    }

    for (int i = 1; 1 << i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];

    char s[10];
    while (~scanf("%s", s)) {
        if (*s == 'D') break;
        int x, y;   scanf("%d %d", &x, &y);
        if (*s == 'C') change(x, y);
        else {
            int z = lca(x, y);
            if (*s == 'Q') {
                int ans = max(query(x, z), query(y, z));
                if (ans == -inf) ans = 0;
                printf("%d\n", ans);
            } else {
                _negate(x, z);  _negate(y, z);
            }
        }
    }
    for (int i = 1; i <= cnt; i++) chain[i].clear();
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    #endif // ONLINE_JUDGE

    int Case;   scanf("%d", &Case);
    while (Case--) process();

    return 0;
}
