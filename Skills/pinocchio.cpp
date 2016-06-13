#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int ans = 1, x, n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d ", &x);
        ans = __gcd(ans, x);
    }
    printf("%d\n", ans);
}
