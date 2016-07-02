#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
const int inf = 2000000001;

int n, c;
int a[N];

bool ok(int x) {
    int t = -inf, cnt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] - t >= x) {
            cnt++;
            if (cnt >= c) return true;
            t = a[i];
        }
    return false;
}

int main() {
    freopen("agg.inp", "r", stdin);
    freopen("agg.out", "w", stdout);
    scanf("%d %d\n", &n, &c);
    for (int i = 1; i <= n; i++) scanf("%d ", &a[i]);
    sort(a + 1, a + n + 1);
    int L = 0, R = inf, mid = (L + R) >> 1;
    while (L < R) {
        if (ok(mid)) L = mid; else R = mid - 1;
        mid = (L + R + 1) >> 1;
    }
    printf("%d\n", mid);
}
