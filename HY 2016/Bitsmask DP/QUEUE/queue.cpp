#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 21;

int n, a[N][N];
ll f[1 << N];

int main() {
    ios_base::sync_with_stdio(0);   cin.tie(NULL);
    freopen("queue.inp", "r", stdin);
    freopen("queue.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];

    int m = (1 << n);
    for (int i = 0; i < m; i++) {
        int j = __builtin_popcount(i);

        for (int t = 0; t < n; t++)
            if (((i >> t) & 1) == 0) {
                int nx = i | (1 << t);
                f[nx] = max(f[nx], f[i] + a[t+1][j+1]);
            }
    }

    cout << f[m - 1];

    return 0;
}
