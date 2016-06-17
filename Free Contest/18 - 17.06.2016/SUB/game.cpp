#include <bits/stdc++.h>

using namespace std;

const int N = 701;
typedef int ll;

int n;
ll a[N], memo[N][N];

ll dp(int L, int R) {
    if (memo[L][R] != -1) return memo[L][R];
    ll ans = 0;
    for (int i = L + 1; i < R; i++)
        ans = max(ans, dp(L, i) + dp(i, R) + a[i]*(a[L] + a[R]));
    return memo[L][R] = ans;
}

int main() {
    //freopen("in.txt", "r", stdin);
    int n;
    memset(memo, -1, sizeof memo);
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) scanf("%d ", &a[i]);
    printf("%d", dp(1, n));
    return 0;
}
