#include <bits/stdc++.h>

using namespace std;

const int N = 201;

int f[N][N], a[N], n;

int main() {
    freopen("email.inp", "r", stdin);
    freopen("email.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) f[i][j] = N*(i != j ? 1 : 0);

    for (int k = 2; k <= n; k++)
        for (int i = 1; i <= n-k+1; i++)
            for (int j = 1; j < k; j++)
                f[i][i+k-1] = min(f[i][i+k-1], f[i][i+j-1] + f[i+j][i+k-1] + (a[i] != a[i+j] ? 1 : 0));

    cout << f[1][n] + 1;
}
