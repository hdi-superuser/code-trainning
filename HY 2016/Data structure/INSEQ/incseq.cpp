#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
const int K = 51;
const long long M = 5000000;

int n, k, a[N], idx[N], x[N];
long long f[K][N];

void update(int op, int pos, long long val) {
    while (pos < n + 5) {
        f[op][pos] = (f[op][pos] % M + val % M) % M;
        pos += (pos & -pos);
    }
}

long long query(int op, int pos) {
    long long ans = 0;
    while (pos > 0) {
        ans = (ans % M + f[op][pos] % M) % M;
        pos -= (pos & -pos);
    }
    return ans % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("incseq.inp", "r", stdin);
    freopen("incseq.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) idx[i] = a[i];
    sort(idx + 1, idx + n + 1);
    int m = unique(idx + 1, idx + n + 1) - idx - 1;
    for (int i = 1; i <= n; i++)
        x[i] = lower_bound(idx + 1, idx + m + 1, a[i]) - idx;

    for (int i = 1; i <= n; i++) {
        update(1, x[i], 1);
        for (int j = 2; j <= k; j++)
            update(j, x[i], query(j-1, x[i]-1));
    }

    cout << query(k, n+1) % M << endl;

    return 0;
}
