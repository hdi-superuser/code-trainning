#include <bits/stdc++.h>

using namespace std;

const int N = 200001;

struct pack {
    int s, f;

    bool operator < (const pack &p) {
        return s < p.s || (s == p.s && f < p.f);
    }
} a[N];

int n;

bool ok(int x) {

}

int main() {
    freopen("convention.inp", "r", stdin);
    freopen("convention.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].s >> a[i].f;

    sort(a + 1, a + n + 1);
    int L = 0, R = n;
    while (L < R - 1) {
        int mid = L + (R - L)/2;
        if (ok(mid)) L = mid;
        else R = mid;
    }

    return 0;
}
