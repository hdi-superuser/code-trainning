#include <bits/stdc++.h>

using namespace std;

const int N = 201;
const int inf = 1001;

int a[N], n, T, tp, tt, tc;
int f[N][N][N];

int dp(int u, int v, int k) {
    if (f[u][v][k] != -1) return f[u][v][k];
    if (u == v) return f[u][v][k] = 1;

    if (k == u) {
        T = 255;
        for (int q = u + 1; q <= v; q++) {
            tp = dp(u+1, v, q);
            tp += (a[u] != a[q] ? 1 : 0);
            T = min(T, tp);
        }
        return f[u][v][k] = T;
    }

    if (k == v) {
        T = 255;
        for (int p = u; p <= v-1; p++) {
            tt = dp(u, v-1, p);
            tt += (a[p] != a[v] ? 1 : 0);
            T = min(T, tt);
        }
        return f[u][v][k] = T;
    }

    T = 255;
    for (int p = u; p <= k-1; p++)
        for (int q = k+1; q <= v; q++) {
            tt = dp(u, k-1, p);
            tp = dp(k+1, v, q);
            if ((a[p] == a[k]) && (a[k] == a[q])) tc = tt+tp-1;
            else if ((a[p] == a[k]) && (a[k] != a[q])) tc = tt+tp;
            else if ((a[p] != a[k]) && (a[k] == a[q])) tc = tt+tp;
            else tc = tt+tp+1;
            T = min(tc, T);
        }
    return f[u][v][k] = T;
}

int main() {
    freopen("email.inp", "r", stdin);
    freopen("email.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++) f[i][j][k] = -1;

    int S = 255;
    for (int k = 1; k <= n; k++) S = min(S, dp(1, n, k));
    cout << S;

    return 0;
}
