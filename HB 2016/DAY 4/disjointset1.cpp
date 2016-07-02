#include <bits/stdc++.h>

using namespace std;

int m, n, q;
int p[100001];

int root(int u) {
    return (p[u] == u) ? u : p[u] = root(p[u]);
}

void joint(int u, int v) {
    p[root(u)] = p[root(v)];
}

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d %d %d\n", &n, &m, &q);
    for (int i = 1; i <= n; i++) p[i] = i;
    while (m--) {
        int x, y;
        scanf("%d %d\n", &x, &y);
        joint(x, y);
    }
    while (q--) {
        int x, y;
        scanf("%d %d\n", &x, &y);
        printf(root(x) == root(y) ? "YES\n" : "NO\n");
    }
    return 0;
}
