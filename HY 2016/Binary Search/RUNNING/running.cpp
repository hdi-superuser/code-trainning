#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

int n, a[N];

int main() {
    freopen("running.inp", "r", stdin);
    freopen("running.out", "w", stdout);

    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) scanf("%d\n", &a[i]);

    int ans = 0;
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = i + 2; j <= n; j++) {
            int x = a[i], z = a[j];
            double ymin = (double) (2*x + z)/3, ymax = (double) (x + z)/2;

            if (ymin - (2*x + z)/3 > 0) ymin = (2*x + z)/3 + 1;
            if (ymax - (x + z)/2 > 0) ymax = (x + z)/2;

            int l = lower_bound(a + i + 1, a + j, ymin) - a;
            int r = upper_bound(a + i + 1, a + j, ymax) - a;
            if (r == l) continue;
            ans += (r - l);
        }
    }

    printf("%d\n", ans);

    return 0;
}
