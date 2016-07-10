#include <bits/stdc++.h>

using namespace std;

const int N = 25001;

int n, a[N], f[N];

int main() {
    freopen("cable.inp", "r", stdin);
    freopen("cable.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    f[1] = 0;
    f[2] = a[1];
    f[3] = a[1] + a[2];

    for (int i = 4; i <= n; i++)
        f[i] = min(f[i-1] + a[i-1], f[i-2] + a[i-1]);

    cout << f[n];
}
