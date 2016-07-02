#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;

int n;
vector<ii> a[100001];
ll d[100001];
bool fr[100001];

void dfs(int u) {
    fr[u] = 1;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i].first;
        if (fr[v]) continue;
        d[v] = d[u] + a[u][i].second;
        dfs(v);
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> n;
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        a[u].push_back(ii(v, k));
        a[v].push_back(ii(u, k));
        sum += k;
    }
    dfs(1);
    ll T = 0;
    for (int i = 1; i <= n; i++) T = max(T, d[i]);
    cout << 2*sum - T;
    return 0;
}
