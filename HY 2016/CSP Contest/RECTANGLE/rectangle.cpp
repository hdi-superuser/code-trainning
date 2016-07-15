#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

typedef long long ll;

ll a[N][N], l;
int n, m;

ll sum(int x1, int y1, int x2, int y2) {
    return a[x1][y1] - a[x1][y2-1] - a[x2-1][y1] + a[x2-1][y2-1];
}

bool ok(int x) {
    for (int i = x; i <= n; i++)
        for (int j = x; j <= m; j++) {
            if (sum(i, j, i - x + 1, j - x + 1) == l) return true;
        }
    return false;
}

void solve() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            a[i][j] = a[i][j-1] + a[i-1][j] - a[i-1][j-1] + cnt,
            cnt++;
    }

    int L = 0, R = min(n, m);
    bool f = false;
    while (L < R - 1) {
        int mid = L + (R - L)/2;
        if (ok(mid)) R = mid, f = true;
        else L  = mid;
    }

    if (!f) { cout << "-1" << endl; return; }
    cout << R*R << endl;
}

int main() {
    ios_base::sync_with_stdio(0);   cin.tie(NULL);
    freopen("rectangle.inp", "r", stdin);
    freopen("rectangle.out", "w", stdout);

    int T;  cin >> T;
    while (T--) {
        cin >> n >> m >> l;
        if (n == 1 && m == 1 && l == 0) { cout << "1" << endl; continue; }
        if (n == 1 && m == 1 && l != 0) { cout << "-1" << endl; continue; }
        solve();
    }

    return 0;
}
