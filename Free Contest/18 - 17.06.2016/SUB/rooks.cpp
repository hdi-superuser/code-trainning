#include <bits/stdc++.h>

using namespace std;

const int N = 51;
const int base = 10003;
const int mod = 10003;

int memo[2*N][N][N][N];

int dp(int K, int r, int n0,int n1) {
    if (K < 0 || n0 < 0 || n1 < 0) return 0;
    if (r == 0) return (K == 0);
    int ans = memo[K][r][n0][n1];
    if (ans >= 0) return ans;

    ans = dp(K, r-1, n0, n1);

    ans = (ans + n0 * dp(K-1, r-1, n0-1, n1+1)) % base;
    ans = (ans + n1 * dp(K-1, r-1, n0, n1-1)) % base;

    ans = (ans + n0 * (n0-1)/2 * dp(K-2, r-1, n0-2, n1+2)) % base;
    ans = (ans + n0 * n1 * dp(K-2, r-1, n0-1, n1)) % base;
    ans = (ans + n1 * (n1-1)/2 * dp(K-2, r-1, n0, n1-2)) % base;

    return memo[K][r][n0][n1] = ans;
}

int main() {
    //freopen("in.txt", "r", stdin);
    int n, m, k;
    scanf("%d %d %d", &m, &n, &k);
    if (k > 2*min(m, n)) {
        printf("0\n");
        return 0;
    }
    memset(memo, -1, sizeof(memo));
    printf("%d\n", dp(k, m, n, 0));
    return 0;
}
