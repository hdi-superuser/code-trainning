#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
typedef pair<int, int> ii;

int n, m, a[N];
int L[500001], R[500001], xx[500001], xy[500001];

int main() {
    freopen("running.inp", "r", stdin);
    freopen("running.out", "w", stdout);

    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) scanf("%d\n", &a[i]);

    sort(a + 1, a + n + 1);
    m = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 2; j <= n; j++) {
            int x = a[i], z = a[j];
            double ymin = (double) (2*x + z)/3, ymax = (double) (x + z)/2;

            if (ymin - (2*x + z)/3 > 0) ymin = (2*x + z)/3 + 1;
            if (ymax - (x + z)/2 > 0) ymax = (x + z)/2;

            L[++m] = ymin;  R[m] =  ymax;
            xx[m] = i;      xy[m] = j;
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int l = lower_bound(a + xx[i] + 1, a + xy[i], L[i]) - a;
        int r = upper_bound(a + xx[i] + 1, a + xy[i], R[i]) - a;
        if (r == l) continue;
        ans += (r - l);
    }

    printf("%d\n", ans);

    return 0;
}

/*
    for x = 1 -> n
        for y = 1 -> n {
            while (3*(a[x] + a[z]) > 6*a[L] && L <= n) L++;
            while (2*(2*a[x] + a[z]) >= 6*a[R] && R <= n) R++;
            ans += R - L;
        }
*/
