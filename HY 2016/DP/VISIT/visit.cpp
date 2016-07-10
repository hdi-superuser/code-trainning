#include <bits/stdc++.h>

using namespace std;

const int N = 20001;

int n, a[N], b[N], l[N], r[N], f[N];

int main() {
    freopen("visit.inp", "r", stdin);
    freopen("visit.out", "w", stdout);

    int s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    a[1] = r[1] - 1 + r[1] - l[1];    b[1] = r[1] - 1;

    for (int i = 2; i <= n; i++) {
        a[i] = r[i] - l[i] + min(a[i-1] + abs(l[i-1] - r[i]), b[i-1] + abs(r[i-1] - r[i]));
        b[i] = r[i] - l[i] + min(a[i-1] + abs(l[i-1] - l[i]), b[i-1] + abs(r[i-1] - l[i]));
    }

    cout << min(a[n] + n - l[n], b[n] + n - r[n]) + n - 1;
}
