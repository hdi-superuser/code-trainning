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
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    memset(d, 0, sizeof d);
    d[1] = 0;
    tr[1] = 1;
    dfs(1);
    int t1 = max_element(d + 1, d + n + 1) - d;
    memset(d, 0, sizeof d);
    memset(tr, 0, sizeof tr);
    d[t1] = 0;
    tr[t1] = t1;
    dfs(t1);
    int k = max_element(d + 1, d + n + 1) - d;
    cout << d[k] << endl;
    if (d[k] % 2 == 0) {
        cout << "1" << endl;
        int t = d[k]/2, u = k;
        while (t--) u = tr[u];
        cout << u << endl;
    } else {
        cout << "2" << endl;
        int t = d[k]/2, u = k;
        while (t--) u = tr[u];
        int v = tr[u];
        if (v < u) swap(u, v);
        cout << u << " " << v;
    }

    return 0;
}

