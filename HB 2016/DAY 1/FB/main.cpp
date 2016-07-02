#include <bits/stdc++.h>

using namespace std;

const int N = 501;
typedef vector<int> vi;

vi res;
int S, m, n, k;
int p[N], c[N][N];

void read() {
    scanf("%d %d %d\n", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%d ", &p[i]);
    scanf("\n");
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d\n", &u, &v);
        c[u][v] = c[v][u] = 1;
    }
}

bool ok(vi t) {
    if (k % 2) {
        if (t.size() < k+1) return false;
    } else {
        if (t.size() < k+2) return false;
    }

    for (int i = 0; i < t.size(); i++)
        for (int j = i + 1; j < t.size(); j++)
            if (c[t[i]][t[j]]) return false;
    return true;
}

void solve_1() {
    int Stt = (1 << n) - 1;
    for (int i = 0; i < Stt; i++) {
        int nS = 0;
        vi t; t.assign(0, 0);
        for (int j = 1; j <= n; j++)
            if ((i >> (j - 1)) & 1) {
                nS += p[j];
                t.push_back(j);
            }
        if (ok(t)) {
            if (nS > S) {
                S = nS;  res.clear();
                for (int i = 0; i < t.size(); i++) res.push_back(t[i]);
            }
        }
    }
}

void print() {
    if (S == 0) { printf("-1"); return; }
    printf("%d\n", S);
    /*
    int nn = res.size();
    int t1[N], t2[N], n1 = 0, n2 = 0;
    for (int i = 0; i < nn/2; i++) t[++n1] = res[i];
    for (int i = nn/2 + 1; i < res.size(); i++) t[++n2] = res[i];
    */
}

int main() {
    freopen("fb.inp", "r", stdin);
    freopen("fb.out", "w", stdout);
    int T;
    scanf("%d\n", &T);
    while (T--) {
        read();
        solve_1();
        print();
    }
}
