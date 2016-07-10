#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
const int N = 100001;

int n, a[N], b[N];
double w, h;

bool ok(double x) {
    double height = 0, width = 0;
    int i = 1;
    while (i <= n) {
        width = 0;  int j = i;
        while (j <= n && width + a[j]*x <= w && b[i] == b[j]) width += a[j]*x, j++;
        height += b[i]*x;
        if (height > h || i == j) return false;
        i = j;
    }
    return true;
}

int main() {
    freopen("advert.inp", "r", stdin);
    freopen("advert.out", "w", stdout);

    cin >> n >> w >> h;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    double L = 0, R = w;
    while (R - L > eps) {
        double mid = (L + R) / 2;
        if (ok(mid)) L = mid; else R = mid;
    }

    printf("%0.6lf", R);

    return 0;
}
