#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
const int inf = 2000000001;

typedef long long ll;

int n, a[N], b[N], c[N];

ll merge_sort(int l, int r) {
    if (l == r) return 0;

    int m = (l + r) >> 1;
    ll res = merge_sort(l, m) + merge_sort(m+1, r);

    int cur1, cur2, nb, nc;
    cur1 = cur2 = 1;    nb = nc = 0;
    for (int i = l; i <= m; i++) b[++nb] = a[i];
    for (int i = m+1; i <= r; i++) c[++nc] = a[i];
    b[++nb] = c[++nc] = inf;

    for (int i = l; i <= r; i++)
        if (b[cur1] <= c[cur2]) a[i] = b[cur1++], res += cur2 - 1;
        else a[i] = c[cur2++];

    return res;
}

int main() {
    freopen("invers.inp", "r", stdin);
    freopen("invers.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << merge_sort(1, n);

    return 0;
}
