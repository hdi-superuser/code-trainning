#include <bits/stdc++.h>

using namespace std;

const int N = 10001;
const int K = 51;

int n, k, a[N], idx[N], x[N];
int f[N][N];

void update(int op, int x, int val) {
    for (; x <= N; x += x & (-x)) f[op][x] += val;
}

int query(int op, int x) {
    int ans = 0;
    for (; x; x -= x & (-x)) ans += f[op][x];
    return ans;
}

int main() {
    freopen("incseq.inp", "r", stdin);
    freopen("incseq.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) idx[i] = a[i];
    sort(idx + 1, idx + n + 1);
    for (int i = 1; i <= n; i++)
        x[i] = lower_bound(idx + 1, idx + n + 1, a[i]) - idx;

    for (int i = 1; i <= n; i++) {
        update(1, x[i], 1);
        for (int j = 2; j <= k; j++)
            update(j, x[i], query(j-1, x[i]-1));
    }

    cout << f[k][x[n]];

    return 0;
}
