#include <bits/stdc++.h>

using namespace std;

const int N = 401;

int n, m, a[N][N], d[160001];

void Sol_1() {
    // O(N^4) solution: two pointer
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            int l = 1, r = 1;
            memset(d, 0, sizeof d);
            while (l <= r && l <= m && r <= m) {
                bool f = true;
                for (int k = i; k <= j; k++) d[a[k][r]]++;
                for (int k = i; k <= j; k++)
                    if (d[a[k][r]] > 1) { f = false; break; }
                if (f) ans = max(ans, (j - i + 1)*(r - l + 1)), r++;
                else {
                    for (int k = i; k <= j; k++) d[a[k][l]] = 0;
                    l++;    r++;
                }
            }
        }
    cout << ans;
}

void Sol_2() {
    // O(N^3 * log2(N)) solution
}

int main() {
    freopen("in.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    Sol_1();

    return 0;
}
