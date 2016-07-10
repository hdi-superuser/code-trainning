#include <bits/stdc++.h>

using namespace std;

int n, m, a[15001];

bool ok(int x) {
    int p = 0, s = 1;
    for (int i = 1; i <= n; i++)
        if (p + a[i] > x) p = a[i], s++;
        else p += a[i];
    return s <= m;
}

int main() {
    freopen("zxy.inp", "r", stdin);
    freopen("zxy.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int L = 0, R = (int) 500e6;
    while (L < R - 1) {
        int mid = L + (R - L)/2;
        if (ok(mid)) R = mid;
        else L = mid;
    }

    cout << R;

    return 0;
}
