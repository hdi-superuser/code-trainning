#include <bits/stdc++.h>

using namespace std;

const int N = 4001;
int a[N], f[N], pre[N], n, L;

int main() {
    freopen("ptrang.inp", "r", stdin);
    freopen("ptrang.out", "w", stdout);

    cin >> n >> L;
    for (int i = 1; i <= n; i++) cin >> a[i];

    f[1] = L - a[1];
    for (int i = 2; i <= n; i++) {
        f[i] = max(L - a[i], f[i-1]);
        pre[i] = i - 1;
        int S = a[i];
        for (int j = i - 1; j >= 1; j--) {
            S += a[j];
            if (S > L) break;
            if (f[i] > max(L - S, f[j-1]))
                f[i] = max(L - S, f[j-1]),
                pre[i] = j - 1;
        }
    }

    cout << f[n] << " ";
    vector < pair<int, int> > ans;
    while (pre[n] != 0) {
        ans.push_back(make_pair(pre[n] + 1, n));
        n = pre[n];
    }
    ans.push_back(make_pair(1, n));

    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; i--) {
        for (int j = ans[i].first; j <= ans[i].second; j++) cout << j << " ";
        cout << endl;
    }

    return 0;
}
