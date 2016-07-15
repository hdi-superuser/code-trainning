#include <bits/stdc++.h>

using namespace std;

const long long N = 1001;
const long long inf = 255;

long long n, k;
long long a[N], f[N][N];

long long sub(long long x, long long y) {
    long long temp = (x - y) % k;
    return temp >= 0 ? temp : temp + k;
}

int main() {
    freopen("sumchiak.inp", "r", stdin);
    freopen("sumchiak.out", "w", stdout);

    cin >> n >> k;
    long long s = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], s += a[i];
    for (int i = 1; i <= k; i++) f[0][i] = inf;

    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            if (f[i-1][j] < f[i-1][sub(j, a[i])] + 1)
                f[i][j] = f[i-1][j];
            else f[i][j] = f[i-1][sub(j, a[i])] + 1;

    cout << n - f[n][s % k] << endl;

    vector<int> ans;
    int i = n;
    long long t = s % k;   s = 0;
    for (int i = n; i >= 1; i--)
        if (f[i][t] == f[i-1][t]) ans.push_back(i);
        else t = sub(t, a[i]);

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

    return 0;
}
