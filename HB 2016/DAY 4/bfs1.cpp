#include <bits/stdc++.h>

using namespace std;

int m, n;
vector <int> a[100001];
int d[100001], tr[100001];

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d\n", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    queue <int> q;
    q.push(1);
    d[1] = 1;
    tr[1] = -1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i];
            if (tr[v]) continue;
            d[v] = d[u] + 1;
            tr[v] = u;
            q.push(v);
        }
    }

    for (int i = 1; i <= n; i++) printf("%d\n", d[i] - 1);
    return 0;
}
