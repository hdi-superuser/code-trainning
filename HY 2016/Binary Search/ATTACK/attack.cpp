#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;
typedef long long ll;

ll k;
int n, a[N], b[N];

ll ok(ll x) {
    ll s = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= x) {
            s += (x - a[i])/b[i] + 1;
            if (s > k) break;
        }
    }
    return s > k;
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("attack.inp", "r", stdin);
    freopen("attack.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    ll L = 0, R = (ll) 6e18;
    while (L < R - 1) {
        ll mid = L + (R - L) / 2;
        if (ok(mid)) R = mid; else L = mid;
    }

    cout << R;

    return 0;
}
