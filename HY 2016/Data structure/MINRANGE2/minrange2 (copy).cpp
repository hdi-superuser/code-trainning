#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
const int inf = 2000000001;

int n, m;
int a[N], it[4*N], lazy[4*N];

void build(int x, int L, int R) {
    if (L == R) {
        it[x] = a[L];
    } else {
        int mid = (L + R) >> 1;
        build(2*x, L, mid);
        build(2*x + 1, mid + 1, R);
        it[x] = min(it[2*x], it[2*x+1]);
    }
}

void lazy_update(int x) {
    if (lazy[x] == 0) return;
    it[2*x] = lazy[x];
    it[2*x+1] = lazy[x];
    lazy[2*x] = lazy[x];
    lazy[2*x+1] = lazy[x];
    lazy[x] = 0;
}

void update(int x, int L, int R, int u, int v, int val) {
    if (L > v || R < u) return;
    if (L >= u && R <= v) {
        it[x] = val;
        lazy[x] = val;
        return;
    }
    lazy_update(x);
    int mid = (L + R) >> 1;
    update(2*x, L, mid, u, v, val);
    update(2*x+1, mid+1, R, u, v, val);
    it[x] = min(it[2*x], it[2*x+1]);
}

int query(int x, int L, int R, int u, int v) {
    if (L > v || R < u) return inf;
    if (L >= u && R <= v) return it[x];
    lazy_update(x);
    int mid = (L + R) >> 1;
    int left = query(2*x, L, mid, u, v);
    int right = query(2*x+1, mid+1, R, u, v);
    return min(left, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("minrange2.inp", "r", stdin);
    freopen("minrange2.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

    while (m--) {
        int c, u, v, k;
        cin >> c >> u >> v;
        if (c == 1) {
            cin >> k;
            update(1, 1, n, u, v, k);
        } else cout << query(1, 1, n, u, v) << endl;
    }

    return 0;
}
