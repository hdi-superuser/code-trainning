#include <bits/stdc++.h>

using namespace std;

int m, n, X, a[1000001];

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d\n", &x);
        X = max(x, X);
        a[x] = 1 - a[x];
        int res = 0, t = 1;
        for (int i = 2; i <= n; i++)
            if (a[i] == a[i-1]) t++;
            else res = max(res, t), t = 1;
        //res = max(res, max(t, n - X + 1));
        res = max(res, t);
        printf("%d\n", res);
    }
    return 0;
}

