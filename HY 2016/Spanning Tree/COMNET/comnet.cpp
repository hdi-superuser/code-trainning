#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
const int M = 1000001;

int n, m, q;
int old[N], root[N];

struct data {
    int u, v, w, w2;
} d[M];

void read() {
    scanf("%d %d %d\n", &n, &m, &q);
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        scanf("%d %d %d\n", &x, &y, &z);
        d[i].u = x; d[i].v = y; d[i].w = z;
    }
}

int getroot(int x) {
    return root[x] == -1 ? x : root[x] = getroot(root[x]);
}

void join(int x, int y) {
    int r1 = getroot(x);
    int r2 = getroot(y);
    if (r1 < r2) root[r2] = r1;
    else root[r1] = r2;
}

void solve() {
    while (q--) {
        memset(root, -1, sizeof root);
        int k, v;
        scanf("%d %d", &k, &v);
        for (int j = 1; j <= v; j++) {
            int u, c;
            scanf("%d %d", &u, &c);
            d[u].w2 = c;
            int t = d[u].w2; d[u].w2 = d[u].w; d[u].w = t;
            old[j] = u;
	    scanf("\n");
        }
        for (int i = 1; i <= m; i++)
            if (d[i].w < d[k].w) {
                int r1 = getroot(d[i].u);
                int r2 = getroot(d[i].v);
                if (r1 != r2) join(r1, r2);
            }
        if (getroot(d[k].u) == getroot(d[k].v)) printf("YES\n");
        else printf("NO\n");
        for (int i = 1; i <= v; i++) {
            int j = old[i];
            int t = d[j].w; d[j].w = d[j].w2; d[j].w2 = t;
        }
    }
}

main() {
    freopen("COMNET.INP", "r", stdin);
    freopen("COMNET.OUT", "w", stdout);
    int T; scanf("%d\n", &T);
    while (T--) {
        read();
        solve();
    }
    return 0;
}
