#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 1000000000;
const int N = 10001;

int n, k, a[N];
ll res, f[11][N], t[N];

void update(int x, ll val) {
    while (x > 0)
        t[x] = (t[x] + val) % M,
        x -= x & (-x);
}

ll query(int x) {
    ll ans = 0;
    while (x <= n)
        ans = (ans + t[x]) % M,
        x += x & (-x);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("kinv.inp", "r", stdin);
    freopen("kinv.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) f[1][i] = 1;
    for (int i = 2; i <= k; i++) {
    	for (int j = 1; j <= n; j++) t[j] = 0;
    	for (int j = 1; j <= n; j++) {
            f[i][j] = query(a[j]+1);
            update(a[j], f[i-1][j]);
        }
    }

    for (int i = 1; i <= n; i++) res = (res + f[k][i]) % M;
    cout << res;

    return 0;
}
