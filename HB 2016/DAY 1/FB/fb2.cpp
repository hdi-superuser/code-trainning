#include <bits/stdc++.h>

using namespace std;

const int N = 501;

int m, n, k, s, resn;
int c[N][N], p[N];
vector <int> res, ans;

void read() {
    scanf("%d %d %d\n", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    scanf("\n");
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d\n", &u, &v);
        c[u][v] = c[v][u] = 1;
    }
}

bool ok() {
    if (k & 1) {
        if (res.size() < k + 1) return false;
    } else {
        if (res.size() < k + 2) return false;
    }
    for (int k = 0; k < (int) res.size(); k++)
        for (int t = k + 1; t < (int) res.size(); t++)
            if (c[res[k]][res[t]]) return false;
    return true;
}

void Max() {
    ans.clear();
    for (int i = 0; i < res.size(); i++) ans.push_back(res[i]);
}

void solve_1() {
    res.clear();
    int nStt = (1 << n) - 1;
    for (int i = 0; i <= nStt; i++) {
        int ns = 0, nn = 0;
        res.clear();
        for (int j = 1; j <= n; j++) {
            if ((i >> (j-1) & 1)) {
                res.push_back(j);
                ns += p[j];
                nn++;
            }
        }
        if (ok() && ns > s) {
            s = ns, resn = nn;
            Max();
        }
    }
}

void print() {
    if (s == 0) { printf("-1"); return; }
    printf("%d\n", resn);
    /*
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    int tt = (res.size() / 2), c1[501], c2[501];
    for (int i = 0; i < tt; i++) c1[i] = res[i + 1];
    for (int i = tt + 1; i < res.size(); i++) c2[i - tt] = res[i];
    for (int i = 1; i < tt; i++)
    */
}

int main() {
    freopen("fb.inp", "r", stdin);
    freopen("fb.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        read();
        solve_1();
        print();
    }
    return 0;
}
