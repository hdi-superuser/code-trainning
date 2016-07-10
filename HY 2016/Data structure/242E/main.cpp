#include <bits/stdc++.h>

using namespace std;

const int N = 100001;

int n, m, bit[21][N];
int it[21][4*N];

void par_update(int op, int x) {
    it[op][x] = it[op][2*x] + it[op][2*x+1];
}

void build(int op, int x, int L, int R) {
    if (L == R) {
        it[op][x] = bit[op][L];
        return;
    } else {
        int mid = (L + R) >> 1;
        build(op, 2*x, L, mid);
        build(op, 2*x+1, mid+1, R);
        par_update(op, x);
    }
}

void update(int op, int x, int L, int R, int u, int v) {
    if (L > v || R < u) return;
    if (L >= u && R <= v) {
        it[op][x] = 1 - it[op][x];
        return;
    }
    int mid = (L + R) >> 1;
    update(op, 2*x, L, mid, u, v);
    update(op, 2*x+1, mid+1, R, u, v);
    par_update(op, x);
}

int query(int op, int x, int L, int R, int u, int v) {
    if (L > v || R < u) return 0;
    if (L >= u || R <= v) return it[op][x];
    int mid = (L + R) >> 1;
    int left = query(op, 2*x, L, mid, u, v);
    int right = query(op, 2*x+1, mid+1, R, u, v);
    return left + right;
}

int CALC(int l, int r) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int temp = query(i, 1, 1, n, l, r);
        for (int j = 1; j <= temp; j++) res += (1 << (i-1));
    }
    return res;
}

void XOR(int l, int r) {
    for (int i = 1; i <= n; i++) update(i, 1, 1, n, l, r);
}

void DBG() {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) cout << bit[i][j] << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(NULL);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;  cin >> a;   int k = floor(log(a)/log(2)) + 1;
        for (int j = 1; j <= k; j++)
            bit[j][i] = (a >> (j-1)) & 1;
    }

    for (int i = 1; i <= 20; i++) build(i, 1, 1, n);
    cin >> m;
    while (m--) {
        int t, l, r, x;
        cin >> t >> l >> r;
        if (t == 1) cout << CALC(l, r) << endl;
        else {
            cin >> x;
            XOR(l, r);
        }
    }

    return 0;
}
