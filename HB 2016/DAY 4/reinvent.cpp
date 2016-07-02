#include <bits/stdc++.h>

using namespace std;

vector <int> a[1000001];
int n, m, x, d[1000001], tr[1000001];

int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= x; i++) {
        int u;
        cin >> u;
        a[0].push_back(u);
    }
    queue<int> q;
    for (int i = 0; i < a[0].size(); i++) {
        q.push(a[0][i]);
        tr[a[0][i]] = a[0][i];
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i];
            if (tr[v] == tr[u]) continue;
            else if (tr[v] == 0) {
                d[v] = d[u] + 1;
                tr[v] = tr[u];
                q.push(v);
            } else {
                cout << d[u] + d[v] + 1 << endl;
                return 0;
            }
        }
    }
    return 0;
}
