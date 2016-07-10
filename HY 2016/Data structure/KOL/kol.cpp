#include <bits/stdc++.h>

using namespace std;

const int N = 30001;

int it[4*N], lazy[4*N];

void lazy_update(int x) {
    if (lazy[x] == 0) return;
    lazy[2*x] += lazy[x];
    lazy[2*x+1] += lazy[x];
    it[2*x] += lazy[x];
    it[2*x+1] += lazy[x];
    lazy[x] = 0;
}

void update(int x, int L, int R, int u, int v, int val) {
    if (L > v || R < u) return;
    if (L >= u && R <= v) {
        it[x] += val;
        lazy[x] += val;
        return;
    }
    lazy_update(x);
    int mid = (L + R) >> 1;
    update(2*x, L, mid, u, v, val);
    update(2*x+1, mid+1, R, u, v, val);
    it[x] = max(it[2*x], it[2*x+1]);
}

int query(int x, int L, int R, int u, int v) {
    if (L > v || R < u) return 0;
    if (L >= u && R <= v) return it[x];
    lazy_update(x);
    int mid = (L + R) >> 1;
    int left = query(2*x, L, mid, u, v);
    int right = query(2*x+1, mid+1, R, u, v);
    return max(left, right);
}

int main() {
    freopen("kol.inp", "r", stdin);
    freopen("kol.out", "w", stdout);

    int n, m, z;    scanf("%d %d %d\n", &n, &m, &z);
    while (z--) {
        int u, v, w;
        scanf("%d %d %d\n", &u, &v, &w);
        int temp = query(1, 1, n, u+1, v);
        if (m - temp >= w) {
            printf("T\n");
            update(1, 1, n, u+1, v, w);
        } else printf("N\n");
    }

    return 0;
}
