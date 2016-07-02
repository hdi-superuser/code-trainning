#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int n, d[100001], tr[100001];
vi a[100001];

int dfs(int u) {
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (tr[v]) continue;
        tr[v] = u;
        d[v] = d[u] + 1;
        dfs(v);
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d\n", &n);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d %d\n", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }

    memset(d, 0, sizeof d);
    dfs(1);
    int t1 = max_element(d + 1, d + n + 1) - d;
    memset(d, 0, sizeof d);
    dfs(t1);
    int w = *max_element(d + 1, d + n + 1);

    cout << w << endl;

    return 0;
}
